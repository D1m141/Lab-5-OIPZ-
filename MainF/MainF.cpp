#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include <Windows.h>
using namespace std;

double calculateY(double x, int n) {
    if (n <= 4) {
        throw invalid_argument("�������� n ������� ���� ����� 4.");
    }

    double y = 0.0;

    if (x <= 0) {
        for (int i = 0; i <= n; ++i) {
            y += pow((x - i), 2);
        }
    }
    else {
        y = 1.0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < n; ++j) {
                y *= (x - i - j);
            }
        }
    }

    return y;
}

int main() {
    SetConsoleOutputCP(1251);
    char sv;
    int n;
    double a, b, h, x, y;

    cout << "������ ��� ������� a = ";
    cin >> a;
    cout << "������ ����� ������� b = ";
    cin >> b;
    cout << "������ ���� h = ";
    cin >> h;
    cout << "������ �������� n: ";
    cin >> n;
    cout << "�������� ���������� � ����? (y/n): ";
    cin >> sv;

    ofstream tofile;
    if (sv == 'y' || sv == 'Y') {
        tofile.open("results.txt");
        if (!tofile) {
            cerr << "������� �������� ����� ��� ������." << endl;
            return 1;
        }
    }
    x = a;

    while (x <= b) {
        if (x <= 0) {
            y = 0;
            for (int i = 0; i <= n; i++) {
                y += pow((x - i), 2);
            }
            tofile << x << ", ����: y = " << y << endl;
            cout << x << ", ����: y = " << y << endl;
        }
        else {
            y = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < n; j++) {
                    y *= (x - i - 2 * j);
                }
            }
            tofile << x << ", �������: y = " << y << endl;
            cout << x << ", �������: y = " << y << endl;
        }
        x += h;
    }
    if (sv == 'y' || sv == 'Y') {
        tofile << "ʳ����" << endl;
        tofile.close();
        cout << "���������� ���������" << endl;
    }
    else {
        cout << "ʳ����" << endl;
    }

    return 0;
}
