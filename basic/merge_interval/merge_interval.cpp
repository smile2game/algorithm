#include <iostream>
#include <vector>
#include <algorithm>
using   namespace std; 
typedef pair<int, int> PII;
vector<PII> segs;
vector<PII> res;
const int N = 1e6+10;
int n,l,r;

vector<PII> merge_interval(vector<PII> segs)
{
    vector<PII> res;
    int st,ed = -2e9+10;
    sort(segs.begin(),segs.end());

    for(auto seg : segs)
    {   
        if(seg.first>ed)
        {
            if(ed != -2e9+10) res.push_back({st,ed}); //大于且不是初始，添加
            st = seg.first,ed = seg.second; //更新维护区间
        }
        else ed =  max(ed,seg.second);   //小于，则更新右端点，不需要添加
    }
    if(st!=-2e9+10) res.push_back({st,ed}); //添加上更新的区间，小于的情况，且不是初始

    return res;

}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >>l>>r;
        segs.push_back({l,r});
    }
    res = merge_interval(segs);
    cout << res.size();
    return 0;
}