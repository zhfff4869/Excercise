import random

all=[i+1 for i in range(12)]

group1=random.sample(all,6)

for i in group1:
    all.remove(i)

for i,j in zip(all,group1):
    print(i," VS ",j)
