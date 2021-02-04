#include <iostream>
#include <cstring>

using namespace std;

int num[3400]={0};
int main()
{
    int n,i,j;
    cin>>n;
    num[0]=1;
    num[1]=1;
    for (i=2; i<=n; ++i)
    {
        num[i]+=num[i-1];
        for (j=1; j<i; ++j)
        {
            num[i]+= num[j-1]*num[i-j-1];
            num[i]%= 19301;
        }
    }
    cout<<num[n];
    return 0;
}
