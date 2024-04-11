#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void nhapMangTangDan(int arr[], int &size)
{
    cout << "Nhap so luong phan tu cua mang (toi da " << MAX_SIZE << " phan tu): ";
    cin >> size;

    if (size <= 0 || size > MAX_SIZE)
    {
        cout << "So luong phan tu khong hop le.\n";
        return;
    }

    cout << "Nhap cac phan tu cua mang tang dan:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];

        if (i > 0 && arr[i] <= arr[i - 1])
        {
            cout << "Phan tu phai lon hon phan tu truoc do.\n";
            --i;
        }
    }
}

void tronMangTangDan(int arr1[], int size1, int arr2[], int size2, int arrResult[], int &sizeResult)
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            arrResult[k++] = arr1[i++];
        }
        else
        {
            arrResult[k++] = arr2[j++];
        }
    }

    while (i < size1)
    {
        arrResult[k++] = arr1[i++];
    }

    while (j < size2)
    {
        arrResult[k++] = arr2[j++];
    }

    sizeResult = k;
}

void xuatMang(int arr[], int size)
{
    cout << "Cac phan tu cua mang:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[MAX_SIZE], arr2[MAX_SIZE], arrResult[MAX_SIZE * 2];
    int size1, size2, sizeResult;

    cout << "Nhap mang thu nhat:\n";
    nhapMangTangDan(arr1, size1);

    cout << "Nhap mang thu hai:\n";
    nhapMangTangDan(arr2, size2);

    tronMangTangDan(arr1, size1, arr2, size2, arrResult, sizeResult);

    cout << "Mang sau khi tron:\n";
    xuatMang(arrResult, sizeResult);

    return 0;
}