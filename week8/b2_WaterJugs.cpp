#include<bits/stdc++.h>

using namespace std;

int a, b, c;

int visited[901][901];
pair<int, int> parent[901][901];
int step[901][901];

vector<pair<int, int> > pump(int x, int y){
    vector<pair<int, int> > child;
    child.push_back(make_pair(x, 0));
    child.push_back(make_pair(0, y));
    child.push_back(make_pair(a, y));
    child.push_back(make_pair(x, b));
    if( x + y > b)
        child.push_back(make_pair( x + y - b, b));
    else
        child.push_back(make_pair( 0, x + y));

    if( x + y > a)
        child.push_back(make_pair( a, x + y - a));
    else
        child.push_back(make_pair( x + y, 0));
    return child;
}

int main(){
    scanf("%d %d %d", &a, &b, &c);

    deque<pair<int, int>> dq;
    visited[0][0] = 1;
    dq.push_back(make_pair(0, 0));
    while( !dq.empty() ){
        int x = dq.front().first;
        int y = dq.front().second;
        visited[x][y] = true;
        step[x][y] = step[parent[x][y].first][parent[x][y].second] + 1;
        dq.pop_front();

        for( auto i: pump(x, y)){
            if( visited[i.first][i.second] == 0 ){
                parent[i.first][i.second] = make_pair(x, y);
                if( i.first == c || i.second == c){
                    cout << step[x][y];
                    // pair<int, int> pa = parent[i.first][i.second];
                    // while( pa.first != 0 || pa.second != 0){
                    //     cout << endl<<  pa.first << " " << pa.second;
                    //     pa = parent[pa.first][pa.second];
                    // }
                    return 0;
                }
                dq.push_back(i);
            }
        }
    }
    cout << -1;
    return 0;
}