#include <iostream>

using namespace std;

int main()
{
    int month,num,day,year1,year2,d;
    cin>>month>>num>>day>>year1>>year2;

    int i,j,sum=0,day0,x,k;

    for(k=year1; k<=year2; ++k)
    {
        sum=0;
        for(i=1850; i<k; ++i)
        {
            if((i%4==0&&i%100!=0)||i%400==0)
                sum+=366;
            else
                sum+=365;
        }

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
                if((k%4==0&&k%100!=0)||k%400==0)
                    sum++;
                break;
            default:
                sum+=31;
            }
        }
        day0=(sum%7+2)%7;//该月1日星期几

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
            if((k%4==0&&k%100!=0)||k%400==0)
                x++;
            break;
        default:
            x=31;
        }

        if(d<=x)
        {
            cout<<k<<"/";
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
