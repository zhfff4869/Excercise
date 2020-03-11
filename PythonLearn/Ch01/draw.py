import matplotlib.pyplot as plt
import numpy as np

if __name__ == "__main__":
    x=np.linspace(-1,1,50)
    y=2*x+1

    plt.figure()
    plt.plot(x,y)
    plt.show()

