#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 0;; i++){
        if(y & (1 << i)){
            cout << n - 1 - i << endl;
            break;
        }
    }
}