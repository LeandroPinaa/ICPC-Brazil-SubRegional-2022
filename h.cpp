#include <bits/stdc++.h>
using namespace std;
#define NMAX 10005

vector<int>grafo[NMAX]; //grafo direcionado basico
vector<int>grafo2[NMAX]; //grafo reverso
vector<int>adj_scc[NMAX]; //DAG a partir das raizes de cada SCC
vector<int>component; //guarda os vertices de um componente
vector<int>roots(NMAX, 0);
set<int>root_nodes; //guarda as raizes, e o adj_scc seria o grafo disso
stack<int>s;
int in[NMAX],out[NMAX];
bool marc[NMAX];

void DFS(int x){
    for(auto viz:grafo[x]){
        if(!marc[viz]){
            marc[viz] = true;
            DFS(viz);
        }
    }
    s.push(x);
}

void DFS2(int x){
    component.push_back(x);
    for(auto viz:grafo2[x]){
        if(!marc[viz]){
            marc[viz] = true;
            DFS2(viz);
        }
    }
}

int main(){
	int N,M,x,y,i;
    cin >> N >> M;
    for(i=0;i<M;i++){
        cin >> x >> y;
        grafo[x].push_back(y);
        grafo2[y].push_back(x);
    }
    for(i=1;i<=N;i++){
        if(!marc[i]){
            marc[i] = true;
            DFS(i);
        }
    }
    memset(marc,false,sizeof marc);
    int aux,scc=0;
    while(!s.empty()){
        aux = s.top();
        s.pop();
        if(!marc[aux]){
            marc[aux] = true;
            DFS2(aux);
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.insert(root);
            component.clear();
            scc++; //se quiser printar a qtd de scc's
        }
    }
    bool flag=true;
    for(i=1;i<=N;i++){
        for(auto u:grafo[i]){
            int root_i = roots[i];
            int root_u = roots[u];
            if(root_i != root_u){
                adj_scc[root_i].push_back(root_u);
                in[root_u] = 1;
                out[root_i] = 1;
                flag=false;
            } 
        }
    }
    
    int inmax=0,outmax=0;
    for(i=1;i<=N;i++){
        if(root_nodes.find(i) != root_nodes.end()){
            if(in[i]==0) inmax++;
            if(out[i]==0) outmax++;
        }
    }
    if(M==0) cout << N << endl; //se n há arestas, a qtd de arestas colocadas será N
    else if(flag) cout << 0 << endl; //já é um grafo fortemente conexo
    else cout << max(inmax,outmax) << endl;
} //query precisa começar antes do nó e terminar depois do nó ql<=l && r<=qr
//fora do intervalo qr<l || ql>r 