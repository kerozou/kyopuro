// ダイクストラ法　まとめ
//
// ダイクストラ法 (Dijkstra's Algorithm) は最短経路問題を効率的に解くグラフ理論におけるアルゴリズムです。
// スタートノードからゴールノードまでの最短距離とその経路を求めることができます。

//    ダイクストラ法はDP（動的計画法）的なアルゴリズムです。
//    つまり，

        「手近で明らかなことから順次確定していき，その確定した情報をもとにさらに遠くまで確定していく」

//    方法で， DPと同じ精神を持っています。

/*
プログラム的には総当りで各ノードをチェックし、
確定しているか判断、確定していたら次のノードをチェックしコストをアップデート、
というような流れで処理をしていきます。
*/

// http://www.deqnotes.net/acmicpc/dijkstra/
// https://qiita.com/edo_m18/items/0588d290a19f2afc0a84 基本ここ参照


// ダイクストラ法には色々な実装方法があります。
// まず，最小の値を持つ確定ノードを選択する方法に「全てのノードを調べる」単純な方法と，
//「優先度付き待ち行列（プライオリティ・キュー）」を使った方法があります。
// また，ノードやエッジの情報をどのように格納するかによって，プログラムの書き方が少し変わってきます。

// ダイクストラ法は負の閉路を持たない単一始点最短経路問題に使える。
// つまり、辺のコストが0以上で、スタート地点（またはゴール地点）が決まっている場合に、グラフの各頂点への最短経路を計算することができる。

// ダイクストラ法ではノードを中心にエッジを参照するので，エッジの情報はそのエッジの接続元ノードに格納しておくとアクセスしやすくなります。 
// 例えばC++であれば，



   パターンA　- これはO(|V^2|)なので遅い

struct Node{    //  有向グラフにおける設定。    無向の時は逆側の有向エッジを定義する必要あり。
    //このノードから伸びるエッジの情報
    vector<int> e_to;  // 各エッジの接続先のノード
    vector<LL> e_cos; // 各エッジのコスト

    int index; // ノード自身の番号

    //ダイクストラ法のためのデータ
    bool done; // 確定済みかどうか
    LL cost; // このノードへの現時点で判明している最小コスト
};

int main(){
// 初期化
int NIL = -1;   // NIL 設定
int N;cin >> N;     // N　は　ノード数


vector<struct Node> G(N);   //有向グラフ
for(auto n : G){
    n.done = false;
    n.cost = -1;
}
int start = 1;  //  開始地点の決定
G[start].cost = 0;   //　スタートノードのコストは0

//
// ここに各ノードの情報を入力するフォームを作っておく（ノードの接続先や、エッジの重みなど）
//


// アルゴリズム実行
while(true){
    // 確定ノードを探す
    int doneNode = NIL;
    for(auto i : G){
        if( i.done || i.cost < 0)continue;      // 確定済み、またはコストが負の時、つまり初期値の時　(最初はstart以外初期値)
        if( doneNode == NIL || i.cost < G[doneNode].cost) doneNode = i;     // if内の条件は左右逆にすると、doneNode == NIL の時に、G[-1].cost になっちゃうので注意。||は左から進む。
    }
    
    // 確定ノードがなくなれば終了
    if(doneNode == NIL)break;

    // 確定フラグを立てる
    G[doneNode].done = true;
   
    // 接続先ノードの情報を更新する。
    rep(i,G[doneNode].e_to.size()-1){
        int to = G[doneNode].e_to[i];       // 接続先ノード番号入手
        LL cost = G[doneNode].cost + G[doneNode].e_cost[i];    // 接続先ノードへのコスト
        if(G[to].cost < 0 || cost < G[to].cost)G[to].cost = cost;   // ノードへのコストが最短を更新できた場合更新する
    }

}
// ここまで
////////////////////

// 以上は構造体を用いてダイクストラ法を書いてみた。
// 以下ではプライオリティキューを用いて関数実装する。

// 構造体のコンストラクタに関しては　http://kyos1704.hatenablog.com/entry/2013/09/17/141305　参照
// 自分的な解釈としては、一塊のデータを投げられたときに中身をそのままEdge型の内容として獲得するために必要なもの。
// vector の中の型とかとして使うときに必要っぽい。下の場合は要素が二個なので、pairで同じことができそう。
// 要素が増えてきたり、いろんな型が入ってごちゃごちゃしてきたりしたら、構造体のほうが便利。
// あと、視認性に優れている。p-queueの方は計算量がO(（N+M)logV )になるらしい。早い。
// 計算量は頂点数をN, 辺数をMとするとO((N+M)logN)。N,M <= 10^5程度のときに適用可能。

  パターンB - p-queue を使う方法　早い。




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

// 主な使い方としては、
   vector<vector<Edge>> G(N);  //で有向グラフを定義して
// 
   rep(i,X){
      int from,to; LL cost; 
      cin >> from >> to >> cost;
      G[from].emplace_back(to,cost);
   }
// としてグラフGに入力　emplace_backはpush_backとほとんど変わらんけど、pairをmake_pairせずにそのままぶっこめる。あと、なんか条件によってpush_backできないときがあって変わってくるらしい。

// そんでdijkstraにぶっこむ。

// 以下にmain内の実装例

int main(){
    int N,M;
    LL T; cin >> N >> M >> T;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];
    vector<vector<Edge>> G(N),rG(N);
    rep(i,M){
        int a,b;
        LL c;
        cin >> a >> b >> c;
        a--;b--;    //0-index にそろえる
        G[a].emplace_back(b,c);
        rG[b].emplace_back(a,c);    // 有向グラフを無向グラフ化するということなので、帰り道は行きと逆に設定して追加しておく。
    }
    auto d = dijkstra(N,G,0);
    auto rd = dijkstra(N,rG,0);
    LL ans = 0;
    rep(i,N){
        LL need = d[i]+rd[i];
        if(need > T)continue;
        ans = max(ans,(T-need)*A[i]);
    }
    cout << ans << endl;
}


//dijkstra法は　
// 1.負の経路をもたない
// 2.スタート地点が決まっているとき
//に使える。

// 計算量O((N+M)logN) N,Mが10^5程度まで行ける。


パターンC　-  最短距離にたどり着く一つ前の頂点も記録するダイクストラ法
// これを使うと、最短経路を求められる。ついで、経路復元もできそう。

typedef struct edge{
    int v;              // エッジの　終点　だと思われる
    LL w;               // エッジの　重み　だと思われる
    edge() {}                                              // 構造体のコンストラクタ 
    edge(int v, LL w) : v(v), w(w) {};                     // これはv,wを同時にpush_back(emplace_back)するために必要
} Edge;

vector<LL> dijkstra(int n, vector<vector<Edge> >& G, int s,vector<int> &prev) {   // N , G , start (ノードは0-index) , previous (直前のマス)
    prev.resize(n);
    fill(all(prev),-1); //prevの初期化
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
                prev[e.v] = u;  //直前のマスを記録
                que.push(make_pair(-d[e.v], e.v));              // 更新したノードの（最短距離と番号）をpush
            }                                                   // つまり、拡張for文でpushされた要素たちは、最短距離を更新できなくなると廃棄されて行ってemptyになるということ。
        }
    }
    return d;                                                   // 各ノードまでのstart地点からの最短距離が出る。
}

vector<int> get_path(int t,vector<int> &prev){                  // start から t までの最短経路を求める。　あらかじめdijkstraしてから使う。求める経路が複数あるときのためにprevを引数にしとく。
    vector<int> path;
    for(int i = t;i != -1;i = prev[i])path.push_back(i);        // iがstartになるまでprev[i]をたどっていく
    reverse(all(path));                                         // このままだと逆順なので、元に戻す
    return path;
}