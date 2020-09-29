#include<iostream>
#include<cmath>

using namespace std;

const int Size=100005;

struct tree
{
    int lchild=0,rchild=0;
} a[Size];
int n;
int b[Size]= {0};

tree elem[Size];

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
    int i;

    for(i=1; i<=n; i++)
    {
        cin>>a[i].lchild>>a[i].rchild;
        b[a[i].lchild]=1;
        b[a[i].rchild]=1;
    }
    for(i=1; i<=n; i++)
    {
        if(b[i]==0)
            break;
    }
    en(a[i]);

    while(front!=rear)
    {
        tree p=head();
        if(p.lchild && p.rchild)
        {
            de();
            en(a[p.lchild]);
            en(a[p.rchild]);
        }
        if(p.lchild==0 && p.rchild!=0)
        {
            cout<<"N";
            return 0;
        }
        if(p.rchild==0)
        {
            de();
            if(p.lchild!=0)
                en(a[p.lchild]);
            while(front!=rear)
            {
                if(head().lchild==0 && head().rchild==0)
                    de();
                else
                {
                    cout<<"N";
                    return 0;
                }
            }
        }
    }
    cout<<"Y";
    return 0;
}
