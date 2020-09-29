#include <iostream>
#include <stdio.h>

using namespace std;

int n,m;
char a[1240][1240];

int sumimalRectangleDP()
{
    int left[1240]= {0},right[1240],height[1240]= {0};
    int sum=0,i,j,leftBound,rightBound;

    for(i=0; i<1240; ++i)
    {
        right[i]=m;
    }
    for(i=0; i<n; i++)
    {
        leftBound=0;
        rightBound=m;
        for(j=0; j<m; j++)
        {
            if(a[i][j]=='-')
            {
                height[j]++;
            }
            else
            {
                height[j] = 0;
            }
        }

        for(j=0; j<m; j++)
        {
            if (a[i][j]=='-')
            {
                left[j]=max(left[j], leftBound);
            }
            else
            {
                left[j] = 0;
                leftBound = j + 1;
            }
        }

        for(j=m-1; j>=0; j--)
        {
            if(a[i][j]=='-')
            {
                right[j]=min(right[j],rightBound);
            }
            else
            {
                rightBound = j;
            }
        }

        for (j=0; j<m; j++)
        {
            if(height[j]>=1&&(right[j]-left[j])>=2*height[j])
                sum=max(height[j]*height[j]*2, sum);
        }
    }
    return sum;
}


int main()
{
    int i;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; i++)
    {
        scanf("%s",a[i]);
    }
    printf("%d",sumimalRectangleDP());
    return 0;
}
