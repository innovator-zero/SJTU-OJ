#include <iostream>

using namespace std;

struct mouse
{
    int p,s,no;
};

int n,r;
mouse x[200000];

void QuickSort(int start, int last);

void Sort();

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int i,j;
    cin>>n>>r;
    n*=2;
    for(i=0; i<n; ++i)
    {
        cin>>x[i].p;
        x[i].no=i+1;
    }
    for(i=0; i<n; ++i)
    {
        cin>>x[i].s;
    }

    for(j=0; j<r; ++j)
    {
        Sort();

        for(i=0; i<=n-2; i+=2)
        {
            if(x[i].s>x[i+1].s)
                x[i].p+=2;
            else if(x[i].s<x[i+1].s)
                x[i+1].p+=2;
            else
            {
                x[i].p++;
                x[i+1].p++;
            }
        }
    }
    Sort();
    for(i=0; i<n; ++i)
    {
        cout<<x[i].no<<" ";
    }

    return 0;
}

void QuickSort(int start, int last)
{
    int i = start;
    int j = last;
    int temp = x[i].p;
    mouse tmp=x[i];
    if (i < j)
    {
        while (i < j)
        {
            while (i < j &&  x[j].p<temp )
                j--;
            if (i < j)
            {
                x[i] = x[j];
                i++;
            }

            while (i < j && temp <= x[i].p)
                i++;
            if (i < j)
            {
                x[j] = x[i];
                j--;
            }
        }

        x[i] = tmp;

        QuickSort(start, i - 1);
        QuickSort(i + 1, last);
    }
}

void Sort()
{
    int i,j,e,q,num;
    QuickSort(0,n-1);


    for(i=0; i<n; ++i)
    {
        if(x[i].p==x[i+1].p)
        {
            j=i;
            while(x[j].p==x[j+1].p&&j<n-1)
            {
                j++;
            }

            bool flag;
            mouse tmp;
            num=j-i+1;
            for(e=1; e<num; ++e)
            {
                flag=false;
                for(q=0; q<num-e; ++q)
                {
                    if(x[q+i].no>x[q+1+i].no)
                    {
                        tmp=x[q+i];
                        x[q+i]=x[q+1+i];
                        x[q+1+i]=tmp;
                        flag=true;
                    }
                }
                if(!flag)
                    break;
            }

            i=j;
        }
    }
}

