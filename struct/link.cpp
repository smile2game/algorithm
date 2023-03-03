#include <iostream>
using   namespace std;  
const int N = 1e6+10;
//head表示头节点下标，idx存储目前在用数组中哪个元素
//new 主要是动态链表的速度很慢
int head,ne[N],e[N],idx;

void init()
{
    head = -1;
    idx = 0;
}

void add_to_head(int x)
{   
    ne[idx] = head;
    head = idx;
    e[idx]  = x;
    idx++;
}
//插到第k个后面
void add(int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++ ;
}
//删掉第K个后面的,直接掠过
void dele(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    init();
    int m;
    cin >> m;
    while (m--)
    {
        int k,x;
        char op;
        cin >> op;
        if(op == 'H') 
            { cin >> x;
            add_to_head(x);}
        else if(op == 'I') 
            {cin >>k >>x;
             add(k-1,x);}
        else if(op=='D')    
            {cin >> k;
            dele(k-1);}
     }
     for(int i = head;i!=-1;i = ne[i]) cout << e[i] <<' ';
     return 0;
}