#include <iostream>
#include <string.h>
using namespace std;
const int N  =100010;
int a[N],s[N];
int n; 
//可以用来优化O[n]
//暴力朴素做法是双循环O[n2]

int main()
{
    cin >> n;
    for(int i = 0; i <n;i++) cin >> a[i];
    int res = 0;
    for(int i = 0,j=0; i < n; i++)
    {
        s[a[i]]++;
        while(s[a[i]]>1) 
        {
            s[a[j]]--;
            j++;
        }
        
       res = max(res,i-j+1);
    }
    cout << res <<endl;
    return 0;
}