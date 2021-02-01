#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)
typedef struct edge{
    int v;              // エッジの　終点　
    LL w;               // エッジの　重み　
    edge() {}                                             
    edge(int v, LL w) : v(v), w(w) {};          
} Edge;

vector<LL> dijkstra(int n, vector<vector<Edge> >& G, int s) {   // N , G , start (ノードは0-index)
    vector<LL> d(n, LLONG_MAX/10); d[s] = 0;                    
    priority_queue<pair<LL, int> > que;                        
    que.push(make_pair(0LL, s));                                           
    while (!que.empty()) {                                  
        auto p = que.top(); que.pop();                      
        int u = p.second;                                      
        LL  dist = -p.first;                                 
        if (dist > d[u]) continue;                           
        for (Edge e : G[u]) {                                
            if (d[e.v] > d[u]+e.w) {                         
                d[e.v] = d[u] + e.w;                          
                que.push(make_pair(-d[e.v], e.v));           
            }                                                 
        }
    }
    return d;                                                
}

vector<vector<Edge>> G;
vector<bool> ch;
vector<int> dis;
vector<int> ct;
queue<pair<int,int>> que;

void bfs(){
    while(!que.empty()){
        pair<int,int> now = que.front();
        que.pop();
        for(auto t : G[now.F]){
            int to = t.v;
            if(ch[to])continue;
            dis[to] = now.F;
            ct[to] = now.S;
            que.push({to,now.S+1});
            ch[to] = true;
        }
    }
}



int main() {
    int N,M;cin >> N >> M;
    G.resize(N);
    ch.resize(N,false);
    dis.resize(N,-1);
    ct.resize(N,0);
    rep(i,M){
        int a,b;cin >> a >> b;
        a--;b--;
        G[a].emplace_back(b,1);
        G[b].emplace_back(a,1);
    }

    que.push({0,1});
    ch[0] = true;
    bfs();
    bool ok = true;
    auto v = dijkstra(N,G,0);

    rep(i,N){
        if(v[i] != ct[i])ok = false;
    }

    if(ok){
        cout << "Yes" << endl;
        for(int i = 1;i < N;i++){
            cout << dis[i]+1 << endl;
        }
    }
    else{
        cout << "No" << endl;
    }
}   