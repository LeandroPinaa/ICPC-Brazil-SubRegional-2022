#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 100005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

int a[NMAX];
pii b[NMAX];
set<pii>grupol,resto;
int n,sum_k,sum_l,k,l;

void relax(){
    while(grupol.size()>l){
        pii value = *(grupol.begin());
        sum_l -= value.first;
        grupol.erase(value);
        resto.insert(value);
    }
    while(grupol.size()<l && resto.size()>0){
        pii value = *(--resto.end());
        sum_l += value.first;
        resto.erase(value);
        grupol.insert(value);
    }
}

void add(int i){
    sum_l += b[i].first;
    grupol.insert(b[i]);
    relax();
}

void remove(int i){
    if(grupol.count(b[i])){
        sum_l -= b[i].first;
        grupol.erase(b[i]);
    }
    else resto.erase(b[i]);
    relax();
}

int32_t main(){ faster
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        cin >> b[i].first;
        b[i].second = i;
    } 
    cin >> k >> l;
    for(int i=1;i<=k;i++){
        sum_k += a[i];
        add(i);
    }
    int ans = sum_k+sum_l;
    for(int i=k,j=n;i>=1;i--,j--){
        sum_k -= a[i];
        remove(i);
        sum_k += a[j];
        add(j);
        ans = max(ans,sum_k+sum_l);
    }
    cout << ans << '\n';    
}
/*
5
9 7 2 2 9
5 2 2 3 1
2 1

*/