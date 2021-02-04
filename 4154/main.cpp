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
        }//判定位数

        k=i;
        sum=0;
        for (j=0;j<n;++j){
            c[j]=k%10;//取每一位数字
            k/=10;
            s=1;
            for(q=1;q<=n;q++)
            {
                s*=c[j];//算每个数字的n次方
            }
            sum+=s;//加起来
        }
        if (sum==i) {cout<<sum<<endl;flag=true;}//存在就输出

    }
    if (flag==false) {cout<<"no";}//不存在
    return 0;
}
