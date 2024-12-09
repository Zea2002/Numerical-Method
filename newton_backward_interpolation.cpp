#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter the values of x:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter the values of y (f(x)):\n";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    vector<vector<double>> diffTable(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];
        }
    }

    cout << "\nBackward Difference Table:\n";
    for (int i = 0; i < n; i++) {
        cout << setw(10) << x[i] << " ";
        for (int j = 0; j <= i; j++) {
            cout << setw(10) << diffTable[i][j] << " ";
        }
        cout << endl;
    }

    double value;
    cout << "\nEnter the value of x to interpolate: ";
    cin >> value;

    double h = x[1] - x[0];
    double u = (value - x[n - 1]) / h;
    double result = y[n - 1];

    for (int i = 1; i < n; i++) {
        double uTerm = 1;
        for (int j = 0; j < i; j++) {
            uTerm *= (u + j);
        }
        result += (uTerm * diffTable[n - 1][i]) / factorial(i);
    }

    cout << "\nThe interpolated value at x = " << value << " is " << result << endl;

    return 0;
}
