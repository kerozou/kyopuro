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
    LL A;cin >> A;
    LL ans = A+1;

    if(A == 1)cout << 1 << " " << 1 << endl;
    else{
        cout << ans << " " << 2 << endl;
    }
}

// CODE FESTIVAL 2014 決勝 D - パスカルの三角形

/*
    左側から二項目が 1 ずつ増えてくので、それを出力すればいい。
    超簡単。

    しかし、これが一番最初に現れるペアとかだったら厄介だった。
*/