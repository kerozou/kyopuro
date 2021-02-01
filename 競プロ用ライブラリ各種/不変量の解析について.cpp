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
    int N;cin >> N;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];
    int ct = 0;
    rep(i,N)if(A[i] < 0)ct++;

    if(ct & 1){  // 奇数
        rep(i,N)A[i] = abs(A[i]);
        sort(all(A));
        A[0] *= -1;
        LL ans = 0;
        rep(i,N)ans += A[i];
        cout << ans << endl;
    }
    else{
        LL ans = 0;
        rep(i,N)ans += abs(A[i]);
        cout << ans << endl;
    }
}

// ABC-D125 D - Flipping Signs

// 解説はけんちょんさんの記事をみれば細かく書いてる
// http://drken1215.hatenablog.com/entry/2019/04/27/224100

// 今回の問題の学びは、
// ・不変量をみつけること
// で、これはABCレベルなら自明なことが多いらしい。
// 今回でいうと、負の数の個数の偶奇が不変らしい。（負の数は2個減るか、1個も減らないで動くだけかなので）
// そのことに気づくと偶奇で排反にとれ、さらには1通りに定まるということ。
