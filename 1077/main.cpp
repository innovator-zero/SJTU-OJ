#include <iostream>
#include <cstdio>

long long dp[39][39];
int root[39][39];
int n;

void out_tree(int l,int r)
{
    if(l>r)
        return;
    printf("%d ",root[l][r]);
    out_tree(l,root[l][r]-1);
    out_tree(root[l][r]+1,r);
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&dp[i][i]);
        dp[i][i-1]=1;
        dp[i+1][i]=1;
        root[i][i]=i;
    }

    for(int l=2; l<=n; l++)
    {
        for(int i=1; i<=n-l+1; i++)
        {
            for(int j=i; j<=i+l-1; j++)
            {
                if(dp[j][j]+dp[i][j-1]*dp[j+1][i+l-1]>dp[i][i+l-1])
                {
                    dp[i][i+l-1]=dp[j][j]+dp[i][j-1]*dp[j+1][i+l-1];
                    root[i][i+l-1]=j;
                }
            }
        }
    }
    printf("%lld\n",dp[1][n]);
    out_tree(1,n);
    printf("\n");
}
