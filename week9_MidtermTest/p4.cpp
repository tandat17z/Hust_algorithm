#include<bits/stdc++.h>

using namespace std;

int n;
// int x[1001];
vector<int> res(1001);
vector<int> x_(1001);
int c[1001][1001];

//backtracking
int visited_[1001];
int c_min = 1e9;
int curr = 0;

//greedy
int visited[1001];
int min_res = 1e9;

void input(){
    scanf("%d", &n);
    for( int i = 1; i <= n ; i++){
        for( int j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if( i != j)
                c_min = min(c_min, c[i][j]);
        }
    }
}

void solution(){
    if( min_res > curr + c[x_[n-1]][x_[n]]){
        min_res = curr + c[x_[n-1]][x_[n]];
        res = x_;
    }
}
void Try_(int k){
    for(int i = 2; i <= n; i++){
        if( !visited_[i] ){
            x_[k] = i;
            visited_[i] = true;
            curr += c[x_[k-1]][x_[k]];

            if( k ==  n - 1) solution();
            else if( curr + (n - k)*c_min < min_res ) Try_(k + 1);

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

    int dis = 0;
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
        dis += c[xx[i-1]][next];
        vis[next] = true;
    }

    if( min_res > dis + c[xx[n-1]][xx[n]]){
        min_res = dis + c[xx[n-1]][xx[n]];
        res = xx;
    }
}

int computeD(int n, vector<int> x){
    int l = 0;
    for( int i = 0; i<n; i++){
        l += c[x[i]][x[i + 1]];
    }
    return l;
}

int main(){
    freopen("input/data4.txt", "r", stdin);
	input();

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

        for( int i = 1; i<n; i++){
            for( int j = i + 1; j < n; j++){
                // changeItinerary
                vector<int> new_x = res;
                
                int cost = c[res[i-1 ]][res[i]] + c[res[j ]][res[j + 1]] , 
                    new_cost = c[res[i-1]][res[j]] + c[res[i]][res[j + 1]];
                for( int k = 0; k <= (j - i) - 1; k++){
                    new_x[ i + k] = res[ j - k];

                    cost += c[res[i + k ]][res[i + k + 1]];
                    new_cost += c[res[j - k]][res[j - k - 1]];
                }
                
                new_x[ j] = res[ i];
                if( new_cost < cost){
                    // min_res = new_cost;
                    res = new_x;
                }
            }
        }
    }

    printf("%d\n", n);
    for( int i = 0; i<n; i++){
        printf("%d ", res[i]);
    }
    cout << endl << computeD(n, res);

    // vector<int> x__ = {1 ,20 ,8 ,11 ,12 ,18 ,15 ,9 ,4 ,7 ,13 ,19 ,3 ,2 ,5 ,14 ,6 ,17, 16, 10, 1};
    // cout << endl << computeD(n, x__) << endl;
	return 0;
}
