#include <iostream>

using namespace std;

int t,n[10],m[10],num[10][100000],sum[100000],cou;

void QuickSort(int array[], int start, int last);

int main()
{
    int i,j,k;

    cin>>t;
    for(i=0;i<t;++i)
    {
        cin>>n[i]>>m[i];
        for(j=0;j<n[i];++j)
        {
            cin>>num[i][j];
        }
    }
    for(i=0;i<n[i];++i)
    {
        cou=0;
        sum[0]=num[i][0];
        for(j=1;j<n[i];++j)
        {
            sum[j]=(sum[j-1]+num[i][j])%m[i];
            if(sum[j]==0)cou++;
        }
        QuickSort(sum,0,n[i]-1);
        for(j=0;j<n[i];++j)
        {
            if(sum[j]==sum[j+1])
            {
                k=j+1;
                while(sum[k]==sum[k+1])k++;
                cou+=(k-j+1)*(k-j)/2;
                j=k;
            }
        }
        cout<<cou<<'\n';
    }
    return 0;
}

void QuickSort(int array[], int start, int last)
{
    int i = start;
    int j = last;
    int temp = array[i];
    if (i < j)
    {
        while (i < j)
        {
            while (i < j &&  array[j]>=temp )
                j--;
            if (i < j)
            {
                array[i] = array[j];
                i++;
            }

            while (i < j && temp > array[i])
                i++;
            if (i < j)
            {
                array[j] = array[i];
                j--;
            }
        }

        array[i] = temp;

        QuickSort(array, start, i - 1);
        QuickSort(array, i + 1, last);
    }
}
