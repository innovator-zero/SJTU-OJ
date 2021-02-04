#include <iostream>

using namespace std;

int main()
{
    char ch[30];
    char out[100][30];
    int n,i=0,j=0,s=0,k=0,m;
    bool flag=true;
    bool wo[100][30];

    cin>>n>>ch;

    for(i=0;i<=n;++i){
        for(j=0;j<=30;++j){
            wo[i][j]=false;
        }
    }
    if(n!=1){
    while(ch[s]!='\0'){s++;}
    s--;

    i=j=0;
    while(k<=s){
        out[i][j]=ch[k];wo[i][j]=true;
        k++;
        if(flag){
            if(i<n-1){i++;}
            else {flag=false;i--;j++;}
        }
        else {
            if(i==0){flag=true;i++;}
            else {i--;j++;}
        }
    }

    for(i=0;i<=n;++i){
        for(m=0;m<=j;++m){
            if (wo[i][m]){cout<<out[i][m];}
        }
    }
    }
    else cout<<ch;
    return 0;
}
