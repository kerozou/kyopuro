#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    LL N,M;cin >> N >> M;
    if(N >= 2 && M >= 2)cout << (N - 2) * (M - 2) << endl;
    else if(N == 1 && M == 1)cout << 1 << endl; 
    else if(N == 1)cout << M - 2 << endl;
    else if(M == 1)cout << N - 2 << endl;
}

// ABC090 C - Flip,Flip, and Flip......
// ・隣接するマスと自分のマス　の個数、つまり自身が反転する回数を考える。

// 自然に考えると、
// 1. 四隅（4回転　表）
// 2. 四隅以外の四辺沿いのマス（6回転　表）
// 3. 八方を囲まれた9回反転組（9回転　裏）

// の3つくらいに分類できそう。
// ただ、注意すべきは上にあげた3つは　いずれも行列が3×3以上を想定している。
// 3はどんな状況でも成り立ち、1は　N or M　==　1　のとき以外成り立つ。

// N , M が1の時は個別に例外を設ければいい。
// 1×N　の時は　両サイドが二回転で表、それ以外は三回転で裏になる。