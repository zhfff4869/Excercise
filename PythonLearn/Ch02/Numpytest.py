import numpy as np

# print(np.full(shape=(3,5),fill_value=666.0))
# print(np.arange(0,1.1,0.2))
# # print(np.random.randn(2,10))
# print(np.random.normal(2,10,size=(2,3)))
R = np.array([[0, 1, np.inf, 4.5, 5], [1, 0, 3, np.inf, 2], [
            np.inf, 3, 0, 10, 4], [4.5, np.inf, 10, 0, 2.5], [5, 2, 4, 2.5, 0]]) 

print(R.shape)