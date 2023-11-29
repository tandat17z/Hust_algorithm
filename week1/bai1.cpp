#include<bits/stdc++.h>

using namespace std;

int n;
string s;

void try_(int k){
    s.push_back('0');
    if( s.size() == n) cout << s << endl;
    else try_(k + 1);
    s.pop_back();

    s.push_back('1');
    if( s.size() == n) cout << s << endl;
    else try_(k + 1);
    s.pop_back();
}
int main(){
    scanf("%d", &n);
    try_(0);
    return 0;
}