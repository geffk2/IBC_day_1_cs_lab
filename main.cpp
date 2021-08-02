#include <iostream>
#include <cmath>
using namespace std;

int triangle_exists(double a, double b, double c) {  //TASK 1
    if((a + b) > c && (b + c) > a && (a + c) > b) {
        return 1;
    } else {
        return 0;
    }
}

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {  // TASK 2
    double side12, side13, side23;
    side12 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    side23 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    side13 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    if(triangle_exists(side12, side23, side13)) {
        double p;
        p = (side12 + side23 + side13) / 2;
        return sqrt(p * (p - side12) * (p - side13) * (p - side23));
    } else {
        return -1;
    }
}

int gcd(int a, int b) { // TASK 3
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    cout << "Task 1" << endl << "Enter triangle sides: ";
    int a, b, c;
    cin >> a >> b >> c;
    if(triangle_exists(a, b, c)) {
        cout << "Triangle exists" << endl;
    } else {
        cout << "Triangle doesn't exist" << endl;
    }

    cout << "Task 2" << endl << "Enter coordinates of the triangle's vertices: ";
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double S = triangle_area(x1, y1, x2, y2, x3, y3);
    if(S == -1) {
        cout << "This triangle doesn't exist" << endl;
    } else {
        cout << "Triangle's area is " << S << endl;
    }

    cout << "Task 3" << endl << "Enter two integer numbers: ";
    int x, y;
    cin >> x >> y;
    cout << "The GCD is " << gcd(x, y) << endl;
    return 0;
}
