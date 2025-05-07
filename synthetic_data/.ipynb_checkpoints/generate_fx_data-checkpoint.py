import numpy as np
import pandas as pd
import random
from datetime import datetime, timedelta
import os


def generate_synthetic_fx_data(num_records=1000):
    # parameters for FX options data
    spot_price_range = (1.05, 1.25)  # example EUR/USD range
    strike_price_range = (1.05, 1.30)  # example range
    volatility_range = (0.05, 0.25)  # volatility 5% to 25%
    interest_rate_range = (0.0, 0.05)  # risk free interest rate (annual)
    time_to_maturity_range = (1, 365)  # 1 to 365 days to maturity
    option_types = ['Call', 'Put']
    symbols = ['EUR/USD', 'USD/JPY', 'GBP/USD', 'AUD/USD', 'USD/CHF']

    # list to store the generated data
    data = []

    # generate synthetic records
    for _ in range(num_records):
        symbol = random.choice(symbols)
        spot_price = np.random.uniform(*spot_price_range)
        strike_price = np.random.uniform(*strike_price_range)
        volatility = np.random.uniform(*volatility_range)
        interest_rate = np.random.uniform(*interest_rate_range)
        time_to_maturity = np.random.randint(*time_to_maturity_range)
        option_type = random.choice(option_types)

        # generate a random expiry date (today + time_to_maturity days)
        expiry_date = datetime.now() + timedelta(days=time_to_maturity)

        # create a dictionary for the option data
        option_data = {
            'Symbol': symbol,
            'Spot Price': spot_price,
            'Strike Price': strike_price,
            'Volatility': volatility,
            'Interest Rate': interest_rate,
            'Time to Maturity (Days)': time_to_maturity,
            'Option Type': option_type,
            'Expiry Date': expiry_date.strftime('%Y-%m-%d')
        }
        
        data.append(option_data)

    # convert the data into a DataFrame
    df = pd.DataFrame(data)

    # save to CSV
    df.to_csv('/Users/thomasbradbury/Documents/FXCore/synthetic_data/data_samples/synthetic_fx_data.csv', index=False)
    print(f"Generated {num_records} synthetic FX options records.")

# sun the function to generate data
generate_synthetic_fx_data()