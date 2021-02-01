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

int N,M;
LL G[110][110];
LL dp[110][110];
bool can[110];

ll dfs(int i,int j){
    if(dp[i][j] >= 0)return dp[i][j];
    if(i == j)return (can[i] ? 0 : 1);

    ll res = 0;

    rep(k,N){
        if(G[i][k] > 0)res += (G[i][k] * dfs(k,j));  
    }

    return dp[i][j] = res;
}

int main(){
    cin >> N >> M;
    rep(i,M){
        LL P,Q,R;cin >> P >> Q >> R;
        P--;R--;
        can[R] = true;
        G[R][P] = Q;
    }
    
    rep(i,110)rep(j,110)dp[i][j] = -1;

    rep(i,N-1)cout << dfs(N-1,i) << endl;

}
