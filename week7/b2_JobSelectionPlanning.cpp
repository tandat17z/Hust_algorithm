#include<bits/stdc++.h>
using namespace std;

typedef struct Job{
    int d, p;
    Job(int x, int y){
        d = x;
        p = y;
    }
    bool operator < (const Job& other){
        if( p > other.p) return true;
        else if( p == other.p && d < other.d) return true;
        return false;
    }
} Job;

int n;
vector<Job> m;

void input(){
    scanf("%d", &n);
    for(int i = 0; i< n; i++){
        int a, b;
        scanf("%d %d ", &a, &b);
        m.push_back(Job(a, b));
    }
}

int main(){
    freopen("data2.txt", "r", stdin);
    input();
    sort(m.begin(), m.end());
    vector<int> a(n, 0);
    int profit = 0;
    for( auto i: m){
        for( int j = i.d - 1; j >= 0; j--){
            if( a[j] == false){
                a[j] = true;
                profit += i.p;
                break;
            }
        }
    }
    printf("%d", profit);
    return 0;
}