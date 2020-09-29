#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node
{
    long long int num;
    int pos;
} a[10005];

bool cmp(node a, node b)
{
    return a.num < b.num;
}

int n;

int main()
{
    cin >> n;
    long long int l, r;
    int i,j = 0;
    for(i=0; i<n; ++i)
    {
        scanf("%lld %lld", &l, &r);
        a[j].num = l;
        a[j++].pos = 0;
        a[j].num = r;
        a[j++].pos = 1;
    }
    int cover = 0;
    long long sum = 0;
    sort(a, a + j,cmp);
    for(i = 0; i < j-1; ++i)
    {
        if(a[i].pos == 0)
            cover ++;
        if(a[i].pos == 1)
            cover--;
        if(cover == 0)
            continue;
        sum += (long long int)(a[i + 1].num - a[i].num);
    }
    printf("%lld",sum);
    return 0;
}
