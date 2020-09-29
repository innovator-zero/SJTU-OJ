#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
struct number
{
    int num,den;
    double value;
    bool operator<(const number &other)
    {
        return value<other.value;
    }
}a[10000];

bool huzhi(int ,int);

int main()
{
    int i,j,k=0;
    cin>>n;
    printf("0/1\n");
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(i==1||huzhi(i,j))
            {
                a[k].num=i;
                a[k].den=j;
                a[k].value=(double)i/j;
                k++;
            }
        }
    }
    sort(a,a+k);
    for(i=0;i<k;i++)
    {
        printf("%d/%d\n",a[i].num,a[i].den);
    }
    printf("1/1");
    return 0;
}

bool huzhi(int a,int b)
{
    int x;
    for(x=2;x<=min(a,b);x++)
    {
        if(a%x==0&&b%x==0)return false;
    }
    return true;
}
