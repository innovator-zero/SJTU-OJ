#include <iostream>

using namespace std;

int main()
{
    char a[30];
    int n,s=0,i,j=0;
    bool flag;
    cin>>n>>a;


    while(a[s]!='\0'){s++;}

    if(n!=1){
    while(j<s){
        cout<<a[j];
        j+=2*n-2;
    }
    for(i=1;i<n-1;++i){
        j=i;
        flag=true;
        while(j<s){
            cout<<a[j];
            if(flag){j+=2*n-2-2*i;flag=false;}
            else {j+=2*i;flag=true;}
        }
    }
    j=n-1;
    while(j<s){
        cout<<a[j];
        j+=2*i;
    }
    }
    else cout<<a;
    return 0;
}
