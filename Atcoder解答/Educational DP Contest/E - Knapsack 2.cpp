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
    int N;LL W;cin >> N >> W;
    vector<LL> w(N);
    vector<LL> v(N);
    rep(i,N)cin >> w[i] >> v[i];
    LL dp[110][110000];
    rep(i,110) rep(j,110000)dp[i][j] = INF;  // 初期化
    dp[0][0] = 0;   // 初期条件     //これが無いと、基準とする最小がINFになってしまう。

    rep(i,N){
        for(int sum_v = 0;sum_v <= 100000;sum_v++){ // i はアイテムの探索済み番号で、sum_vはカバン内の最低価値を示す。dpはその遷移時点にありうる最小の重さを記録。
            
            if(sum_v - v[i] >= 0){
                chmin(dp[i+1][sum_v],dp[i][sum_v - v[i]] + w[i]);
            }

            chmin(dp[i+1][sum_v],dp[i][sum_v]);
        }
    }

    LL ans = 0;
    rep(i,100001){
        if(dp[N][i] <= W)ans = i;
    }
    cout << ans << endl;
}

