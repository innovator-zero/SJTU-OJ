#include<iostream>
#include<cstdio>

using namespace std;

const int N=100005;

int a[N],b[N]; //bΪ��������
long long cnt=0;

void merge_sort(int l, int r)
{
    if(r-l > 0)//�������������Ԫ�ظ�������1��������ָ�
    {
        int mid = (l+r) / 2 ;
        int i = l; //����������±�
        int p = l, q = mid+1;
        merge_sort(l, mid);
        merge_sort(mid+1, r);

        while(p<=mid || q<=r)//����������ֻҪ��һ���ֲ�Ϊ��
        {
            if(q>r || (p<=mid && a[p]<=a[q]))//��������鸴�Ƶ���������
                b[i++] = a[p++];
            else
            {
                b[i++] = a[q++];
                cnt += mid -p +1;//������Եĸ����ۼ�����
            }
        }
        for(i = l ; i <= r; i++)//��b���ź����Ԫ�ظ��Ƶ�a��
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
