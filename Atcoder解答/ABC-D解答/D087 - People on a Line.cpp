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


int main(){
    int N,M;cin >> N >> M;
    UnionFind<int> uni(N);
    rep(i,M){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;

        if(uni.same(a,b)){    // 同一集合内にある時の分岐
            int diff = uni.diff(a,b);

            if(diff != c){
                cout << "No" << endl;
                return 0;
            }
        }
        else{
            uni.unite(a,b,c);
        }
    }
    cout << "Yes" << endl;
}

// ABC087 	D - People on a Line

// 問題の方針と重み付きUnionFindについては理解したんだけど、Class Abel をint にしておくと通らない意味が解らなかった。

