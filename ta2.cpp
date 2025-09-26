#include <iostream>
using namespace std;

void tukar(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

int main()
{
    int n;
    int arr[1005];

    cout << "=== Program Pengurutan Nilai Ujian Mahasiswa ===" << endl;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    cout << "Masukkan nilai ujian mahasiswa: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nilai mahasiswa ke-" << (i + 1) << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                tukar(&arr[i], &arr[j]);
            }
        }
    }

    cout << "\n=== Hasil Pengurutan Nilai (Ascending) ===" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Mahasiswa ke-" << (i + 1) << " -> Nilai: " << arr[i] << endl;
    }

    return 0;
}
