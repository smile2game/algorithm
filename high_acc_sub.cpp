#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
//这个最大的问题就是同位数大小，要从高位比起，即从i=0比起
// bool cmp(vector<int> &A,vector <int> &B)
// {
//     if (A.size() != B.size()) return A.size() > B.size();
//     for(int i=0; i<A.size(); i++)
//     {
//         if(A[i] != B[i]) return A[i]>B[i];
//     }
//     return true;
// }

bool cmp(vector<int>& A, vector<int> &B)
{
    if(A.size() != B.size()) return A.size() > B.size();  //直接ruturn 了就不用else

    for(int i = A.size(); i >= 0; i--)
        if(A[i] != B[i])
            return A[i] > B[i];

    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;

    for(int i=0,t=0;i<A.size();i++  )
    {
        t = A[i]-t;
        if(i<B.size()){t-=B[i];}
        C.push_back((t+10)%10);
        if(t<0){t=1;}
        else{t=0;}
    }
    while(C.size()>1 && C.back()==0) C.pop_back();
    return C;
}



int main()
{
    string a,b;
    vector<int> A,B;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) {A.push_back(a[i]-'0');}
    for(int i = b.size() -1;i >= 0; i--) {B.push_back(b[i]-'0');}

    if(cmp(A,B)) 
    {
        auto C = sub(A,B);
        for(int i=C.size()-1;i>=0;i--)
         {cout << C[i];}
    }
    else
    {
        auto C = sub(B,A);
        cout<<'-';
        for(int i=C.size()-1;i>=0;i--) 
        {cout << C[i];}
    }
    return 0;
    // cout << C.size() <<'\n';
    
}


