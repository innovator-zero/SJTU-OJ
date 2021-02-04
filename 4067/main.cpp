#include <iostream>

using namespace std;
void plusone(char array[],int x);
int main()
{
    char a[50];
    int i,n=0;

    cin>>a;

    while(a[n]!='\0'){
        n++;
    }
    n--;

    plusone(a,n);

    for(i=0;i<=n;++i)
        cout<<a[i];

    return 0;
}

void plusone(char array[],int x){
    if (array[x]=='9'){
            if (x>0){array[x]='0';plusone(array,x-1);}
            else {array[x]='0';cout<<"1";}}
    else array[x]++;
}
