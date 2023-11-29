#include<bits/stdc++.h>

using namespace std;

int n;
// int x[1001];
vector<int> x(1001);
vector<int> x_(1001);
int c[1001][1001];
int visited[1001];
int visited_[1001];
int c_min = 1e9;
int min_res = 1e9;
int curr = 0;

int computeDistance(int n, vector<int> x){
    int l = 0;
    for( int i = 0; i<n; i++){
        l += c[x[i]][x[i + 1]];
    }
    return l;
}

void solution(){
    if( min_res > curr + c[x_[n-1]][x_[n]]){
        min_res = curr + c[x_[n-1]][x_[n]];
        x = x_;
    }
}
void Try_(int k){
    for(int i = 2; i <= n; i++){
        if( !visited_[i] ){
            x_[k] = i;
            visited_[i] = true;
            curr += c[x_[k-1]][x_[k]];
            if( k ==  n - 1){
                solution();
            }
            else if( curr + (n - k)*c_min < min_res )
                Try_(k + 1);
            curr -= c[x_[k-1]][x_[k]];
            visited_[i] = false;
        }
    }
}

void greedy(int n, int start){
    vector<int> xx(n + 1, 0);
    vector<bool> vis(n, false);
    xx[0] = start;
    xx[n] = start;
    vis[start] = true;
    for( int i = 1; i< n; i++){
        int min = 1e9;
        int next;
        for( int j = 1; j<= n; j ++){
            if(vis[j] == false && c[xx[i-1]][j] < min){
                min = c[xx[i-1]][j];
                next = j;
            }
        }
        xx[i] = next;
        vis[next] = true;
    }

    int dis = computeDistance(n, xx);
    if( min_res > dis){
        min_res = dis;
        x = xx;
    }
}
int main(){
    freopen("data3.txt", "r", stdin);
	scanf("%d", &n);
    int M = 0;

    for( int i = 1; i <= n ; i++){
        for( int j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if( i != j)
                c_min = min(c_min, c[i][j]);
        }
    }
    if( n <= 20){
        x_[0] = 1; x_[n] = 1;
        Try_(1);
    }
    else{
        if( n > 100){
            greedy(n, 1);
        }
        else{
            for(int start = 1; start<=n; start++){
                greedy(n, start);
            }
        }
        bool out = true;
        int count = 0;
        while( out ){
            count ++;
            out = false;
            for( int i = 1; i<n; i++){
                for( int j = i + 1; j < n; j++){
                    // changeItinerary
                    vector<int> new_x = x;
                    for( int k = 0; k <= (j - i); k++){
                        new_x[ i + k] = x[ j - k];
                    }
                    // new_x[i] = x[j];
                    // new_x[j] = x[i];
                    
                    int new_cost = computeDistance(n, new_x);
                    // cout << new_cost << endl;
                    if( new_cost < min_res){
                        min_res = new_cost;
                        x = new_x;
                    }
                }
            }
        }
    }

    printf("%d\n", n);
    for( int i = 0; i<n; i++){
        printf("%d ", x[i]);
    }

    // vector<int> x__ = {1, 3, 10, 5, 4, 8, 6, 9, 2, 7, 1};
    // cout << endl << computeDistance(n, x) << endl;
	return 0;
}
