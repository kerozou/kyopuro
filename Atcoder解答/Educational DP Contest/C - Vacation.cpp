#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

// DPの二次元添え字で前日の行動を管理する。
// ループは3重にして、j==kでcontinueすれば重複なく全部回せる。

int main(){
    int N;cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(N);
    rep(i,N)cin >> a[i] >> b[i] >> c[i];
    LL DP[N+10][3] = {0};
    LL tmp;

    rep(i,N) rep(j,3) rep(k,3){   //jは前日に何をしていたか,kは前々日に何をしていたか
        if(j == k)continue;
        if(j == 0)tmp = a[i];
        if(j == 1)tmp = b[i];
        if(j == 2)tmp = c[i];
        chmax(DP[i+1][j],DP[i][k] + tmp);
    }
    LL ans = max(DP[N][0],DP[N][1]);
    ans = max(ans,DP[N][2]);
    cout << ans << endl;
}