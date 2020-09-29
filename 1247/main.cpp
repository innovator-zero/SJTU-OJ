#include <iostream>

using namespace std;

int a[10005]={0};
int n,m;

int main()
{
    int l,r,sum=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>l>>r;
        for(int j=l;j<=r;j++)
        {
            if(!a[j])sum++;
            a[j]=1;
        }
    }

    cout << n-sum+1 ;
    return 0;
}
