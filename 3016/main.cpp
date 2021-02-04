#include <iostream>

using namespace std;

int main()
{
    int n,i,sum=0,avg,op=0;
    int *a;

    cin>>n;
    a=new int[n];

    for(i=0; i<n; ++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    avg=sum/n;

    for(i=0;i<n-1;i++){
    if (a[i]>avg)
        {a[i+1]+=a[i]-avg;op++;}
    if(a[i]<avg)
        {a[i+1]-=avg-a[i];op++;}
    }

    cout<<op;

        return 0;
}
