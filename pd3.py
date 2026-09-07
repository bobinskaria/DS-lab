import pandas as pd


data = {
    "Name": ["Anu", "Rahul", "Meera"],
    "Age": [20, 21, 19],
    "City": ["Kochi", "Thrissur", "Calicut"]
}


df = pd.DataFrame(data)

print("DataFrame:")
print(df)