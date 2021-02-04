#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 20010
int n,A,B,C;
struct link
{
    int y,z;
    link *next;
};
link *head[MAXN];
int dist[5][MAXN];
int q[1000000];
int h=0,rear=0;
void insert(int x,int y,int z)
{
    link *node = new link;
    node->y=y;
    node->z=z;
    node->next=head[x];
    head[x]=node;
}
int pop()
{
    h++;
    return q[h-1];
}
void enque(int x)
{
    q[rear++]=x;
}
void init()
{
    scanf("%d%d%d%d",&n,&A,&B,&C);
    int x,y,z;
    for(int i=1; i<n; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        insert(x,y,z);
        insert(y,x,z);
    }
}
void spfa(int xxx,int std)
{
    dist[xxx][std]=0;
    enque(std);
    while(h!=rear)
    {
        int x=pop();
        link *node=head[x];
        while(node)
        {
            int y=node->y,z=node->z;
            if(dist[xxx][y]>dist[xxx][x]+z)
            {
                dist[xxx][y]=dist[xxx][x]+z;
                enque(y);
            }
            node=node->next;
        }
    }
}
void work()
{
    for (int i=0; i<=4; ++i)
        for (int j=0; j<=n; ++j)
            dist[i][j]=1000000;
    spfa(1,A);
    spfa(2,B);
    spfa(3,C);
    int ans=0x07070707,k=0;
    for(int i=1; i<=n; i++)
        if(ans>dist[1][i]+dist[2][i]+dist[3][i])
        {
            ans=dist[1][i]+dist[2][i]+dist[3][i];
            k=i;
        }
    if(ans==0x07070707)
        printf("-1");
    else
        printf("%d\n%d",k,ans);
}
int main()
{
    init();
    work();
    return 0;
}
