#include <iostream>

using namespace std;

int main()
{
    int a,b,i,n,j,k,sum,s,q;
    bool flag;
    int c[5];
    cin>>a>>b;

    if (a<=0||a>=100000||b<=0||b>=100000||a>b){cout<<"error";return 0;}
    flag=false;
    for(i=a;i<=b;i++){
        n=1;
        k=i;

        for(j=1;j>0;++j){
            if (k/10>=1) n++;
            k/=10;
            if (k==0) break;
        }//�ж�λ��

        k=i;
        sum=0;
        for (j=0;j<n;++j){
            c[j]=k%10;//ȡÿһλ����
            k/=10;
            s=1;
            for(q=1;q<=n;q++)
            {
                s*=c[j];//��ÿ�����ֵ�n�η�
            }
            sum+=s;//������
        }
        if (sum==i) {cout<<sum<<endl;flag=true;}//���ھ����

    }
    if (flag==false) {cout<<"no";}//������
    return 0;
}
