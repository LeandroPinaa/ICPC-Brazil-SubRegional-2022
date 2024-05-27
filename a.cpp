#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 100005
#define MOD 1000000007
#define int long long
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<string,null_type,less<string>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

int32_t main(){ faster
    int n;
    cin >> n;
    string s;
    cin >> s;
    int qtd=0,ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            qtd++;
        }
        else{
            if(qtd>1) ans += qtd;
            qtd=0;
        }
    } if(qtd>1) ans += qtd;
    cout << ans << '\n';
}