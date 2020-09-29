#include <iostream>

using namespace std;

void QuickSort(long long int array[], int start, int last);

int main()
{
    int n,i;
    long long int a[100000],b[100000];
    long long int sum=0;

    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>a[i];
    }
    for(i=0; i<n; ++i)
    {
        cin>>b[i];
    }

    QuickSort(a,0,n-1);
    QuickSort(b,0,n-1);
    for(i=0; i<n; ++i)
    {
        sum+=a[i]*b[i];
    }
    cout<<sum<<" ";

    sum=0;

    for(i=0; i<n; ++i)
    {
        sum+=a[i]*b[n-i-1];
    }

    cout<<sum;
    return 0;
}

void QuickSort(long long int array[], int start, int last)
{
    int i = start;
    int j = last;
    long long int temp = array[i];
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

