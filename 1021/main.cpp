#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n,i,j,k=1,**a;
    cin>>n;
    a=new int*[n];
    for(i=0;i<n;++i) a[i]=new int[n];

    for(i=0;i<n/2;++i){
        for(j=i;j<n-i;++j) a[i][j]=k++;
        for(j=i+1;j<n-i;++j) a[j][n-i-1]=k++;
        for(j=n-i-2;j>=i;--j) a[n-i-1][j]=k++;
        for(j=n-i-2;j>i;--j) a[j][i]=k++;
    }
    if(n%2==1) a[(n-1)/2][(n-1)/2]=n*n;

    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            cout<<setw(6)<<a[i][j];
        }
        cout<<endl;
    }
    for(i=0;i<n;++i) delete []a[i];
    delete []a;
    return 0;
}

