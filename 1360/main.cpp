#include <iostream>

using namespace std;

struct pro
{
    int st,en;
};
void QuickSort(pro array[], int start, int last);

int n;
pro x[100000];

int main()
{
    int i,j,sum=1;
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>x[i].st>>x[i].en;
    }

    QuickSort(x,0,n-1);

    i=0;
    for(j=1;j<n;++j)
    {
        if(x[j].st>=x[i].en){
            i=j;
            sum++;
        }
    }

    cout<<sum;
    return 0;
}

void QuickSort(pro array[], int start, int last)
{
    int i = start;
    int j = last;
    int temp = array[i].en;
    pro tmp=array[i];
    if (i < j)
    {
        while (i < j)
        {
            while (i < j &&  array[j].en>=temp )
                j--;
            if (i < j)
            {
                array[i] = array[j];
                i++;
            }

            while (i < j && temp > array[i].en)
                i++;
            if (i < j)
            {
                array[j] = array[i];
                j--;
            }
        }

        array[i]= tmp;
        QuickSort(array, start, i - 1);
        QuickSort(array, i + 1, last);
    }
}
