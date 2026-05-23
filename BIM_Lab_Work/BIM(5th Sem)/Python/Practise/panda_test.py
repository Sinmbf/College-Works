import pandas as pd
import numpy as np

data = {
    "Name": ["John", "Alice", None, "Bob"],
    "Age": [20, None, 22, 21]
}

df = pd.DataFrame(data)

print(df.head())
print(df.tail())

# Identify missing values
print(df.isna())