import numpy as np
inf=np.inf
W=np.array([
    [0,0.5,2,1.5,inf,inf,inf],
    [0.5,0,inf,inf,1.2,9.2,inf],
    [2,inf,0,inf,5,inf,3.1],
    [1.5,inf,inf,0,inf,inf,4],
    [inf,1.2,5,inf,0,6.7,inf],
    [inf,9.2,inf,inf,6.7,0,15.6],
    [inf,inf,3.1,4,inf,15.6,0]
    ])

print(W.ndim)
print(W[3,2])
print("W"+str(1)+":\n")
for iter in W:
    print(iter)
