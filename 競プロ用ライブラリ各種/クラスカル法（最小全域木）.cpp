
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> siz; // 素集合のサイズを表す配列(1 で初期化)

    UnionFind(int N) : par(N), siz(N, 1){ //最初は全てが根であるとして初期化、頂点数N
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        siz[ry] += siz[rx];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x) { // 素集合のサイズ
        return siz[root(x)];
    }
};




// 頂点a, bをつなぐコストcostの（無向）辺
struct Edge
{
  int a, b, cost;

  // コストの大小で順序定義
  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};


// 頂点数と辺集合の組として定義したグラフ
struct Graph
{
  int n;  // 頂点数
  vector<Edge> es;  // 辺集合

  // クラスカル法で無向最小全域木のコストの和を計算する
  // グラフが非連結のときは最小全域森のコストの和となる
  int kruskal() {
    // コストが小さい順にソート
    sort(es.begin(), es.end());

    UnionFind uf(n);
    int min_cost = 0;

    rep(ei, es.size()) {
      Edge& e = es[ei];
      if (!uf.same(e.a, e.b)) {
        // 辺を追加しても閉路ができないなら、その辺を採用する
        min_cost += e.cost;
        uf.unite(e.a, e.b);
      }
    }

    return min_cost;
  }
};

// 標準入力からグラフを読み込む
Graph input_graph() {
  Graph g;
  int m;
  cin >> g.n >> m;
  rep(i, m) {
    Edge e;
    cin >> e.a >> e.b >> e.cost;
    g.es.push_back(e);
  }
  return g;
}


int main()
{
  Graph g = input_graph();
  cout << "最小全域木のコスト: " << g.kruskal() << endl;
  return 0;
}



// N M  （頂点数　辺の数）
// a b cost


/*

入力例：

5 8
0 1 10
0 3 5
1 2 1
1 3 1000
1 4 500
2 3 100
2 4 10000
3 4 5000

出力例：

最小全域木のコスト: 516

入力例のグラフは冒頭に挙げた最小全域木の例の図に対応します。

クラスカル法の計算量は、辺の数をEとするとO(E log E)になります。
 Union Findの処理がほぼ定数時間であるため、
最初に辺をソートする部分の計算時間が支配的になります。

*/