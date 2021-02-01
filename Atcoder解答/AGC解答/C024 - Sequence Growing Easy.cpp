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
    LL N;cin >> N;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];

    vector<LL> num(N);
    rep(i,N){
        num[i] = i - A[i];
    }
    bool ok = true;
    if(num[0] != 0)ok = false;
    rep(i,N-1){
        if(A[i+1] - A[i] > 1)ok = false;
    }

    if(ok){
        LL ans = 0;
        rep(i,N){
            if(binary_search(all(num),i)){
                LL k = upper_bound(all(num),i) - num.begin() - 1;
                ans += (k-i);
            }
        }
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
}

// AGC024 C - Sequence Growing Easy

/*
    りんごさんの解説を見てAC。
    発想が頭良すぎ。

    この解法での重要なポイントは、後ろ側から処理していく必要がある部分があること。
    例えば
        1 2 2 2 
    とくれば、度重なる2は後ろから処理していかないといけない。
    この辺の話は自分でも考えてけど、結局複雑になってしまった。

    解説では、2は自分の二つ前からやってくることを明らかにしていた。
    これは xi が xi-1 + 1 にしかなりえないことから明らか。
    つまり、　「右に進むと1増えるので、3増やすためには3回→に進む必要がある」　ということ。
    これはすなわち、目標とするA[i]の数字は、A[i]自身の数分だけ前からやってくるということ。
    これが動画で矢印を引いていた意味。
    なので、[ 自分のindex - 自分の数字 = 出発地点のindex ] となる。
    この「出発地点のindex」の配列は広義単調増加なので、upperboundで一番大きいindexを引っ張ってこれる。
    そのindexと出発点の距離をansに足していけば答えになる。

    このとき、A[i] == 0　であることと、各iについて　A[i+1] - A[i] > 1 が必要なことに注意。
    これは、右に3歩しか移動していないのに、3歩先が4増えることはないということ。
*/

