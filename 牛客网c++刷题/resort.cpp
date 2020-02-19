#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isodd(int n)
    {
        if (n % 2 == 1)
            return true;
        else
            return false;
    }

    void reOrderArray(vector<int> &array)
    {
        while (1)
        {
            auto cur = array.begin();
            while (isodd(*cur))
            {
                cur++;
            }
            auto next = cur + 1;
            while (!isodd(*next))
            {
                next++;
            }
            if (next == array.end())
                return;
            swap(*cur, *next);
        }
    }
};

int main()
{
    vector<int> array{4,8,2,1,3,7,9,25,10};
    Solution S;
    S.reOrderArray(array);
    for(auto i:array)
     cout<<i<<' ';
}