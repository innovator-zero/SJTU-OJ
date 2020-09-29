#include <iostream>

using namespace std;

int n;
char in;
int a[1000],ml,mr,sum=0;

int main()
{
    int i=0,j;

    cin>>n>>in;

    while(in!='[')
    {
        cin>>in;
    }
    while(in!=']')
    {
        cin>>a[i]>>in;
        i++;
    }

    for(i=1; i<n-1; ++i)
    {
        ml=mr=a[i];
        for(j=0;j<i;++j)
        {
            if(a[j]>ml)ml=a[j];
        }
        for(j=i+1;j<n;++j)
        {
            if(a[j]>mr)mr=a[j];
        }
        sum+=min(ml,mr)-a[i];
    }
    cout<<sum;
    return 0;
}
