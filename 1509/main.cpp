#include <iostream>

using namespace std;

int main()
{
    int month,num,day,year1,year2,d;
    cin>>month>>num>>day>>year1>>year2;

    int i,j,sum=0,day0,x;
    for(i=1850; i<year1; ++i)
    {
        if((i%4==0&&i%100!=0)||i%400==0)
            sum+=366;
        else
            sum+=365;
    }
    day0=sum%7+2;//year1的1月1日星期几

    sum=0;
    for(j=1; j<month; ++j)
    {
        switch (j)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            sum+=30;
            break;
        case 2:
            sum+=28;
            if((year1%4==0&&year1%100!=0)||year1%400==0)
                sum++;
            break;
        default:
            sum+=31;
        }
    }
    day0=(day0+sum%7)%7;//该月1日星期几
    if (day0 == 0) day0 = 7;
    if(day0<=day)
        d=(num-1)*7+day-day0+1;
    else
        d=num*7+day-day0+1;


    switch (month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        x=30;
        break;
    case 2:
        x=28;
        if((year1%4==0&&year1%100!=0)||year1%400==0)
            x++;
        break;
    default:
        x=31;
    }

    if(d<=x)
    {
        cout<<year1<<"/";
        if(month<10)
            cout<<"0";
        cout<<month<<"/";
        if(d<10)
            cout<<"0";
        cout<<d<<endl;
    }
    else
        cout<<"none"<<endl;

    for(i=year1+1; i<=year2; ++i)
    {
        if (month<=2)
        {
            if(((i-1)%4==0&&(i-1)%100!=0)||(i-1)%400==0)
                sum=366;
            else
                sum=365;
        }
        else
        {
            if((i%4==0&&i%100!=0)||i%400==0)
                sum=366;
            else
                sum=365;
        }
        day0=(day0+sum%7)%7;
        if (day0 == 0) day0 = 7;
        if(day0<=day)
            d=(num-1)*7+day-day0+1;
        else
            d=num*7+day-day0+1;

        switch (month)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            x=30;
            break;
        case 2:
            x=28;
            if((i%4==0&&i%100!=0)||i%400==0)
                x++;
            break;
        default:
            x=31;
        }

        if(d<=x)
        {
            cout<<i<<"/";
            if(month<10)
                cout<<"0";
            cout<<month<<"/";
            if(d<10)
                cout<<"0";
            cout<<d<<endl;
        }
        else
            cout<<"none"<<endl;
    }

    return 0;
}
