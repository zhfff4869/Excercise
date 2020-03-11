#include <iostream>
#include<random>
#include <random>
#include <iterator>
#include <vector>
#include<algorithm>
#include <ctime>
using namespace std;
//Cpp Standard: C++14,之后的版本random_shuffle被取消了

int main()
{
    srand(time(nullptr)); // 以当前时间为随机生成器的种子
    //default_random_engine rd;
    vector<int> A = {1, 2, 3, 4, 5, 6},B={7,8,9,10,11,12};
    random_shuffle(A.begin(), A.end());
    random_shuffle(B.begin(), B.end());
    for(int i=0;i<6;i++)
    {
        cout<<A[i]<<" VS "<<B[i]<<endl;
    }
    system("pause");
    return 0;
}