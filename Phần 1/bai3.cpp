#include<iostream>
#include<cmath>
using namespace std;

int fibonacci(int n) {
    if (n < 0)
        return -1;
    else if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int result = fibonacci(n);
    if (result == -1)
        cout << "Khong ton tai phan tu thu " << n << " trong day Fibonacci";
    else
        cout << "Phan tu thu " << n << " trong day Fibonacci la: " << result;
    return 0;
}
