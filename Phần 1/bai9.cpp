#include <iostream>
#include <vector>

using namespace std;

void tinhVaInDaThuc(vector<double> heSo, int bac, double x) {
    double ketQua = 0.0;

    for (int i = 0; i <= bac; ++i) {
        double soMu = 1.0;

        for (int j = 0; j < i; ++j) {
            soMu *= x;
        }
        ketQua += heSo[i] * soMu;
    }

    cout << "Gia tri cua da thuc tai x = " << x << " la: " << ketQua << endl;
}

int main() {
    int bac;
    cout << "Nhap bac cua da thuc: ";
    cin >> bac;

    vector<double> heSo(bac + 1);

    cout << "Nhap " << bac + 1 << " he so cua da thuc:\n";
    for (int i = 0; i <= bac; ++i) {
        cout << "Nhap he so a" << i << ": ";
        cin >> heSo[i];
    }

    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;

    tinhVaInDaThuc(heSo, bac, x);

    return 0;
}
