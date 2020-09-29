#include <iostream>
using namespace std;
int main()
{
    long long int n,i,j,sum=0;
    long long int taki,mitsaha;
    cin>>n>>i>>j;
    while (i<n&&j<n&&i!=1&&j!=1)
    {
        sum+=(n-1)*4;
        n=n-2;
        i=i-1;
        j=j-1;
    }
    taki=mitsaha=sum;
    if (j==1)
        taki+=n-i+1;
    else
    {
        if (j==n)
            taki+=i+2*(n-1);
        else
        {
            if (i==1)
                taki+=n+j-1;
            else
                taki+=4*n-2-j;
        }
    }
    if (j==n)
        mitsaha+=i;
    else
    {
        if (j==1)
            mitsaha+=n-i+1+2*(n-1);
        else
        {
            if (i==n)
                mitsaha+=n+n-j;
            else
                mitsaha+=2*n+n-2+j-1;
        }
    }
    cout<<taki-1<<' '<<mitsaha-1;
    return 0;
}
