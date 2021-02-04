#include <iostream>

using namespace std;

int main()
{
    int n,i,j,tmp,t=0;
    int a[100];
    bool flag;

    cin>>n;
    for (i=0;i<n;++i){cin>>a[i];}

    for(i=1;i<n;++i){
        flag=false;
        for(j=0;j<n-i;++j){
            if(a[j+1]<a[j]){tmp=a[j];a[j]=a[j+1];a[j+1]=tmp;flag=true;}
        if(!flag) break;
        }
    }
    if(n==1){t=a[0];}
    else if (n % 2==1&&n>1){t+=a[0]+a[1]+a[2];i=4;}
    else{t+=a[1];i=3;}
    while(i<n){
        t+=a[1]+a[0]+a[i]+a[1];
        i+=2;
    }
    cout<<t;
    return 0;
}


