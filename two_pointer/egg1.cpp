#include <iostream>
#include <string.h>
using namespace std;
const int N  =1010;
//可以用来优化
int main()
{
    char str[N];
    fgets(str,N,stdin);
    int n = strlen(str);
    for(int i = 0; i < n; i++)
    {
        int j=i;
        while(j<n&&str[j]!=' ') j++;
        for(int k=i;k<j;k++) cout << str[k];
        cout << endl;
        i=j;
    }
    return 0;
}