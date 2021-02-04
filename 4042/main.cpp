#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3e5 + 10;
const int mod = 1e9 + 7;
long long n, a[N], len[N], two[N], k[N];
void QuickSort(int start, int last);

void init ()
{
    two[0] = 1;
    for (int i = 1; i <= 300000; ++i)
    {
        two[i] = (two[i-1] * 2) % mod;
        k[i] =  (two[i] - 1 + mod) % mod;
    }
}

int main ()
{
    scanf("%lld",&n);
    init ();
    for (int i = 1; i <= n; ++i)
        cin>>a[i];
    QuickSort(1, n);
    for (int i = 2; i <= n; ++i)
        len[i] = a[i] - a[i-1];
    long long ans = 0;
    for (int i = 2; i <= n; ++i)
        ans = (ans + (len[i] * ((k[i-1] * k[n-i+1]) % mod)) % mod) % mod;
    printf("%lld",ans);
    return 0;
}

void QuickSort(int start, int last)
{
    int i=start;
    int j=last;
    int temp=a[i];
    if (i<j)
    {
        while(i<j)
        {
            while(i<j&&a[j]>=temp)
                j--;
            if(i<j)
            {
                a[i]=a[j];
                i++;
            }
            while (i<j&&temp>a[i])
                i++;
            if (i<j)
            {
                a[j]=a[i];
                j--;
            }
        }
        a[i] = temp;
        QuickSort(start, i - 1);
        QuickSort(i + 1, last);
    }
}
