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


struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> siz; // 素集合のサイズを表す配列(1 で初期化)

    UnionFind(int N) : par(N), siz(N, 1){ //最初は全てが根であるとして初期化 、頂点数N
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

struct Edge {
    int a;
    int b;
};

int main(){
    int N,M;cin >> N >> M;
    vector<Edge> g;
    vector<LL> ans(M);
    rep(i,M){
        int c,d;cin >> c >> d;
        c--;d--;
        g.push_back((Edge){c,d});
    }
    
    UnionFind uni(N);
    
    for(int i = M-1;i >= 0;--i){
        int u = g[i].a;
        int v = g[i].b;
        if(uni.same(u,v)){
            ans[i] = 0;
            continue;
        }
        else{
            LL s = uni.size(u);
            LL t = uni.size(v);
            ans[i] = s*t;
            uni.unite(u,v);
        }
    }

    LL sum = 0;
    rep(i,M){
        sum += ans[i];
        cout << sum << endl;
    }

}


// ABC-D120 D - Decayed Bridges

// グラフを作って、辺を一本ずつ破壊していくんだが、この処理はやばい。
// 非常に大変かつ、一回一回の処理で減るルート検索も大変。
// なので、逆にすべてぶっ壊れた状態から一本ずつ橋をかける処理を考える。

// このとき、橋でつながってる島々を集合として考えると、集合を連結していくデータ構造であるUnionFindが使える。
// あとは、UnionFindで島をつないでいくときに増えるルート検索の処理を考えればいい。

// この時、UnionFind の size関数が役立つ。
// 増えるルートの総数は 集合1の要素数 * 集合2の要素数 である。
// なぜこうなるかは、お互いの集合内の各要素について、対岸の全要素へのアクセス権が得られるのと、
// 対岸の全要素から新しくアクセス可能になった要素へのアクセス権が 得られることから分かる。
// つまり、ありえるペアは総当たりでとれるということ。
// 二頂点がすでに連結である場合は0 件のアクセス権が増えると考える。

// これらの処理を終えたのちに、巻き戻し再生すると問題文の条件をクリアしていくことになる。

// ofutontonさんとアルメリアさんの記事とAtcoderTypicalContest001を参照
// https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396
// https://betrue12.hateblo.jp/entry/2019/03/03/224118
// https://atc001.contest.atcoder.jp/tasks/unionfind_a