#include <iostream>
#include <cstdio>

using namespace std;

const int Size=1e5+5;

bool flag[Size]={0};
int n,que[Size];

struct node
{
    int son,bro,data;
}tree[Size];

void pre(int root)
{
    printf("%d ",tree[root].data);
    if (tree[root].son>0)
        pre(tree[root].son);
    if (tree[root].bro>0)
        pre(tree[root].bro);
}

void post(int root)
{
    if (tree[root].son>0)
        post(tree[root].son);
    printf("%d ",tree[root].data);
    if (tree[root].bro>0)
        post(tree[root].bro);
}

void layorder(int root,int n)
{
    int head=-1,rear=0;

    que[0]=root;
    while (head!=n-1)
    {
        head+=1;
        printf("%d ",tree[que[head]].data);

        int tmp=tree[que[head]].son;
        while (tmp>0)
        {
            que[++rear]=tmp;
            tmp=tree[tmp].bro;
        }
    }
}
int main()
{
    int i,s,b,d;
    cin>>n;

    for (i=1; i<=n; ++i)
    {
        cin>>s>>b>>d;
        tree[i].son=s;
        tree[i].bro=b;
        tree[i].data=d;
        flag[s]=1;
        flag[b]=1;
    }
    for (i=1; i<=n; ++i)
    {
        if (!flag[i])
            break;
    }

    int root=i;
    pre(root);
    cout<<'\n';
    post(root);
    cout<<'\n';
    layorder(root,n);
    return 0;
}
