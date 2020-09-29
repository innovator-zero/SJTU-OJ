#include <iostream>

using namespace std;

int n;
int a[505],b[505],c[505],d[505];
int num[4000010]={0};
int cou=0;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            num[a[i]+b[j]+2000005]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cou+=num[-(c[i]+d[j])+2000005];
        }
    }
    cout<<cou;
    return 0;
}
