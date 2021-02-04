#include <iostream>
#define m 1000000007
using namespace std;

int n;
long long a[1001];

void fun(int);

int main()
{
    cin>>n;
    int i;
    a[1]=1;
    a[2]=2;
    for(i=3;i<=n;++i)
    {
        fun(i);
    }
    cout<<a[n];
    return 0;
}

void fun(int num)
{
    if(num%2==1)a[num]=a[num-1];
    else a[num]=(a[num-1]+a[num/2])%m;
}
