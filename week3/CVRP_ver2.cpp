#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int n, k, Q;
int d[N];
int c[N][N];

// Cấu trúc dữ liệu bổ sung
int y[N];
//int x[N]; // điểm tiếp theo của điểm i
bool visited[N];
int load[N];

int cnt = 0; // số điểm đã được giao hàng
int res = 100000;
int cur = 0;

int total_load = 0;
int cur_load = 0;
void input(){
    scanf("%d %d %d", &n, &k, &Q);
    for(int i = 1; i<=n; i++){
        scanf("%d", &d[i]);
        total_load += d[i];
    }
    for( int i = 0; i<=n; i++){
        for( int j = 0; j <= n; j++){
            scanf("%d", &c[i][j]) ;
        }
    }

}

bool checkX(int arg, int i);
bool checkY(int arg, int i);
void tryX(int arg, int s);
void tryY(int arg);

void solution(){
    //cout << "solution" << endl;
    res = min(res, cur);
}

bool checkX(int arg, int i){
    if( i == 0) return true;

    if( visited[i] == true) return false;
    if( load[arg] + d[i] > Q) return false;

    return true;
}

void tryX(int arg, int s){ // xe thứ arg đang tại điểm s -> cần xác định điểm tiếp theo
    for( int i = 0; i <= n; i++){
        if( checkX(arg, i)){
            //cout << "X: " << arg << " - " << i << endl;
            //x[s] = i;
            cur += c[s][i];
            if( cur < res ){
                if( i == 0){
                    if( cnt == n ) solution();
                    else if( arg < k && (k - arg)*Q >= total_load - cur_load) tryY(arg + 1);
                }
                else{
                    visited[i] = true;
                    cnt += 1;
                    load[arg] += d[i];
                    cur_load += d[i];

                    tryX(arg, i);

                    cnt -= 1;
                    load[arg] -= d[i];
                    visited[i] = false;
                    cur_load -= d[i];
                }
            }
            cur -= c[s][i];
        }
    }
}

bool checkY(int arg, int i){
    if( visited[i] == true) return false;
    if( load[arg] + d[i] > Q) return false;
    return true;
}

void tryY(int arg){ // Tìm điểm xuất phát của xe k
    for(int i = y[arg-1] + 1; i<=n ;i++){
        if( checkY(arg, i)){
            //cout << "Y: " << arg << " - " << i << endl;
            y[arg] = i;
            cur += c[0][i];
            visited[i] = true;
            load[arg] += d[i];
            cur_load += d[i];
            cnt += 1;

            if( cur < res) tryX(arg, i);

            cnt -= 1;
            visited[i] = false;
            load[arg] -= d[i];
            cur -= c[0][i];
            cur_load -= d[i];
        }
    }
}

int main(){
    freopen("input/data1.txt", "r", stdin);
    input();
    tryY(1);
    printf("%d", res);
    return 0;
}
