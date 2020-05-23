import numpy as np

xx, yy= np.meshgrid(np.arange(0, 2, 0.2),np.arange(1, 3, 0.5))

print(xx,"\n\n",yy)

np.c_[xx.ravel(), yy.ravel()]

