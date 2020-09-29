#include <iostream>
#include <cstdio>

using namespace std;

struct point
{
    int x,y;
};

class seqqueue
{
private:
    point *elem;
    int maxsize;
    int front,rear;
    void doublespace();

public:
    seqqueue(int size=10);
    ~seqqueue();
    bool isempty() const;
    void enqueue(const point &x);
    point dequeue();
};
seqqueue::seqqueue(int size)
{
    elem=new point[size];
    maxsize=size;
    front=rear=0;
}
seqqueue::~seqqueue()
{
    delete []elem;
}

bool seqqueue::isempty()const
{
    return front==rear;
}

void seqqueue::enqueue(const point &x)
{
    if((rear+1)%maxsize==front)
        doublespace();
    rear=(rear+1)%maxsize;
    elem[rear]=x;
}

point seqqueue::dequeue()
{
    front=(front+1)%maxsize;
    return elem[front];
}

void seqqueue::doublespace()
{
    point *tmp=elem;
    elem=new point[2*maxsize];
    for(int i=1; i<=maxsize; ++i)
        elem[i]=tmp[(front+i)%maxsize];
    front=0;
    rear=maxsize;
    maxsize*=2;
    delete tmp;
}
int n,m;
int a[505][505];

void bfs(int,int);

int main()
{
    int i,j,k=0;
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(a[i][j]==0)
            {
                a[i][j]=++k;
                bfs(i,j);
            }
        }
    }
    printf("%d",k);
    return 0;
}

void bfs(int b,int c)
{
    seqqueue q;
    point start;
    start.x=b;
    start.y=c;
    q.enqueue(start);
    while(!q.isempty())
    {
        point tmp=q.dequeue();
        if(tmp.x+1<n&&a[tmp.x+1][tmp.y]==0)
        {
            a[tmp.x+1][tmp.y]=a[tmp.x][tmp.y];
            point next;
            next.x=tmp.x+1;
            next.y=tmp.y;
            q.enqueue(next);
        }
        if(tmp.y+1<m && a[tmp.x][tmp.y+1]==0)
        {
            a[tmp.x][tmp.y+1]=a[tmp.x][tmp.y];
            point next;
            next.x=tmp.x;
            next.y=tmp.y+1;
            q.enqueue(next);
        }
        if(tmp.x-1>=0&&a[tmp.x-1][tmp.y]==0)
        {
            a[tmp.x-1][tmp.y]=a[tmp.x][tmp.y];
            point next;
            next.x=tmp.x-1;
            next.y=tmp.y;
            q.enqueue(next);
        }
        if(tmp.y-1>=0&&a[tmp.x][tmp.y-1]==0)
        {
            a[tmp.x][tmp.y-1]=a[tmp.x][tmp.y];
            point next;
            next.x=tmp.x;
            next.y=tmp.y-1;
            q.enqueue(next);
        }
    }
}
