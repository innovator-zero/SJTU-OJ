#include<iostream>
#include<cstdio>

using namespace std;

const int N=100005;

int a[N],b[N]; //b为辅助数组
long long cnt=0;

void merge_sort(int l, int r)
{
    if(r-l > 0)//如果整个区间中元素个数大于1，则继续分割
    {
        int mid = (l+r) / 2 ;
        int i = l; //辅助数组的下标
        int p = l, q = mid+1;
        merge_sort(l, mid);
        merge_sort(mid+1, r);

        while(p<=mid || q<=r)//左右两部分只要有一部分不为空
        {
            if(q>r || (p<=mid && a[p]<=a[q]))//从左半数组复制到辅助数组
                b[i++] = a[p++];
            else
            {
                b[i++] = a[q++];
                cnt += mid -p +1;//将逆序对的个数累加起来
            }
        }
        for(i = l ; i <= r; i++)//将b中排好序的元素复制到a中
            a[i] = b[i];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n; i ++)
        scanf("%d",&a[i]);
    merge_sort(1, n);
    printf("%lld\n",cnt);
    return 0;
}
