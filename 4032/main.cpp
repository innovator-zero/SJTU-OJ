#include <iostream>

using namespace std;

int main()
{
    double a,b,c,tmp;//���ֿ��Դ�С��

    cin>>a>>b>>c;

    if(a<b){tmp=a;a=b;b=tmp;}//���������ְ���С����
    if(a<c){tmp=a;a=c;c=tmp;}

    if(a<=0||b<=0||c<=0){cout<<"-1";}//����������
    else if(b+c>a)
            if (a*a==b*b+c*c) cout<<"1";//ֱ��������
            else cout<<"0";//��ͨ������
          else cout<<"-1";//����������

    return 0;
}
