#include <iostream>
using namespace std;
const int N=1e6+10;
void search(int &n,int &k)
{
     for(int t =k;t>=0;t--) cout << (n>>t&1);
}

int lowbit(int x)
{
    return x& -x;
}
//n>>k&1
int main()
{
    int n;
    cin >> n;
    for(int i=31;i>=0;i--) //目前操作系统中的int是32位
    {
        cout << (n >> i & 1);
    }
    
    return  0;  
}