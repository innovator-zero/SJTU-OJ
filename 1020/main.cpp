#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long int num,i,k;
    bool flag;

    cin>>num;
    cout<<num<<"=";

    for(i=2; i<=sqrt(num); ++i)
    {
        k=0;
        flag=false;
        do
        {
            if (num%i==0)
            {
                flag=true;
                num/=i;
                k++;
            }
        }
        while(num%i==0); //输出所有相同的因数
        if(flag)
            cout<<i<<"("<<k<<")";
    }
    if(num!=1)
        cout<<num<<"(1)";//输出最后剩下的

    return 0;
}

