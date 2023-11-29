//CPP 
#include <bits/stdc++.h> 
using namespace std;

int n;
string s;
vector<bool> chk;

void back_tracking(int k){
    for( int i = 1; i<= n; i++){
        if( chk[i] == false){
            chk[i] = true;
            s = s + to_string(i) + " ";
            if( s.length() == 2*n) cout<< s << endl;
            else back_tracking(k + 1);
            s.pop_back(); s.pop_back();
            chk[i] = false;
        }
    }
}
int main() 
{
    cin >> n;
    chk = vector<bool>(n);
    back_tracking(0);
    return 0;
}