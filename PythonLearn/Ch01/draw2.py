import matplotlib.pyplot as plt
import numpy as np

good=input()
good=float(good)
x=np.linspace(0.0001,1,50)

temp=good*0.3/x #good vary

y=0.5*np.tanh(2*(temp-0.5))+0.5 #good normalization

plt.figure(figsize=(8,5),)
plt.plot(x,y)
plt.show()