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

void warshall_floyd(int n,vector<vector<LL>> &d) {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main(){
    LL N,M;cin >> N >> M;
    LL L;cin >> L;

    //隣接行列
    vector<vector<LL>> G(N,vector<LL>(N,INF));
    rep(i,M){
        LL a,b;cin >> a >> b;
        ll c;cin >> c;
    
        a--;b--;
        G[a][b] = c; G[b][a] = c;
    }
    rep(i,N)G[i][i] = 0;

    warshall_floyd(N,G);    //一回目の各町ごとの最短距離リスト作成

    vector<vector<LL>> path(N,vector<LL>(N,INF));     //必要燃料L以下の街間に重み1の経路を追加したグラフを作成。L以下で通過できない街の経路は自然に淘汰されている。
    rep(i,N) rep(j,N) if(G[i][j] <= L)path[i][j] = 1;

    warshall_floyd(N,path); //二回目のWFで重み1の経路を使った最短経路リストを作る。


    int Q;cin >> Q;
    rep(i,Q){
        int s,t;cin >> s >> t;
        s--;t--;

        if(path[s][t] >= 1 << 30)cout << -1 << endl;
        else cout << path[s][t] - 1 << endl;
    }


}

