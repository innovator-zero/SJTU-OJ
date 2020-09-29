#include <iostream>

using namespace std;

int n,k,a[200000];

int mk(int);

int main()
{
    int i,m;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    m=mk(0);
    for(i=1;i<n;i++)
    {
        if(mk(i)<m)m=mk(i);
    }
    cout <<m;
    return 0;
}

int mk(int x)
{
    int j=0,y=0;
    while(j<k)
    {
        if(a[(x+j)%n]>y)y=a[(x+j)%n];
        j++;
    }
    return y;
}
