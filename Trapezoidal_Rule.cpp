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
    cout << "Enter the number of subintervals (n): ";
    cin >> n;

    double h = (b - a) / n;
    double result = 0.0;

    result += f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        result += 2 * f(x);
    }

    result *= (h / 2);

    cout << "\nThe approximate value of the integral is: " << result << endl;

    return 0;
}
