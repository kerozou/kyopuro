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

const int MAX = 3000;    //  ここのサイズ選びめっちゃ注意。5*10^5とかにしてたら余裕でTLEこく。

LL fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
LL COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// n-1 C m-1
int count_7(int n, int m){
    if(n < m) return 0;
    // 前処理
    COMinit();
    return COM(n-1,m-1);
}



int main(){
    int N,K;cin >> N >> K;
    COMinit();

    vector<LL> ans(K+1);
    ans[0] = 0;
    ans[1] = N-K+1;  // N-K+1 C 1

    for(int i = 2;i <= K;++i){
        LL tmp = count_7(K,i) % MOD;    // blue
        LL lr_n = count_7(N-K,i-1) % MOD;
        LL l = count_7(N-K,i) % MOD;
        LL r = count_7(N-K,i) % MOD;
        LL lr =  count_7(N-K,i+1) % MOD;
        ans[i] = tmp * (lr_n + l + r + lr) % MOD;
    }

    for(int i = 1;i <= K;++i)cout << ans[i] << endl;
}


//　ABC-132 D - Blue and Red Balls

// 問題そのままだとよくわからないので、問題を分解する。
// 結局、青いボールの取り方は、連続するものを同時にとることを連続して行うのが最小回数である。
// なので、操作回数の最大は高々 K 回になるはず。
// よって、青の塊の個数 i 個の隙間に赤の塊を詰めていく形がとれる。

// これによって、　赤　青　赤　青　赤　みたいに分けることができる。
// これは青の個数によって排反なので、青が 1~K 個 の各パターンに　赤の塊の並べ方をかけたものが
// 各操作回数 i の時の取りうる場合の数となる。

// (1) 青の塊の作り方の場合の数を考えるとき、写像12相の分類に従うと
//      区別　青球：無　箱：有　　全射（少なくとも一つ入る）　→　count_7
// なので、count_7を使って各 i の時の場合の数をとっていく。

// (2) 赤の塊の作り方の場合の数は、
//      両端を含まない　＋　左を含む　＋　右を含む　＋　両端を含む　
// のように、青の塊にできる隙間とその両端で排反になる場合を総取りすればいい。
// これらの各場合も
//      区別　赤球：無　箱：有　　全射（少なくとも一つ入る）　→　count_7
// で考えると、count_7を使って各場合を求めればよい。

// なので、
//  青球の個数でループ　
//      その中で青球の選び方  *  赤球の選び方
// をすればよい。    