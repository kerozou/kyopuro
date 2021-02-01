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
    int H,W,K;cin >> H >> W >> K;
    --K;    // 0-index 化
    LL dp[110][10] = {0};           // 横線h段、0がkにくるものの数 dp[H][k]
    dp[0][0] = 1;

    rep(h,H){                       // 各行をすすむ
        rep(b,(1 << (W-1))){        // 行ごとにbit全探索
            // 横線チェック
            bool judge = true;
            rep(i,W-2) if((b >> i) % 4 == 3)judge = false;

            if(!judge)continue;

            // 各始点がどこに行くか求める
            int perm[W];
            rep(i,W)perm[i] = i;
            rep(i,W-1) if((b >> i) & 1)swap(perm[i],perm[i+1]);

            // 配る
            rep(i,W){
                dp[h+1][perm[i]] += dp[h][i];
                dp[h+1][perm[i]] %= MOD;
            }
        }

    }

    cout << dp[H][K] << endl;
}


// 	ABC113 D - Number of Amidakuji

// https://misteer.hatenablog.com/entry/ABC113

// あみだくじの問題を見た感じ、dpを使いたくなる。
// 今回は最初のスタートが1固定なので、各行においてbit全探索で辺が存在するかを探索して、結果をdpに格納して次へ回す。

// このとき、辺の左と右どちらから移動してくるかを考えなくちゃいけないけど、それを場合分けするとめんどい。
// なので、misterさんの解法では、
// ・その行で始点からどこの終点に行くかをあらかじめperm[i]に保存しておいて
// ・それを左から通ると仮定してswapすることで同時に右側の処理もやってる。
// これで得た始点と終点をdpにぶちこむと各行での遷移の全パターンが得られる。

// その行までの全通りにその行で起こりうる可能性をかけて格納していくのでdp

// 今回は
// ・dpには気づいたけど、bit全探索をdp内で使うことに気づかなかった。
// ・swapのところの処理が思いつかなかった。
// というところが学びのポイント