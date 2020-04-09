import numpy as np
INF=np.inf
R=np.array([[0,8,4,2,INF],
            [8,0,3,INF,INF],
            [4,3,0,1,3],
            [2,INF,1,0,3],
            [INF,INF,3,3,0]])   #图的矩阵表示

W=np.array(5)

def dijkstra(R,s):
    base="v"+str(s)  #置定
    Processroad=[base]  #运行路径
    minroad={'v'+str(i):[] for i in range(R[0].size)}  #最短路径
    Gp={"v"+str(i):None for i in range(R[s,:].size)}   #已覆盖点
    Gp[base]=[s,0,'']
    G={"v"+str(i):[i,INF,''] for i in range(R[s,:].size) if i is not s}    #未覆盖点
    while len(G) > 0:   #若还有未覆盖点存在
        update(Gp,G,R,Processroad) #更新参数

    #追踪最短路径
    it=['v'+str(i) for i in range(len(minroad))]
    for iter in it:
        Routetrace(Gp,iter,minroad[iter])
    print("\n",minroad)

def update(Gp,G,R,Processroad):
    base=Processroad[-1]    #当前置定

    baseValue=Gp[base][1]
    for key in G:  #更新标值
        currentValue=G[key][1]
        d=R[Gp[base][0]][G[key][0]]
        G[key][1]=min(currentValue,baseValue+d)
        if G[key][1]!=currentValue:
            G[key][2]=base
    #更新运行路径
    minvalue=INF
    minnode=''
    for iter in G:
        if G[iter][1]<minvalue:
            minvalue=G[iter][1]
            minindex=G[iter][0]
            minnode=iter
    Processroad.append(minnode)
    #更新Gp,G
    Gp[minnode]=G[minnode]
    G.pop(minnode)
    print(Processroad)
    print(Gp)

def Routetrace(Gp,node,minroad):
    if(Gp[node][2]==''):
        minroad.append(node)
        minroad.reverse()
        return

    minroad.append(node)
    node=Gp[node][2]
    Routetrace(Gp,node,minroad)


if __name__ == "__main__":
    dijkstra(R,0)