#include <iostream>
#include <sstream>
#include <cmath>
#include <complex>
using namespace std;

int solve (double a,double b, double c) {
    double check = (pow(b, 2) - 4 * a * c);

    if (check >= 0 ) {
        double square_root = sqrt((pow(b,2)+(-4 *c* a)));
        double plus_square_root = ((-b) + square_root)/(2*a);
        double minus_square_root = ((-b) - square_root)/(2*a);
        cout <<"x=" << plus_square_root << "  x=" << minus_square_root << endl;
    }
    else {
        complex<double> sqrt_discriminant = sqrt(complex<double>(check, 0));
        complex<double> plus_square_root = ((-b) + sqrt_discriminant) / (2.0 * a);
        complex<double> minus_square_root = ((-b) - sqrt_discriminant) / (2.0 * a);
        cout <<" else x=" << plus_square_root << "  x=" << minus_square_root << endl;
    }

}
int main() {
    double a,b,c;
    cout << "Welcome to the Quad Equation Program!" << endl;
    cout<<"Please make sure you equation is setup in ax^2 + bx +c form"<<endl;
    cout <<"Enter the value of a: ";
    cin >> a;
    cout <<"Enter the value of b: ";
    cin >> b;
    cout <<"Enter the value of c: ";
    cin >> c;
    cout << solve(a,b,c) << endl;
}
