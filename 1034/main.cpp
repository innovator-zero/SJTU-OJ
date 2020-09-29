#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n,k,a[400005],b[200005];

int check(int);

int main()
{
    int i,high,low,mid;
    scanf("%d %d",&n,&k);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
        b[i]=a[i];
    }

    sort(b,b+n);
    low=0;
    high=n-1;

    if(k==1)
    {
        printf("%d",b[0]);
        return 0;
    }
    while(high-low>1)
    {
        mid=(low+high)/2;
        if(check(b[mid]))
            high=mid;
        else
            low=mid+1;
    }

    printf("%d",b[high]);

    return 0;
}

int check(int x)
{
    int i,j;
    bool flag;
    for(i=0; i<n; ++i)
    {
        flag=true;
        j=0;
        while(j<k)
        {
            if(a[i+j]>x)
                {flag=false;break;}
            j++;
        }
        if(flag) return 1;
        else i+=j;
    }
    return 0;
}
