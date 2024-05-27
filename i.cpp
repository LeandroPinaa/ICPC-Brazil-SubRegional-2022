#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    bool flag=true;
    for(int i=0;i<8;i++){
        cin >> x;
        if(x==9) flag=false;
    }
    if(flag) cout << "S" << endl;
    else cout << "F" << endl;
}