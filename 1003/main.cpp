#include <iostream>

using namespace std;

int l,a[100][100];
bool b[100][100];

int main()
{
    int i,j,m=0;
    bool flag=true;
    cin>>l;
    for(i=0; i<l; ++i)
    {
        for(j=0; j<l; ++j)
        {
            cin>>a[i][j];
            if (a[i][j]==1)
                b[i][j]=1;
            else
                b[i][j]=0;
        }
    }

    for(i=0; i<l; ++i)
    {
        for(j=0; j<l; ++j)
        {
            if (a[i][j]==0)
            {
                flag=false;
                break;
            }
        }
    }

    while(!flag)
    {
        for(i=0; i<l; ++i)
        {
            for(j=0; j<l; ++j)
            {
                if (a[i][j]==1)
                {
                    b[i][j]=1;
                }
            }
        }

        for(i=0; i<l; ++i)
        {
            for(j=0; j<l; ++j)
            {
                if (a[i][j]==1&&b[i][j]==1)
                {
                    if(j-1>=0&&a[i][j-1]!=2)
                        a[i][j-1]=1;
                    if(j+1<l&&a[i][j+1]!=2)
                        a[i][j+1]=1;
                    if(i-1>=0&&a[i-1][j]!=2)
                        a[i-1][j]=1;
                    if(i+1<l&&a[i+1][j]!=2)
                        a[i+1][j]=1;
                }

            }
        }
        m++;

        flag=true;

        for(i=0; i<l; ++i)
        {
            for(j=0; j<l; ++j)
            {
                if (a[i][j]==0)
                {
                    flag=false;
                    break;
                }
            }
        }

    }
    cout<<m;
    return 0;
}
