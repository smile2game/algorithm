#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 10;

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for(int i=0;i<A.size()||t;i++)
    {
        if(i<A.size())t += A[i]*b;
        // t += A[i]*b; 如果没有前置条件就会越界，并且未知A[越界]
        C.push_back(t%10);
        t /= 10;
    }
    while(C.size()>1 && C.back()==0) {C.pop_back();}
    return C;
}


int main()
{
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) {A.push_back(a[i]-'0');}
    auto C = mul(A,b);
    // cout << C.size() <<'\n';
    for(int i=C.size()-1;i>=0;i--) {cout << C[i];}
    return 0;
}