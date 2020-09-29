#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,m;
    char type[7];

    cin>>type;
    cin>>n>>m;

    if(strcmp(type,"int")==0){
        int *a,i;
        a=new int[n+m];
        for(i=0;i<n+m;++i) cin>>a[i];
        for(i=0;i<n+m;++i) cout<<a[i]<<" ";
        delete []a;
    }

     if(strcmp(type,"char")==0){
        char *a;
        int i;
        a=new char[n+m];
        for(i=0;i<n+m;++i) cin>>a[i];
        for(i=0;i<n+m;++i) cout<<a[i]<<" ";
        delete []a;
    }

     if(strcmp(type,"double")==0){
        double *a;
        int i;
        a=new double[n+m];
        for(i=0;i<n+m;++i) cin>>a[i];
        for(i=0;i<n+m;++i) cout<<a[i]<<" ";
        delete []a;
    }
    return 0;
}



