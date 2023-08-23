#include <stdio.h>
#include <iostream>
#include <TCHAR.h>
using namespace std;
class X {
public:
    int* x1, * x2;
    X(int x1, int x2) {
        X::x1 = new int;
        X::x2 = new int;
        Set(x1, x2);
    }
    ~X() {
        delete X::x1;
        delete X::x2;
    }
    virtual void Set(int x1, int x2) {
        *X::x1 = x1;
        *X::x2 = x2;
    }
};
class Y : public X {
public:
    int* y;
    Y(int x1, int x2, int y) : X(x1, x2) {
        Y::y = new int;
        Set(x1, x2, y);
    }
    ~Y() {
        delete Y::y;
    }
    virtual void Set(int x1, int x2, int y) {
        X::Set(x1, x2);
        *Y::y = y;
    }
    virtual int Run() {
        return *X::x1 + *X::x2 * *Y::y;
    }
};
int _tmain(int argc, _TCHAR* argv[]) {
    int x1, x2, y;
    cout << "X1: ";
    cin >> x1;
    cout << "X2: ";
    cin >> x2;
    cout << "Y: ";
    cin >> y;
    Y obj(x1, x2, y);
    cout << endl << "Otvet = " << obj.Run() << endl;
    system("pause");
    return 0;
}