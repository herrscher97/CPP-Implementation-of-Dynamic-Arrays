//动态数组
#include <iostream>
using namespace std;

class Array{
private:
    int* p=NULL;
public:
    int* array=NULL;
    int len;//数组长度
    int length=0;//有效数据长度

    Array();
    Array(int num);
    ~Array();
    int& operator[](int num);
    int** operator&();
    int operator*();
    Array& operator=(Array&p);
    bool operator==(Array& p);
    int* operator+(int num);
    void push_back(int a);
    void show();
};

Array::Array() {
    len=10;
    array=new int[len]{0};
}

Array::Array(int num) {
    if (num%10==0){
        len=num;
    }
    else{
        len=num+10-(num%10);
    }
    array=new int[len]{0};
}

Array::~Array(){
    delete[]array;
//    cout<<&array<<"&0"<<endl;
//    cout<<array<<"-0"<<endl;
//    cout<<*array<<"*0"<<endl;
//    cout<<array+1<<"--1"<<endl;
//    cout<<*(array+1)<<"*11"<<endl;

    array=NULL;
//    cout<<&array<<"&2"<<endl;
//    cout<<array<<"-2"<<endl;
//    cout<<*array<<"*2"<<endl;
}

int& Array::operator[](int num){
    if (length<=num && num<len){
        length=num+1;
    }
    else if (len<=num){
        len=num+10-(num%10);
        length=num+1;
        p=new int[len]{0};
        //把旧数据拷贝到新数组
        for (int i = 0; i < length; i++) {
            p[i]=array[i];
        }

        delete []array;
        array=p;
        p=NULL;
    }
    return array[num];
}

int** Array::operator&(){
    return &array;
}

int Array::operator*(){
    return *array;
}

Array& Array::operator=(Array&p){
    if (array!=NULL){
        delete array;
        array=NULL;
    }
    array=p.array;
    len=p.len;
    length=p.length;
    return *this;
}


bool Array::operator==(Array& p){
    if (len==p.len && length==p.length){
        for (int i = 0; i < length; i++) {
            if (array[i]!=p.array[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

int* Array::operator+(int num){
    return array+num;
}

//全局函数重载加号运算符
//用到push_back不能在Array作用域下定义
Array& operator+(Array& p1,Array& p2){
    for (int i=0;i<p2.length;i++) {
        p1.push_back(p2[i]);
    }
    return p1;
}

//全局函数重载左移运算符
ostream& operator<<(ostream& cout,Array& p){
    cout<<p.array;
    return cout;
}

void Array::push_back(int a){
    if (length<len){
        array[length]=a;
        length++;
    }
    else{
        len*=2;
        p=new int[len]{0};
        //把旧数据拷贝到新数组
        for (int i = 0; i < length; i++) {
            p[i]=array[i];
        }

        delete []array;
        array=p;
        p=NULL;
        array[length]=a;
        length++;
    }
}

void Array::show() {
    cout<<"数组的长度为"<<len<<endl;
    cout<<"数组的有效数据长度为"<<length<<endl;
    cout<<"数组中元素为:";
    for (int i = 0; i < len; i++) {
        cout<<array[i]<<' ';
    }
    cout<<endl;
}

void test1(){
    Array a;
    Array b(14);
    cout<<"a数据:"<<endl;
    a.show();
    cout<<"--------------------------------------------------------"<<endl;

    cout<<"b数据:"<<endl;
    b.show();
    cout<<"--------------------------------------------------------"<<endl;

    cout<<"使用[]给a前7位赋值"<<endl;
    for (int i = 0; i < 7; i++) {
        a[i]=i+1;
    }
    a.show();
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"*a="<<*a<<endl;
    cout<<"a="<<a<<endl;
    cout<<"a+1="<<a+1<<endl;
    cout<<"*(a+1)="<<*(a+1)<<endl;
}

void test2(){
    Array a(10),b(10);
    cout<<"初始------------------------------------------------------"<<endl;
    cout<<"a的数据"<<endl;
    a.show();
    cout<<"b的数据"<<endl;
    b.show();
    for (int i = 0; i < b.len; i++) {
        b[i]=i+1;
    }
    cout<<"给b赋值后-------------------------------------------------"<<endl;
    cout<<"a的数据"<<endl;
    a.show();
    cout<<"b的数据"<<endl;
    b.show();

    a=b;
    cout<<"a=b后---------------------------------------------------"<<endl;
    cout<<"a的数据"<<endl;
    a.show();
    cout<<"b的数据"<<endl;
    b.show();
}

void test3(){
    Array a(10);
    Array b(10);
    Array c(13);
    //Array b(10)=a;
    cout<<"Array b(10)=a;会报错"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"a数据:"<<endl;
    a.show();
    cout<<"b数据:"<<endl;
    b.show();
    cout<<"c数据:"<<endl;
    c.show();
    cout<<"--------------------------------------------------------"<<endl;
    if (a==b){
        cout<<"a==b"<<endl;
    }
    else{
        cout<<"a!=b"<<endl;
    }

    if (a==c){
        cout<<"a==c"<<endl;
    }
    else{
        cout<<"a!=c"<<endl;
    }
}

void test4(){
    Array a(14);
    cout<<"a数据:"<<endl;
    a.show();
    cout<<"--------------------------------------------------------"<<endl;
    for (int i = 0; i < 14; i++) {
        a[i]=i+1;
    }
    cout<<"赋值后a数据:"<<endl;
    a.show();
    cout<<"--------------------------------------------------------"<<endl;
    for (int i = 0; i < 30; i++) {
        cout<<"数组长度"<<a.len<<','<<"有效数据长度"<<a.length<<endl;
        a.push_back(i);
    }
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"a数据:"<<endl;
    a.show();
}


int main(){
//    test1();
//    test2();
//    test3();
    test4();
    return 0;
}