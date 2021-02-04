#include <iostream>
#include <cstdio>

using namespace std;

int n,m,k,del=0;
bool *p;
int main()
{
    int i,j,f;

    scanf("%d%d%d",&n,&m,&k);
    p=new bool[n+1];
    for(i=1; i<=n; i++)
    {
        p[i]=true;
    }

    i=1;
    while(del<k)
    {
        j=0;
        while(j<m-1)
        {
            if(p[i]==1)
            {
                j++;
            }
            i++;
            if(i==n+1)
                i=1;
        }
        while(p[i]==0)
        {
            i++;
            if(i==n+1)
                i=1;
        }
        p[i]=false;
        f=i;
        del++;
        i++;
        if(i==n+1)
            i=1;
    }

    printf("%d",f);
    delete[] p;
    return 0;
}
