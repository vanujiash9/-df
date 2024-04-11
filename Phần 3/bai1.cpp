#include <iostream>
#include <string>
using namespace std;

void xuatChuoiNguocLai(string S)
{
    cout << "a) Chuoi theo chieu nguoc lai: ";
    for (int i = S.length() - 1; i >= 0; i--)
    {
        cout << S[i];
    }
    cout << endl;
}

int demChuCaiVaChuSo(string S)
{
    int countAlpha = 0, countDigit = 0;
    for (char ch : S)
    {
        if (isalpha(ch))
        {
            countAlpha++;
        }
        else if (isdigit(ch))
        {
            countDigit++;
        }
    }
    cout << "b) So luong chu cai: " << countAlpha << endl;
    cout << "   So luong chu so: " << countDigit << endl;
}

string dinhDangChuoi(string S)
{
    string chuoiDinhDang;
    bool laKiTuDauTien = true;
    for (char &ch : S)
    {
        if (isalpha(ch))
        {
            if (laKiTuDauTien)
            {
                chuoiDinhDang += toupper(ch);
                laKiTuDauTien = false;
            }
            else
            {
                chuoiDinhDang += tolower(ch);
            }
        }
        else if (isspace(ch))
        {
            chuoiDinhDang += ch;
            laKiTuDauTien = true;
        }
    }
    return chuoiDinhDang;
}

bool kiemTraChuoi(string S)
{
    return S == "Ngon ngu lap trinh C++";
}

string xoaKiTuKhongChuCai(string S)
{
    string ketQua = "";
    for (char ch : S)
    {
        if (isalpha(ch))
        {
            ketQua += ch;
        }
    }
    return ketQua;
}

string thayTheChuInHoaBangDausao(string S)
{
    for(char &ch : S){
        if( isupper(ch)){
            ch = '*';
        }
    }
    return S;
}

string themChuoiHello(string S)
{
    return "Hello " + S;
}

int main()
{
    string S;
    int lc = 0; 

    cout << "Nhap chuoi S: ";
    getline(cin, S);
    xuatChuoiNguocLai(S);

    while (true)
    {
        cout << "Nhap lua chon (0 de thoat): ";
        cin >> lc;
        cin.ignore();

        switch (lc)
        {
        case 0:
            return 0;
        case 1:
            demChuCaiVaChuSo(S);
            break;
        case 2:
            cout << "c) " << dinhDangChuoi(S) << endl;
            break;
        case 3:
            cout << "d) ";
            if (kiemTraChuoi(S))
            {
                cout << "Chuoi S giong voi 'Ngon ngu lap trinh C++'." << endl;
            }
            else
            {
                cout << "Chuoi S khong giong voi 'Ngon ngu lap trinh C++'." << endl;
            }
            break;
        case 4:
        {
            cout << "e) ";
            string ketQua = xoaKiTuKhongChuCai(S);
            cout << "Chuoi sau khi xoa cac ki tu khong phai chu cai: " << ketQua << endl;
            break;
        }
        case 5:
            cout << "f) ";
            cout << "Chuoi sau khi thay the: " << thayTheChuInHoaBangDausao(S) << endl;
            break;
        case 6:
            cout << "g) ";
            cout << "Chuoi sau khi them chuoi Hello: " << themChuoiHello(S) << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    }
}
