#include <iostream>

using namespace std;

int t,m,f[1005]= {0};

struct mushroom
{
    int time,value;
};
mushroom a[105];


int main()
{
    int i,j;
    cin>>t>>m;
    for(i=0; i<m; ++i)
    {
        cin>>a[i].time>>a[i].value;
    }

    for(i=0; i<m; ++i)
    {
        for(j=t; j>=a[i].time; --j)
        {
            if(f[j]<f[j-a[i].time]+a[i].value)
                f[j]=f[j-a[i].time]+a[i].value;
        }
    }
    cout<<f[t];

    return 0;
}
