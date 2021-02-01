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
    int N,K;cin >> N >> K;
    vector<LL> V(N);
    rep(i,N)cin >> V[i];

    LL res = 0;
    for(int p = 0;p <= min(N,K);++p){
        for(int q = 0;p + q <= min(N,K);++q){
            vector<LL> get;
            LL cur = 0;
            rep(i,p)get.push_back(V[i]),cur += V[i];            // 左からとり続ける
            rep(i,q)get.push_back(V[N-1-i]),cur += V[N-1-i];    // 右からとり続ける

            sort(all(get));
            for(int i = 0;i < min(K-p-q,(int)get.size());++i){  // 残り回数か、もしくはとった分だけ元に戻す。 
                if(get[i] < 0)cur -= get[i];
            }
            res = max(res,cur);
        }   
    }

    cout << res << endl;
}

// ABC-D128 D - equeue
// 全探索をうまくやれば通る。
// 今回の問題で学ぶべきポイントは、
// ・左からp回取り出し、右からq回取り出す時のforループのとりかた
// ・dequeをvectorで実装しているところのforごとに初期化されて使い捨てにするところ。
// ・rep()内の表記に,を使うことで1行で短く書いてるところ。

// けんちょんさんの記事参照
// http://drken1215.hatenablog.com/entry/2019/06/15/142900
