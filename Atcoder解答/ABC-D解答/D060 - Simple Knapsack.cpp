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
    LL W;cin >> W;
    vector<LL> w(N);
    vector<LL> v(N);
    rep(i,N)cin >> w[i] >> v[i];

    LL dp[110][110][310] = {0};
    rep(i,N)rep(j,101)rep(k,301){
        chmax(dp[i+1][j+1][k + w[i] - w[0]],dp[i][j][k] + v[i]);
        chmax(dp[i+1][j][k],dp[i][j][k]);
    }
    LL ans = 0;
    LL ct = W/w[0];
    rep(i,N+1){
        LL sum = w[0]*i;
        LL modi = W - sum;
        if(modi >= 0){
            chmax(ans,dp[N][i][min(300LL,modi)]);
        }
    }
    cout << ans << endl;
}

// ABC060 D - Simple Knapsack

// バグりまくった
// 普通のナップサックとしては条件が厳しすぎるので、w1 <= wi <= w1+3 をうまく使うやつ