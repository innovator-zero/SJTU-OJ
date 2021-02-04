#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

long long int pow10(int);

long long int weihuiwen(char *);

char l[20],r[20];
int ll;

int main()
{
    cin>>l>>r;

    long long int ans;

    ll=strlen(l);

    ans=weihuiwen(r)-weihuiwen(l);
    if(l[0]==l[ll-1])
        ans++;

    cout << ans;
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

long long int weihuiwen(char *s)
{
    int l,i,ini;
    long long int sum=0,powi,k,midnum=1;
    l=strlen(s);
    powi=pow10(l-1);
    ini=s[0]-'0';

    if(l==1)
    {
        sum=ini;
    }
    else
    {
        for(i=1; i<l; i++)
        {
            sum+=9*pow10(i-2);
        }
        sum+=(ini-1)*powi/10;

        k=powi/100;
        for(i=1; i<l-1; i++)
        {
            midnum+=(s[i]-'0')*k;
            k/=10;
        }
        sum+=midnum;
        if(s[l-1]<s[0])
            sum--;
    }
    return sum;
}
