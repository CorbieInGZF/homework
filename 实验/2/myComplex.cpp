#include <iostream>
#include "myComplex.h"

using namespace std;

int main() {
    myComplex c1;
    myComplex c2;
    myComplex c3;
    cout << "��ֱ����븴��A��ʵ�����鲿�� "<< endl;
    cin >> c1;
    cout << "A��ֵ�ǣ� " << c1 << endl;
    cout << "��ֱ����븴��B��ʵ�����鲿�� "<< endl;
    cin >> c2;
    cout << "B��ֵ�ǣ� " << c2 << endl;
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