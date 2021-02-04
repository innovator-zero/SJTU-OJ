#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int pic[2000][2000]= {0},n,m,k;
char str[2001];

int press(int,int);
bool isprime(int);

int main()
{
    int i,j,length,wide,kmin,sum,mn;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; i++)
    {
        scanf("%s",str);
        for(j=0; j<m; j++)
        {
            if(str[j]=='1')
                pic[i][j]=1;
        }
    }

    kmin=m*n;
    if(max(m,n)>800)
        mn=sqrt(max(m,n));
    else
        mn=max(m,n);

    for(k=2; k<=mn; ++k)
    {
        if(!isprime(k))
            continue;
        sum=0;
        if(n%k==0)
            length=n;
        else
            length=(n/k+1)*k;
        if(m%k==0)
            wide=m;
        else
            wide=(m/k+1)*k;

        for(i=0; i<length; i+=k)
        {
            for(j=0; j<wide; j+=k)
            {
                sum+=press(i,j);
            }
        }
        if(sum<kmin)
            kmin=sum;
    }
    printf("%d",kmin);
    return 0;
}

int press(int a,int b)
{
    int i,j,white=0,black=0;
    for(i=a; i<a+k; ++i)
    {
        for(j=b; j<b+k; ++j)
        {
            if(pic[i][j]==0)
                white++;
            else
                black++;
        }
    }
    return min(white,black);
}

bool isprime(int x)
{
    int i;
    for(i=2; i<=sqrt(x); i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
