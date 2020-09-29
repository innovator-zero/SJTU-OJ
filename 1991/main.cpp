#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int k,n;
double x[100000],low,high,mid;

int judge(double r);

int main()
{
    int i;
    cin>>n>>k;
    for(i=0; i<n; ++i)
    {
        cin>>x[i];
    }
    low=x[0];
    high=x[n-1];
    while((high-low)>=pow(10,-7))
    {
        mid=(high+low)/2;
        if(judge(mid)==0)
        {
            cout<<fixed<<setprecision(6)<<mid;
            return 0;
        }
        else if(judge(mid)==1)
        {
            high=mid;
        }
        else
        {
            low=mid;
        }
    }
    cout<<fixed<<setprecision(6)<<mid;
    return 0;
}

int judge(double r)
{
    int i=0,j=0,p=0;
    while(i<k)
    {
        while(x[p]<=x[j]+2*r)
        {
            p++;
            if(p>=n&&x[n-1]==x[j]+2*r) return 0;
            if(p>=n&&x[n-1]<x[j]+2*r) return 1;
        }
        j=p;
        i++;
    }

    return -1;
}
