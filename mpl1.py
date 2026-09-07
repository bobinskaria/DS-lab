import matplotlib.pyplot as plt


x = [1, 2, 6, 18]
y = [3, 10, 12, 20]


plt.plot(x, y, marker='o')


plt.title("Line Diagram")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")


plt.grid(True)
plt.show()