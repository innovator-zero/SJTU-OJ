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
        while(num%i==0); //���������ͬ������
        if(flag)
            cout<<i<<"("<<k<<")";
    }
    if(num!=1)
        cout<<num<<"(1)";//������ʣ�µ�

    return 0;
}

