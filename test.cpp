//��̬����
#include <iostream>
using namespace std;

class Array{
private:
    int* p=NULL;
public:
    int* array=NULL;
    int len;//���鳤��
    int length=0;//��Ч���ݳ���

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
        //�Ѿ����ݿ�����������
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

//ȫ�ֺ������ؼӺ������
//�õ�push_back������Array�������¶���
Array& operator+(Array& p1,Array& p2){
    for (int i=0;i<p2.length;i++) {
        p1.push_back(p2[i]);
    }
    return p1;
}

//ȫ�ֺ����������������
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
        //�Ѿ����ݿ�����������
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
    cout<<"����ĳ���Ϊ"<<len<<endl;
    cout<<"�������Ч���ݳ���Ϊ"<<length<<endl;
    cout<<"������Ԫ��Ϊ:";
    for (int i = 0; i < len; i++) {
        cout<<array[i]<<' ';
    }
    cout<<endl;
}

void test1(){
    Array a;
    Array b(14);
    cout<<"a����:"<<endl;
    a.show();
    cout<<"--------------------------------------------------------"<<endl;

    cout<<"b����:"<<endl;
    b.show();
    cout<<"--------------------------------------------------------"<<endl;

    cout<<"ʹ��[]��aǰ7λ��ֵ"<<endl;
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
    cout<<"��ʼ------------------------------------------------------"<<endl;
    cout<<"a������"<<endl;
    a.show();
    cout<<"b������"<<endl;
    b.show();
    for (int i = 0; i < b.len; i++) {
        b[i]=i+1;
    }
    cout<<"��b��ֵ��-------------------------------------------------"<<endl;
    cout<<"a������"<<endl;
    a.show();
    cout<<"b������"<<endl;
    b.show();

    a=b;
    cout<<"a=b��---------------------------------------------------"<<endl;
    cout<<"a������"<<endl;
    a.show();
    cout<<"b������"<<endl;
    b.show();
}

void test3(){
    Array a(10);
    Array b(10);
    Array c(13);
    //Array b(10)=a;
    cout<<"Array b(10)=a;�ᱨ��"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"a����:"<<endl;
    a.show();
    cout<<"b����:"<<endl;
    b.show();
    cout<<"c����:"<<endl;
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
    cout<<"a����:"<<endl;
    a.show();
    cout<<"--------------------------------------------------------"<<endl;
    for (int i = 0; i < 14; i++) {
        a[i]=i+1;
    }
    cout<<"��ֵ��a����:"<<endl;
    a.show();
    cout<<"--------------------------------------------------------"<<endl;
    for (int i = 0; i < 30; i++) {
        cout<<"���鳤��"<<a.len<<','<<"��Ч���ݳ���"<<a.length<<endl;
        a.push_back(i);
    }
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"a����:"<<endl;
    a.show();
}


int main(){
//    test1();
//    test2();
//    test3();
    test4();
    return 0;
}