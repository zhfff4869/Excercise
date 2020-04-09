import numpy as np
import random

#prim 是非NP问题，因为其复杂度是多项式级别的，对于多项式级别不能实现的问题称为NP问题，计算机对此种问题无法承受，只能求近似解

class Prim:
    def update(self):
        self.G1.add(self.point)
        self.G.difference_update(self.G1)
        self.C[self.pointAtR[0]][self.pointAtR[1]]=1
        self.C[self.pointAtR[1]][self.pointAtR[0]]=1
        self.length+=self.d
        self.d=np.inf

    def randomBegin(self):
        Glist = list(self.G)
        rand = random.sample(Glist, 1)[0]
        self.G1.add(rand)
        # self.G.remove(rand)
        self.G.difference_update(self.G1)

    def findNewPoint(self):
        for base in self.G1:
            for des in self.G:
                if self.R[base[1]][des[1]] < self.d:
                    self.d = self.R[base[1]][des[1]]
                    self.point = des
                    self.pointAtR = (base[1], des[1])

    length=0    # length in main tree
    d = np.inf  # min point value
    point = []  # min point
    pointAtR = (-1, -1)  # min point address
    C = np.zeros((5, 5))    #main tree construct
    G = set(("v"+str(i+1), i) for i in range(5))  #unseen graph
    G1 = set()  #seen graph
    R = np.array([[0, 1, np.inf, 4.5, 5], [1, 0, 3, np.inf, 2], [
                np.inf, 3, 0, 10, 4], [4.5, np.inf, 10, 0, 2.5], [5, 2, 4, 2.5, 0]])    #relationship


if __name__ == "__main__":
    prim=Prim()
    prim.randomBegin()
    for i in range(4):
        prim.findNewPoint()
        prim.update()
    print(prim.G1)
    print(prim.length)
    print(prim.C)




