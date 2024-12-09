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
    cout << "Enter the number of subintervals (n, must be even): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Number of subintervals (n) must be even for Simpson's 1/3 rule." << endl;
        return 1;
    }

    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            result += 2 * f(x);
        } else {
            result += 4 * f(x);
        }
    }

    result *= (h / 3);

    cout << "\nThe approximate value of the integral is: " << result << endl;

    return 0;
}
