#include<bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
    Point(int x, int y): x(x), y(y){

    }
};

long long dist2(Point &a, Point &b){
    long long x = a.x - b.x;
    long long y = a.y - b.y;
    return x*x + y*y;
}

// Tích vô hướng OA, OB
long long dot_product(Point &O, Point &A, Point &B){
    long long xa = A.x - O.x; long long ya = A.y - O.y;
    long long xb = B.x - O.x; long long yb = B.y - O.y;
    return xa*xb + ya*yb;
}


int main(){
    // freopen("input/data2.txt", "r", stdin);
    int n;
    cin >> n;
    for( int i =1; i<=n; i++){
        int x1, x2, x3, y1, y2, y3;
        cin >> x1 >> y1
            >> x2 >> y2
            >> x3 >> y3;
        Point A(x1, y1), B(x2, y2), C(x3, y3);
        long long k = dot_product(A, B, C);
        if( k*k ==  dist2(A, B)*dist2(A, C) && k <= 0) 
            cout << "1" << endl;
        else cout << "0" << endl;
    }
}
