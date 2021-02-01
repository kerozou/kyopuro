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
    int v;              // エッジの　終点　だと思われる
    LL w;               // エッジの　重み　だと思われる
    edge() {}                                              // 構造体のコンストラクタ 
    edge(int v, LL w) : v(v), w(w) {};                     // これはv,wを同時にpush_back(emplace_back)するために必要
} Edge;

vector<LL> dijkstra(int n, vector<vector<Edge> >& G, int s) {   // N , G , start (ノードは0-index)
    vector<LL> d(n, LLONG_MAX/10); d[s] = 0;                    // LLONG_MAX はlong　long　の最大値を呼び出す 
    priority_queue<pair<LL, int> > que;                         // p_queue の作成　s　はやっぱりstart地点の番号
    que.push(make_pair(0LL, s));                                // queue に　（0、辺の始点）をpushしてる。                 
    while (!que.empty()) {                                      // queue が空っぽになるまでループ
        auto p = que.top(); que.pop();                          // queue から一個もってくる
        int u = p.second;                                       // もってきたpairから　二番目の情報、つまり対象となるノード番号を獲得
        LL  dist = -p.first;                                    // dist は最短距離の一時変数で、 -p.first と負の数にしているのは、p_queue の greater を省略するため。逆順ソートしたいから。
        if (dist > d[u]) continue;                              // dはそのノードまでの最短距離を表現していると考えられる。
        for (Edge e : G[u]) {                                   // 作ったグラフの　u番目　のもつpairを呼び出してる
            if (d[e.v] > d[u]+e.w) {                            // d[e.v]はEdgeの接続先のこれまでの最短距離。　右辺は接続元までの距離＋辺の重み
                d[e.v] = d[u] + e.w;                            // 最短距離の更新 
                que.push(make_pair(-d[e.v], e.v));              // 更新したノードの（最短距離と番号）をpush
            }                                                   // つまり、拡張for文でpushされた要素たちは、最短距離を更新できなくなると廃棄されて行ってemptyになるということ。
        }
    }
    return d;                                                   // 各ノードまでのstart地点からの最短距離が出る。
}


int main() {
    int N,M;cin >> N >> M;

    vector<vector<Edge>> G(N);

    rep(i,M){
        int from,to; LL cost; 
        cin >> from >> to >> cost;
        from--;to--;
        G[from].emplace_back(to,cost);
        G[to].emplace_back(from,cost);
    }


    LL ans = INF;
    rep(i,N){
        vector<LL> tmp = dijkstra(N,G,i);
        LL t = 0;
        rep(j,N){
            t = max(t,tmp[j]);
        }
        ans = min(ans,t);
    }

    cout << ans << endl;
}

// D012 - バスと避けられない運命

/*
    ダイクストラで各頂点からの最短距離が最大のものをとり、ans = min(ans,tmp) するだけ。
*/