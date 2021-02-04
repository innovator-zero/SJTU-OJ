#include <iostream>

using namespace std;

int main()
{
    char a[30];
    char ch;
    char *p;
    int i;
    bool flag=false;
    cin>>a>>ch;
    p=a;
    for(i=0;p[i]!='\0';i++){
        if(p[i]==ch){cout<<i<<" ";flag=true;}
    }
    if(!flag){cout<<"NULL";}
    return 0;
}
