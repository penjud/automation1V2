import pandas as pd
from flumine import BaseStrategy 
from flumine.order.trade import Trade
from flumine.order.order import LimitOrder
from flumine.markets.market import Market
import logging

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class StrategyBase(BaseStrategy):
    def fetch_data(self, url):
        try:
            logger.info(f"Fetching data from {url}")
            df = pd.read_csv(url)
            df = df.rename(columns={
                "meetings.races.bfExchangeMarketId": "market_id",
                "meetings.races.runners.bfExchangeSelectionId": "selection_id",
                "meetings.races.runners.ratedPrice": "rating"
            })
            df['market_id'] = df['market_id'].astype(str)
            return df.set_index(['market_id', 'selection_id'])
        except Exception as e:
            logger.error(f"Error fetching data from {url}: {e}")
            raise

    def process_market_book(self, market: Market, market_book, df):
        if market.seconds_to_start < 60 and not market_book.inplay:
            for runner in market_book.runners:
                if runner.status == "ACTIVE" and runner.ex.available_to_back and runner.ex.available_to_lay:
                    try:
                        runner_price = df.loc[market_book.market_id].loc[runner.selection_id].item()
                        if runner.ex.available_to_back[0]['price'] > runner_price:
                            self.place_order(market_book, runner, "BACK", runner.ex.available_to_back[0]['price'])
                        if runner.ex.available_to_lay[0]['price'] < runner_price:
                            self.place_order(market_book, runner, "LAY", runner.ex.available_to_lay[0]['price'])
                    except KeyError:
                        logger.info(f"Price data not found for market {market_book.market_id} and runner {runner.selection_id}")

    def place_order(self, market_book, runner, side, price):
        trade = Trade(
            market_id=market_book.market_id,
            selection_id=runner.selection_id,
            handicap=runner.handicap,
            strategy=self,
        )
        order = trade.create_order(side=side, order_type=LimitOrder(price=price, size=1.00))
        market_book.place_order(order)

class FlatKashModel(StrategyBase):
    def start(self) -> None:
        print("starting strategy 'FlatKashModel'")
        url = 'https://betfair-data-supplier-prod.herokuapp.com/api/widgets/kash-ratings-model/datasets?date='
        url += pd.Timestamp.now().strftime("%Y-%m-%d")
        url += '&presenter=RatingsPresenter&csv=true'
        self.kash_df = self.fetch_data(url)

    def check_market_book(self, market: Market, market_book) -> bool:
        return market_book.status != "CLOSED"

    def process_market_book(self, market: Market, market_book) -> None:
        super().process_market_book(market, market_book, self.kash_df)

class FlatIggyModel(StrategyBase):
    def start(self, flumine) -> None:
        print("starting strategy 'FlatIggyModel'")
        url = 'https://betfair-data-supplier-prod.herokuapp.com/api/widgets/iggy-joey/datasets?date='
        url += pd.Timestamp.now().strftime("%Y-%m-%d")
        url += '&presenter=RatingsPresenter&csv=true'
        self.iggy_df = self.fetch_data(url)

    def check_market_book(self, market_book) -> bool:
        return market_book.status != "CLOSED"

    def process_market_book(self, market: Market, market_book) -> None:
        super().process_market_book(market, market_book, self.iggy_df)
