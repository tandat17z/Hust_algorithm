#include<bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
    Point(int x, int y): x(x), y(y){

    }
};

struct Segment{
    Point A, B;
    Segment(Point A, Point B):A(A), B(B){

    }
};

long long dist(Point &a, Point &b){
    long long x = a.x - b.x;
    long long y = a.y - b.y;
    return x*x + y*y;
}

long long dot_product(Point &O, Point &A, Point &B){
    long long xa = A.x - O.x; long long ya = A.y - O.y;
    long long xb = B.x - O.x; long long yb = B.y - O.y;
    return xa*xb + ya*yb;
}

long long cross_product(Point &O, Point &A, Point &B){
    long long xa = A.x - O.x; long long ya = A.y - O.y;
    long long xb = B.x - O.x; long long yb = B.y - O.y;
    return xa*yb - ya*xb;
}

bool checkIntersection(Segment s1, Segment s2){ // s1: A,B ,s2: C, D
    // Kiểm tra C, D nằm khác phía so với AB
    if(cross_product(s1.A, s1.B, s2.A)*cross_product(s1.A, s1.B, s2.B) > 0) return false;
    // Kiểm tra A, B nằm khác phía so với CD
    if(cross_product(s2.A, s2.B, s1.A)*cross_product(s2.A, s2.B, s1.B) > 0) return false;

    return true;
}
vector<Segment> list_segment;

int main(){
    freopen("input/data3.txt", "r", stdin);
    int n;
    cin >> n;
    for( int i = 0; i<n; i++){
        int xa, ya, xb, yb;
        cin >> xa >> ya >> xb >> yb;
        list_segment.push_back(Segment(Point(xa, ya), Point(xb, yb)));
    }

    int cnt = 0;
    for(int i = 0; i<list_segment.size() - 1; i++){
        for(int j = i+1; j<list_segment.size(); j++){
            if( checkIntersection(list_segment[i], list_segment[j])) cnt += 1;
        }
    }
    cout << cnt;
}
