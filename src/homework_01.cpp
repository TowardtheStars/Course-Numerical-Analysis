
#include <iostream>
#include <iomanip>
#include <vector>
#include "../lib/analysis/series.h"

using namespace std;

double kk(double x, int n)
{
    return 1.0/((n+1)*(n+x+1));
}

int main() {
    vector<double> x({0.0, 0.5, 1.0, sqrt(2), 10.0, 100.0, 300.0});
    vector<double> y(7);
    for (int i = 0; i < x.size(); ++i) {
        cout << "x = " << x[i] << ", ";
        y[i] = series<double>(kk, x[i], ABSOLUTE, 0.000001);
        cout << "y = " << setprecision(15) << y[i] << endl;
    }
    cout<<endl;
    return 0;
}