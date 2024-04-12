"""Initial migration.

Revision ID: fdf3fe8f8990
Revises: 
Create Date: 2024-04-12 10:11:50.959035

"""
from alembic import op
import sqlalchemy as sa
from sqlalchemy.dialects import postgresql

# revision identifiers, used by Alembic.
revision = 'fdf3fe8f8990'
down_revision = None
branch_labels = None
depends_on = None


def upgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    op.create_table('strategies',
    sa.Column('strategy_id', sa.Integer(), nullable=False),
    sa.Column('strategy_name', sa.String(), nullable=False),
    sa.Column('strategy_settings', sa.String(), nullable=True),
    sa.Column('created_at', sa.DateTime(), nullable=True),
    sa.Column('updated_at', sa.DateTime(), nullable=True),
    sa.PrimaryKeyConstraint('strategy_id'),
    sa.UniqueConstraint('strategy_name')
    )
    with op.batch_alter_table('additional_data', schema=None) as batch_op:
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))
        batch_op.drop_column('value')
        batch_op.drop_column('data_type')

    with op.batch_alter_table('betfair_api_usage', schema=None) as batch_op:
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))
        batch_op.drop_column('api_key')
        batch_op.drop_column('timestamp')
        batch_op.drop_column('operation')

    with op.batch_alter_table('bets', schema=None) as batch_op:
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))
        batch_op.drop_column('stake')
        batch_op.drop_column('outcome')
        batch_op.drop_column('placed_at')
        batch_op.drop_column('price')

    with op.batch_alter_table('events', schema=None) as batch_op:
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))
        batch_op.alter_column('start_time',
               existing_type=postgresql.TIMESTAMP(),
               nullable=True)

    with op.batch_alter_table('historical_data', schema=None) as batch_op:
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))
        batch_op.drop_column('captured_at')
        batch_op.drop_column('data')

    with op.batch_alter_table('market_changes', schema=None) as batch_op:
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))
        batch_op.drop_column('published_time')
        batch_op.drop_column('change_type')

    with op.batch_alter_table('markets', schema=None) as batch_op:
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))
        batch_op.alter_column('market_time',
               existing_type=postgresql.TIMESTAMP(),
               nullable=True)
        batch_op.alter_column('market_status',
               existing_type=sa.VARCHAR(length=50),
               nullable=True)
        batch_op.drop_column('runners_voidable')
        batch_op.drop_column('number_of_active_runners')
        batch_op.drop_column('version')
        batch_op.drop_column('complete')
        batch_op.drop_column('bet_delay')
        batch_op.drop_column('number_of_winners')
        batch_op.drop_column('bsp_reconciled')
        batch_op.drop_column('turn_in_play_enabled')
        batch_op.drop_column('cross_matching')
        batch_op.drop_column('in_play')

    with op.batch_alter_table('price_volume_data', schema=None) as batch_op:
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))
        batch_op.drop_column('time_recorded')
        batch_op.drop_column('volume')
        batch_op.drop_column('price')

    with op.batch_alter_table('runners', schema=None) as batch_op:
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))
        batch_op.drop_column('handicap')
        batch_op.drop_column('sort_priority')
        batch_op.drop_column('adjustment_factor')
        batch_op.drop_column('status')
        batch_op.drop_column('selection_id')
        batch_op.drop_column('last_traded_price')
        batch_op.drop_column('removal_date')
        batch_op.drop_column('total_matched')

    with op.batch_alter_table('sports', schema=None) as batch_op:
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))

    with op.batch_alter_table('user_ip_whitelist', schema=None) as batch_op:
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))

    with op.batch_alter_table('users', schema=None) as batch_op:
        batch_op.add_column(sa.Column('id', sa.Integer(), nullable=False))
        batch_op.add_column(sa.Column('created_at', sa.DateTime(), nullable=True))
        batch_op.add_column(sa.Column('updated_at', sa.DateTime(), nullable=True))
        batch_op.drop_column('api_key')
        batch_op.drop_column('session_token')

    # ### end Alembic commands ###


def downgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    with op.batch_alter_table('users', schema=None) as batch_op:
        batch_op.add_column(sa.Column('session_token', sa.VARCHAR(length=255), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('api_key', sa.VARCHAR(length=255), autoincrement=False, nullable=True))
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')
        batch_op.drop_column('id')

    with op.batch_alter_table('user_ip_whitelist', schema=None) as batch_op:
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')

    with op.batch_alter_table('sports', schema=None) as batch_op:
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')

    with op.batch_alter_table('runners', schema=None) as batch_op:
        batch_op.add_column(sa.Column('total_matched', sa.DOUBLE_PRECISION(precision=53), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('removal_date', postgresql.TIMESTAMP(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('last_traded_price', sa.DOUBLE_PRECISION(precision=53), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('selection_id', sa.INTEGER(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('status', sa.VARCHAR(length=50), autoincrement=False, nullable=False))
        batch_op.add_column(sa.Column('adjustment_factor', sa.DOUBLE_PRECISION(precision=53), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('sort_priority', sa.INTEGER(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('handicap', sa.DOUBLE_PRECISION(precision=53), autoincrement=False, nullable=True))
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')

    with op.batch_alter_table('price_volume_data', schema=None) as batch_op:
        batch_op.add_column(sa.Column('price', sa.DOUBLE_PRECISION(precision=53), autoincrement=False, nullable=False))
        batch_op.add_column(sa.Column('volume', sa.DOUBLE_PRECISION(precision=53), autoincrement=False, nullable=False))
        batch_op.add_column(sa.Column('time_recorded', postgresql.TIMESTAMP(), autoincrement=False, nullable=False))
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')

    with op.batch_alter_table('markets', schema=None) as batch_op:
        batch_op.add_column(sa.Column('in_play', sa.BOOLEAN(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('cross_matching', sa.BOOLEAN(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('turn_in_play_enabled', sa.BOOLEAN(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('bsp_reconciled', sa.BOOLEAN(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('number_of_winners', sa.INTEGER(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('bet_delay', sa.INTEGER(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('complete', sa.BOOLEAN(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('version', sa.INTEGER(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('number_of_active_runners', sa.INTEGER(), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('runners_voidable', sa.BOOLEAN(), autoincrement=False, nullable=True))
        batch_op.alter_column('market_status',
               existing_type=sa.VARCHAR(length=50),
               nullable=False)
        batch_op.alter_column('market_time',
               existing_type=postgresql.TIMESTAMP(),
               nullable=False)
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')

    with op.batch_alter_table('market_changes', schema=None) as batch_op:
        batch_op.add_column(sa.Column('change_type', sa.VARCHAR(length=50), autoincrement=False, nullable=False))
        batch_op.add_column(sa.Column('published_time', postgresql.TIMESTAMP(), autoincrement=False, nullable=False))
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')

    with op.batch_alter_table('historical_data', schema=None) as batch_op:
        batch_op.add_column(sa.Column('data', sa.TEXT(), autoincrement=False, nullable=False))
        batch_op.add_column(sa.Column('captured_at', postgresql.TIMESTAMP(), autoincrement=False, nullable=False))
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')

    with op.batch_alter_table('events', schema=None) as batch_op:
        batch_op.alter_column('start_time',
               existing_type=postgresql.TIMESTAMP(),
               nullable=False)
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')

    with op.batch_alter_table('bets', schema=None) as batch_op:
        batch_op.add_column(sa.Column('price', sa.NUMERIC(precision=18, scale=2), autoincrement=False, nullable=False))
        batch_op.add_column(sa.Column('placed_at', postgresql.TIMESTAMP(), autoincrement=False, nullable=False))
        batch_op.add_column(sa.Column('outcome', sa.VARCHAR(length=50), autoincrement=False, nullable=True))
        batch_op.add_column(sa.Column('stake', sa.NUMERIC(precision=18, scale=2), autoincrement=False, nullable=False))
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')

    with op.batch_alter_table('betfair_api_usage', schema=None) as batch_op:
        batch_op.add_column(sa.Column('operation', sa.VARCHAR(length=255), autoincrement=False, nullable=False))
        batch_op.add_column(sa.Column('timestamp', postgresql.TIMESTAMP(), autoincrement=False, nullable=False))
        batch_op.add_column(sa.Column('api_key', sa.VARCHAR(length=255), autoincrement=False, nullable=True))
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')

    with op.batch_alter_table('additional_data', schema=None) as batch_op:
        batch_op.add_column(sa.Column('data_type', sa.VARCHAR(length=255), autoincrement=False, nullable=False))
        batch_op.add_column(sa.Column('value', sa.TEXT(), autoincrement=False, nullable=False))
        batch_op.drop_column('updated_at')
        batch_op.drop_column('created_at')

    op.drop_table('strategies')
    # ### end Alembic commands ###