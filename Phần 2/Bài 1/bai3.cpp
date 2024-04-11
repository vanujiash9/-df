#include <iostream>
#include <climits> 
#include <algorithm> 
using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

void nhapMang(int A[MAX_ROWS][MAX_COLS], int &m, int &n) {
    cout << "Nhap so hang cua mang (m): ";
    cin >> m;
    cout << "Nhap so cot cua mang (n): ";
    cin >> n;

    cout << "Nhap cac phan tu cua mang " << m << "x" << n << ":" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
}

void xuatMang(int A[MAX_ROWS][MAX_COLS], int m, int n) {
    cout << "Mang " << m << "x" << n << " la:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int demPhanTuAm(int A[MAX_ROWS][MAX_COLS], int m, int n) {
    int dem = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] < 0) {
                dem++;
            }
        }
    }
    return dem;
}

int timMax(int A[MAX_ROWS][MAX_COLS], int m, int n) {
    int maxVal = INT_MIN; 
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] > maxVal) {
                maxVal = A[i][j];
            }
        }
    }
    return maxVal;
}

int tinhTongDongLonNhat(int A[MAX_ROWS][MAX_COLS], int m, int n) {
    int maxSum = INT_MIN;
    int rowIndex = -1;

    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += A[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            rowIndex = i;
        }
    }

    return rowIndex;
}

void sapXepTangDanTheoDong(int A[MAX_ROWS][MAX_COLS], int m, int n) {
    for (int i = 0; i < m; ++i) {
        sort(A[i], A[i] + n);
    }
}

void sapXepGiamDan(int A[MAX_ROWS][MAX_COLS], int m, int n) {
    int temp[MAX_ROWS * MAX_COLS];
    int index = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[index++] = A[i][j];
        }
    }
    sort(temp, temp + m * n, greater<int>());

    index = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = temp[index++];
        }
    }
}

int main() {
    int A[MAX_ROWS][MAX_COLS];
    int m, n;

    nhapMang(A, m, n);
    xuatMang(A, m, n);

    int lc;
    do {
        cout << "\nLua chon: \n";
        cout << "1. Dem so luong phan tu am trong mang.\n";
        cout << "2. Tim gia tri lon nhat trong mang.\n";
        cout << "3. Dong nao cua A co tong cac phan tu la lon nhat.\n";
        cout << "4. Sap xep tung dong cua A theo thu tu tang dan.\n";
        cout << "5. Sap xep mang A theo thu tu giam dan.\n";
        cout << "0. Thoat.\n";
        cout << "Lua chon cua ban: ";
        cin >> lc;

        switch (lc) {
            case 1:
                cout << "So luong phan tu am trong mang: " << demPhanTuAm(A, m, n) << endl;
                break;
            case 2:
                cout << "Gia tri lon nhat trong mang: " << timMax(A, m, n) << endl;
                break;
            case 3: {
                int rowIndex = tinhTongDongLonNhat(A, m, n);
                cout << "Dong co tong lon nhat la dong thu " << rowIndex << endl;
                break;
            }
            case 4:
                sapXepTangDanTheoDong(A, m, n);
                cout << "Mang sau khi sap xep tung dong tang dan: " << endl;
                xuatMang(A, m, n);
                break;
            case 5:
                sapXepGiamDan(A, m, n);
                cout << "Mang sau khi sap xep giam dan: " << endl;
                xuatMang(A, m, n);
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
    } while (lc != 0);

    return 0;
}
