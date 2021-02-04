#include <iostream>
#include <algorithm>

using namespace std;

int n,c;
long long pos[100000];

int check(long long);

int main()
{
    int i;
    long long high,low=0,mid;
    cin>>n>>c;
    for(i=0; i<n; i++)
    {
        cin>>pos[i];
    }
    sort(pos,pos+n);

    high=pos[n-1];
    while(low<=high)
    {
        mid=(low+high)/2;
        if(check(mid))
            low=mid+1;
        else
            high=mid-1;
    }
    cout<<high;
    return 0;
}

int check(long long m)
{
    int i,j=0,cou=1;

    for(i=1;i<n;i++)
    {
        if(pos[i]>=pos[j]+m)
        {
            cou++;
            j=i;
        }
    }
    if(cou>=c)return 1;
    else return 0;

}
