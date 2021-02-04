#include <iostream>

using namespace std;

unsigned int fi(int num);
int main()
{
    int n;
    cin>>n;

    if(n<=0){cout<<"error!";return 0;}

    cout<<fi(n);

    return 0;
}
unsigned int fi(int num){
    unsigned int f[60];

    if(num==1)return 0;
    if(num==2)return 1;

    f[1]=0;f[2]=1;
    for(int i=3;i<=num;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[num];
}
