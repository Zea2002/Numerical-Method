#include <bits/stdc++.h>
using namespace std;

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

    double value;
    cout << "\nEnter the value of x to interpolate: ";
    cin >> value;

    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (value - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    cout << "\nThe interpolated value at x = " << value << " is " << result << endl;

    return 0;
}
