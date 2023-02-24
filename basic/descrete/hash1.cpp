#include <vector>
#include <iostream>
#include <algorithm>
using   namespace std;  
const int N = 3e5+10;
typedef pair<int,int> PII;

int a[N],s[N];
//题目是区间和
vector<int> alls;
vector<PII> add,query;
//去重
void set_unique(vector<int> &a)
{
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
}

//二分找到对应离散index
int find(int x)
{
    int l = 0,r=alls.size()-1;
    while(l<r)
    {
        int mid = l+r>>1;
        if(alls[mid]>=x) r= mid;
        else l = mid+1;
    }
    return r+1; //映射到1，2，3
}

int main()
{
    int n,m,x,c,l,r;
    cin >>n>>m;
    for(int i=0;i<n;i++)
    {
        cin >>x >> c;
        add.push_back({x,c});
        alls.push_back(x);
    }

    for(int i=0;i<m;i++)
    {
        cin >>l >> r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    for(auto item : add) //遍历add实现映射操作
    {
        int x  = find(item.first); 
        a[x] += item.second;
    }
    for(int i=1;i<=alls.size();i++) s[i] = s[i-1] + a[i]; 
    
    for(auto item:query)
    {
        int l  = find(item.first),r = find(item.second);
        cout << (s[r] - s[l-1]) << endl;
    }
    return 0;
}