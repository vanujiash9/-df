#include<iostream>
using namespace std;

int tinhgiaithua(int n){
    if(n<=1)
    return -1;
    else
    return n*tinhgiaithua(n-1);
}
int tohop(int n, int k){
    if( k<0 || k > n)
        return 0;
    else
    return tinhgiaithua(n) / (tinhgiaithua(k)*tinhgiaithua(n-k));
    
}
int main(){
    int n, k;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;
    int result = tohop(n, k);
    cout <<"To hop chap k cua n la: " << result;
    return 0;
}