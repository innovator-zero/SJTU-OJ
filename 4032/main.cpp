#include <iostream>

using namespace std;

int main()
{
    double a,b,c,tmp;//数字可以带小数

    cin>>a>>b>>c;

    if(a<b){tmp=a;a=b;b=tmp;}//把三个数字按大小排序
    if(a<c){tmp=a;a=c;c=tmp;}

    if(a<=0||b<=0||c<=0){cout<<"-1";}//不是三角形
    else if(b+c>a)
            if (a*a==b*b+c*c) cout<<"1";//直角三角形
            else cout<<"0";//普通三角形
          else cout<<"-1";//不是三角形

    return 0;
}
