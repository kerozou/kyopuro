#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
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

int main(){
    int N;cin >> N;
    vector<vector<Edge>> G(N);
    rep(i,N-1){
        int a,b;cin >> a >> b;
        a--;b--;
        G[a].push_back((Edge){b,1LL});
        G[b].push_back((Edge){a,1LL});
    }

    vector<LL> d1;
    vector<LL> d2;

    d1 = dijkstra(N,G,0);
    d2 = dijkstra(N,G,N-1);

    int cf = 0;int cs = 0;
    rep(i,N){
        if(d1[i] <= d2[i])cf++;
        else cs++;
    }
    if(cs >= cf)cout << "Snuke" << endl;
    else cout << "Fennec" << endl;
}

// ABC067 D - Fennec VS. Snuke

// お互いからの距離が近い点はとれる点であり、相手よりも近い点の数が多いほうが勝つというシンプルなゲーム。
// というのも、木構造上でフェネックとスヌケ君の間にあるを取り合うゲームになるわけだが、
// 結局、間にある頂点から派生する部分木もすべて頂点を先にとったほうのものになるため、
// 相手よりも自分のほうが近い距離にある点を調べ上げると、先述した部分木もすべて獲得できる計算になる。
// 実際に図にしてみるとわかりやすい。
// お互いの端にある領域の点はすべて相手より近くなるので、単純にダイクストラで数え上げておけばおｋ。

// フェネックは先行なので、スヌケ君と同じ数の頂点しかとれなかったらフェネックの負けになることは忘れないように。