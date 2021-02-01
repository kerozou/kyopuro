#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    // 入力
    LL N;cin >> N;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];

    // A の累積和
    vector<LL> rui(N+1);
    rui[0] = 0;
    rep(i,N){
        rui[i+1] = rui[i] + A[i];
    }

    // 操作iに関して、最右に到達する瞬間の距離を格納
    vector<LL> len(N+1,0);
    LL t_len = 0;
    rep(i,N+1){
        chmax(t_len,rui[i]);
        len[i] = t_len;
    }

    // 計算
    LL ans = -999999999;
    LL tmp = 0;
    rep(i,N+1){
        chmax(ans,tmp + len[i]);
        tmp += rui[i];
    }


    cout << ans << endl;
}

// ABC182 D - Wandering