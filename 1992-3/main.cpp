#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int max_size=10005;
int n;
long long int ans=0,l=0,r=0;

struct range
{
    long long int l,r;
    bool operator<(const range &b)const
    {
        if(l==b.l)
        {
            return r>b.r;
        }
        return l<b.l;
    }
} a[max_size];

int main()
{
    int i;
    scanf(("%d"),&n);
    for(i=0; i<n; i++)
    {
        scanf("%lld %lld",&a[i].l,&a[i].r);
    }
    sort(a,a+n);

    for(i=0; i<n; i++)
    {
        if(l<=a[i].l&&a[i].l<=r)
            r=max(r,a[i].r);
        else
        {
            ans+=r-l;
            l=a[i].l;
            r=a[i].r;
        }
    }
    ans+=r-l;
    printf("%lld",ans);

    return 0;
}
