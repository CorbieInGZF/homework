#include <iostream>
#include <cmath>
using namespace std;



class myComplex {
private:
    double real;
    double imag;
public:
    myComplex();

    myComplex(double a);

    myComplex(double a, double b);

    myComplex(const myComplex &v);


    double getReal();  //���ظ�����ʵ��
    double getImaginary();  //���ظ������鲿
    double getModulus(); //���ظ�����ģ

    void setReal(double r);  //���ø�����ʵ��
    void setImaginary(double i);  //���ø������鲿

    myComplex& operator=(const myComplex &rhs);  //�����ĸ�ֵ

    myComplex& operator+=(const myComplex &rhs);

    myComplex& operator-=(const myComplex &rhs);

    myComplex& operator*=(const myComplex &rhs);

    myComplex& operator/=(const myComplex &rhs);

    friend myComplex operator+(myComplex m, myComplex n);

    friend myComplex operator-(myComplex m, myComplex n);

    friend myComplex operator*(myComplex m, myComplex n);

    friend myComplex operator/(myComplex m, myComplex n);

    friend ostream& operator<<(ostream &os, myComplex &c);

    friend istream& operator>>(istream &is, myComplex &c);
};

myComplex::myComplex(){
	real = 0;
	imag = 0;
}

myComplex::myComplex(double a){
	real = a;
	imag = 0;
}

myComplex::myComplex(double a, double b){
	real = a;
	imag = b;
}

myComplex::myComplex(const myComplex &v){
	real = v.real;
	imag = v.imag;
}

double myComplex::getImaginary() {
    return this->imag;
}

double myComplex::getReal() {
    return this->real;
}

double myComplex::getModulus() {
    return sqrt(this->imag * this->imag + this->real * this->real);
}

void myComplex::setReal(double r) {
    this->real = r;
}

void myComplex::setImaginary(double i) {
    this->imag = i;
}

myComplex& myComplex::operator=(const myComplex &rhs) {
    this->real = rhs.real;
    this->imag = rhs.imag;
    return *this;
}

myComplex& myComplex::operator+=(const myComplex &rhs) {
    real = real+rhs.real;
    imag = imag+rhs.imag;
    return *this;
}

myComplex& myComplex::operator-=(const myComplex &rhs) {
    real = real-rhs.real;
    imag = imag-rhs.imag;
    return *this;
}

myComplex& myComplex::operator*=(const myComplex &rhs) {
	real = real*rhs.real;
    imag = imag*rhs.imag;
    return *this;
}

myComplex& myComplex::operator/=(const myComplex &rhs) {
    real = real/rhs.real;
    imag = imag/rhs.imag;
    return *this;
}

myComplex operator+(myComplex m, myComplex n) {
	return myComplex(m.real+n.real,m.imag+n.imag);
}

myComplex operator-(myComplex m, myComplex n) {
    return myComplex(m.real-n.real,m.imag-n.imag);
}

myComplex operator*(myComplex m, myComplex n) {
    return myComplex(m.real*n.real-m.imag*n.imag,m.real*n.imag+m.imag*n.real);
}

myComplex operator/(myComplex m, myComplex n) {
    return myComplex((m.real*n.real+m.imag*n.imag)/(n.real*n.real+n.imag*n.imag),(m.real*n.real-m.real*n.imag)/(n.real*n.real+n.imag*n.imag));
}

ostream &operator<<(ostream &os, myComplex &c) {
    os<<"("<<c.real<<"+"<<c.imag<<"i)"<<endl;
}

istream &operator>>(istream &is, myComplex &c) {
    is>>c.real>>c.imag;
    return is;
}