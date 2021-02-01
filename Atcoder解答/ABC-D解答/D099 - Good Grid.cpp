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
    int C;cin >> C;
    vector<vector<int>> D(C,vector<int>(C,0));
    vector<vector<int>> c(N,vector<int>(N,0));

    rep(i,C)rep(j,C)cin >> D[i][j];
    rep(i,N)rep(j,N)cin >> c[i][j],c[i][j]--;

    // 前処理
    vector<vector<int>> sum(3,vector<int>(C,0));
    rep(k,C)rep(i,N)rep(j,N)sum[(i+j)%3][k] += D[c[i][j]][k];

    // クエリ
    LL ans = INF;
    rep(i,C)rep(j,C)rep(k,C){
        LL tmp = 0;
        if(i == j)continue;
        if(i == k)continue;
        if(j == k)continue;
        tmp += sum[0][i] + sum[1][j] + sum[2][k];
        ans = min(ans,tmp);
    }

    cout << ans << endl;


}

// ABC099 D - Good Grid

// 全探索の前に前処理をしておく問題。
// とりあえず、愚直な全探索が描けるようになろう。

// 公式解説放送が神ってる

// http://drken1215.hatenablog.com/entry/2018/07/22/133200
