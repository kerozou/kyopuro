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
    string N;cin >> N;
    int K;cin >> K;
    LL dp[111][2][5] = {0};

    // dp[i][j][k]
    // i : 左から何桁目を含むまで
    // j : 未満フラグ　0でi桁目まで上限 　
    //N = 12345 で i = 3 の時、i-1桁目つまりは左から2桁なので
    //ind=1桁目までが上限かどうか,0で上限
    // k : 左からi桁目まででK=何某　
    
    // 初期化    -1桁目があると仮定してる
    dp[0][0][0] = 1;

    rep(i,N.size()+1) rep(j,2) rep(k,4){
        if(i == 0)continue;
        int c = N[i-1] - '0';
        rep(l,10){
            if(j == 0 && l > c)continue;

            int k2 = k;
            if(l != 0)k2++;

            dp[i][j || c != l][k2] += dp[i-1][j][k];

        }
    }
    
    LL ans = dp[N.size()][0][K] + dp[N.size()][1][K];

//    rep(i,4)cout << dp[N.size()][0][i] << " " << dp[N.size()][1][i] << endl;

    cout << ans << endl;



}

// ABC154 E - Almost Everywhere Zero

// 桁DPの典型的な問題？
// 桁DPは　現在参照している桁　と　現在参照している桁のindex　がずれることでバグりやすい。
// なので、あらかじめ配列で現在の桁の数を取っておくのではなく、ループ内でint c を定義してあげるほうがいい。
// なるだけ配列をforのiで調べないようにするのがバグらせないコツ。

// dp[i][j || c != l][k2] この || を使った遷移がテクい。
// 便利なので、つかっていくといい。
// 0 → 0 , 0 → 1 ,1 → 1 の３種類ifでくくってもいいんだけど、なんだかんだシンプルでバグりにくいこっちがいい。
