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
    int n;cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    sort(rall(a));

    int l = a[0];
    int r = 0;
    rep(i,n)if(l > i){
        if(abs(l/2 - r) > abs(l/2 - a[i]))r = a[i];
    }
    cout << l << " " << r << endl;
}

// D - Binomial Coefficients

// 最初はコンビネーションの前処理してやろうとしてた。
// nCrのｎが最大値だと分かってるから、10^5回nCr調べて大小比較すればいいと思ってたけど、n max = 10^9で終わった。

// なので、パスカルの三角形を使って、nCr が最大となるときの r 、つまりabs(n/2 - r) が最小になるときの r を求めればいい。