#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int n,score;
double gpa=0;

int main()
{
    int i;
    scanf("%d",&n);

    for(i=0;i<n;++i)
    {
        scanf("%d",&score);
        if(score>=95)
            gpa+=4.3;
        else if(score>=90)
            gpa+=4.0;
        else if(score>=85)
            gpa+=3.7;
        else if(score>=80)
            gpa+=3.3;
        else if(score>=75)
            gpa+=3.0;
        else if(score>=70)
            gpa+=2.7;
        else if(score>=67)
            gpa+=2.3;
        else if(score>=65)
            gpa+=2.0;
        else if(score>=62)
            gpa+=1.7;
        else gpa+=1.0;
    }
    gpa/=n;
    cout<<fixed<<setprecision(2)<<gpa;
    return 0;
}
