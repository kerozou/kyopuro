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
    int x,y,a,b;cin >> x >> y >> a >> b;
    rep(i,b-y)cout << 'U';
    rep(i,a-x+1)cout << 'R';
    rep(i,b-y+1)cout << 'D';
    rep(i,a-x+1)cout << 'L';
    rep(i,1)cout << 'U';
    rep(i,1)cout << 'L';
    rep(i,b-y+1)cout << 'U';
    rep(i,a-x+1)cout << 'R';
    rep(i,b-y+1)cout << 'D';
    rep(i,a-x)cout << 'L';
    cout << endl;
}

// 長方形二枚分移動するだけ。
// スタートもエンドも4方向から入っていけないということを利用して最適化すると、1パターンになる。