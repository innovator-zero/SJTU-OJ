#include <iostream>
#include <cstdio>
using namespace std;
int n;
bool record[500007];
int depth[500007];
int anc[500007][22];
struct edge
{
    int des;
    edge *next;
};
edge *head[500007];
void Add(int s,int d)
{
    edge *tmp=new edge;
    tmp->des=d;
    tmp->next=head[s];
    head[s]=tmp;
}
void dfs(int p)
{
    edge *tmp=head[p];
    while (tmp)
    {
        int t=tmp->des;
        if (!record[t])
        {
            anc[t][0]=p;
            for (int i=1; i<=20; ++i)
            {
                anc[t][i]=anc[anc[t][i-1]][i-1];
            }
            record[t]=true;
            depth[t]=depth[p]+1;
            dfs(t);
        }
        tmp=tmp->next;
    }
}
int query(int x,int y)
{
    if (depth[x]<depth[y])
    {
        int t=x;
        x=y;
        y=t;
    }
    for (int i=20; i>=0; --i)
    {
        if (depth[y]<=depth[anc[x][i]])
        {
            x=anc[x][i];
        }
    }
    if (x==y)
        return x;
    for (int i=20; i>=0; --i)
    {
        if (anc[x][i]!=anc[y][i])
        {
            x=anc[x][i];
            y=anc[y][i];
        }
    }
    return anc[x][0];
}
int main()
{
    int q,root=1;
    scanf("%d",&n);
    int i;
    for (i=1; i<n; ++i)
    {
        int s,d;
        scanf("%d%d",&s,&d);
        Add(s,d);
        Add(d,s);
    }
    depth[root]=1;
    record[root]=true;
    dfs(root);
    scanf("%d",&q);
    for (i=0; i<q; ++i)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        int a=query(u,v);
        int b=query(u,w);
        int c=query(v,w);
        if (depth[a]<depth[b])
        {
            if (depth[b]<depth[c])
                printf("%d\n",c);
            else
                printf("%d\n",b);
        }
        else
        {
            if (depth[c]<depth[a])
                printf("%d\n",a);
            else
                printf("%d\n",c);
        }
    }
    return 0;
}
