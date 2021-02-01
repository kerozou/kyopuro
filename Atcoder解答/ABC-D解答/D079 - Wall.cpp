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

void WF(vector<vector<LL>> &L,int N){  // Lは隣接行列、Nは頂点数
    rep(k,N)rep(i,N)rep(j,N)L[i][j] = min(L[i][j],L[i][k]+L[k][j]);
    return;
}

int main(){
    int H,W;cin >> H >> W;
    vector<vector<LL>> c(10,vector<LL>(10,0));
    rep(i,10)rep(j,10)cin >> c[i][j];
    vector<vector<LL>> A(H,vector<LL>(W,0));
    rep(i,H)rep(j,W)cin >> A[i][j];

    WF(c,10);    
    LL ans = 0;
    rep(i,H)rep(j,W){
        if(A[i][j] == -1)continue;
        int tmp = A[i][j];
        ans += c[tmp][1];
    }
    cout << ans << endl;
}

//	ABC079 D - Wall

//  与えられた入力が有向グラフの重みであるので、隣接行列を作って各数字から1への最短距離を前処理しておけばいい。
//  わーシャルフロイドで作っておく。

