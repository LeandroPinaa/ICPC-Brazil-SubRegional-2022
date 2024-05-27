#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 200005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

vector<pii>grafo[NMAX];
vector<int>v[NMAX];
int cor[NMAX];
int c2[NMAX]; //contagem das cores fora da subtree de v
int c1[NMAX]; //contagem das cores dentro da subtree de v, logo, entre a aresta i, basta fazer c2[cor[x]] * c1[cor[x]]
int ans[NMAX];
int sz[NMAX],soma;

void DFSsz(int x, int p){
    sz[x] = 1;
    for(auto [viz,ind]:grafo[x]){
        if(viz==p) continue;
        DFSsz(viz,x);
        sz[x] += sz[viz];
    }
}

void add(int c){
    soma -= c2[c] * c1[c];
    c2[c]--;
    c1[c]++;
    soma += c2[c] * c1[c];
}

void remove(int c){
    soma -= c2[c] * c1[c];
    c2[c]++;
    c1[c]--;
    soma += c2[c] * c1[c];
}

void DFS(int x, int p, bool keep, int id){ //chama DFS(1,-1,1,-1);
    int maior=-1,bigchild=-1,aresta=-1;
    for(auto [viz,ind]:grafo[x]){
        if(viz==p) continue;
        if(sz[viz] > maior){
            maior = sz[viz];
            bigchild = viz;
            aresta = ind;
        }
    }
    for(auto [viz,ind]:grafo[x]){
        if(viz==p || viz==bigchild) continue;
        DFS(viz,x,0,ind);
    }
    if(bigchild!=-1){
        DFS(bigchild,x,1,aresta);
        swap(v[bigchild],v[x]);
    }
    v[x].push_back(x);
    add(cor[x]);
    for(auto [viz,ind]:grafo[x]){
        if(viz==p || viz==bigchild) continue;
        for(auto j:v[viz]){
            v[x].push_back(j);
            add(cor[j]);
        }
    }
    if(id!=-1) ans[id] = soma;
    if(!keep){
        for(auto j:v[x]) remove(cor[j]);
    }
}

int32_t main(){ faster
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> cor[i];
        c2[cor[i]]++;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        grafo[a].push_back({b,i});
        grafo[b].push_back({a,i});
    }
    DFSsz(1,-1);
    DFS(1,-1,1,-1); //4°parametro: id, verifica se tem uma aresta pra salvar em ans
    for(int i=1;i<n;i++) cout << ans[i] << " ";
}