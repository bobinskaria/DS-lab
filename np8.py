import numpy as np
a = np.array([10,20,30,40,50])
np.savetxt("array.txt",a)
b = np.loadtxt("array.txt")
print(b)