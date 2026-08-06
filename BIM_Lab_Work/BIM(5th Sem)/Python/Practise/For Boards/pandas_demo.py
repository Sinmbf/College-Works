import numpy as np
import pandas as pd
array = np.array([
    ['Alice', 25, 'New York'],
    ['Bob', 30, 'Los Angeles'],
    ['Charlie', 35, 'Chicago']
])
df = pd.DataFrame(array, columns=['Name', 'Age', 'City'])
# print(df)

print(df.loc[0])