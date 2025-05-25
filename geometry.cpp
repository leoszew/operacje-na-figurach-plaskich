#include <iostream>
#include <cmath>
#include "geometry.h"

using namespace std;


double distance(point A, point B) {
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}


bool is_triangle(point A, point B, point C) {
    
    return (distance(A, B) + distance(B, C) > distance(A, C)) &&
           (distance(A, B) + distance(A, C) > distance(B, C)) &&
           (distance(A, C) + distance(B, C) > distance(A, B));
}


double area_triangle(point A, point B, point C) {
    if (!is_triangle(A, B, C)) {
        cout << "To nie trojkat " << endl;
        return 0;
    }
    return fabs((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x)) / 2;
}

bool is_inside(point A, point B, point C, point D) {
    double total = area_triangle(A, B, C);
    double area1 = area_triangle(A, B, D);
    double area2 = area_triangle(B, C, D);
    double area3 = area_triangle(C, A, D);
    double suma = area1 + area2 + area3;

    if (suma == total) {
        return true;
    } else {
        return false;
    }
}



double area_pentagon(point A, point B, point C, point D, point E) {
    double area = 0;

    area += area_triangle(A, B, C);
    area += area_triangle(A, C, D);
    area += area_triangle(A, D, E);

    return area;
}


