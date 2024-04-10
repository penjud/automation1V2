from sqlalchemy import create_engine, Column, Integer, String, ForeignKey, DateTime
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import relationship

Base = declarative_base()

class Strategy(Base):
    __tablename__ = 'strategies'
    strategy_id = Column(Integer, primary_key=True)
    strategy_name = Column(String, unique=True, nullable=False)
    strategy_settings = Column(String)

class Sport(Base):
    __tablename__ = 'sports'
    sport_id = Column(Integer, primary_key=True)
    name = Column(String, nullable=False)
    events = relationship("Event", back_populates="sport")

class Event(Base):
    __tablename__ = 'events'
    event_id = Column(Integer, primary_key=True)
    sport_id = Column(Integer, ForeignKey('sports.sport_id'))
    name = Column(String, nullable=False)
    start_time = Column(DateTime)
    venue = Column(String, nullable=True)
    sport = relationship("Sport", back_populates="events")
    markets = relationship("Market", back_populates="event")

class Market(Base):
    __tablename__ = 'markets'
    market_id = Column(Integer, primary_key=True)
    event_id = Column(Integer, ForeignKey('events.event_id'))
    market_name = Column(String, nullable=False)
    market_type = Column(String, nullable=False)
    market_time = Column(DateTime)
    market_status = Column(String, nullable=True)
    event = relationship("Event", back_populates="markets")
    runners = relationship("Runner", back_populates="market")

class Runner(Base):
    __tablename__ = 'runners'
    runner_id = Column(Integer, primary_key=True)
    market_id = Column(Integer, ForeignKey('markets.market_id'))
    runner_name = Column(String, nullable=False)
    market = relationship("Market", back_populates="runners")

class User(Base):
    __tablename__ = 'users'
    user_id = Column(Integer, primary_key=True)
    username = Column(String, unique=True, nullable=False)
    email = Column(String, unique=True, nullable=False)
    password_hash = Column(String, nullable=False)
    bets = relationship("Bet", back_populates="user")
    api_usages = relationship("BetfairAPIUsage", back_populates="user")
    whitelists = relationship("UserIPWhitelist", back_populates="user")

class UserIPWhitelist(Base):
    __tablename__ = 'user_ip_whitelist'
    whitelist_id = Column(Integer, primary_key=True)
    user_id = Column(Integer, ForeignKey('users.user_id'))
    ip_address = Column(String, nullable=False)
    user = relationship("User", back_populates="whitelists")

class Bet(Base):
    __tablename__ = 'bets'
    bet_id = Column(Integer, primary_key=True)
    user_id = Column(Integer, ForeignKey('users.user_id'))
    market_id = Column(Integer, ForeignKey('markets.market_id'))
    runner_id = Column(Integer, ForeignKey('runners.runner_id'))
    user = relationship("User", back_populates="bets")

class BetfairAPIUsage(Base):
    __tablename__ = 'betfair_api_usage'
    usage_id = Column(Integer, primary_key=True)
    user_id = Column(Integer, ForeignKey('users.user_id'))
    user = relationship("User", back_populates="api_usages")

class MarketChange(Base):
    __tablename__ = 'market_changes'
    change_id = Column(Integer, primary_key=True)
    market_id = Column(Integer, ForeignKey('markets.market_id'))
    market = relationship("Market")

class PriceVolumeData(Base):
    __tablename__ = 'price_volume_data'
    data_id = Column(Integer, primary_key=True)
    runner_id = Column(Integer, ForeignKey('runners.runner_id'))
    market_id = Column(Integer, ForeignKey('markets.market_id'))
    runner = relationship("Runner")
    market = relationship("Market")

class HistoricalData(Base):
    __tablename__ = 'historical_data'
    historical_id = Column(Integer, primary_key=True)
    market_id = Column(Integer, ForeignKey('markets.market_id'))
    event_id = Column(Integer, ForeignKey('events.event_id'))
    market = relationship("Market")
    event = relationship("Event")

class AdditionalData(Base):
    __tablename__ = 'additional_data'
    additional_data_id = Column(Integer, primary_key=True)
    event_id = Column(Integer, ForeignKey('events.event_id'))
    event = relationship("Event")

# Establish connection to the database and create tables
def create_db(uri):
    engine = create_engine(uri)
    Base.metadata.create_all(engine)
    return engine

if __name__ == '__main__':
    # Example usage, replace with your actual database URI
    engine = create_db('postgresql://username:password@')
