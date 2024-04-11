#include<iostream>
using namespace std;

int fibonacci(int n){
    if( n<=1){
        return n;
    }
    int a=0, b=1;
    for(int i = 2; i<=n; i++){
        int temp = b;
        b +=a;
        a=temp;
    }
    return b;
}
int tong(int M, int N){
    int sum = 0;
    for( int i= M; i< N; i++){
        int fib = fibonacci(i);
        if( fib % 2==0){
            sum += fib;
        }
    }
    return sum;
}
int main() {
    int M, N;
    cout << "Nhap M:  ";
    cin >> M;
    cout << "Nhap N (N > M): ";
    cin >> N;

    if (N <= M) {
        cout << "N phai lon hon M" << endl;
        return 1;
    }

    int result = tong(M, N);
    cout << "Tong cac so chan tu (" << M << ") den F(" << N << ") la:  " << result << endl;

    return 0;
}