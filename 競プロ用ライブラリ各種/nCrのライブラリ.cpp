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


// 前処理 COMinit(): O(n)
// クエリ処理 COM(n, k): O(1)

// 使用可能場面
// 1 ≤ k ≤ n ≤ 10^7
// p は素数 (実装ではさらに p > n を仮定している)

const int MAX = 5100000;
const int MOD = 1000000007;

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

int main() {
    // 前処理
    COMinit();

    // 計算例
    cout << COM(100000, 50000) << endl;
}


// http://drken1215.hatenablog.com/entry/2018/06/08/210000

//前処理 COMinit(): O(n)
//クエリ処理 COM(n, k): O(1)




------------------------------------------------------------------------------------------------------------------------------------------



// n も k も小さいとき ( 1≦ k ≦ n ≦ 2000 程度、mod. p が素数でなくてもよい)
// 答えが　long long で　10桁以上になるときとかに使うべきパターン

// Com の生成のところで %MOD を消せば　LL　でいけそう。
// この場合は　Nが高々50程度でないと厳しそう。(MOD消したらいけた！)

const long long MOD = 1000000007;
const int MAX_C = 1000;
long long Com[MAX_C][MAX_C];

void calc_com() {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]) % MOD;
        }
    }
}