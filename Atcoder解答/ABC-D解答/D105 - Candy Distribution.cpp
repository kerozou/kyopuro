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
    LL N,M;cin >> N >> M;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];
    map<LL,LL> m;
    vector<LL> rui(N+1);
    rui[0] = 0;
    rep(i,N){
        rui[i+1] = rui[i] + A[i];
    }

    rep(i,N+1){
        LL tmp = rui[i] % M;
        m[tmp]++;
    }

    LL ans = 0;
    for(auto a : m){
        ans += (a.S)*(a.S-1)/2;
    }
    cout << ans << endl;
}

// ABC105 D - Candy Distribution

// 連続する整数の和の区間は累積和で表せるのはわかる。
// しかし、累積和の場合、任意の2点を選ぶ組み合わせを網羅するとO(N^2)になることは容易にわかる。

// 今回は任意の2点を選ぶという部分と問題の条件に着目する。
// 整数列の和が単調な条件を満たすとき（最大、最小、ある値以上、以下など）のときはしゃくとり法が有効だった。
// しかし、今回のようにMの倍数というときは変わってくる。

// ある区間の和がMの倍数　→　累積和　rui[right] - rui[left] がMの倍数　→　rui[right] と rui[left] の　%M　が等しい
// ということに着目する。

// すると、M以下の余りで分類でき、その個数をmapなどに突っ込むと　各余りpについて p(p-1)/2 を答えに加算するとよくなる。
// これは、任意の2点の集合から2つ取り出す pC2 に他ならない。

