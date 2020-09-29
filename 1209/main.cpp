#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,*a,i,j,k,sum=0;
    cin>>n;
    a=new int[n];

    for(i=0;i<n;++i){
        cin>>a[i];
    }

    for(i=0;i<n;++i){
        k=0;
        for(j=32;j>=0;--j){
            if(a[i]>=pow(2,j)){
                k++;
                a[i]-=pow(2,j);
            }
        }
        sum+=k;
    }

    cout<<sum;
    delete a;
    return 0;
}
