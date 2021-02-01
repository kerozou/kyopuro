// Union-Find木　まとめ

一番下のやつ使おう

// Union-Find木とは？
// Union-Find木とは、グループ分けを管理するデータ構造であり、次のようなことを効率的に行える。

・要素a　と　要素b　が同じグループに属するかを調べる。
・要素a　と　要素b　のグループを併合する。

// Union-Find 木の細かい話は蟻本参照

// 習うより慣れろということで、以下にUnion-Find木の使用例を記す。

int par[Max N]; //親
int rank[Max N]; //木の深さ

// n要素で初期化
void init(int n){
    rep(i,n){
        par[i] = i;     //自分自身が親というか根になってる
        rank[i] = 0;    //もちろんその時の深さは0
    }
    return;
}

// 木の根を求める
int find(int x){
    if(par[x] = x)return x;             // 根に到達
    else return par[x] = find(par[x]);  // 根に達するまでにたどったノードもすべて根は等しいのでメモしている。
}

// xとyの属する集合を併合
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(rank[x] < rank[y])par[x] = y;        // 木が片方に伸び続けないように、深いほうの根に浅いほうの根がくっついて木を作る。
    else{
        par[y] = x;
        if(rank[x] == rank[y])rank[x]++;
    }
    return;
}

// xとyが同じ集合に属するか否か
bool same(int x,int y){
    return find(x) == find(y);
}



///////////////////////////////////////////
こっちのほうが使いやすそう

// 素集合データ構造(Union-Find)
// 集合を高速に扱うためのデータ構造。集合を合併する操作(unite), ある要素がどの集合に属しているか(find)を問い合わせる操作を行うことが出来る。

// unite(x,y):集合xとyを併合する。併合済みの時 false 未併合の時 true を返す。
// find(k):要素kが属する集合を求める。
// size(k):要素kが属する集合の要素数を求める。

// 計算量:O(α(n)))　アッカーマンの逆関数

// 実装例
struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return(false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return(true);
  }

  int find(int k)
  {
    if(data[k] < 0) return(k);
    return(data[k] = find(data[k]));
  }

  int size(int k)
  {
    return(-data[find(k)]);
  }
};

// https://ei1333.github.io/algorithm/union-find.html 参照



//////// satanic さんのこっちのほうもかなりよさそう

// union by size + path having
class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)              // すでに同一集合内にいたらfalse、違ったら高さが小さいほうの木を根っこにさす。
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};


/*
 UnionFindは木と言いながらも、集合を扱うデータ構造なので、木の高さというのは集合の数。
 つまり、マージするときはデカい集合に小さい集合を子として登録している。
*/
merge の関数の処理をたどっていくと、　根っこ　と　根っこのもつ集合のサイズ　のみを更新してるので、つながり方とかはどうでもいい。よって、閉路があっても問題ない。

//基本的な部分のみ補足しておきます．

par：素集合の要素の親（木構造の根）を配列*3で保持している
     初期状態では頂点間の辺は存在せず，孤立した状態のため，自分自身を根として初期化している（par: parent の略）．

siz：各集合（木）の大きさ．根をたどるとその木の大きさが返されるように実装されている．この配列を用意しておくとある頂点の連結成分の大きさを簡単に求められる．

　   以上 Union-Find を実装してみました．メジャーな実装では union by rank + path compression（蟻本はこれらしい） が多いと思いますが，自分の理解しやすいものに合わせると良いと思います．
*3:std::vector で実装しているが配列でも当然大丈夫（むしろ余計なオーバラップが少ない？）．


///////////////////////////////////////////////////////////////////////////////////////////////////////////


典型的な考え方：辺を切り離す処理より繋ぐ処理の方が簡単
　問題を解いていく前にポイントを解説します．ABC120 の解説放送で chokudai さんが触れていた話です．
Union-Find 木に限らず，グラフを扱う問題の一般的なポイントを紹介します．グラフを扱う問題で，辺を切り離すという処理が出てきた時，

グラフの辺を切り離す（壊す）処理より繋ぐ処理の方が簡単
切り離すしかなかったら繋ぐ処理に言い換えることができる（分離を高速にできるデータ構造 directed-connectivity もあるが AtCoder では扱わない，覚える必要はない by chokudai さん）
と考える，というのがポイントになります．これらのポイントは，

繋げていく処理だけを考えるとき，繋げたものだけを考えれば良いので，連結かどうかの判定は簡単
辺を壊した後にグラフが連結がどうかは，遠くまで見ないと連結かどうかの判定が難しい．
上記の「難しい」というのは，グラフ上を遠くまで探索して連結かどうかを愚直に調べることのできるのは DFS，BFS なので，制約が大きいと計算量的に判定が難しい，という意味．
以上 3 つを考えると意味が分かると思います．
繋がっているかどうかの判定は，ここまで見てきた通り，Union-Find 木を使えば簡単にできます（DFS，BFS，ワーシャルフロイド法などでも繋がっているかの判定はできるが，制約が大きくなると計算量的に使えない）．

　このポイントは，例えば「無向グラフが与えられてその辺を壊し，連結かどうかの判定」を行うという典型的な問題に対して適用することができます．


// ABC C075-Bredge 参照