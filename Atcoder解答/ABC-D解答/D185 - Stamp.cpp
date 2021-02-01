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
    LL N,M;cin >> N >> M;
    vector<LL> A(M);
    rep(i,M)cin >> A[i];
    sort(all(A));
    map<int,int> m;
    
    // スタンプ間の距離をmapに格納
    int start = 1;
    int szmin = 9999999999;
    rep(i,M){
        int sz = A[i] - start;
        if(sz != 0){
            m[sz]++;
            chmin(szmin,sz);
        }
        start = A[i] + 1;
    }
    int sz2 = N+1-start;
    if(sz2 != 0){
        m[sz2]++;   //  右端
        chmin(szmin,sz2);
    }

    // 計算
    LL ans = 0;
    for(auto [x,y] : m){
        ans += ((x+szmin-1)/szmin)*y;
    }

    cout << ans << endl;
}

// ABC185 D - Stamp