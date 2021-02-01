// UnionFind 

// この構造体は基本機能にsizeをたしたもの
// https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396

// size あると便利そうなので
// struct の最初にあるUnionFindはコンストラクタ。par(N),siz(N,1) は継承（それぞれ初期化している）。
// コンストラクタは起動時(宣言時)に最初に実行される。

// rank と 経路圧縮で　O(α(N))　だと思われ。
// 重みはLLとかもとれるようにアーベル群を使ってる。
// s に単位元を入れて使う。int とか　LL　の時は0 でおｋ。

// UnionFind<int> uni(N);　てな感じで<>内に重みの型を指定する。

// ABC-D087 	D - People on a Line
// なんかAbelにしたら通って、intのままだと通らなかった。謎。


x と y がすでに同じグループにいるときに merge(x, y, w) を呼ぶ
x と y が同じグループにいないときに diff(x, y) を呼ぶ
については未定義動作

注意

このライブラリに関してあまりよく理解してないんで極力使わない。
普通のUnionFindは簡単版を使うべき。

template<class Abel> struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> siz; // 素集合のサイズを表す配列(1 で初期化)
    vector<int> rank;
    vector<Abel> diff_weight;    // 根からの距離

    UnionFind(int N,Abel s = 0) : par(N), siz(N, 1), rank(N,0){ //最初は全てが根であるとして初期化、頂点数N
        diff_weight.resize(N);
        for(int i = 0; i < N; i++) par[i] = i,diff_weight[i] = s;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]]; // 累積和をとる
            return par[x] = r;
        }
    }

    void unite(int x, int y,Abel w=0) { // xとyの木を併合 重みがあるときはw指定
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return ;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        // 素集合のサイズ更新
        siz[y] += siz[x];
        return ;

    }


    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x) { // 素集合のサイズ
        return siz[root(x)];
    }

    int weight(int x) {
        root(x); // 経路圧縮
        return diff_weight[x];
    }

    Abel diff(int x, int y) {    // 同じ集合内にある時のみ定義。異なる集合の頂点同士いれるとバグる。二頂点の距離を得る。
        return weight(y) - weight(x);
    }
};
