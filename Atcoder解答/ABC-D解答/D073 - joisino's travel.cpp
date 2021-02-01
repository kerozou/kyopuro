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
    int N,M,R;cin >> N >> M >> R;
    vector<int> r(R);
    rep(i,R)cin >> r[i];
    sort(all(r));
    vector<vector<LL>> G(N+1,vector<LL>(N+1,INF));
    rep(i,M){
        int s,t,u;cin >> s >> t >> u;
        G[s][t] = u;
        G[t][s] = u;
    }

    // WF
    rep(k,N+1)rep(i,N+1)rep(j,N+1)G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
    rep(i,N+1)G[i][i] = 0;
    vector<int> np(R);

    LL ans = INF;

    do{
        LL tmp = 0;
        for(int i = 1;i < R;++i){
            int s = r[i-1];
            int t = r[i];
            tmp += G[s][t]; 
        }
        ans = min(ans,tmp);
    }while(next_permutation(all(r)));

    cout << ans << endl;
}

// ABC073 D - joisino's travel

// Warshall_Floyd 後に next_permitation で順列列挙する
// r のソートを忘れるとケース６で落ちる。

