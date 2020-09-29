#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node
{
    long long int num;
    int pos;
}a[10005];

int n;

int main()
{
    cin >> n;
    int l, r, top = 0;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &l, &r);
        a[top].num = l;
        a[top++].pos = 0;
        a[top].num = r;
        a[top++].pos = 1;
    }
    int cover = 0;
    long long sum = 0;
    sort(a, a + top);
    for(int i = 0; i < top - 1; ++i)
    {
        if(a[i].pos == 0)
            cover ++;
        if(a[i].pos == 1)
            cover--;
        if(cover == 0)
            continue;
        sum += (long long int)(a[i + 1].num - a[i].num);
    }
    cout << sum << '\n';
    return 0;
}
