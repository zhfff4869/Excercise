import numpy as np
inf=np.inf
class Floyd():
    W=np.array([
        [0,0.5,2,1.5,inf,inf,inf],
        [0.5,0,inf,inf,1.2,9.2,inf],
        [2,inf,0,inf,5,inf,3.1],
        [1.5,inf,inf,0,inf,inf,4],
        [inf,1.2,5,inf,0,6.7,inf],
        [inf,9.2,inf,inf,6.7,0,15.6],
        [inf,inf,3.1,4,inf,15.6,0],
        ])

    R=np.array([
        [0,2,3,4,0,0,0],
        [1,0,0,0,5,6,0],
        [1,0,0,0,5,0,7],
        [1,0,0,0,0,0,7],
        [0,2,3,0,0,6,0],
        [0,2,0,0,5,0,7],
        [0,0,3,4,0,6,0],
    ])

    def Fprocess(self):
        size=len(self.W[0])
        for i in range(size): #迭代7次

            for j in range(size):
                if j is i:
                    continue
                for k in range(j,size):
                    if k is i:
                        continue
                    if self.W[j,k]>self.W[i,k]+self.W[j,i]:    #if j+1 to k+1 via i+1 node is shorter
                        self.W[j,k]=float('%.2f'%(self.W[i,k]+self.W[j,i]))
                        self.W[k,j]=float('%.2f'%(self.W[i,k]+self.W[j,i]))

                        # self.W[j][k]=(self.W[i][k]+self.W[j][i])
                        # self.W[k][j]=(self.W[i][k]+self.W[j][i])

                        self.R[j,k]=i+1
                        self.R[k,j]=i+1
            
            print("W"+str(i+1)+":")
            for iter in self.W:
                # np.set_printoptions(precision=3)
                print(iter)

            print("R"+str(i+1)+":")
            for iter in self.R:
                # np.set_printoptions(precision=3)
                print(iter)
            print()


    def showminroad(self,x,y):
        weight=self.W[x-1,y-1]
        road=[x]
        temp=y
        while(self.R[x-1,temp-1]!=temp):
            road.insert(1,self.R[x-1,temp-1])
            temp=self.R[x-1,temp-1]
        road.append(y)
        print("road(",x," to ",y,"):",road,"\t--weight:",weight)

    def showcenter(self):
        temp1=np.amax(self.W,axis=1)
        i=np.argmin(temp1)
        # W_tri=np.triu(self.W)
        # where=np.argwhere(W_tri==temp2)
        print(
            "The center node is v",i+1,
        )

    def showmiddle(self):
        temp1=np.sum(self.W,axis=1)
        i=np.argmin(temp1)
        print(
            "The middle node is v",i+1,
        )


if __name__ == "__main__":
    floyd=Floyd()
    floyd.Fprocess()
    floyd.showminroad(1,6)
    floyd.showcenter()
    floyd.showmiddle()
    