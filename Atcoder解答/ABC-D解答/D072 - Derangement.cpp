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
    vector<int> p(N);
    rep(i,N)cin >> p[i];

    int ct = 0;
    bool ok = false;
    rep(i,N){
        if(p[i] == i+1){
            if(ok)ok = false;
            else{
                ok = true;
                ct++;
            }
        }
        else{
            ok = false;
        }
    }
    cout << ct << endl;
}

// ABC072 D - Derangement

// 隣り合う数字をswapしたところで絶対に p[i]=i になることはない。
// これは実際にやってみればわかることで、swapしてp[i]=iができるためには 213 の 21 を動かすときのように、
// p[i]=iとならない数同士を選択してswapする必要がある。

// 加えて、p[i]=iとなる数が連続するときに一回のswapで2つ数字を消化できることに着目すると、
// 連続するp[i]=iペアの数　＋　連続しないp[i]=iの数　が答えになる。