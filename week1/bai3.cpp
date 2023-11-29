#include<bits/stdc++.h>
using namespace std;

int n;
string s;
void back_tracking(int k){
    if( s.back() == '1' ) {
        s.push_back('0');
        if(s.size() == n) cout << s << endl;
        else back_tracking(k + 1);
        s.pop_back();
    }
    else{
        s.push_back('0');
        if(s.size() == n) cout << s << endl;
        else back_tracking(k + 1);
        s.pop_back();

        s.push_back('1');
        if(s.size() == n) cout << s << endl;
        else back_tracking(k + 1);
        s.pop_back();
    }
}
int main(){
    cin >> n;
    back_tracking(0);
    return 0;
}