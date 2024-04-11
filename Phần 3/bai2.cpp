#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 50;

// Hàm nhập mảng fullName
void nhapFullName(string fullName[], int n) {
    cout << "Nhap ho va ten sinh vien:\n";
    cin.ignore(); 
    for (int i = 0; i < n; ++i) {
        cout << "Sinh vien thu " << i + 1 << ": ";
        getline(cin, fullName[i]);
    }
}

// Hàm xuất mảng fullName
void xuatMang(const string mang[], int n, const string tieude) {
    cout << tieude << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Sinh vien thu " << i + 1 << ": " << mang[i] << endl;
    }
}

// Hàm tách họ từ chuỗi họ tên và lưu vào mảng firstName
void tachHo(const string fullName[], string firstName[], int n) {
    for (int i = 0; i < n; ++i) {
        size_t pos = fullName[i].find(' ');
        if (pos != string::npos) { 
            firstName[i] = fullName[i].substr(0, pos); 
        }
        else { 
            firstName[i] = fullName[i]; 
        }
    }
}

// Hàm tách tên từ chuỗi họ tên và lưu vào mảng lastName
void tachTen(const string fullName[], string lastName[], int n) {
    for (int i = 0; i < n; ++i) {
        size_t pos = fullName[i].find_last_of(' '); 
        if (pos != string::npos) { 
            lastName[i] = fullName[i].substr(pos + 1); 
        }
        else {
            lastName[i] = fullName[i]; 
        }
    }
}

// Hàm sắp xếp mảng fullName theo thứ tự tăng dần của phần tên
void sapXepTheoTen(string fullName[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {

            string ten1 = fullName[j].substr(fullName[j].find_last_of(' ') + 1);
            string ten2 = fullName[j + 1].substr(fullName[j + 1].find_last_of(' ') + 1);

            if (ten1 > ten2) {
                swap(fullName[j], fullName[j + 1]);
            }
        }
    }
}

// Hàm tìm sinh viên có họ là "Nguyen" và xuất thông tin của họ
void timSinhVienNguyen(const string fullName[], int n) {
    bool found = false;

    cout << "Cac sinh vien co ho la \"Nguyen\":\n";
    for (int i = 0; i < n; ++i) {
        if (fullName[i].find("Nguyen") == 0) {
            cout << fullName[i] << endl;
            found = true; 
        }
    }

    if (!found) { 
        cout << "Khong co sinh vien nao co ho la \"Nguyen\".\n";
    }
}

// Hàm tìm sinh viên có phần tên có nhiều ký tự nhất và xuất thông tin của họ
void timSinhVienTenDaiNhat(const string fullName[], int n) {
    int maxTenLength = 0; 
    int viTriSinhVien = -1; 

    for (int i = 0; i < n; ++i) {
        size_t pos = fullName[i].find_last_of(' '); 
        if (pos != string::npos) { 
            int tenLength = fullName[i].length() - pos - 1; 
            if (tenLength > maxTenLength) { 
                maxTenLength = tenLength; 
                viTriSinhVien = i; 
            }
        }
    }

    if (viTriSinhVien != -1) { 
        cout << "Sinh vien co phan ten co nhieu ky tu nhat la:\n";
        cout << fullName[viTriSinhVien] << endl;
    }
    else {
        cout << "Khong co sinh vien nao trong danh sach.\n";
    }
}

int main() {
    int n;
    string fullName[MAX_SIZE];
    string firstName[MAX_SIZE];
    string lastName[MAX_SIZE];

    cout << "Nhap so sinh vien (n <= 50): ";
    cin >> n;

    nhapFullName(fullName, n); 

    char choice;
    cout << "Lua chon:\n";
    cout << "a. Tach ho.\n";
    cout << "b. Tach ten.\n";
    cout << "c. Sap xep theo ten.\n";
    cout << "d. Tim sinh vien co ho la \"Nguyen\".\n";
    cout << "e. Tim sinh vien co phan ten dai nhat.\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> choice;

    switch(choice) {
        case 'a':
            tachHo(fullName, firstName, n);
            xuatMang(firstName, n, "Cac ho cua sinh vien");
            break;
        case 'b':
            tachTen(fullName, lastName, n);
            xuatMang(lastName, n, "Cac ten cua sinh vien");
            break;
        case 'c':
            sapXepTheoTen(fullName, n);
            xuatMang(fullName, n, "Mang fullName sau khi sap xep");
            break;
        case 'd':
            timSinhVienNguyen(fullName, n);
            break;
        case 'e':
            timSinhVienTenDaiNhat(fullName, n);
            break;
        default:
            cout << "Lua chon khong hop le.\n";
    }

    return 0;
}
