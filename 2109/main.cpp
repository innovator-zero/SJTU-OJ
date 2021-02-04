#include <iostream>

using namespace std;

int n,k,b,c;
int a[100000];

long long int de(int);

int main()
{
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    int i;
    int low,high,mid;

    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>a[i];
    }
    cin>>k;
    for(i=0; i<k; ++i)
    {
        cin>>b>>c;

        low=0;
        high=n-1;

        while(low<=high)
        {
            mid=(low+high)/2;

            if(de(a[mid])==0)
            {
                low=mid;
                break;
            }
            if(de(a[mid])<0)
                high=mid;
            else
                low=mid;
            if(high-low==1)
            {
                if(de(a[high])>0)
                    low=high;
                if(de(a[low])<0)
                    low--;
                break;
            }
        }
        cout<<low+1<<'\n';


    }
    return 0;
}

long long int de(int num)
{
    return ((long long int)(b)*b-(long long int)(num)*4*c);
}
