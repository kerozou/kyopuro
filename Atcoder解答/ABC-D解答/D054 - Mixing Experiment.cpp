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


LL dp[50][500][500];


int main(){
    int N;cin >> N;
    int ma,mb;cin >> ma >> mb;
    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(N);
    rep(i,N)cin >> a[i] >> b[i] >> c[i];


    rep(i,50)rep(j,500)rep(k,500)dp[i][j][k] = INF;
    dp[0][0][0] = 0;

    rep(i,N)rep(j,500)rep(k,500){
        if(dp[i][j][k] >= INF)continue;
        // 使うとき
        chmin(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k] + c[i]);
        // 使わないとき
        chmin(dp[i+1][j][k],dp[i][j][k]);
    }

    LL ans = INF;
    for(int j = 1;j < 500;++j)for(int k = 1;k < 500;++k){
        if(ma * k != mb * j)continue;
        chmin(ans,dp[N][j][k]);
    }
    if(ans == INF)cout << -1 << endl;
    else cout << ans << endl;
}

// ABC054 D - Mixing Experiment

// dp の添え字やループの始まりに注意。