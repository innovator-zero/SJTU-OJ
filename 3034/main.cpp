#include <iostream>
#include <cmath>

using namespace std;

bool sushu(long long int);

int main()
{
    long long int n,i,j;
    cin>>n;

    i=j=n;
    while(sushu(i)!=true)
    {
        i--;
    }
    while(sushu(j)!=true)
    {
        j++;
    }
    cout<<(j-i);
    return 0;
}

bool sushu(long long int num)
{
    if (num==2)return true;
    if(num%2==0)return false;

    long long int i;
    for(i=3;i<=sqrt(num);++i){
        if(num%i==0)return false;
    }
    return true;
}
