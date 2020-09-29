#include <iostream>

using namespace std;

int n,x,y;
long long sum1=-1,sum2=-1;

bool taki(int);
bool mitsaha(int);

int main()
{
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    cin>>n>>y>>x;
    y=n+1-y;
    int m=1,p=n;
    while(!taki(m))
    {
        m++;
    }
    while(!mitsaha(p))
    {
        p--;
    }
    cout<<sum1<<" "<<sum2;
    return 0;
}

bool taki(int a1)
{
    int i,j;
    i=a1;

    for(j=a1;j<=n-a1+1;++j){\
        sum1++;
        if(i==x&&j==y){return true;}
    }
    j--;
    for(i=a1+1;i<=n-a1+1;++i){
        sum1++;
        if(i==x&&j==y){return true;}
    }
    i--;
    for(j=n-a1;j>=a1;--j){
        sum1++;
        if(i==x&&j==y){return true;}
    }
    ++j;
    for(i=n-a1;i>=a1+1;--i){
        sum1++;
        if(i==x&&j==y){return true;}
    }
    ++i;
    return false;
}

bool mitsaha(int a1)
{
    int i,j;
    i=a1;

    for(j=a1;j>=n-a1+1;--j){
        sum2++;
        if(i==x&&j==y){return true;}
    }
    j++;
    for(i=a1-1;i>=n-a1+1;--i){
        sum2++;
        if(i==x&&j==y){return true;}
    }
    i++;
    for(j=n-a1+2;j<=a1;++j){
        sum2++;
        if(i==x&&j==y){return true;}
    }
    --j;
    for(i=n-a1+2;i<=a1-1;++i){
        sum2++;
        if(i==x&&j==y){return true;}
    }
    --i;
    return false;
}
