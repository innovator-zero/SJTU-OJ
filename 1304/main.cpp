#include <iostream>

using namespace std;

int main()
{
    int n,i;
    long long l,lmin,lmax,rmin,rmax;
    cin>>n>>l;
    int ball[10000];

    for(i=0;i<n;i++)
    {
        cin>>ball[i];
    }
    rmin=rmax=l-ball[0];
    for(i=2;i<n;i+=2)
    {
        if((l-ball[i])>rmax)rmax=l-ball[i];
        if((l-ball[i])<rmin)rmin=l-ball[i];
    }
    lmax=lmin=ball[1];
    for(i=1;i<n;i+=2){
        if(ball[i]>lmax)lmax=ball[i];
        if(ball[i]<lmin)lmin=ball[i];
    }
    if(rmin>lmin)cout<<lmin<<" ";
    else cout<<rmin<<" ";
    if(rmax>lmax)cout<<rmax;
    else cout<<lmax;
    return 0;
}
