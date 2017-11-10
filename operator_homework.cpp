#include <iostream>
#include <cstring>
using namespace std;

template<typename T>

#define SIZE 100

class Mystring{
    friend ostream& operator<<(ostream &os,Mystring<char> const &p);
    friend void operator>>(istream &is, Mystring<char> &p);
    private:
    T Array[SIZE];
    public:
    Mystring(){
        for(int i = 0; i < SIZE; i++)
        {
            Array[i] = 0;
        }
    }
    void operator+(Mystring<char> &b)
    {
        strcat(Array, b.Array);
    }
    bool operator==(Mystring<char> &b)
    {
        int i = strcmp(Array, b.Array);
        if(i == 0)
        return true;
        else 
        return false;
    }
    bool operator>(Mystring<char> &b)
    {
        int i = strcmp(Array, b.Array);
        if(i > 0)
        return true;
        else
        return false;
    }
    bool operator<(Mystring<char> &b)
    {
        int i = strcmp(Array, b.Array);
        if(i < 0)
        return true;
        else
        return false;
    }
    bool operator!=(Mystring<char> &b)
    {
        int i = strcmp(Array, b.Array);
        if(i != 0)
        return true;
        else
        return false;
    }
    
    T operator[](int i)
    {
        return Array[i];
    }

};
ostream& operator<<(ostream &os,Mystring<char>const &p)
{
    for(int i = 0; i < SIZE; i++)
    os<<p.Array[i];
    return os;//对系统的ostream对象cout进行修改
}

void operator>>(istream &is, Mystring<char> &p)
{
    is>>p.Array;
}

int main()
{
    Mystring<char> a;
    Mystring<char> b;
    cin>>a;
    cin>>b;
    if(a != b)
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;
    a+b;
    cout<<a<<endl;
    cout<<a[8]<<endl;
}