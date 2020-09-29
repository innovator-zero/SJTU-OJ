#include <iostream>

using namespace std;

int Ack(int,int);

int main()
{
    int i,j;
    cin>>i>>j;
    cout<<Ack(i,j);
    return 0;
}

int Ack(int m,int n){
    if(m==0)return n+1;
    if(n==0)return Ack(m-1,1);
    return Ack(m-1,Ack(m,n-1));
}
