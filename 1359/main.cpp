#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[1001];
    int sum=0,i;
    cin.getline(str,1000);
    for(i=0;i<strlen(str);++i)
    {
        if(str[i]>='A'&&str[i]<='Z')sum+=(str[i]-'A'+1)*(i+1);
        if(str[i]>='a'&&str[i]<='z')sum+=(str[i]-'a'+27)*(i+1);
    }
    cout<<sum;
    return 0;
}
