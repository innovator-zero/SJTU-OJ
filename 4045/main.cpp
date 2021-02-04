#include <iostream>
#include <stdio.h>

using namespace std;

struct Read
{
    int left,right,read;
};

int n,m,p[10000],tmp[10000];
Read s[10000];

void QuickSort(int start, int last);

int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; ++i)
    {
        scanf("%d",&tmp[i]);
    }

    for(i=0; i<m; ++i)
    {
        scanf("%d %d %d",&s[i].left,&s[i].right,&s[i].read);
    }
    for(i=0; i<m; ++i)
    {
        for(j=0;j<n;++j)
        {
            p[j]=tmp[j];
        }
        k=p[s[i].read-1];
        QuickSort(s[i].left-1,s[i].right-1);
        if(p[s[i].read-1]==k)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

void QuickSort(int start, int last)
{
    int i=start;
    int j=last;
    int temp=p[i];
    if (i<j)
    {
        while(i<j)
        {
            while(i<j&&p[j]>=temp)
                j--;
            if(i<j)
            {
                p[i]=p[j];
                i++;
            }
            while (i<j&&temp>p[i])
                i++;
            if (i<j)
            {
                p[j]=p[i];
                j--;
            }
        }
        p[i] = temp;
        QuickSort(start, i - 1);
        QuickSort(i + 1, last);
    }
}
