#include <iostream>
#include <cstring>
using namespace std;

struct scoreT{
    char name[20];
    int chinese;
    int math;
    int english;
};

int main()
{
    scoreT *score;
    int *total;
    int n,i,k,j;
    bool flag;
    scoreT tmp;
    cin>>n;

    score=new scoreT[n];
    total=new int[n];
    for(i=0;i<n;++i){
        cin>>score[i].name>>score[i].chinese>>score[i].math>>score[i].english;
        total[i]=score[i].chinese+score[i].math+score[i].english;
    }
    cin>>k;
    for (i=1;i<n;i++){
        flag=false;
        for(j=0;j<n-i;j++){
            if(total[j]<total[j+1]){tmp=score[j];score[j]=score[j+1];score[j+1]=tmp;flag=true;}
            else if (total[j]==total[j+1]){
                if(score[j].chinese<score[j+1].chinese){tmp=score[j];score[j]=score[j+1];score[j+1]=tmp;flag=true;}
                else if (score[j].chinese==score[j+1].chinese){
                    if(score[j].math<score[j+1].math){tmp=score[j];score[j]=score[j+1];score[j+1]=tmp;flag=true;}
                    else if(score[j].math==score[j+1].math){
                        if(strcmp(score[j].name,score[j+1].name)>0){tmp=score[j];score[j]=score[j+1];score[j+1]=tmp;flag=true;}
                    }
                }
            }
        }

        if(!flag)break;
}

    cout<<score[k-1].name<<" "<<score[k-1].chinese+score[k-1].math+score[k-1].english;



    delete []score;
    delete []total;
    return 0;
}
