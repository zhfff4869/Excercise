#include <iostream>
#include <vector>
#include <random>
#include<time.h>
using namespace std;


void randomsort(vector<int> &A)
{

    for (int i = A.size() - 1; i >= 1; --i)
    {
        
        swap(A[i], A[rand() % i]);
    }
}

int main()
{
    srand(time(NULL));
    vector<int> a{1, 2, 3, 4, 5, 6}, b{7, 8, 9, 10, 11, 12};
    randomsort(a);
    randomsort(b);
    for (int i=0;i<a.size();i++)
        cout<<a[i]<<" vs "<<b[i]<<endl;
    system("pause");
    return 0;
}
