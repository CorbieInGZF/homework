#include <iostream>
#include "myComplex.h"

using namespace std;

int main() {
    myComplex c1;
    myComplex c2;
    myComplex c3;
    cout << "请分别输入复数A的实部与虚部： "<< endl;
    cin >> c1;
    cout << "A的值是： " << c1 << endl;
    cout << "请分别输入复数B的实部与虚部： "<< endl;
    cin >> c2;
    cout << "B的值是： " << c2 << endl;
    c3 = c2*c1;
    cout << "B *= A = " << c3 << endl;
    c3 = c1/c2;
    cout << "B /= A = " << c3 << endl;
    c3 = c1 + c2;
    cout << "B + A = " << c3 << endl;
    c3 = c1 - c2;
    cout << "B - A = " << c3 << endl;
    c3 = c1 / c2;
    cout << "B / A = " << c3 << endl;
    c3 = c1 * c2;
    cout << "B * A = " << c3 << endl;

    return 0;

}