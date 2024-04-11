#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 10;

void nhapMaTran(int A[MAX_SIZE][MAX_SIZE], int n) {
    cout << "Nhap cac phan tu cua ma tran " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
}

void xuatMaTran(int A[MAX_SIZE][MAX_SIZE], int n) {
    cout << "Ma tran " << n << "x" << n << " la:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int tinhTongNgoaiDuongCheoChinh(int A[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                tong += A[i][j];
            }
        }
    }
    return tong;
}

int timMaxDuongCheoChinh(int A[MAX_SIZE][MAX_SIZE], int n) {
    int maxVal = A[0][0];
    for (int i = 1; i < n; ++i) {
        if (A[i][i] > maxVal) {
            maxVal = A[i][i];
        }
    }
    return maxVal;
}

int demSoAmTrenDuongCheoPhu(int A[MAX_SIZE][MAX_SIZE], int n) {
    int dem = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i][n - i - 1] < 0) {
            dem++;
        }
    }
    return dem;
}

bool kiemTraSoNguyenTo(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int demSoNguyenTo(int A[MAX_SIZE][MAX_SIZE], int n) {
    int dem = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (kiemTraSoNguyenTo(A[i][j])) {
                dem++;
            }
        }
    }
    return dem;
}

void timSoXuatHienNhieuNhat(int A[MAX_SIZE][MAX_SIZE], int n) {
    map<int, int> tanSuat;
    int maxTanSuat = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tanSuat[A[i][j]]++;
            maxTanSuat = max(maxTanSuat, tanSuat[A[i][j]]);
        }
    }

    cout << "Cac so xuat hien nhieu nhat la: ";
    for (auto it = tanSuat.begin(); it != tanSuat.end(); ++it) {
        if (it->second == maxTanSuat) {
            cout << it->first << " ";
        }
    }
    cout << endl;
}

void lietKeDongNhieuSoChanNhat(int A[MAX_SIZE][MAX_SIZE], int n) {
    vector<pair<int, int>> demChan;
    for (int i = 0; i < n; ++i) {
        int dem = 0;
        for (int j = 0; j < n; ++j) {
            if (A[i][j] % 2 == 0) {
                dem++;
            }
        }
        demChan.push_back(make_pair(dem, i));
    }
    sort(demChan.begin(), demChan.end(), greater<pair<int, int>>());

    cout << "Dong(s) co nhieu so chan nhat la: ";
    for (int i = 0; i < demChan.size() && demChan[i].first == demChan[0].first; ++i) {
        cout << demChan[i].second << " ";
    }
    cout << endl;
}

void lietKeDongNhieuSoNguyenToNhat(int A[MAX_SIZE][MAX_SIZE], int n) {
    vector<pair<int, int>> demNguyenTo;
    for (int i = 0; i < n; ++i) {
        int dem = 0;
        for (int j = 0; j < n; ++j) {
            if (kiemTraSoNguyenTo(A[i][j])) {
                dem++;
            }
        }
        demNguyenTo.push_back(make_pair(dem, i));
    }
    sort(demNguyenTo.begin(), demNguyenTo.end(), greater<pair<int, int>>());

    cout << "Dong(s) co nhieu so nguyen to nhat la: ";
    for (int i = 0; i < demNguyenTo.size() && demNguyenTo[i].first == demNguyenTo[0].first; ++i) {
        cout << demNguyenTo[i].second << " ";
    }
    cout << endl;
}

void tinhSoBien(int A[MAX_SIZE][MAX_SIZE], int n) {
    cout << "Cac so tren duong bien cua ma tran la: ";
    for (int i = 0; i < n; ++i) {
        cout << A[0][i] << " "; 
        cout << A[i][n - 1] << " "; 
        if (i < n - 1) {
            cout << A[n - 1][i] << " "; 
            cout << A[i][0] << " "; 
        }
    }
    cout << endl;
}

int main() {
    int A[MAX_SIZE][MAX_SIZE];
    int n;

    cout << "Nhap cap ma tran n (n <= 10): ";
    cin >> n;

    nhapMaTran(A, n);
    xuatMaTran(A, n);

    char lc;
    do {
        cout << "\nLua chon: \n";
        cout << "a. Tinh tong cac phan tu nam ngoai duong cheo chinh.\n";
        cout << "b. Tim gia tri lon nhat tren duong cheo chinh.\n";
        cout << "c. Dem so phan tu am tren duong cheo phu.\n";
        cout << "d. Dem so luong so nguyen to.\n";
        cout << "e. Tim cac so xuat hien nhieu nhat trong ma tran.\n";
        cout << "f. Liet ke cac dong co nhieu so chan nhat.\n";
        cout << "g. Liet ke cac dong co nhieu so nguyen to nhat.\n";
        cout << "h. Tinh cac so tren duong bien cua ma tran.\n";
        cout << "j. Thoat.\n";
        cout << "Lua chon cua ban: ";
        cin >> lc;

        switch (lc) {
            case 'a':
                cout << "Tong cac phan tu nam ngoai duong cheo chinh: " << tinhTongNgoaiDuongCheoChinh(A, n) << endl;
                break;
            case 'b':
                cout << "Gia tri lon nhat tren duong cheo chinh: " << timMaxDuongCheoChinh(A, n) << endl;
                break;
            case 'c':
                cout << "So phan tu am tren duong cheo phu: " << demSoAmTrenDuongCheoPhu(A, n) << endl;
                break;
            case 'd':
                cout << "So luong so nguyen to: " << demSoNguyenTo(A, n) << endl;
                break;
            case 'e':
                timSoXuatHienNhieuNhat(A, n);
                break;
            case 'f':
                lietKeDongNhieuSoChanNhat(A, n);
                break;
            case 'g':
                lietKeDongNhieuSoNguyenToNhat(A, n);
                break;
            case 'h':
                tinhSoBien(A, n);
                break;
            case 'j':
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
    } while (lc != 'j');

    return 0;
}
