#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n,q,t;
int dp[100000][15]= {0};
int pow2(int);
int Max(int,int);

int main()
{
    int i,j,k,l,r,range,ans,mj,p;
    scanf("%d",&t);
    for(p=0; p<t; p++)
    {
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&dp[i][0]);
        }
        mj=log((double)n)/0.69314718+1;
        for(j=1; j<=mj; j++)
        {
            for(i=1; i<=n-pow2(j)+1; i++)
            {
                dp[i][j]=Max(dp[i][j-1],dp[i+pow2(j-1)][j-1]);
            }
        }
        scanf("%d",&q);
        for(i=0; i<q; i++)
        {
            scanf("%d %d",&l,&r);
            range=r-l+1;
            k=log((double)range)/0.69314718;
            ans=Max(dp[l][k],dp[r-pow2(k)+1][k]);
            printf("%d\n",ans);
        }
    }
    return 0;
}

int pow2(int x)
{
    if(x==0)
        return 1;
    if(x==1)
        return 2;
    int y=2;
    y<<=(x-1);
    return y;
}

int Max(int a,int b)
{
    return a>b?a:b;
}
