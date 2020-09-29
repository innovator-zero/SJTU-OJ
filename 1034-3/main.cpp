#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int max_size=400005;
int n,k,ss=0,tt=-1;
int q[max_size],q_pos[max_size],num[max_size];

void q_push(int num, int pos)
{
    while (ss <= tt && q[tt] < num)
        --tt;
    q[++tt] = num;
    q_pos[tt] = pos;
}
void q_pop(int pos)
{
    if (pos == q_pos[ss])
        ++ss;
}
int main()
{
    int i,res;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &num[i]);
        num[i + n] = num[i];
    }
    for (i = 0; i < k; ++i)
    {
        q_push(num[i], i);
    }
    res=q[ss];
    for (i = k; i < 2*n; ++i)
    {
        q_push(num[i], i);
        q_pop(i - k);
        res=min(q[ss], res);
    }
    printf("%d",res);

    return 0;
}
