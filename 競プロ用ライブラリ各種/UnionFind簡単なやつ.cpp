// UnionFind 

// この構造体は基本機能にsizeをたしたもの
// https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396

// size あると便利そうなので
// struct の最初にあるUnionFindはコンストラクタ。par(N),siz(N,1) は継承（それぞれ初期化している）。
// コンストラクタは起動時(宣言時)に最初に実行される。

// これは大小を整理するやつシンプルな実装（経路圧縮のみ）なので、合体クエリがO(logN)らしい。

// ABC-D120 D - Decayed Bridges
// ABC-D157 D - Friend Suggestions
// CODE FESTIVAL 2016 C - Interpretation


UnionFind uni(N);
↑で作る


struct UnionFind {  // UnionFind uni(N);
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




