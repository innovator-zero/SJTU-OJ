#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[10000];
    char word[10000];
    int i,j,m,n,k=0,p,q,s,num;
    bool flag=false;

    cin>>a;
    num=strlen(a);

    for(i=num-1;i>=0;--i){
        for(j=num-1;j>=i+1;--j){
            if(a[i]==a[j]){
                m=s=i;n=j;p=0;
            while(a[m]==a[n]&&m<n){
                m++;n--;
            }
            if(m==n+1)p=(m-i)*2;
            if(m==n)p=(m-i)*2+1;
            if(p>=k){
                k=p;
                q=0;
                while(q<k){word[q]=a[s];q++;s++;}
                flag=true;
            }
            }

        }
    }
    if(flag)cout<<k<<endl<<word;
    else cout<<"0";
    return 0;
}
