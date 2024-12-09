#include <bits/stdc++.h>
using namespace std;


int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

double newtonForwardInterpolation(const vector<double> &x, const vector<double> &y, double x_target)
{
    int n = x.size();
    vector<vector<double>> diffTable(n, vector<double>(n, 0));

    
    for (int i = 0; i < n; i++)
    {
        diffTable[i][0] = y[i];
    }

    
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }

    cout << "Difference Table:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << setw(10) << diffTable[i][j] << " ";
        }
        cout << endl;
    }

    double h = x[1] - x[0];
    double u = (x_target - x[0]) / h;

    double result = diffTable[0][0];
    double u_product = 1;

    for (int i = 1; i < n; i++)
    {
        u_product *= (u - (i - 1));
        result += (u_product * diffTable[0][i]) / factorial(i);
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter the x and y values:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    double x_target;
    cout << "Enter the value of x to interpolate: ";
    cin >> x_target;

    double result = newtonForwardInterpolation(x, y, x_target);
    cout << "The interpolated value at x = " << x_target << " is " << result << endl;

    return 0;
}