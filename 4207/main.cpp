#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_size = 5005;
int n,k,a[max_size];
int num[max_size];
int dp[max_size][max_size]={0};

int main()
{
    int i,j,low;
    scanf("%d%d",&n,&k);
    for(i = 1; i <= n; i++)
        scanf("%d",&a[i]);

    sort(a+1,a+n+1);
    for(i = 1; i <= n; i++)
    {
        low = a[i] - 5;
        num[i] = i+1-(lower_bound(a+1,a+n+1,low)-a);
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= k; j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i-num[i]][j-1]+num[i]);
        }
    }
    printf("%d",dp[n][k]);
}
