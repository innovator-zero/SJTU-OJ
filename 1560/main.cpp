#include <iostream>

using namespace std;

template<class T>
class seqQueue
{
private:
    T *data;
    int maxSize;
    int front;
    int rear;
    void doubleSpace()
    {
        T *tmp = data;
        data = new T[maxSize*2];
        for(int i=1;i<maxSize;++i)
            data[i] = tmp[(front+i)%maxSize];
        front = 0;
        rear = maxSize-1;
        maxSize *= 2;
        delete tmp;
    }
public:
    seqQueue(int init = 10) {
        maxSize = init;
        data = new T[maxSize];
        front = rear = 0;
    }
    ~seqQueue() {delete [] data;}
    bool isEmpty() const {return rear==front;}
    void enqueue(const T &x)
    {
        if((rear+1)%maxSize == front)
            doubleSpace();
        rear = (rear+1)%maxSize;
        data[rear] = x;
    }
    T getHead() const
    {
        return data[(front+1)%maxSize];
    }
    T getTail() const
    {
        return data[rear];
    }
    T dequeue()
    {
        front = (front+1)%maxSize;
        return data[front];
    }
};

struct node
{
    int key;
    node *lchild,*rchild;

    node(const int k,node *l,node *r):key(k),lchild(l),rchild(r) {};
};

node *root;

void ins(const int x,node *&t)
{
    if(t==NULL)
    {
        t=new node(x,NULL,NULL);
        return;
    }
    else if(x<t->key)
        ins(x,t->lchild);
    else if(t->key<x)
        ins(x,t->rchild);

}

void rem(const int &x,node *&t)
{
    if(t==NULL)
        return;
    if(x<t->key)
        rem(x,t->lchild);
    else if(t->key<x)
        rem(x,t->rchild);
    else if(t->rchild==NULL)
    {
        node *oldnode=t;
        t=t->lchild;
        delete oldnode;
    }
    else if(t->rchild!=NULL)
    {
        node *tmp=t->rchild,*rtmp=t->rchild;
        if(!tmp->lchild)
        {
            t->key=tmp->key;
            t->rchild=tmp->rchild;
            delete tmp;
            return;
        }
        while(tmp->lchild!=NULL)
        {
            rtmp=tmp;
            tmp=tmp->lchild;
        }
        t->key=tmp->key;
        rtmp->lchild=tmp->rchild;
        delete tmp;
    }
}
void f(const int &x)
{
    seqQueue<int> s;
    bool flag=false;
    node *tmp=root;
    while(tmp)
    {
        if(tmp->key==x)
        {
            flag = true;
            printf("*");
            while(!s.isEmpty())
                s.dequeue() ? printf("l"):printf("r");
            break;
        }
        else if(tmp->key>x)
        {
            s.enqueue(1);
            tmp=tmp->lchild;
        }
        else
        {
            s.enqueue(0);
            tmp=tmp->rchild;
        }
    }
    if(!flag)
        printf("Nothing.");
    printf("\n");
}


int n;
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        char s;
        int k;
        getchar();
        s=getchar();
        scanf("%d",&k);
        switch(s)
        {
        case '+':
            ins(k,root);
            break;
        case '-':
            rem(k,root);
            break;
        case '*':
            f(k);
        }
    }
    return 0;
}
