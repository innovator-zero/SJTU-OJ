#include <iostream>
#include <stdio.h>

using namespace std;

int m,n,q,**a,x1,x2,y1,y2;
long long sum;

int main()
{
    int i,j,k;
    scanf("%d %d %d",&n,&m,&q);
    a=new int *[n+1];
    for(i=1;i<=n;i++)
    {
        a[i]=new int[m+1];
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<q;++i)
    {
        sum=0;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(j=x1;j<=x2;++j)
        {
            for(k=y1;k<=y2;++k)
            {
                sum+=(long long int)a[j][k];
            }
        }
        cout<<sum;
        printf("\n");
    }
    return 0;
}
