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
    string S;cin >> S;
    LL dp[100200][5] = {0};     // 0 は初期値, 1 は A, 2 は AB , 3 は ABC
    dp[0][0] = 1;

    int N = S.size();
    rep(i,N+1){
        // 既存の場合の数を遷移させる処理
        rep(j,4){
            if(S[i] != '?')dp[i+1][j] += dp[i][j] % MOD;
            else dp[i+1][j] += dp[i][j] * 3 % MOD;
        }

        // i+1個目の文字を判別して個別対応する処理
        if(S[i] == 'A')dp[i+1][1] += dp[i][0] % MOD;
        if(S[i] == 'B')dp[i+1][2] += dp[i][1] % MOD;
        if(S[i] == 'C')dp[i+1][3] += dp[i][2] % MOD;
        if(S[i] == '?'){
            dp[i+1][1] += dp[i][0] % MOD;
            dp[i+1][2] += dp[i][1] % MOD;
            dp[i+1][3] += dp[i][2] % MOD;
        }
        dp[i+1][1] %= MOD;
        dp[i+1][2] %= MOD;
        dp[i+1][3] %= MOD;
    }

    cout << dp[N][3] << endl;
}


// ABC104 D - We Love ABC

// Sの長さ的に考えてDP
// 今回は
// ・？が入るとそれまでの場合の数にそれぞれ3本の行先ができるので3倍になる
// ・dp[i][0]がなぜ必要なのか
// ・A,AB,ABCの準備状況の数をdp遷移する
// という3点気づく必要があった。

// dp[i][0] を　+=1 にしてはいけない理由は、？によって根っこの場合の数が3倍3倍3倍と3倍されて増えた状況で、Aを生やしたとき
// i+1 におけるAの場合の数の増え方はどう考えても それまでの考えうる文字列の総数に一致するはず。
// つまり、i+1 番目のAは i番目までの場合の数の全ルートから生えるということ。
// なので、Aが生える何もない土壌、すなわち生える元となる文字列の総数も更新し続けておく必要があるというわけ。
// これは既存の遷移の？パートで3倍されている。

// 遷移パートを分けている理由は、文字が'A'の時にもAB,ABCのその時点までの個数はコピーしておかなければならないから。

