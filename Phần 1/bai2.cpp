//Viết hàm trả về chiều dài của một số nguyên.

#include<iostream>
using namespace std;

int chieudai(int n){
    int CD = 0;
    while(n > 0){
        n = n/10;
        CD ++;
    }
    return CD;
}
int main(){
    int n;
    cout << "Nhap n ";
    cin >> n;
    int chieudaila = chieudai(n);
    cout << "Chieu dai la " << chieudaila;
}