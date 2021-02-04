#include <iostream>

using namespace std;

int n;
long long w[100000],h[100000],a[100000];

int main()
{
    int i;
    bool flag=true;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>w[i]>>h[i];
    }

    a[0]=max(w[0],h[0]);
    for(i=1;i<n;++i)
    {
        if(w[i]>a[i-1]&&h[i]>a[i-1]){flag=false;break;}
        if(w[i]<a[i-1]&&h[i]<a[i-1])a[i]=max(w[i],h[i]);
        else a[i]=min(w[i],h[i]);
    }
    if(!flag) cout<<"NO";
    else cout<<"YES";
    return 0;
}
