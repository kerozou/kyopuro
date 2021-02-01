#include<bits/stdc++.h>
using namespace std;
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
    LL N,A,B;cin >> N >> A >> B;
    vector<LL> X(N);rep(i,N)cin >> X[i];

    vector<LL> sa(N-1);
    rep(i,N-1){
        sa[i] = X[i+1]- X[i];
    }   

    LL ans = 0;
    rep(i,N-1){
        if(A * sa[i] > B)ans += B;
        else ans += A*sa[i];
    }
    cout << ans << endl;
}

// ARC067 D - Walk and Teleport

/*
    消費の少ないほうを選ぶ貪欲
*/