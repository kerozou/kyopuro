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
    LL H,W;cin >> H >> W;
    vector<vector<LL>> maze(H,vector<LL>(W,0));
    rep(i,H) rep(j,W){
        char a;cin >> a;
        if(a == '#')maze[i][j] = 0;
        else maze[i][j] = 1;
    }

    vector<vector<LL>> dp(H+1,vector<LL>(W+1,0));
    dp[0][0] = 1;   //初期化

    rep(i,H) rep(j,W){
        if(maze[i][j]){
            dp[i+1][j] += dp[i][j] % MOD;
            dp[i][j+1] += dp[i][j] % MOD;
        }
    }

    LL ans = dp[H-1][W-1] % MOD;
    cout << ans << endl;
    

}

