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
        }while(num%i==0);//���������ͬ������
    }
    if(num!=1)cout<<num;//������ʣ�µ�

    return 0;
}
