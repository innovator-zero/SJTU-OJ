#include <iostream>
#include <cstdio>

using namespace std;

struct point
{
    int h,pos;
};

class seqqueue
{
private:
    point *elem;
    int maxsize;
    int front,rear;
    void doublespace();

public:
    seqqueue(int size);
    ~seqqueue();
    bool isempty() const;
    void enqueue(const point &x);
    point dequeue();
    point head();
    point tail();
    void pop();
};

int n,d;
point *a;

int main()
{
    scanf("%d %d",&n,&d);
    a=new point[n];
    int k=2*d+1,i;
    int cou=0;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i].h);
        a[i].pos=i;
    }

    seqqueue q(n);
    q.enqueue(a[0]);

    for(i=1; i<n; i++)
    {
        while(q.isempty()==0&&q.head().pos<i-k+1)
            q.dequeue();
        while(q.isempty()==0&&q.tail().h<a[i].h)
            q.pop();
        q.enqueue(a[i]);
        if(i>=d)
        {
            if(2*a[i-d].h<q.head().h)
                cou++;
        }

    }
    for(i=n-d; i<n; i++)
    {
        while(q.isempty()==0&&q.head().pos<i-d)
            q.dequeue();
        if(2*a[i].h<q.head().h)
                cou++;
    }
    printf("%d",cou);

    return 0;
}

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
    rear=(rear+1)%maxsize;
    elem[rear]=x;
}

point seqqueue::dequeue()
{
    front=(front+1)%maxsize;
    return elem[front];
}

point seqqueue::head()
{
    return elem[front+1];
}

point seqqueue::tail()
{
    return elem[rear];
}

void seqqueue::pop()
{
    rear=(rear+maxsize-1)%maxsize;
}

