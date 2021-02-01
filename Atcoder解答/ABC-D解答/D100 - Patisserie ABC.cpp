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
    int N,M;cin >> N >> M;
    vector<vector<LL>> a(3);
    rep(i,N){
        rep(j,3){
            LL s;cin >> s;
            a[j].push_back(s);
        }
    }


    LL ans = 0;
    for(int bit = 0;bit < (1 << 3);++bit){
        vector<LL> v;
        rep(i,N){
            LL tmp = 0;
            rep(j,3){
                if(bit & (1 << j))tmp += a[j][i];
                else tmp -= a[j][i];
            }
            v.push_back(tmp);
        }
        sort(rall(v));
        LL sum = 0;
        rep(i,M){
            sum += v[i];
        }

        ans = max(ans,sum);
    }

    cout << ans << endl;
}

// ABC100 D - Patisserie ABC

// 一見DPだと思わせておきながら違うパターン
// DPでもやれないことはないけどってかんじ

// 3個のパラメタの絶対値の合計が欲しい。
// この時、各数値が正だと仮定すると、パラメタ毎の和の和とパラメタ同士の和の和は同じ結果になるはず。
// （各種類ごとに足しあげたものを足すか、各ケーキごとの数値の和を足すか）
// しかし、負の数が混ざっているので、ケーキごとにやると絶対値がぶれてしまう。

// なので、 + - - といったようにあらかじめ各パラメタが目指す符号を決め打ちしておいて、各符号セットごとのとりうる最大値を2^3 = 8通り更新すればよい。
// 本来正の数値を-1かけて足してあげた時、そのセットは最大値になりえないはず。

// これらの実装をbitでマスクしてあげると楽。
// bit 101などの時のパターン毎に作ったvectorを降順ソートして上からM個足しあげればよい。


