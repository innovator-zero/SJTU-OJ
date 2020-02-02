#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define N 10005
struct node{
    char name[35];
    int price;
    node(){
        price=0;
    }
};
int p[N];
vector<node>List[N];
unsigned int BKDRHash(char *str){
    unsigned int seed = 31,key = 0;
    while(*str){
        key=key*seed+*str++;
    }
    return key&0x7fffffff;
}
int main(){
    int n,m,k,add,memory_price,tot,len;
    char s[35];
    node t;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<N;i++){
            List[i].clear();
        }
        for(int i=0;i<n;i++){
            scanf("%s",t.name);
            k=BKDRHash(t.name)%N;
            List[k].push_back(t);
        }
        scanf("%d",&m);
        while(m--){
            tot=len=0;
            for(int i=0;i<n;i++){
                scanf("%d%s",&add,s);
                k=BKDRHash(s)%N;
                for(int j=0;j<List[k].size();j++){
                    if(strcmp(List[k][j].name,s)==0){

                        List[k][j].price+=add;
                        if(strcmp(s,"memory")==0)
                            memory_price=List[k][j].price;
                        else
                            p[len++]=List[k][j].price;
                        break;
                    }
                }
            }
            for(int i=0;i<len;i++){
                if(memory_price<p[i]) tot++;
            }
            printf("%d\n",tot+1);
        }
    }
    return 0;
}
