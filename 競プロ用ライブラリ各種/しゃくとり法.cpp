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
    LL N,K;cin >> N >> K;
    vector<LL> a(N);
    rep(i,N)cin >> a[i];


    LL right = 0;
    LL sum = 0;
    LL ans = 0;

    rep(left,N){
        while(right < N && sum + a[right] < K){
            sum += a[right];
            right++;
        }
        if(sum + a[right] >= K)ans += (N-1) - right + 1;

        if(left == right)right++;
        else sum -= a[left];
    }

    cout << ans << endl;
}

// ABC-D130 D - Enough Array

// アイディアは尺取り法そのまま。
// しゃくとり法の内容はけんちょんさんの記事を参考にした。
// https://qiita.com/drken/items/ecd1a472d3a0e7db8dce#1-3-%E3%81%97%E3%82%83%E3%81%8F%E3%81%A8%E3%82%8A%E6%B3%95%E3%81%8C%E4%BD%BF%E3%81%88%E3%82%8B%E6%9D%A1%E4%BB%B6


// しゃくとりほうのひな形的に記事にもあるように次のようにイメージしておくといい。

/* 
int right = 0;     
for (int left = 0; left < n; ++left) {
    while (right < n && (right を 1 個進めたときに条件を満たす)) {
        /* 実際に right を 1 進める */
        // ex: sum += a[right];
        //++right;
 //   }

    /* break した状態で right は条件を満たす最大なので、何かする */
    // ex: res += (right - left);

    /* left をインクリメントする準備 */
    // ex: if (right == left) ++right;
    // ex: else sum -= a[left];
// }


// あと、尺取り法が使える条件についてもよく確認しておくこと。
// 基本的なイメージとしては、←の境界と→の境界が右に動いていくのだから、
// それぞれが左に動くことが無いように、広義単調増加、広義単調減少などにならないといけない。


// // ABC098 D - Xor Sum 2 使用例

