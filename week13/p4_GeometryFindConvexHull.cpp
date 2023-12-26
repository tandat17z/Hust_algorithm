#include<bits/stdc++.h>

using namespace std;

#define N 100000

struct Point{
    double x, y;
    Point(){

    }
    Point(int x, int y): x(x), y(y){

    }
};

Point P[N];
int n;
vector<Point> C;

void input(){
    cin >> n;
    for( int i = 0; i<n; i++){
        int u, v;
        cin >> u >> v;
        P[i].x = u;
        P[i].y = v;
    }
}

long long dist2(Point &a, Point &b){
    long long x = a.x - b.x;
    long long y = a.y - b.y;
    return x*x + y*y;
}

long long cross_product(Point &O, Point &A, Point &B){
    long long xa = A.x - O.x; long long ya = A.y - O.y;
    long long xb = B.x - O.x; long long yb = B.y - O.y;
    return xa*yb - ya*xb;
}

bool cmp(Point &A, Point &B){
    int cp = cross_product(P[0], A, B);
    return cp == 0 ? dist2(P[0], A) < dist2(P[0], B) : cp > 0;
}
int  ccw(Point &A, Point &B, Point &C){
    int cp = cross_product(A, B, C);
    return cp == 0 ? 0 : (cp < 0 ? -1 : 1);
}

void solve(){
    int k = 0;
    for( int i = 1; i < n; i++){
        if( P[i].y < P[k].y || P[i].y == P[k].y && P[i].x < P[k].x) k = i;
    }

    //swap
    Point temp = P[0];
    P[0] = P[k];
    P[k] = temp;

    // for( int i = 0 ; i< n; i++){
    //     cout << P[i].x << P[i].y << endl;
    // }
    // cout << "-----" << endl;;
    sort(P + 1, P + n, cmp);
    // for( int i = 0 ; i< n; i++){
    //     cout << P[i].x << P[i].y << endl;
    // }
    C.push_back(P[0]); C.push_back(P[1]);

    for( int i = 2; i<n ; i++){
        while( C.size() > 1 && ccw(C[C.size() - 2], C[C.size() - 1], P[i]) <= 0)
            C.pop_back();
        C.push_back(P[i]);
    }

    //print
    cout <<  C.size() << endl;
    for( auto p: C){
        cout << p.x << " " << p.y << endl;
    }
}
int main(){
    freopen("input/data4.txt", "r", stdin);
    input();
    solve();
}
