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
    int N,M; cin >> N >> M;
    vector<pair<int,int>> A(M);
    rep(i,M)cin >> A[i].S >> A[i].F;

    sort(all(A));

    int ans = 0;
    int endtime = 0;
    rep(i,M){
        if(A[i].S >= endtime){
            endtime = A[i].F;
            ans++;
        }
    }
    cout << ans << endl;
}

// ABC103 D - Islands War

// 蟻本にも載ってる超有名問題の「区間スケジューリング問題」と同じ考え方をする問題。
// http://drken1215.hatenablog.com/entry/2018/07/21/224200

// 一瞬UnionFindかと思ったけど、橋を落としていく仮定を復元するのが無理だったので違うと思った。




// 追記20201029

/*
    区間スケジューリング問題がARC106に出て解けなかったのでメモ。
    基本的に区間スケジューリングで覚えておかなければならない事項は
    
        1, 目的は「1次元の区間 [L:R] において、重複なく最も多くの区間を選ぶ」こと
        2, R の昇順で区間をソートして、R の座標で下へ串刺しにして刺さった部分はノーカウントで次へと進んでいく

    というものである。
    1 はそのまま 区間スケジューリング を必要とする場合がどういう時かを理解しておく必要があるということ。
    2 は区間スケジューリングを貪欲で書くために知っておくこと。

    この手続きでシンプルに処理できることを知っておけば、道具として使いこなせるはず。
*/