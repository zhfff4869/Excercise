#include<iostream>
using namespace std;

class Solution {
    public:
     int NumberOf1(int n) {
        int m=0;
        while(n!=0){
           n=n&(n-1);   //for example,1100 have 2 '1',1100-1=1011,1100&1011=1000,then drop the last '1';
            m=m+1;  //actually,each loop change a '1' to '0',1100 make 2 loops,m will be 2
        }   //对于负数，其补码也是一个循环减少掉最后一个1
        return m ;
    }
};

int main()
{
    int a=-12;
    Solution S;
    cout<<S.NumberOf1(a)<<endl;

}