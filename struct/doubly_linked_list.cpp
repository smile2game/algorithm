#include <iostream>
using   namespace std;  
const int N = 1e6+10;
//idx = 0为head，idx = 1为tail
//new 主要是动态链表的速度很慢
int e[N],l[N],r[N],idx;

void init()
{
    r[0] = 1,l[1] = 0;
    idx = 2;
}
//在下标为k的右边插入
void add(int k,int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k; //只要先把被接入节点接好了，就不用担心了
    l[r[idx]] = idx;
    r[l[idx]] = idx;
    idx ++;
}

//删除第k个点
void remove(int k)
{
     r[l[k]] = r[k];
     l[r[k]] = l[k];
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
            if(!k) head = head[ne]; //删除头节点和删除普通节点不同
            dele(k-1);}
     }
     for(int i = head;i!=-1;i = ne[i]) cout << e[i] <<' ';
     return 0;
}