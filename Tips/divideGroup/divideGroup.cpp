#include <iostream>
#include<random>
#include<time.h>
#include <vector>

using namespace std;

class Group
{
public:
    Group()
    {
        for (int i = 0; i < count; i++)
        {
            group.push_back(i + 1);
        }
    }
    int size()
    {
        return group.size();
    }
    void selectCouple();

private:
    vector<int> group;
    int count = 12;
};

void Group::selectCouple()
{

    int p,q,A,B;
    p=rand()%group.size();
    A=group.at(p);
    group.erase(group.begin()+p);
    q=rand()%group.size();
    B=group.at(q);
    group.erase(group.begin()+q);
    cout<<A<<" VS "<<B<<endl;
}

int main()
{
    Group G;
    srand(time(0));
    while (G.size())
    {
        G.selectCouple();
    }
    system("pause");
    return 0;
}