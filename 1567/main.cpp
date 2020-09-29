#include <iostream>

using namespace std;

int main()
{
    char s;int n,i,j;
    cin>>s>>n;

    for(i=0;i<(n+1)/2;++i){
        for(j=0;j<(n-1)/2-i;j++)cout<<" ";
        for(j=0;j<2*i+1;j++)cout<<s;
        for(j=0;j<(n-1)/2-i;j++)cout<<" ";
        cout<<endl;
    }
    for(i=(n+1)/2;i<n;++i){
        for(j=0;j<i-(n-1)/2;j++)cout<<" ";
        for(j=0;j<2*(n-i)-1;j++)cout<<s;
        for(j=0;j<i-(n-1)/2;j++)cout<<" ";
        cout<<endl;
    }
    return 0;
}
