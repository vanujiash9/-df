#include <iostream>
using namespace std;

int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
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

    int sum = UCLN(a, b) + UCLN(b, c) + UCLN(a, c);
    cout << "Tong cua USCLN(a, b) va USCLN(b, c) va USCLN(a, c) la: " << sum << endl;

    return 0;
}
