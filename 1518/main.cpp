#include<iostream>

using namespace std;

const int maxn=100005;
int a[maxn],b[maxn];
int m,flag;

void createtree(int preleft,int preright,int inleft,int inright)
{
    int i,lsize,rsize;
    if(preleft<=preright && inleft<=inright)
    {
        for(i=inleft; i<inright; i++)
        {
            if(a[preleft]==b[i])
                break;
        }
        lsize=i-inleft;
        rsize=inright-i;
        if(lsize > 0)
        {
            createtree(preleft+1, preleft + lsize,inleft,i-1);
        }
        if(rsize > 0)
        {
            createtree(preleft+lsize+1,preright,i+1,inright);
        }

        cout<<a[preleft]<<" ";
    }
}


int main()
{
    int i;
    cin>>m;
    for(i=0; i<m; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<m; i++)
    {
        cin>>b[i];
    }
    createtree(0,m-1,0,m-1);

    return 0;
}
