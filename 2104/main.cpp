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
int x,y,n;
int m[1200][1200]= {0};

void bfs();

int main()
{
    int i,j;
    scanf("%d %d %d",&x,&y,&n);
    for(int k=0; k<n; k++)
    {
        scanf("%d %d",&i,&j);
        m[i+600][j+600]=-1;
    }
    bfs();
    printf("%d",m[x+600][y+600]);
    return 0;
}

void bfs()
{
    seqqueue q;
    point start;
    start.x=600;
    start.y=600;
    q.enqueue(start);
    while(!q.isempty())
    {
        point tmp=q.dequeue();
        if(tmp.x==x+600&&tmp.y==y+600)return;
        if(tmp.x+1<1200&&m[tmp.x+1][tmp.y]==0)
        {
            m[tmp.x+1][tmp.y]=m[tmp.x][tmp.y]+1;
            point next;
            next.x=tmp.x+1;
            next.y=tmp.y;
            q.enqueue(next);
        }
        if(tmp.y+1<1200 && m[tmp.x][tmp.y+1]==0)
        {
            m[tmp.x][tmp.y+1]=m[tmp.x][tmp.y]+1;
            point next;
            next.x=tmp.x;
            next.y=tmp.y+1;
            q.enqueue(next);
        }
        if(tmp.x-1>=0&&m[tmp.x-1][tmp.y]==0)
        {
            m[tmp.x-1][tmp.y]=m[tmp.x][tmp.y]+1;
            point next;
            next.x=tmp.x-1;
            next.y=tmp.y;
            q.enqueue(next);
        }
        if(tmp.y-1>=0&&m[tmp.x][tmp.y-1]==0)
        {
            m[tmp.x][tmp.y-1]=m[tmp.x][tmp.y]+1;
            point next;
            next.x=tmp.x;
            next.y=tmp.y-1;
            q.enqueue(next);
        }
    }
}
