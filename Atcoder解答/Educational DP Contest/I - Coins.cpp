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
    int N;cin >> N;
    vector<double> p(N+1);
    rep(i,N)cin >> p[i];
    vector<vector<double>> dp(N+1,vector<double>(N+1,0));
    dp[0][0] = 1.0;

    rep(i,N) rep(j,N){
        dp[i+1][j+1] += dp[i][j] * p[i];
        dp[i+1][j] += dp[i][j] * (1.0-p[i]);
    }

    double ans = 0.0;
    for(int j = (N+1)/2;j<=N;++j)ans += dp[N][j];
    cout << fixed << setprecision(10) << ans << endl;
}

