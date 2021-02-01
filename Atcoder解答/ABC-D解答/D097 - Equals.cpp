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

// UnionFind 

// この構造体は基本機能にsizeをたしたもの
// https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396

// size あると便利そうなので
// struct の最初にあるUnionFindはコンストラクタ。par(N),siz(N,1) は継承（それぞれ初期化している）。
// コンストラクタは起動時(宣言時)に最初に実行される。

// これは大小を整理するやつシンプルな実装（経路圧縮のみ）なので、合体クエリがO(logN)らしい。

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

int main(){
    int N,M;cin >> N >> M;
    vector<int> p(N);
    rep(i,N)cin >> p[i],p[i]--;
    UnionFind uni(N);
    rep(i,M){
        int a,b;cin >> a >> b;
        a--;b--;
        uni.unite(a,b);
    }
    int ans = 0;
    rep(i,N)if(uni.same(i,p[i]))ans++;
    cout << ans << endl;
}

// ABC097 D - Equals

// 与えられたペアで無向グラフをつくると、いくつかの整数の集合ができあがる。
// この集合内でswapするとき、集合内の数字は好きなように配置することができる。
// これの証明は、グラフの葉の数字を一つ選んで、そこをゴールにするべく他の点からswapして運んでくる。
// swapし終わったら、完了したということで、運び終えた葉と親への辺を消去する。
// これをすべての葉について行うとき、目標達成可能な葉はすべて消えることになり、これによって消えた葉というのがソート済みの数字になる。

// というわけで、任意の集合内での任意の回数のswapによってその集合内の数字は自由に移動できることが保証されたので、
// あとは各集合ごとにいくつの数字が整列可能かを調べればよい。

// 複数個の集合内で数字が存在するかどうかの確認を行うにはUnionFindが最適。

// 公式解説放送が分かりやすかった。