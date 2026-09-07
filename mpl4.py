import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(0,10, 100)
y1 = np.sin(x)
y2 = np.cos(x)
y3 = 0.5 * x
plt.figure(figsize=(8,5))
plt.plot(x,y1,label = 'sin(x)',color = 'blue',linestyle = '-',linewidth = 2)
plt.plot(x,y2,label = 'cos(x)',color = 'red',linestyle = '--',linewidth = 2)
plt.plot(x,y3,label = '0.5*x',color = 'green',linestyle = ':',linewidth = 2)
plt.xlabel('X axis')
plt.ylabel('Y axis')
plt.title('Multiple lines on same plot')
plt.legend()
plt.grid(True)
plt.show()