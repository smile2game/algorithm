#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N],S[N];
int n,m,l,r;

int main()
{

    cin >> n>> m;
    for(int i=1;i<=n;i++)    {cin >> a[i];}
    S[0] = 0;
    for(int i=1;i<=n;i++)    {S[i]=S[i-1]+a[i];}
    while(m--)
    {
        cin >> l >>r;
        cout << (S[r]-S[l-1]) <<endl;
    }
    return 0;
}