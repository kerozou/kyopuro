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

auto GCD(auto a, auto b) { //ユークリッドの互助法で最大公約数
    if(a % b == 0)return b;
    else return GCD(b, a % b);
}
auto LCM(auto a, auto b) { //GCDを使って最小公倍数を求める
    auto g = GCD(a, b);
    return (a / g) * b;
}


int main() {
    LL N,K;cin >> N >> K;
    vector<LL> A(N);rep(i,N)cin >> A[i];
    sort(all(A));

    LL G = A[0];
    rep(i,N)G = GCD(G,A[i]);

    if(K > A[N-1])cout << "IMPOSSIBLE" << endl;
    else{
        if(K % G == 0)cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }


}

// AGC018 	A - Getting Difference

/*
    解説AC
    ユークリッドの互除法を想起できるかどうかの問題。
    ZeroSumRange　は　連続部分列の総和が0になるときの話だった。
    この問題は2数の差が問題になっている。
    このように、ある程度整数の話はパターン化できるので、知っているか知らないかの世界になりそう。

    実際、本番で閃くのを待つのはリスキーすぎる。
    なので、いずれはこの辺の知識も整理して網羅したい。
*/