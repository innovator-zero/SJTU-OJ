#include <iostream>

using namespace std;

long long squ(long long int,long long int);
long long x,y;

int main()
{
    cin>>x>>y;

    cout<<squ(x,y);
    return 0;
}

long long squ(long long int a,long long int b)
{
    long long sum=0;
    if(a==b){sum+=a*4;}
    else if(a>b){sum+=b*4+squ(a-b,b);}
    else{sum+=a*4+squ(a,b-a);}

    return sum;
}
