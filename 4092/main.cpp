#include <iostream>

using namespace std;

class matrix
{
    friend istream& operator>>(istream & is,matrix &obj);
    friend ostream& operator<<(ostream & os,const matrix &obj);
private:
    double **a;
    int row,col;
public:
    matrix(int r,int c);
    ~matrix();
    double table(int i,int j){return a[i][j];};
    matrix & operator+=(const matrix & obj);
    matrix & operator*=(const matrix & obj);
    matrix & operator=(const matrix &obj);
};

int main()
{
    int row1,col1,row2,col2;
    cin>>row1>>col1;
    matrix table1(row1,col1);
    cin>>table1;
    cin>>row2>>col2;
    matrix table2(row2,col2);
    cin>>table2;

    cout<<table1.table(row1/2,col1/2)<<endl<<endl;

    table1 *= table2;
    cout<<endl;
    table1 += table2;
    cout<<endl;
    table1 = table2;
    cout<<table1;

    return 0;
}

matrix::matrix(int r ,int c){
    int i;
    row=r;col=c;
    a=new double *[row];
    for(i=0;i<row;++i){
        a[i]=new double [col];
    }
}

matrix::~matrix(){
    int i;
    for(i=0;i<row;++i){
        delete []a[i];
    }
    delete []a;
}

istream& operator>>(istream & is,matrix &obj){
    int i,j;
    for(i=0;i<obj.row;++i){
        for(j=0;j<obj.col;++j){
            is>>obj.a[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream & os,const matrix &obj){
    int i,j;
    for(i=0;i<obj.row;++i){
        for(j=0;j<obj.col;++j){
            os<<obj.a[i][j]<<" ";
        }
        os<<endl;
    }
    return os;
}

matrix & matrix::operator+=(const matrix & obj){
    if (row!=obj.row||col!=obj.col){cout<<"ERROR!"<<endl;return *this;}
    int i,j;
    for(i=0;i<row;++i){
        for(j=0;j<col;++j){
            a[i][j]+=obj.a[i][j];
        }
    }
    cout<<*this;
    return *this;
}

matrix & matrix::operator*=(const matrix & obj){
    if(col!=obj.row){cout<<"ERROR!"<<endl;return *this;}
    int i,j,k;
    double sum;

    matrix tmp(0,0);
    tmp=*this;
    for(i=0;i<row;++i){
        delete []a[i];
    }
    delete []a;

    col=obj.col;
    a=new double *[row];
    for(i=0;i<row;++i){
        a[i]=new double [col];
    }

    for(i=0;i<row;++i){
        for(j=0;j<col;++j){
            sum=0;
            for(k=0;k<tmp.col;k++){
                sum+=tmp.a[i][k]*obj.a[k][j];
            }
        a[i][j]=sum;
        }
    }
    cout<<*this;
    return *this;
}

matrix & matrix::operator=(const matrix &obj){
    int i,j;
    for(i=0;i<row;++i){
        delete []a[i];
    }
    delete []a;

    row=obj.row;
    col=obj.col;
    a=new double *[row];
    for(i=0;i<row;++i){
        a[i]=new double [col];
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            a[i][j]=obj.a[i][j];
        }
    }
    return *this;
}
