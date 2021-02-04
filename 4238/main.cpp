#include <iostream>
#include <cstdio>
using namespace std;

const int Size=200005;
int pre[Size],hide[Size]= {0};
int n,m;

int f(int x)
{
    int r=x;
    while (pre[r]!=r)
        r=pre[r];

    int i=x,j;
    while(i!=r)
    {
        j =pre[i];
        pre[i]= r;
        i=j;
    }
    return r ;
}

void uni(int x,int y)
{
    int fx=f(x),fy=f(y);
    if(fx!=fy)
        pre[fx]=fy;
}

int main()
{
    int cmd,x1,x2;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        pre[i]=i;
    }
    for(int i=0; i<m; i++)
    {
        cin>>cmd>>x1;
        switch(cmd)
        {
        case 1:
            cin>>x2;
            uni(x1,x2);
            break;
        case 2:
            cin>>x2;
            if(f(x1)==f(x2) && !hide[x1] && !hide[x2])
                printf("YES\n");
            else
                printf("NO\n");
            break;
        case 3:
            hide[x1]=1;
        }
    }

    return 0;
}
