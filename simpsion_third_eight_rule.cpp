#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x;
}

int main() {
    double a, b;
    int n;
    cout << "Enter the lower limit of integration (a): ";
    cin >> a;
    cout << "Enter the upper limit of integration (b): ";
    cin >> b;
    cout << "Enter the number of subintervals (n, must be a multiple of 3): ";
    cin >> n;

    if (n % 3 != 0) {
        cout << "Number of subintervals (n) must be a multiple of 3 for Simpson's 3/8 rule." << endl;
        return 1;
    }

    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            result += 2 * f(x);
        } else {
            result += 3 * f(x);
        }
    }

    result *= (3 * h / 8);

    cout << "\nThe approximate value of the integral is: " << result << endl;

    return 0;
}
