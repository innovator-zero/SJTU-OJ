#include <iostream>

using namespace std;

int main()
{
    int a,b,i,n,j,k,sum;
    bool flag;
    cin>>a>>b;

    if (a<=0||b<=0||a>b){cout<<"error";return 0;}
    flag=false;
    for(i=a;i<=b;i++){
        n=1;
        k=i;

        for(j=1;j>0;++j){
            if (k/10>=1) n++;
            k/=10;
            if (k==0) break;
        }//�ж�λ��

        int c[10];
        k=i;
        sum=0;
        for (j=0;j<n;++j){
            c[j]=k%10;//ȡÿһλ������
            k/=10;
            sum+=c[j]*c[j]*c[j];//������������
        }
        if (sum==i) {cout<<sum<<endl;flag=true;}//�ҵ��˾����

    }
    if (flag==false) {cout<<"no";}//û�ҵ�
    return 0;
}
