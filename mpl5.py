import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(0,10, 100)
y1 = np.sin(x)
y2 = np.cos(x)
y3 = x**2
y4 = np.random.randn(100)
fig,axs = plt.subplots(2,2,figsize=(10,8))
fig.suptitle('Multiple Plots Example',fontsize=16)
axs[0,0].plot(x,y1,color='blue')
axs[0,0].plot(x,y2)
plt.show()