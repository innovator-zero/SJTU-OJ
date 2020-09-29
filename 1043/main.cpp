#include<iostream>
#include<cmath>

using namespace std;

struct tree
{
    int lchild=0,rchild=0;
} a[1000000];
int n;

tree elem[1000000];
int Size=1000000;
int front=0,rear=0;

void de()
{
    front=(front+1)%Size;
}

void en(tree x)
{
    rear=(rear+1)%Size;
    elem[rear]=x;
}

tree head()
{
    return elem[(front+1)%Size];
}

int main()
{
    cin>>n;
    int m;

    for(int i=1; i<=n-1; i++)
    {
        cin>>m;
        if(a[m].lchild==0)
            a[m].lchild=i;
        else
            a[m].rchild=i;
    }
    en(a[0]);
    while(front!=rear)
    {
        tree p=head();
        if(p.lchild && p.rchild)
        {
            de();
            en(a[p.lchild]);
            en(a[p.rchild]);
        }
        if(p.rchild==0)
        {
            de();
            if(p.lchild!=0)en(a[p.lchild]);
            while(front!=rear)
            {
                if(head().lchild==0 && head().rchild==0)
                    de();
                else
                {
                    cout<<"false";
                    return 0;
                }
            }
        }
    }
    cout<<"true";
    return 0;
}
