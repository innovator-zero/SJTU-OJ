#include <iostream>

using namespace std;

int main()
{
    int n,t,i ,low,high,mid;
    cin>>n>>t;
    long long x[100000];
    long long y[100000];

    for(i=0; i<n; i++)
    {
        cin>>x[i];
    }
    for(i=0; i<t; i++)
    {
        cin>>y[i];
    }

    for(i=0;i<t;++i)
    {
        low=0;high=n-1;
        while(low<=high){
            mid=(low+high)/2;
            if(y[i]==x[mid]){low=mid;break;}
            if(y[i]<x[mid]) high=mid;else low=mid;
            if (high-low==1)
            {
                if(y[i]>=x[high])low=high;
                if(y[i]<x[low])low=low-1;
                break;
            }
        }
        cout<<n-low-1<<'\n';
    }

    return 0;
}
