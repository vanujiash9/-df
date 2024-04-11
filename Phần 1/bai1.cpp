//Viết hàm tìm số đảo ngược của 1 số nguyên

#include<iostream>
using namespace std; 
int daonguoc(int n){
    int sodaonguoc = 0;
    while ( n>0){
        int digit = n%10;
        sodaonguoc = sodaonguoc*10 + digit;
        n = n/10;
    }
    return sodaonguoc;
}
int main(){
    int n;
    cout <<"Nhap n: ";
    cin >> n;
    int sodaonguocla = daonguoc(n);
    cout << "So dao nguoc cua "  << sodaonguocla;
    return 0;
}