import pandas as pd
import numpy as np
from scipy.stats import norm
import matplotlib.pyplot as plt

def black_scholes_fx(S, K, T, r_d, r_f, sigma, option_type='call'):
    d1 = (np.log(S / K) + (r_d - r_f + 0.5 * sigma ** 2) * T) / (sigma * np.sqrt(T))
    d2 = d1 - sigma * np.sqrt(T)

    if option_type == 'call':
        return S * np.exp(-r_f * T) * norm.cdf(d1) - K * np.exp(-r_d * T) * norm.cdf(d2)
    else:
        return K * np.exp(-r_d * T) * norm.cdf(-d2) - S * np.exp(-r_f * T) * norm.cdf(-d1)

# Load the synthetic FX options data
data = pd.read_csv("/Users/thomasbradbury/Documents/FXCore/synthetic_data/data_samples/synthetic_fx_data.csv")

# Prepare data and rename columns for consistency
data = data.rename(columns={
    'Symbols': 'Symbol',
    'Spot Price': 'Spot',
    'Strike Price': 'Strike',
    'Volatility': 'Volatility',
    'Interest Rate': 'DomesticRate',
    'Time to Maturity (Days)': 'TimeToMaturity',
    'Option Type': 'OptionType'
})

# Assume foreign rate (r_f) = 0 for now
data['ForeignRate'] = 0.0

# Convert days to maturity into years
data['TimeToExpiry'] = data['TimeToMaturity'] / 365

# Calculate option price
data['Price'] = data.apply(lambda row: black_scholes_fx(
    S=row['Spot'],
    K=row['Strike'],
    T=row['TimeToExpiry'],
    r_d=row['DomesticRate'],
    r_f=row['ForeignRate'],
    sigma=row['Volatility'],
    option_type=row['OptionType'].lower()
), axis=1)

# Display sample results
print(data[['Symbol', 'Spot', 'Strike', 'OptionType', 'Volatility', 'TimeToExpiry', 'Price']].head())

# Plot
plt.figure(figsize=(10, 5))

symbols = data['Symbol'].unique()
for symbol in symbols:
    subset = data[data['Symbol'] == symbol]
    plt.scatter(subset['Strike'], subset['Price'], label=symbol, alpha=0.6)

plt.scatter(data['Strike'], data['Price'], alpha=0.6, label='Option Prices')
plt.xlabel('Strike Price')
plt.ylabel('Option Price')
plt.title('FX Option Prices vs Strike')
plt.grid(True)
plt.legend()
plt.show()