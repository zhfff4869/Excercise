import numpy as np
import copy


class Kruskal():

    # R = np.array([[0, 1, np.inf, 4.5, 5], [1, 0, 3, np.inf, 2], [
    #             np.inf, 3, 0, 10, 4], [4.5, np.inf, 10, 0, 2.5], [5, 2, 4, 2.5, 0]])    #relationship
    R = np.array([[0, 2, 3, 7, np.inf, np.inf, np.inf], [2, 0, 9, 8, 4, 5, np.inf], [
        3, 9, 0, 10, 12, np.inf, np.inf], [7, 8, 10, 0, 7, 6, 11], [np.inf, 4, 12, 7, 0, 4, 6], [np.inf, 5, np.inf, 6, 4, 0, 5], [np.inf, np.inf, np.inf, 11, 6, 5, 0]])  # relationship

    C = np.zeros(R.shape)  # main tree construct
    Edges = []

    def isvalid(self, C_tmp):
        # return True
        for _ in range(len(C_tmp[0])):
            try:
                C_csum = np.dot(C_tmp, np.ones(len(C_tmp[0, :])))
            except:
                print('error')
            V = []
            for i in range(len(C_csum)):
                V.append([i, C_csum[i]])
            delete = []
            for iter in V:
                if iter[1] <= 1:
                    delete.append(iter[0])

            try:
                C_tmp = np.delete(C_tmp, delete, axis=0)
            except:
                print("empty!")
            try:
                C_tmp = np.delete(C_tmp, delete, axis=1)
            except:
                print("empty!")

            if(C_tmp.size == 0):
                break
        if(C_tmp.size == 0):

            return True
        else:

            return False

    def getEdges(self):
        S = copy.deepcopy(self.R)
        S_triu = np.triu(S)
        S = S_triu.flatten()
        S = S[S != 0]
        S = S[S != np.inf]
        S.sort()
        S=np.unique(S)
        for iter in S:
            where=np.argwhere(S_triu == iter)
            # length=int(len(where)/2)
            # where=np.reshape(where,(length,2))
            for edge in where:
                self.Edges.append(['v',edge,iter])
        # self.Edges = [['v', list(np.where(self.R == i)[0]), i] for i in S]

        print(self.Edges)

    def constructToC(self):
        while len(np.triu(self.C)[np.triu(self.C) == 1]) < len(self.R[0, :])-1:
            C_tmp = copy.deepcopy(self.C)
            Edges_tmp = copy.deepcopy(self.Edges)
            minEdge = Edges_tmp[0]
            C_tmp[minEdge[1][0], minEdge[1][1]] = 1
            C_tmp[minEdge[1][1], minEdge[1][0]] = 1
            Edges_tmp.remove(Edges_tmp[0])
            if self.isvalid(C_tmp):
                self.C = C_tmp
            self.Edges = Edges_tmp


if __name__ == "__main__":
    K = Kruskal()
    K.getEdges()
    K.constructToC()
    print(K.C)
