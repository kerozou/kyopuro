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

const int MAX = 200001;

long long fac[MAX], finv[MAX], inv[MAX];

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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    int H,W,A,B;cin >> H >> W >> A >> B;
    // 前処理
    COMinit();

    LL ans = 0;
    rep(i,W-B){
        LL tmp = 1;
        tmp = tmp * COM(H-A-1+B,B+i) % MOD;
        if(A+i < H)tmp = tmp * COM(A+W-1-B,A+i) % MOD;

        ans += tmp;
        ans %= MOD;
    }

    cout << ans << endl;

}

// ABC042 D - いろはちゃんとマス目 / Iroha and a Grid

// 数Aでやった場合の数の問題。
// ある点までの最短ルートの総数　*　ある点から終点までの最短ルートの総数　を階段状に排反にとって足しあげるだけ。

/*
    o o o o x
    o o o x o
    o o x o o
    s s o o o
    s s o o o

    のように左上から右下までのルートは、3つのxを通る3通り足しあげる必要がある。
*/
