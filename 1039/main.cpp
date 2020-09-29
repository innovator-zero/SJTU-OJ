#include <iostream>

using namespace std;

int a[100000],b[100000];
int n;

void post(int);

int main()
{
    cin>>n;
    int i,l,r,k;
    a[1]=1;
    b[1]=1;
    for(int j=0;j<n;j++)
    {
        cin>>i>>l>>r;
        k=1;
        while(a[k]!=i)k++;
        a[2*k]=l;
        a[2*k+1]=r;
        if(l!=-1)b[l]=2*k;
        if(r!=-1)b[r]=2*k+1;
    }
    for(i=1;i<=n;i++)
        cout<<b[i]<<" ";
    cout<<'\n';
    post(1);
    return 0;
}

void post(int t)
{
    if(a[t]==-1)return;
    post(2*t);
    post(2*t+1);
    cout<<a[t]<<" ";
}
