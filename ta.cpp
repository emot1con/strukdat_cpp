#include <iostream>
using namespace std;

struct Vector
{
    int *data;
    int capacity;
    int length;
};

void init(Vector &v)
{
    v.capacity = 2;
    v.length = 0;
    v.data = new int[v.capacity];
}

void resize(Vector &v, int newCap)
{
    int *newData = new int[newCap];
    for (int i = 0; i < v.length; i++)
    {
        newData[i] = v.data[i];
    }
    delete[] v.data;
    v.data = newData;
    v.capacity = newCap;
}

void push_back(Vector &v, int value)
{
    if (v.length == v.capacity)
    {
        resize(v, v.capacity * 2);
    }
    v.data[v.length] = value;
    v.length++;
}

void display(Vector &v)
{
    cout << "[";
    for (int i = 0; i < v.length; i++)
    {
        cout << v.data[i];
        if (i < v.length - 1)
            cout << ", ";
    }
    cout << "]\n";
}

double average(Vector &v)
{
    if (v.length == 0) return 0;
    int sum = 0;
    for (int i = 0; i < v.length; i++)
    {
        sum += v.data[i];
    }
    return (double)sum / v.length;
}

int main()
{
    Vector suhu;
    init(suhu);

    cout << "=== Program Monitoring Suhu Hewan Kebun Binatang ===\n";
    cout << "Masukkan suhu tubuh hewan (dalam Celcius), -1 untuk berhenti:\n";

    int x;
    while (true)
    {
        cout << "Suhu: ";
        cin >> x;
        if (x == -1) break;
        push_back(suhu, x);
    }

    cout << "\nData suhu yang tercatat: ";
    display(suhu);

    cout << "Rata-rata suhu hewan = " << average(suhu) << " C" << endl;

    return 0;
}
