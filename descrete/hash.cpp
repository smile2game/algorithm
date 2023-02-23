#include <vector>
#include <iostream>
#include <algorithm>
using   namespace std;  

vector<int> a;
//去重
vector<int> set_unique(vector<int> &a)
{
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
}
//二分找到对应离散index
int find(int x)
{
    int l = 0,r=a.size()-1;
    while(l<r)
    {
        int mid = l+r>>1;
        if(a[mid]>=2) r= mid;
        else l = mid+1;
    }
    return r+1; //映射到1，2，3
}

int main()
{

}