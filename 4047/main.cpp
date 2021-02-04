#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n,i,j;
    bool b[2000000];
    cin>>n;

    for (i=2;i<=n;++i){
        b[i]=true;
    }
    for(i=2;i<=sqrt(n);++i){
        if (b[i]){
        for(j=i*i;j<=n;j+=i){
            b[j]=false;//把i的倍数划掉
        }
        }
    }
    for(i=2;i<=n;++i){
        if(b[i])cout<<i<<" ";
    }

    return 0;
}
