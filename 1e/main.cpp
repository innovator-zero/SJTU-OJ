#include <iostream>
#include <cstdio>
#include <cctype>
#include <cmath>
// Other headers you need and your variables
using namespace std;

inline int read()
{
    int X = 0;
    char ch = 0;
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return X;
}

inline void write(int x)
{
    int y = 10, len = 1;
    while (y <= x)
    {
        y *= 10;
        len++;
    }
    while (len--)
    {
        y /= 10;
        putchar(x / y + 48);
        x %= y;
    }
}

int n,q;
int dp1[300005][17]= {0},dp2[300005][17]= {0};
int pow2(int);

int main()
{
    int i,j,k,range,ans=0,mj;
    n=read();

    for(i=1; i<=n; i++)
    {
        dp1[i][0]=read();
    }
    for(i=1; i<=n; i++)
    {
        dp2[i][0]=read();
    }
    mj=log((double)n)/0.69314718+1;
    for(j=1; j<=mj; j++)
    {
        for(i=1; i<=n; i++)
        {
            dp1[i][j]=max(dp1[i][j-1],dp1[i+pow2(j-1)][j-1]);
            dp2[i][j]=min(dp2[i][j-1],dp2[i+pow2(j-1)][j-1]);
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=i; j<=n; j++)
        {
            range=j-i+1;
            k=log((double)(range))/0.69314718;
            if(max(dp1[i][k],dp1[j-pow2(k)+1][k])==min(dp2[i][k],dp2[j-pow2(k)+1][k]))
                ans++;

        }
    }
    write(ans);

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
