#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 1005
#define MOD 1000000007
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

int tamanho[NMAX][NMAX];
pii parent[NMAX][NMAX];
bool grafo[NMAX][NMAX][4];
bool marc[NMAX][NMAX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool dentro(int x, int y){
    if(x>=0&&x<NMAX&&y>=0&&y<NMAX) return true;
    return false;
}

int BFS(int i, int j){
    marc[i][j] = true;
    queue<pii>fila;
    fila.push({i,j});
    int quantos = 1;
    while(!fila.empty()){
        auto [x,y] = fila.front(); fila.pop();
        for(int d=0;d<4;d++){
            if(grafo[x][y][d]){
                int X = x+dx[d];
                int Y = y+dy[d];
                if(!marc[X][Y]){
                    marc[X][Y] = true;
                    quantos++;
                    fila.push({X,Y});
                }
            }    
        }
    }
    return quantos;
}

pii find(pii x){
    if(x == parent[x.first][x.second]) return x;
    return parent[x.first][x.second] = find(parent[x.first][x.second]);
}

void merge(pii i, pii j){
    i = find(i);
    j = find(j);
    if(i==j) return; //mesmo grupo
    if(tamanho[i.first][i.second] < tamanho[j.first][j.second]) swap(i,j);
    parent[j.first][j.second] = i;
    tamanho[i.first][i.second] += tamanho[j.first][j.second];
}

void buildunionfind(){
    for(int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX;j++){
            parent[i][j] = {i,j};
            tamanho[i][j] = 1;
        }
    }
}

int main(){ faster
    vector<pii>v;
    int n;
    cin >> n; n++;
    buildunionfind();
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        x+=2; y+=2;
        v.push_back({x,y});
    }
    for(int i=1;i<n;i++){
        if(v[i].first == v[i-1].first){
            int l = min(v[i].second,v[i-1].second);
            int r = max(v[i].second,v[i-1].second);
            for(int j=l+1;j<=r;j++){
                merge({v[i].first,j},{v[i].first-1,j});
            }
        }
        else{
            int l = min(v[i].first,v[i-1].first);
            int r = max(v[i].first,v[i-1].first);
            for(int j=l;j<r;j++){
                merge({j,v[i].second},{j,v[i].second+1});
            }
        }
    }
    // agora que a gente juntou todos os pares de coordenadas nos mesmos grupos, todo e qualquer traço do grid de
    // grupo diferente, a gente monta um caminho permitido, um grafo matriz, afirmando que pode ir nesse caminho
    for(int x=0;x<NMAX;x++){
        for(int y=0;y<NMAX;y++){
            for(int d=0;d<4;d++){
                int X = x+dx[d];
                int Y = y+dy[d];
                if(!dentro(X,Y)) continue;
                if(find({x,y}) != find({X,Y})){
                    grafo[x][y][d] = 1; // a coordenada é permitida ir para a direção d
                }
            }
        }
    }
    BFS(0,0); // pra percorrer todo o grid e definir as bordas
    int ans = 0;
    for(int x=0;x<NMAX;x++){
        for(int y=0;y<NMAX;y++){
            if(!marc[x][y]){
                ans = max(ans,BFS(x,y));
            }
        }
    }
    cout << ans << '\n';
}