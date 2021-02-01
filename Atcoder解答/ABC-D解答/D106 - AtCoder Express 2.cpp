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

int main(){
    int N,M,Q;cin >> N >> M >> Q;
    vector<pair<int,int>> lr(M);
    rep(i,M)cin >> lr[i].F >> lr[i].S;
    vector<pair<int,int>> p(Q);
    rep(i,Q)cin >> p[i].F >> p[i].S;

    // a に二次元の座標LRを格納
    vector<vector<int>> a(N+1, vector<int>(N+1,0));
    rep(i,M){
        int s = lr[i].F;
        int t = lr[i].S;
        a[s][t]++;
    }

    // 二次元累積和
    vector<vector<int> > s(N+2, vector<int>(N+2, 0));
    rep(i,N+1)rep(j,N+1)s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

    // クエリ [x1, x2) × [y1, y2) の長方形区域の和
    rep(i,Q){
        int x1 = p[i].F;
        int x2 = p[i].S + 1;
        int y1 = p[i].F;
        int y2 = p[i].S + 1;
        cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
    }

    

}

// ABC106 D - AtCoder Express 2

// 二次元累積和を使って解く問題。
// 二次元累積和については
// http://tutuz.hateblo.jp/entry/2018/08/19/064525
// https://qiita.com/drken/items/56a6b68edef8fc605821#4-%E4%BA%8C%E6%AC%A1%E5%85%83%E7%B4%AF%E7%A9%8D%E5%92%8C
// を参照。

// ライブラリにひな形を用意しておいた。
// ・区間ごとの総和とかをQ個処理すべきときは二次元累積和がO(N)でいけて有効。