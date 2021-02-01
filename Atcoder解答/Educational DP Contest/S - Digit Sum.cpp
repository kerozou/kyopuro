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
    string K;cin >> K;
    LL D;cin >> D;
    LL dp[10010][110][2] = {0};
    LL N = K.size();

    dp[0][0][0] = 1;

    rep(i,N) rep(j,D) rep(k,2) rep(l,(k ? 9 : K[i] - '0') + 1){
        LL c = K[i] - '0';
        dp[i+1][(j+l)%D][k || l != c] = (dp[i+1][(j+l)%D][k || l != c] + dp[i][j][k]) % MOD;
    }


    cout << (dp[N][0][0] + dp[N][0][1] +  MOD  -1 ) % MOD  << endl;
}

// EDPC S - Digit Sum

// 典型的な桁DP
// 途中に出てくる、rep(l,(k ? 9 : K[i] - '0') + 1) が素敵。
// あと、[k || l != c]も頻出テク。

// 最後の出力の（）内の＋MODないと最後のケースだけ落ちる。
// これは、おそらくdpが0っていうとんでもケースが混ざってて-1になってるせい