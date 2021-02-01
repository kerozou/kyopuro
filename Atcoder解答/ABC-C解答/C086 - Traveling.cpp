#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    // 入力
    int N;cin >> N;
    vector<int> t(N),x(N),y(N);
    rep(i,N)cin >> t[i] >> x[i] >> y[i];

    bool ans = true;    // 条件1、2を満たすかのフラグ

    rep(i,N) if(t[i] % 2 != (x[i] + y[i]) % 2) ans = false;     // 条件1をチェック

    if(ans) rep(i,N){                                           // 条件2をチェック
        if(i == 0){ 
            if(t[0] < x[0]+y[0]) ans = false;
        }
        else if (t[i] - t[i-1] < abs(x[i] - x[i-1]) + abs(y[i] - y[i-1])) ans = false;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}

// ABC086 C - Traveling
// ・特定のポイントを通れる場合に必要な条件を探り、その条件をすべて満たす場合を調べる。

// まず、一つの点を訪れる場合を考える。
// 例えば、3 1 2 を訪れるとすると、ぴったり到達できる。
// なぜぴったりつけるかというと、移動可能距離 t と最短距離 x + y が等しいからである。
// また、5 1 2 なども、最短 t=3 でたどりついてから、2回ガバムーブすれば戻ってこれる。

// 以上からある仮設が立つ。
//   1 到達可能ポイントは「最短距離(x+y) と 移動可能距離 t の偶奇が一致する」こと
// である。
// これに加えて、
//   2 次のポイントまでの時間 ti - t(i-1) で　次のポイントまでの距離 abs(xi - x(i-1)) + abs(yi - y(i-1)) を達成できるかどうか
// のチェックが必要。

// if if 
// else 
// みたいな書き方はif if の後ろの if　がelse とつながっちゃってエラー出るから注意。（1敗）