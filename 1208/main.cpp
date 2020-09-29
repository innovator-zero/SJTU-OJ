#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double r,a,t,s,m=0;
int main()
{
    while(cin>>r>>a)
    {
        t=acos(a/r);
        s=t*r*r-a*r*sin(t);
        if(s>m)m=s;
    }

    cout <<fixed<<setprecision(2)<<m<< endl;
    return 0;
}
