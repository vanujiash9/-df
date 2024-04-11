// Viết hàm chuyển đổi số hệ thập phân sang số hệ nhị phân hoặc thập lục phân.
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

string thapPhanSangNhiPhan(int thapPhan)
{
    string nhiPhan = "";
    if (thapPhan == 0)
    {
        nhiPhan = "0";
    }
    else
    {
        while (thapPhan > 0)
        {
            nhiPhan = to_string(thapPhan % 2) + nhiPhan;
            thapPhan /= 2;
        }
    }
    return nhiPhan;
}

string thapPhanSangThapLucPhan(int thapPhan)
{
    stringstream stream;
    stream << hex << thapPhan;
    return stream.str();
}

string thapPhanSangCoSo(int thapPhan, int coSo)
{
    if (coSo == 2)
        return thapPhanSangNhiPhan(thapPhan);
    else if (coSo == 16)
        return thapPhanSangThapLucPhan(thapPhan);
    else
        return "Co so khong duoc ho tro";
}

int main()
{
    int thapPhan, coSo;
    cout << "Nhap so thap phan: ";
    cin >> thapPhan;
    cout << "Nhap he co so muon chuyen (2 hoac 16): ";
    cin >> coSo;
    string ketQua = thapPhanSangCoSo(thapPhan, coSo);
    if (ketQua != "Co so khong duoc ho tro")
        cout << "So hien thi trong he co so " << coSo << ": " << ketQua << endl;
    else
        cout << ketQua << endl;
    return 0;
}
