#include <iostream>
#include <iomanip>
using namespace std;

class Complex
{
    friend ostream &operator<<(ostream &,const Complex &);
    friend istream &operator>>(istream &,Complex &);
    friend Complex operator+(const Complex&,const Complex &);
    friend Complex operator-(const Complex&,const Complex &);
    friend Complex operator*(const Complex &,const Complex &);
    friend Complex operator/(const Complex &,const Complex &);

private:
    double x,y;
public:
    Complex &operator+=(const Complex &);
    Complex &operator-=(const Complex &);
    Complex &operator*=(const Complex &);
    Complex &operator/=(const Complex &);
};

int main()
{
    Complex z1;
    Complex z2;

    cin >> z1>> z2;

    cout << z1 + z2 <<endl;
    cout << z1 - z2 <<endl;
    cout << z1 * z2 <<endl;
    cout << z1 / z2 <<endl;
    cout << (z1 += z2) <<endl;
    cout << (z1 -= z2) <<endl;
    cout << (z1 *= z2) <<endl;
    cout << (z1 /= z2) <<endl;

    return 0;
}

istream &operator>>(istream &is,Complex &obj)
{
    is>>obj.x>>obj.y;
    return is;
}

ostream &operator<< (ostream &os,const Complex &obj)
{
    os<<fixed<<setprecision(2)<<obj.x<<" "<<obj.y;
    return os;
}


Complex operator*(const Complex &c1,const Complex &c2)
{
    Complex t;
    t.x=c1.x*c2.x-c1.y*c2.y;
    t.y=c1.y*c2.x+c1.x*c2.y;
    return t;

}

Complex operator+(const Complex &c1,const Complex &c2)
{
    Complex t;
    t.x=c1.x+c2.x;
    t.y=c1.y+c2.y;
    return t;
}

Complex operator-(const Complex &c1,const Complex &c2)
{
    Complex t;
    t.x=c1.x-c2.x;
    t.y=c1.y-c2.y;
    return t;
}

Complex operator/(const Complex &c1,const Complex &c2)
{
    Complex t;
    t.x=(c1.x*c2.x+c1.y*c2.y)/(c2.x*c2.x+c2.y*c2.y);
    t.y=(c1.y*c2.x-c1.x*c2.y)/(c2.x*c2.x+c2.y*c2.y);
    return t;
}

Complex & Complex::operator+=(const Complex &c)
{
    this->x+=c.x;
    this->y+=c.y;
    return *this;
}

Complex & Complex::operator-=(const Complex &c)
{
    this->x-=c.x;
    this->y-=c.y;
    return *this;
}

Complex & Complex::operator*=(const Complex &c)
{
    double a;
    a=this->x*c.x-this->y*c.y;
    this->y=this->y*c.x+this->x*c.y;
    this->x=a;
    return *this;
}

Complex & Complex::operator/=(const Complex &c)
{
    double a;
    a=(this->x*c.x+this->y*c.y)/(c.x*c.x+c.y*c.y);
    this->y=(this->y*c.x-this->x*c.y)/(c.x*c.x+c.y*c.y);
    this->x=a;
    return *this;
}
