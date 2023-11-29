#include<bits/stdc++.h>
using namespace std;

int n, k, q;
int d[13];
int c[13][13];
int total_d, empty_route;
int x[13][100];
int cur_total_d, cur_capa, min_total_d = 1e9;
int mark[100], visited;

void TryY(int ky);
void TryX(int kx, int ky);

void input(){
    cin >> n >> k >> q;
    for( int i = 1; i <= n; i++){
        cin >> d[i];
        total_d += d[i];
    }
    empty_route = k - (total_d/q + 1);

    for( int i = 0; i<= n; i++){
        for( int j = 0; j<= n; j++){
            cin >> c[i][j];
        }
    }
}

bool checkY(int i, int ky){
    if( i != 0 && mark[i] ) return false;
    if( i == 0 && ky - 1 < empty_route ) return true;
    if( i > x[ky - 1][0] ) return true;
    return false;
}

void solution(){
    // cout << cur_total_d << endl;
    min_total_d = min(min_total_d, cur_total_d);
    // for( int i = 1; i <= k ; i++){
    //     int j = 0;
    //     while(x[i][j] != 0)
    //         cout << x[i][j++] << " ";
    //     cout << endl;
    // }
    // cout << "------------" << endl;
}

void TryY(int ky){
    for(int i = 0; i<=n ; i++){
        if( checkY(i, ky) ){
            // cout << i << endl;
            x[ky][0] = i;
            if( i != 0){
                cur_capa = d[i];
                visited -= 1; mark[i] = true;
                cur_total_d += c[0][i];
                if( cur_total_d < min_total_d)
                    TryX(1, ky);
                visited += 1; mark[i] = false;
                cur_total_d -= c[0][i];
            } 
            else TryY(ky + 1);
            x[ky][0] = 0;
        }
    }
}

bool checkX(int i, int kx){
    if( mark[i] ) return false;
    if( cur_capa + d[i] > q) return false;
    return true;
}

void TryX(int kx, int ky){
    for( int i = 0; i<=n ; i++){
        if( checkX(i, kx) ){
            int _ = cur_capa;
            x[ky][kx] = i;
            cur_total_d += c[ x[ky][kx - 1] ][i];
            if( cur_total_d < min_total_d)
                if( i == 0){
                    if( ky == k && visited == 0) solution();
                    else if( ky < k) {
                        TryY(ky + 1);
                    }
                }
                else {
                    cur_capa += d[i];
                    visited -= 1; mark[i] = true;
                    TryX(kx + 1, ky);
                    mark[i] = false; visited += 1;
                }
            cur_capa = _;
            x[ky][kx] = 0;
            cur_total_d -= c[ x[ky][kx - 1] ][i];
        }
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    input();
    visited = n;
    TryY(1);

    cout << min_total_d;
    return 0;
}