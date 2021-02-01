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

void pre(vector<int>& a,const int s,const int t){
    ++a[s];
    --a[t];
}

void imos(vector<int>& a){
    int sz = a.size();
    for(int i = 1;i <= sz;++i){
        a[i] += a[i-1];
    }
}

int main(){
    int N,C;cin >> N >> C;
    vector<int> s(N);
    vector<int> t(N);
    vector<int> c(N);
    rep(i,N)cin >> s[i] >> t[i] >> c[i],++t[i],--c[i];

    vector<vector<int>> rec(C,vector<int>(100010));
    rep(i,N){
        pre(rec[c[i]],s[i],t[i]);
    }
    rep(i,C){
        imos(rec[i]);
    }
    int ans = 0;
    rep(i,100010){
        int tmp = 0;
        rep(j,C)if(rec[j][i])tmp++;
        ans = max(ans,tmp);
    }

    cout << ans << endl;
}

// ABC080 	D - Recording

// imos法による。
// BIT でもできそうだけど、わざわざ大変な方法を選ぶメリットがない。
// あと、調べてみた感じ、BITってimosとほぼ変わらないような気がする。
// kerozouの知らない高速化利用例とかそもそもの用途が違うのかもしれん。

// 仕組みは簡単なんだけど、細かい制御とか添え字でバグり散らかしたので、実装はvectorではなくint二次元配列で実装するべきだと思った。
// というか、可変長じゃなくていいときは極力レガシーで書いたほうが良いのかもわからん。

// https://madman6.hatenablog.jp/entry/2018/06/28/174150
// この解説がわかりやすい。

// imosの解説は公式で
// https://imoz.jp/algorithms/imos_method.html

// あと、気を付けるのは、これは全然二次元いもすじゃないということ。