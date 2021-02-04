#include <iostream>
#include <cmath>

using namespace std;

long long int l,r,sum=0;

long long int pow10(int);

int main()
{
    int i=0,j=0,k;
    long long int powi,powj,midnuml,midnumr;
    cin>>l>>r;
    while(l/pow10(i)>=1)
    {
        i++;
    }//pow10 large than l
    while(r/pow10(j)>=10)
    {
        j++;
    }//pow10 small than r
    powi=pow10(i-1);
    powj=pow10(j);

    if(i<=2)
        midnuml=1;
    else
        midnuml=(l-l/powi*powi)/10+1;

    if(j<=1)
        midnumr=1;
    else
        midnumr=(r-(r/powj)*powj)/10+1;//取中间的数+1

    if(i<=j)
    {
        for(k=i; k<j; ++k)
        {
            if(k==1)
                sum+=9;
            else
                sum+=pow10(k-1)*9;
        }//pow(10,i)`pow(10,j)中的个数

        if(powi==1)
            sum+=10-l;//l是个位数
        else if(l%10<=l/powi)
            sum+=(9-(l/powi)+1)*powi/10-midnuml+1;
        else
            sum+=(9-(l/powi)+1)*powi/10-midnuml;//从l到pow(10,i)中的个数


        sum+=(r/powj-1)*powj/10;//从powj到r最近的倍数
        if(r%10>=l/powi)
            sum+=midnumr;
        else
            sum+=midnumr-1;//到r

    }
    else//如果l和r位数相同
    {
        if(j==0)//都是个位数
        {
            sum+=r-l+1;
        }
        else
        {
            sum+=(r/powj-l/powj-1)*powj/10;//中间的powi的倍数

            if(l%10<=l/powi)
                sum+=powi/10-midnuml+1;
            else
                sum+=powi/10-midnuml;


            if(r%10>=l/powi)
                sum+=midnumr;
            else
                sum+=midnumr-1;
        }
    }
    cout << sum;
    return 0;
}

long long int pow10(int x)
{
    long long int m=1;
    int i;
    for(i=1; i<=x; i++)
    {
        m*=10;
    }
    return m;
}

