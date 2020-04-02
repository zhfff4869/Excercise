# pylint: disable=no-member
# 因为pylint是静态检查，而np.random 是动态创建，所以会出现误报，加上上面这句注释就好了

import numpy as np

def sigmoid(x):
    return 1/(1+np.exp(-x))

def sigmoid_derivative(x):
    return x*(1-x)

training_inputs= np.array([ [0,0,1],
                            [1,1,1],
                            [1,0,1],
                            [0,1,1]])

training_outputs=np.array([[0,1,1,0]]).T

np.random.seed(1)

synaptic_weights=2*np.random.random((3,1)) -1

print('Random starting sysnaptic weights:')
print(synaptic_weights)

for iteration in range(100000):
    input_layer = training_inputs

    outputs=sigmoid(np.dot(input_layer,synaptic_weights))

    error =training_outputs -outputs

    adjustments = error*sigmoid_derivative(outputs)

    synaptic_weights +=np.dot(input_layer.T,adjustments)

print('Synaptic weights after training:')
print(synaptic_weights)
print('Outputs after training:')
print(outputs)