#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e6+7;
int n,m;
long long dist[maxn];
struct edge
{
    int des;
    int w;
    edge *next;
};
edge *head[maxn];
int q[1000000];
int h=0,r=0;
void enque(int x)
{
    if (dist[x]<dist[q[h]])
    {
        q[r]=q[h];
        q[h]=x;
    }
    else
        q[r]=x;
    ++r;
    r%=1000000;
}
int deq()
{
    int tmp=h;
    ++h;
    h%=1000000;
    return q[tmp];
}
void spfa()
{
    enque(1);
    dist[1]=0;
    while (h!=r)
    {
        int tmp=deq();
        edge *p=head[tmp];
        while (p)
        {
            if (dist[p->des]>dist[tmp]+p->w)
            {
                dist[p->des]=dist[tmp]+p->w;
                enque(p->des);
            }
            p=p->next;
        }
    }
    cout<<dist[n];
}
void Add(int s,int e,int v)
{
    edge *tmp;
    tmp=new edge;
    tmp->des=e;
    tmp->w=v;
    tmp->next=head[s];
    head[s]=tmp;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int i,s,e,v;
    for (i=0; i<m; ++i)
    {
        cin>>s>>e>>v;
        Add(s,e,v);
        Add(e,s,v);
    }
    for (i=1; i<=n; ++i)
        dist[i]=1000000007;
    spfa();
    return 0;
}
