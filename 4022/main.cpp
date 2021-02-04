#include <iostream>

using namespace std;

int x;
long long n,sum=0;

int main()
{
    int i;
    cin>>x>>n;
    sum+=(n/7)*1250;
    n=n%7;
    for(i=0;i<n;i++)
    {
        if(x+i!=6&&x+i!=7)
            sum+=250;
    }
    cout<<sum;
    return 0;
}
