#include <iostream>

using namespace std;

int main()
{
    int m,n,i,j;

    cin>>m>>n;

    int a[10][10],b[10][10];

    for (i=0;i<m;++i){
        for(j=0;j<n;++j){
            cin>>a[i][j];
        }
    }

    cout<<n<<" "<<m<<endl;

    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            b[i][j]=a[(m-1-j)][i];
            cout<<b[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}
