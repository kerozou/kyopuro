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
    int N;cin >> N;
    vector<LL> d(N);rep(i,N)cin >> d[i];

    LL sum = 0;
    LL ma = 0;
    rep(i,N){
        ma = max(ma,d[i]);
        sum += d[i];
    }
    sum -= ma;

    if(N == 1){
        cout << d[0] << endl;
        cout << d[0] << endl;
    }
    else{
        cout << sum + ma << endl;
        if(sum >= ma)cout << 0 << endl;
        else cout << ma - sum << endl;
    }
}

// ARC004 B - 2点間距離の最大と最小 ( Maximum and Minimum )

/*
    三角形を作れるかどうか判定する問題に落とし込める。
*/