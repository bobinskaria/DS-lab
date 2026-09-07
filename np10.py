import numpy as np
a = np.random.randint(15,25,(4,4))
print("original Array")
print(a)
a[[0,3]] = a[[3+,0]]
print("After Swapping")
print(a)