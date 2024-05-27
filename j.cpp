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

int valorcarta[15];
int qtd[15];

int32_t main(){ faster
    for(int i=1;i<=13;i++){
        if(i>10) valorcarta[i] = 10;
        else valorcarta[i] = i;
        qtd[i] = 4;
    }
    int n;
    cin >> n;
    int a,b,joao=0,maria=0;
    cin >> a >> b;
    qtd[a]--,qtd[b]--;
    joao = valorcarta[a]+valorcarta[b];
    cin >> a >> b;
    qtd[a]--,qtd[b]--;
    maria = valorcarta[a]+valorcarta[b];
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        qtd[x]--;
        joao += valorcarta[x];
        maria += valorcarta[x];
    }
    bool flag=false;
    for(int i=1;i<=13;i++){
        if(qtd[i]==0) continue;
        if( (joao+valorcarta[i]>23 && maria+valorcarta[i]<=23) || maria+valorcarta[i]==23){
            flag = true;
            cout << valorcarta[i] << '\n';
            break;
        } 
    }
    if(!flag) cout << "-1\n";
}