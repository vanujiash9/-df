/*Bài 1. Nhập/xuất dữ liệu cho mảng số nguyên có tối đa 100 phần tử.
a. Kiểm tra xem mảng có phải chứa toàn số chẵn hay không?*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void kiemtrasochan(int a[100], int &n)
{
    bool sochan = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            sochan = false;
            break;
        }
    }
    if (sochan)
    {
        cout << "Mang chua toan so chan" << endl;
    }
    else
    {
        cout << "Mang khong chua toan so chan " << endl;
    }
}

//
bool kiemtrasonguyento(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
void kiemtrasonguyento(int a[100], int &n)
{
    bool cosonguyento = false;
    for (int i = 0; i < (n); i++)
    {
        if (kiemtrasonguyento(a[i]))
        {
            cosonguyento = true;
            break;
        }
    }
    if (cosonguyento)
    {
        cout << "Mang chua so nguyen to" << endl;
    }
    else
    {
        cout << "Mang khong chua so nguyen to" << endl;
    }
}
//
void kiemtrasx(int a[100], int n)
{
    bool tang_dan = true;
    bool giam_dan = true;

    // Kiểm tra mảng có được sắp xếp tăng dần không
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            tang_dan = false;
            break;
        }
    }

    // Kiểm tra mảng có được sắp xếp giảm dần không
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            giam_dan = false;
            break;
        }
    }

    if (tang_dan)
    {
        cout << "Mang dang duoc sap xep theo thu tu tang dan." << endl;
    }
    else if (giam_dan)
    {
        cout << "Mang dang duoc sap xep theo thu tu giam dan." << endl;
    }
    else
    {
        cout << "Mang khong duoc sap xep." << endl;
    }
}
//

void kiemtratrungnhau(int a[100], int &n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n;)
        {
            if (a[j] == a[i])
            {
                for (int k = j; k < n - 1; ++k)
                {
                    a[k] = a[k + 1];
                }
                --n; // Giảm số lượng phần tử
            }
            else
            {
                ++j;
            }
        }
    }
    cout << "Mang sau khi loai bo phan tu trung nhau va chi giu lai 1 phan tu:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
// so sánh số lượng chẵn và số lượng lẻ trong mảng

void sosanhchanle(int a[100], int &n)
{
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    cout << "So phan tu chan la: " << count1 << endl;
    cout << "So phan tu le la: " << count2 << endl;

    if (count1 > count2)
    {
        cout << "Phan tu chan nhieu hon phan tu le" << endl;
    }
    else if (count1 < count2)
    {
        cout << "Phan tu le nhieu hon phan tu chan" << endl;
    }
    else
    {
        cout << "Phan tu chan va phan tu le co so luong bang nhau" << endl;
    }
}
// f. Hãy chèn số có giá trị x vào vị trí có chỉ số p của mảng nếu mảng chưa đầy?
void kiemtraphantuday(int a[5], int &n, int x, int p)
{
    cout << "Nhap p: ";
    cin >> p;
    cout << "Nhap x: ";
    cin >> x;
    if (n >= 5)
    {
        cout << "Mang da day khong the chen them phan tu";
        return;
    }
    if (p < 0 || p > n)
    {
        cout << "Vi tri chen khong hop le";
        return;
    }
    for (int i = n; i > p; --i)
    {
        a[i] = a[i - 1];
    }
    a[p] = x;
    ++n;
    cout << "Da chen " << x << "vao vi tri " << p << " cua mang " << endl;
    cout << "Mang sau khi chen: ";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
/*g. Hãy tìm số nguyên tố đầu tiên xuất hiện trong mảng mà phần tử đứng trước của nó
là số chính phương?
*/
bool isSquare(int x)
{
    int sr = sqrt(x);
    return (sr * sr == x);
}

bool isPrime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i < sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void nguyentochinhphuong(int a[100], int &n, int &result)
{
    result = -1;
    for (int i = 1; i < n; i++)
    {
        if (isSquare(a[i]) && isPrime(a[i - 1]))
        {
            result = a[i];
            return;
        }
    }
}
// h. Tách các số không phải là số nguyên tố và đưa vào mảng khác.
bool isPrimee(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void tachso(int arr[100], int n, int nonPrimeArr[], int &nonPrimeCount)
{
    nonPrimeCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (!isPrimee(arr[i]))
        {
            nonPrimeArr[nonPrimeCount] = arr[i];
            nonPrimeCount++;
        }
    }
}
/*i. Sắp xếp nửa đầu của mảng tăng dần, nửa sau giảm dần. Phần tử ở giữa nếu có thì giữ
nguyên*/
void sapxep(int a[100], int n, int mid)
{
    mid = n / 2;
    sort(a, a + mid);
    sort(a + mid, a + n, greater<int>());
}
// k. Sắp xếp mảng giảm dần.
void sapxepgiamdan(int a[100], int n)
{
    sort(a, a + n, greater<int>());
}
// m. Chèn số x vào mảng giảm dần sao cho mảng vẫn giảm dần sau khi chèn x.
void chenSo(int a[], int &n, int x)
{
    int viTriChen = n;

    while (viTriChen > 0 && a[viTriChen - 1] < x)
    {
        viTriChen--;
    }

    for (int i = n; i > viTriChen; i--)
    {
        a[i] = a[i - 1];
    }

    a[viTriChen] = x;

    n++;
}

void sapXepChen(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] < key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}
// n. Kiểm tra mảng có đối xứng hay không? [1, 2,3, 3, 2, 1]
bool kiemtradoixung(int a[100], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int a[100], n, lc, x, p, result, nonPrimeArr[100], nonPrimeCount = 0, mid;
    cout << "Nhap so luong: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i << "] "
             << " = ";
        cin >> a[i];
        while (a[i] <= 0)
        {
            cout << "Nhap a[" << i << "] "
                 << " = ";
            cin >> a[i];
        }
    }
    while (lc != 0)
    {
        cout << "1. Kiem tra mang toan so chan hay khong" << endl;
        cout << "2. Hien thi cac so nguyen to co trong mang" << endl;
        cout << "3. Mang co dang duoc sap xep hay khong. Tang dan hay giam dan" << endl;
        cout << "4. Cac phan tu co trung nhau hay khong. Neu co loai bo va de 1 phan tu" << endl;
        cout << "5. So sanh so luong chan le" << endl;
        cout << "6. chen so co gia tri x vao vi tri co chi so p cua mang neu mang chua day" << endl;
        cout << "7. Tim so dau tien trong mang ma phan tu dung truoc cua no la so chinh phuong" << endl;
        cout << "8. Tach ca so khong phai la so nguyen to va dua vao mang khac" << endl;
        cout << "9. Sx nua dau mang tang dan, nua sau giam dan, phan tu o giua neu co thi giu nguyen" << endl;
        cout << "10. Sap xep mang giam dan" << endl;
        cout << "11. Chen so x vao mang giam dan sao cho mang van giam dan sau khi chen x " << endl;
        cout << "12. Kiem tra mang co doi xung hay khong " << endl;
        cout << "13. Kiem tra mang co sap thu tu tang hay khong" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon: ";
        cin >> lc;
        switch (lc)
        {
        case 1:
            kiemtrasochan(a, n);
            break;

        case 2:
            kiemtrasonguyento(a, n);
            break;
        case 3:
            kiemtrasx(a, n);
            break;
        case 4:
            kiemtratrungnhau(a, n);
            break;
        case 5:
            sosanhchanle(a, n);
            break;
        case 6:
            kiemtraphantuday(a, n, x, p);
            break;
        case 7:
            nguyentochinhphuong(a, n, result);
            if (result != -1)
            {
                cout << "So nguyen to dau tien co phan tu dung truoc la so chinh phuong: " << result << endl;
            }
            else
            {
                cout << "Khong tim thay so thoa man dieu kien." << endl;
            }
            break;

        case 8:
            tachso(a, n, nonPrimeArr, nonPrimeCount);
            cout << "Cac so khong phai la so nguyen to: ";
            for (int i = 0; i < nonPrimeCount; ++i)
            {
                cout << nonPrimeArr[i] << " ";
            }
            cout << endl;
            break;

        case 9:
            sapxep(a, n, mid);
            cout << "Mang sau khi sap xep nua dau tang dan, nua sau giam dan: ";
            for (int i = 0; i < n; ++i)
            {
                cout << a[i] << " ";
            }
            cout << endl;
            break;
        case 10:
            sapxepgiamdan(a, n);
            cout << "Mang sau khi sap xep giam dan la: ";
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            break;
        case 11:
            cout << "Nhap so can chen: ";
            cin >> x;

            chenSo(a, n, x);

            sapXepChen(a, n);

            cout << "Mang sau khi chen " << x << " va sap xep la: ";
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
            break;
        case 12:
            kiemtradoixung(a, n);
if (kiemtradoixung(a, n)) {
        cout << "Mang la doi xung.\n";
    } else {
        cout << "Mang khong doi xung.\n";
    }
            break;
        case 13:

            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong dung ";
            break;
        }
    }
    return 0;
}
