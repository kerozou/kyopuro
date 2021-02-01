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
    int K;cin >> K;

    vector<LL> f(K+5);

    f[0] = 0;
    f[1] = 1;
    f[2] = 1;

    for(int i = 3;i <= K+4;i++){
        f[i] = f[i-1] + f[i-2];
    }

    cout << f[K+2] << " " << f[K+1] << endl;
}

// ARC051 B - 互除法

/*
    最初は p[i] = {p[i-1].F * 2 + p[i-1].S , p[i-1].F} でおいたんだけど、これだと10^9を超えちゃって駄目。
    K = 10とかなら大丈夫なんだけど、40は耐えられない。

    模範解答ではフィボナッチ数列を使っていた。
    これでAC。

    フィボナッチは隣接二項がちょうどGCDで一個ずつ削れていく。
    証明は普通に代入してやってみると n+1 から順に帰納的に分かる。
*/