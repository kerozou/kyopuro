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

std::vector<bool> IsPrime;
void sieve(LL max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(LL i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(LL j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}


int main(){
    int Q;cin >> Q;
    sieve(100003);
    vector<int> l(Q);
    vector<int> r(Q);
    rep(i,Q)cin >> l[i] >> r[i];

    vector<int> ok(100003,0);
    rep(i,100001){
        if(IsPrime[i])if(i % 2 == 1)if(IsPrime[(i+1)/2])ok[i] = 1;
    }
    vector<LL> rui(100002,0);
    rui[0] = 0;
    rep(i,100001){
        rui[i+1] = rui[i] + ok[i+1];
    }
    rep(i,Q){
        cout << rui[r[i]] - rui[l[i]-1] << endl;
    }
}

// ABC084 D - 2017-like Number

// 素数は基本的にうまい解決法はないと思うので、愚直に調べるほかないはず。
// しかし、l<=x<=rの範囲で調べるとO(N^2)はくだらないはず。

// そういう時に有効なのが、O(N)の一巡で前処理を済ませておいて、各クエリをO(logN)以下に抑える方法であるはず。
// そのようなはDP、累積和、尺取りなどが考えられて、今回は素数チェック判定の累積和を事前に用意しておけば解ける。
// 素数の特徴としても、前後の数や法則によらない独立な部分があるので、このへんは累積和が有効。