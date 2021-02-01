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

    //bit_flag集をvectorに格納
//
    vector<int> bit_flag(10);
    rep(i,10){
        bit_flag[i] = (1 << i);
    }
//

    int N;cin >> N;
    vector<int> shop(N); // int で入れておいてbitで取り出す
    int tmp = 0;    // 入力用
    int F = 0;      // 入力用

    // 入力１
    rep(i,N){
        tmp = 0;
        rep(j,10){
            cin >> F;   // 入力用
            if(F == 1)tmp |= bit_flag[j];   // 入力用
        }
        shop[i] = tmp;  // ここで初めて入力
    }

    // 入力２
    vector<vector<LL>> P(N,vector<LL>(11));     // お姉さんのお店の利益リスト
    rep(i,N) rep(j,11) cin >> P[i][j];          // 入力

    LL ans = -1000000000000000000;int open_ct = 0;int empty_ct = 0;int now = 0;LL tmp_ans = 0;      // こまごまとした変数の定義。ansはmaxで更新していくので-INFにしておく。
    for(int bit = 0;bit < (1 << 10);bit++){     // bit 全探索
        tmp_ans = 0;                            // 内部ループで得た暫定的な利益の最大値
        empty_ct = 0;                           // さぼりフラグ
        rep(i,N){                           // 全他店をチェックするループ             
            open_ct = 0;                    // 競合具合のカウント変数
            now = shop[i] & bit;            // 現在の他店との競合時間帯を取得

            rep(j,10) if(now & bit_flag[j])open_ct++;   // 競合時間帯の時数カウント

            if(open_ct == 0)empty_ct++;     // おねえさんがさぼってたらカウント
            tmp_ans += P[i][open_ct];       // 暫定的な利益の最大値の更新
        }
        if(empty_ct == N)continue;          // 完全にさぼってたらOUT
        ans = max(ans,tmp_ans);             // 利益の更新
    }

    cout << ans << endl;    // 出力
}


// ABC080 C - Shopping Street
// ・超絶重たかった。しかし、bit全探索で 2^10*100*10 = 10^6程度なので、正確に実装できればそれだけの問題。

// 他店がやっているかどうかを入力1、お姉さんのお店の利益を入力2として取得。
// このときに店のフラグは10個なのに対し、利益は11個あることに注意！（1敗）

// また、お姉さんは最低でも一回お店を開けないといけない。条件で必ず他店と一日以上競合することが与えられているので、全店舗と一回もかぶらない店の開け方をNGにすれば大丈夫。
// それをempty_ctで管理する。

// あとは、bit全探索ループごとに、内部ループ（つまりbitごとのお店の競合具合のチェック）で得た利益を更新していく。