#include <iostream>

using namespace std;

int main()
{
    int year,month,day,i;
    int sum=0;
    int m[13];//�·ݵ�����

    for (i=1;i<=12;++i){
        switch(i){
        case 1:case 3:case 5:case 7:case 8:case 10:case 12: m[i]=31;break;
        default :m[i]=30;}
    }

    cin>>year>>month>>day;

    if (year<0||year>9999||month<0||month>12||day<0){cout<<"error";return 0;}

    if ((year%4==0&&year%100!=0)||year%400==0)m[2]=29;//�ж��Ƿ�����Ͷ��µ�����
    else m[2]=28;


    if(day>m[month]){cout<<"error";return 0;}//���ڵ��������ܳ������µ�����


    for(i=1;i<month;++i){
        sum+=m[i];
    }
    sum+=day;
    cout<<sum;
    return 0;
}
