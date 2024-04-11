#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_NAME_LENGTH = 50;

void tachHoTen(char fullName[][MAX_NAME_LENGTH], char firstName[][MAX_NAME_LENGTH], char lastName[][MAX_NAME_LENGTH], int n) {
    for (int i = 0; i < n; ++i) {
        char* token = strtok(fullName[i], " ");
        strcpy(firstName[i], token); 
        token = strtok(NULL, " ");
        strcpy(lastName[i], token);
    }
}

void tachTen(char fullName[][MAX_NAME_LENGTH], char lastName[][MAX_NAME_LENGTH], int n) {
    for (int i = 0; i < n; ++i) {
        char* token = strrchr(fullName[i], ' ') + 1;
        strcpy(lastName[i], token); 
    }
}

void sapXepTheoTen(char fullName[][MAX_NAME_LENGTH], int n) {
    sort(fullName, fullName + n, [](const char* a, const char* b) {
        char lastNameA[MAX_NAME_LENGTH], lastNameB[MAX_NAME_LENGTH];
        strcpy(lastNameA, strrchr(a, ' ') + 1);
        strcpy(lastNameB, strrchr(b, ' ') + 1);
        return strcmp(lastNameA, lastNameB) < 0;
    });
}

void timHoNguyen(char fullName[][MAX_NAME_LENGTH], int n) {
    cout << "Sinh vien co ho la 'Nguyen':\n";
    for (int i = 0; i < n; ++i) {
        if (strstr(fullName[i], "Nguyen") != nullptr) {
            cout << fullName[i] << endl;
        }
    }
}

void timTenDaiNhat(char fullName[][MAX_NAME_LENGTH], int n) {
    int maxLen = 0;
    char* longestName;
    for (int i = 0; i < n; ++i) {
        char* token = strrchr(fullName[i], ' ') + 1;
        int len = strlen(token);
        if (len > maxLen) {
            maxLen = len;
            longestName = token;
        }
    }
    cout << "Sinh vien co phan ten dai nhat: " << longestName << endl;
}

int main() {
    char fullName[MAX_STUDENTS][MAX_NAME_LENGTH];
    char firstName[MAX_STUDENTS][MAX_NAME_LENGTH];
    char lastName[MAX_STUDENTS][MAX_NAME_LENGTH];
    int n;

    cout << "Nhap so luong sinh vien (toi da " << MAX_STUDENTS << "): ";
    cin >> n;
    cin.ignore(); 

    cout << "Nhap ho va ten cua " << n << " sinh vien:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Nhap ho va ten sinh vien thu " << i + 1 << ":\n";
        cin.getline(fullName[i], MAX_NAME_LENGTH - 1);
    }

    tachHoTen(fullName, firstName, lastName, n);

    while (true) {
        char lc;
        cout << "Chon chuc nang:\n";
        cout << "a) Tach ho cua sinh vien\n";
        cout << "b) Tach ten cua sinh vien\n";
        cout << "c) Sap xep theo phan ten\n";
        cout << "d) Tim sinh vien co ho la 'Nguyen'\n";
        cout << "e) Tim sinh vien co phan ten dai nhat\n";
        cout << "0) Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> lc;
        cin.ignore();

        switch (lc) {
            case '0':
                return 0;
            case 'a':
                cout << "Họ của sinh viên:\n";
                for (int i = 0; i < n; ++i) {
                    cout << firstName[i] << endl;
                }
                break;
            case 'b':
                cout << "Tên của sinh viên:\n";
                for (int i = 0; i < n; ++i) {
                    cout << lastName[i] << endl;
                }
                break;
            case 'c':
                sapXepTheoTen(fullName, n);
                cout << "Danh sach sinh vien sau khi sap xep theo phan ten:\n";
                for (int i = 0; i < n; ++i) {
                    cout << fullName[i] << endl;
                }
                break;
            case 'd':
                timHoNguyen(fullName, n);
                break;
            case 'e':
                timTenDaiNhat(fullName, n);
                break;
            default:
                cout << "Lua chon khong hop le!\n";
                break;
        }
    }

    return 0;
}
