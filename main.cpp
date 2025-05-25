#include <iostream>
#include "geometry.h"

using namespace std;

int main() {
    point A, B, C, D, E;

    cout << "Podaj punkt A (x y): ";
    cin >> A.x >> A.y;

    cout << "Podaj punkt B (x y): ";
    cin >> B.x >> B.y;

    cout << "Odleglosc miedzy A i B: " << distance(A, B) << endl;

    cout << "Podaj punkt C (x y): ";
    cin >> C.x >> C.y;

    if (is_triangle(A, B, C)) {
        cout << "Punkty A, B i C tworza trojkat." << endl;
    } else {
        cout << "Punkty A, B i C nie tworza trojkata." << endl;
    }

    cout << "Pole trojkata ABC: " << area_triangle(A, B, C) << endl;

    cout << "Podaj punkt D (x y): ";
    cin >> D.x >> D.y;

    if (is_inside(A, B, C, D)) {
        cout << "Punkt D lezy w trojkacie ABC." << endl;
    } else {
        cout << "Punkt D nie lezy w trojkacie ABC." << endl;
    }

    cout << "Podaj punkt E (x y): ";
    cin >> E.x >> E.y;

    double pole = area_triangle(A, B, C) +
                  area_triangle(A, C, D) +
                  area_triangle(A, D, E);

    cout << "Pole pieciokata ABCDE: " << pole << endl;

    return 0;
}
