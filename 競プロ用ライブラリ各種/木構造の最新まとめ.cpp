// 木構造のDFS　や　オイラーツアーなど

// DFS
vector<vector<int>> G;

void dfs(int v,int p){
    for(auto nv : G[v]){
        if(nv == p)continue;
        /* ここに処理 */
        dfs(nv,v);
    }
}

// 辺の情報が必要になるとき
// Edge を使うといい

typedef struct Edge{
    int to;
    int num;
} Edge;

        // 入力
        G[a].push_back((Edge){b,i});
        G[b].push_back((Edge){a,i});

        // 構造体は nv.to とか nv.num とか使う

// Euler Tour

// euler[] には　1 2 3 4 3 2 1 のように辿った頂点が書いてある
// beg[] は部分木の始点、en[] は部分木の終点を示す
// なので、euler の [beg[v] , en[v]) が部分木のvを根とするノード集合のツアー

// 部分木毎の子ノードの数はEulerTourの性質から (en[i]-beg[i])/2 で求まる。
// この場合、根となるノード自身は数にカウントされない。                         ※注意
// queryはO(1)のはず

vector<vector<int>> G;
vector<int> euler;
vector<int> beg;
vector<int> en;
int ct_e = 0;

void dfs_Euler(int v,int p){
    beg[v] = ct_e;
    euler.push_back(v);
    ct_e++;
    for(auto nv : G[v]){
        if(nv == p)continue;
        dfs_Euler(nv,v);
        euler.push_back(v);
        ct_e++;
    }
    en[v] = ct_e;
}


// 木DP

//そもそも木DPとはなにか？
根から子に向かって進んでいくのが DFS で、子から根に向かって走査するのが 木DP くらいの認識でよさそう。

//木DPするために必要なこと
まず、DFSと違い 根から子 へと動きながら 子から根 を見る必要がある時点で DFS 中でDPを組めないことは理解しなくてはいけない。
なので、DFSを必要なパーツ集めに使い（前処理）そのあとで DP を行えばいい。

ここで必要なパーツは
1. 各子ノードの親の配列 par[i]
2. EulerTourで得た部分木のindex配列
3. 上のindexとpar,別に用意したrootを使って得た 各ノードを根とする部分木 毎のクエリの結果を格納した配列
の以上である。

1 はDFSでO(N)
2 もDFSでO(N)
3 は部分木の走査が全体としてEulerTourで得た辺の数だけ調べるはずなので、O(2N-1)となるはず。つまりO(N)。

以上について全てのノードを根として調査するので、全体の計算量はO(N^2)になる。

各回の細かい動作については以下に記す。

1. DFS中でparを記録するだけ。DFS中のcontinueを回った時にでも書き込めばよさそう。
2. 上記EulerTour参照
3. 部分木のrootが深い順にpairで取っておいた配列を降順ソートして、深い順に部分木を作って親に投げていく。
   根までたどり着いたら終了。


// 全方位木DP
