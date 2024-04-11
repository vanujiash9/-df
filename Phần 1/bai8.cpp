#include <iostream>
using namespace std;


int USCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int BSCNN(int a, int b) {
    return (a * b) / USCLN(a, b);
}

int main() {
    int a, b, c;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;


    if (a == 0 || b == 0 || c == 0) {
        cout << "Cac so nhap vao khong hop le." << endl;
        return 1; 
    }


    int sum = USCLN(a, b) + BSCNN(a, c);
    cout << "Tong USCLN va BSCNN la: " << sum << endl;

    return 0;
}
