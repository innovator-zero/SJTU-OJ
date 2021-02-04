#include <iostream>
#include <cstring>
using namespace std;

void delch (char *str,char c);
int main()
{
    char a[50][50];
    char ch;
    char tmp[50];
    int n=0,i,j;
    bool flag;
    cin>>ch;
    cin>>a[0];
    while(a[n][0]!='@'){
        n++;
        cin>>a[n];
    }

    for(i=0;i<n;i++){
        delch(a[i],ch);
    }
    for(i=1;i<n;i++){
        flag=false;
        for(j=0;j<n-i;j++){
            if(strcmp(a[j],a[j+1])<0){
                strcpy(tmp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],tmp);
                flag=true;
            }

        }if(!flag)break;
    }
    for(i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
void delch (char *str,char c){
    char *p=str,*q;
    while(*p!='\0'){
        if(*p==c){
            q=p;
            while(*q!='\0'){
                *q=*(q+1);
                q++;
            }
        }
        if(*p!=c){p++;}
    }
}
