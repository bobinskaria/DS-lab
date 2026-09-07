import matplotlib.pyplot as plt
temperature = [12,14,16,18,20,22,24]
sales = [100,200,250,400,300,450,500]
plt.figure(figsize=(10,5))
plt.plot(temperature,sales,marker='*',linestyle='--',color='green')
plt.xlabel("Temperature")
plt.ylabel("Sales")
plt.title("Temperature vs Sales")
plt.grid(True)
plt.show()