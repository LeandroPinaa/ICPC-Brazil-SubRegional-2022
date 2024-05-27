#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 500005
#define MOD 1000000007
#define int long long
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

int v[NMAX];
int freq[1000002];

int32_t main(){ faster
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];    
    int flechas=1;
    freq[v[1]] = 1;
    for(int i=2;i<=n;i++){
        if(freq[v[i]+1]>0){
            freq[v[i]+1]--;
            freq[v[i]]++;
        }
        else{
            flechas++;
            freq[v[i]]++;
        }
    }
    cout << flechas << '\n';
}