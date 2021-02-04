#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num,i;

    cin>>num;

    for(i=2;i<(num/2);++i){
        do {
                if (num%i==0) {cout<<i<<" ";num/=i;}
        }while(num%i==0);//输出所有相同的因数
    }
    if(num!=1)cout<<num;//输出最后剩下的

    return 0;
}
