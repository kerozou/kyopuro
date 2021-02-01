#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    int N;cin >> N;
    vector<LL> a(N);rep(i,N)cin >> a[i];

    bool ok = false;
    rep(i,N){
        if(a[i] % 2 == 1)ok = true;
    }

    if(ok)cout << "first" << endl;
    else cout << "second" << endl;

}

// CADDi 2018 D - Harlequin

/*
    解答のまんまでつくった。

    この問題で重要なのは、「先攻後攻が最善を尽くす」ありがちな問題であるところ。
    この類の問題は
    ・最後の一手前に落とし込む
    ・必勝法を見つける
    のが解答法なんだけど、今回は必勝法の場合だった。

    どうしてこの解答が導けるのかというと、りんごの数の偶奇が2つに分かれて01で表せるから。
    これは、相手の動きを真似てそっくりそのまま状況再現ができるということ。
    なので、最後の一手前に落とし込むのと似てる。

    全部0になる手番を引くことが勝ちの条件なので、その手は必ず奇数を含む。
    なので、毎ターン必ず奇数手を自分が引き、相手が偶数手を引き続ければ勝てるということに気づければいい。

    これは結局、最後と一個前の手を繰り返すという「この手の問題」の解き方に忠実である。
*/