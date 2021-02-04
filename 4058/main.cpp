#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,i,j,m=0,tmp,num;
    char a[80],b[80];
    bool flag,f;

    cin>>n;
    cin.getline(a,80,'\n');
    num=strlen(a);
    for(i=0;i<num;++i){
        flag=true;
        for(j=0;j<i;++j){
            if (a[i]==a[j]){flag=false;}
        }
        while(flag){
        if(a[i]>='A'&&a[i]<='Z'){b[m]=a[i]-'A'+'a';m++;}
        if(a[i]>='a'&&a[i]<='z'){b[m]=a[i]-'a'+'A';m++;}
        if(a[i]>='0'&&a[i]<='9'){b[m]=a[i];m++;}
        flag=false;
    }
    }
    for(i=1;i<m;++i){
        f=false;
        for(j=0;j<m-i;++j){
            if(b[j+1]>b[j]){tmp=b[j];b[j]=b[j+1];b[j+1]=tmp;f=true;}
        }
       if(!f)break;
    }
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
        cout<<b[j];
    return 0;
}
