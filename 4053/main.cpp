#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int);
void arrange(int);

int n,a[16];
bool flag=false;
int main()
{
    cin>>n;
    int i;
    if(n%2==0)
    {
        for(i=0; i<n; ++i)
        {
            a[i]=i+1;
        }
        arrange(1);
    }

    if(!flag)
        cout<<"None";
    return 0;
}

bool isprime(int x)
{
    int i;
    for(i=2; i<=sqrt(x); ++i)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

void arrange(int begin)
{
    int i;
    if(begin==n)
    {
        if(isprime(a[n-1]+a[0])&&isprime(a[n-1]+a[n-2]))
        {
            flag=true;
            for(i=0; i<n; ++i)
            {
                cout<<a[i]<<" ";
            }
            cout<<'\n';
        }
        return;
    }
    else if(begin>1&&!isprime(a[begin-1]+a[begin-2]))
    {
        return;
    }
    else
    {
        for(i=begin; i<n; i++)
        {
            swap(a[begin],a[i]);
            arrange(begin+1);
            swap(a[begin],a[i]);
        }
    }

}
