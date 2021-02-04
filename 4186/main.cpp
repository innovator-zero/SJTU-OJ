#include <iostream>
#include <cstring>
using namespace std;

int sublen,srclen,dstlen;

void change(char* strdst,char *strsrc,char*strsub);

int main()
{
    char dst[150],src[50],sub[10];


    cin>>dst>>sub>>src;
    srclen=strlen(src);
    sublen=strlen(sub);
    dstlen=strlen(dst);
    change(dst,src,sub);

    return 0;
}
void change(char* strdst,char *strsrc,char*strsub)
{
    int i,j,m,n;
    bool flag,subflag,wfind=false;
    char *p;
    char strx[150];

    for (i=0; strdst[i]!='\0'; ++i)
    {
        flag=true;
        for(j=0; strsub[j]!='\0'; ++j)//找sub
        {
            if(strdst[i+j]!=strsub[j])
            {
                flag=false;break;

            }
        }
        if(!flag){continue;}
        else {wfind=true;}


        if(wfind){
        if(srclen==sublen){
            for(m=0;m<srclen;++m){
                if (strsrc[m]!=strsub[m])break;
            }
            if(m==srclen){cout<<"error!";return;}
        }
        else {for(m=0;strsrc[m]!='\0';++m){
            subflag=true;
            for(n=0;strsub[n]!='\0';++n){
                if(strsrc[m+n]!=strsub[n]){
                    subflag=false;break;
                }
            if(!subflag)continue;
            else{cout<<"error!";return;}
            }
        }
        }
        p=&strdst[i];//移动位置
        while(*p!='\0')
        {
            *p=*(p+sublen);
            p++;
        }
        strcpy(strx,strdst);

        p=&strdst[i];

        for(j=0;j<dstlen-i-sublen;++j){
            *(p+srclen+j)=strx[i+j];
        }
        *(p+srclen+j)='\0';
        p=&strdst[i];
        for(j=0; strsrc[j]!='\0'; ++j) //传进去src
        {
            *(p+j)=strsrc[j];
        }
        p=strdst;
    }
    }
    if(!wfind)cout<<"No string to replace!";
    else cout<<p;
}
