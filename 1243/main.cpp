#include <iostream>
#include <iomanip>

using namespace std;

int n,m;
int score[1005];

int main()
{
    int opt,l,r,M;
    double sum;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>score[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>opt>>l>>r;
        switch(opt)
        {
        case 0:
            sum=0;
            for(int j=l;j<=r;j++)
            {
                sum+=score[j];
            }
            sum/=(r-l+1);
            cout<<fixed<<setprecision(2)<<sum<<'\n';
            break;
        case 1:
            M=score[l];
            for(int j=l+1;j<=r;j++)
            {
                if(score[j]>M)M=score[j];
            }
            cout<<M<<'\n';
            break;
        case 2:
            for(int j=0;j<=(r-l)/2;j++)
            {
                int tmp=score[l+j];
                score[l+j]=score[r-j];
                score[r-j]=tmp;
            }
            break;
        case 3:
            for(int j=l;j<=r;j++)
            {
                cout<<score[j]<<" ";
            }
            cout<<'\n';
            break;
        case 4:
            for(int j=l;j<=r;j++)
            {
                if(score[j]>0)score[j]--;
            }
        }
    }
    return 0;
}
