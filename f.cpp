#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 500005
#define MOD 1000000007
#define int long long
#define pii pair<string,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

bool comp(pii a, pii b){
    if(a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

int32_t main(){ faster
    map<string,int>mp;
    vector<pii>ans;
    vector<string>v;
    int n,c;
    cin >> n >> c;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    for(char i='a';i<='z';i++){
        for(auto it:v){
            string aux = it;
            for(int j=0;j<aux.size();j++){
                if(aux[j]=='*'){
                    aux[j] = i;
                }
            }
            mp[aux]++;
        }
    }
    for(auto it:mp) ans.push_back({it.first,it.second});
    sort(ans.begin(),ans.end(),comp);
    cout << ans[0].first << " " << ans[0].second << '\n';
}