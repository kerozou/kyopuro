#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)



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




int main() {
    // 入力
    LL N,K;cin >> N >> K;
    vector<LL> P(N);
    rep(i,N){
        int p;cin >> p;
        p--;
        P[i] = p;
    }
    vector<LL> C(N);
    rep(i,N)cin >> C[i];

    vector<LL> roop_point(N,0);     // 1周分のポイントには自分に帰ってきた時の得点も含む

    // 1 : 素集合の作成 と roop_point のセットアップ
    UnionFind uni(N);
    rep(i,N){
        int next = P[i];
        LL tmp = 0;
        UnionFind uni_tmp(N);
        while(!uni_tmp.same(i,next)){
            tmp += C[next];
            uni_tmp.unite(i,next);
            uni.unite(i,next);
            next = P[next];
        }
        tmp += C[next];
        roop_point[i] = tmp;
    }

    // 2 : 端数分の得点を管理する配列 (マス i 到達時の累積和で格納)
    vector<vector<LL>> last_point(N);
    rep(i,N){
        last_point[i].resize(uni.size(i),0);    // 素集合のサイズに変更
    }
    rep(i,N){
        int lim = last_point[i].size();
        LL tmp = 0;
        int next = P[i];
        rep(j,lim){
            if(j == 0)continue;
            tmp += C[next];
            last_point[i][j] = tmp;
            next = P[next];
        }
    }


    LL ans = 0;

    rep(i,N){
        LL uni_sz = uni.size(i);        // 各ループのサイズ 
        LL num = K / uni_sz;            // 何周できるか
        LL lim = uni_sz;                // 端数の限界回数
        LL tmp = 0;

        if(num == 0)lim = K+1;

        // 3 : ループで追加される得点が正になるとき
        if(roop_point[i] > 0){
            tmp = num * roop_point[i];  
            lim = K - num*uni_sz + 1; 
        }

        // 4 : 端数を足していく
        rep(j,lim){
            chmax(ans,tmp+last_point[i][j]);
        }

        // 5 : 限界まで周回しきらない方が有利な場合の更新
        if(roop_point[i] > 0 && num > 0)rep(j,uni_sz){
            chmax(ans,(num-1)*roop_point[i] + last_point[i][j]);
        }
    }

    // 6 : 動かないときが最適解　かつ　C[i]  が全部負の時
    if(ans == 0){
        ans = -999999999999;
        rep(i,N)chmax(ans,C[i]);
    }

    cout << ans << endl;
}

// ABC175 D - Moving Piece