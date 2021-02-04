#include <iostream>

using namespace std;

int n;
int w[100000][3];
long long sum[100000][3][2],num;
void TREE(int);

int main()
{
    cin>>n;
    int i,j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<3;++j)
        {
            cin>>w[i][j];
        }
    }
    sum[0][0][0]=w[0][0];
    sum[0][1][0]=0;
    sum[0][1][1]=0;
    sum[0][2][1]=0;
    for(i=1;i<n;++i)
    {
        TREE(i);
    }
    num=max(sum[n-1][1][1],sum[n-1][2][1]);

    sum[0][0][0]=0;
    sum[0][1][0]=w[0][1];
    sum[0][1][1]=0;
    sum[0][2][1]=0;
    for(i=1;i<n;++i)
    {
        TREE(i);
    }
    if(sum[n-1][2][1]>num) num=sum[n-1][2][1];

    sum[0][0][0]=0;
    sum[0][1][0]=0;
    sum[0][1][1]=w[0][1];
    sum[0][2][1]=0;
    for(i=1;i<n;++i)
    {
        TREE(i);
    }
    if(sum[n-1][0][0]>num) num=sum[n-1][0][0];

    sum[0][0][0]=0;
    sum[0][1][0]=0;
    sum[0][1][1]=0;
    sum[0][2][1]=w[0][2];
    for(i=1;i<n;++i)
    {
        TREE(i);
    }
    if(max(sum[n-1][0][0],sum[n-1][1][0])>num) num=max(sum[n-1][0][0],sum[n-1][1][0]);

    cout<<num;
    return 0;
}

void TREE(int i)
{
    sum[i][0][0]=max(sum[i-1][1][1],sum[i-1][2][1])+w[i][0];
    sum[i][1][0]=sum[i-1][2][1]+w[i][1];
    sum[i][1][1]=sum[i-1][0][0]+w[i][1];
    sum[i][2][1]=max(sum[i-1][0][0],sum[i-1][1][0])+w[i][2];
}
