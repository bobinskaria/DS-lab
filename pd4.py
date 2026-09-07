
import pandas as pd


data = [
    [101, "Anu", 20],
    [102, "Rahul", 21],
    [103, "Meera", 19]
]


df = pd.DataFrame(data, columns=["Roll No", "Name", "Age"])
print("DataFrame:")
print(df)