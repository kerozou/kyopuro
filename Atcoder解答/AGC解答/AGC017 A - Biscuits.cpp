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
    LL P;cin >> P;
    vector<LL> A(N);rep(i,N)cin >> A[i];

    bool ev = true;
    rep(i,N)if(A[i] % 2 == 1)ev = false;
    LL ans = 0;

    if(ev){
        if(P == 0)ans = pow(2,N);
        else ans = 0;
    }
    else{
        ans = pow(2,N-1);
    }
    cout << ans << endl;

}

// AGC017 A - Biscuits

/*
    解説の通り。
    発想が病気。

    今回の問題のポイントは結局「偶奇」の特性を生かしたものだった。
    偶奇のポイントは「一点を選ぶと、その他の結果を操作可能」であるところである。
    つまり、偶数なら変化なし、奇数なら結果を反転できるということ。

    今回は奇数に着目して、どれか一つの数字を選んだ時に、それ以外の選び方の結果を操作できるという点に注目している。
    なので、それ以外のN-1個がなんであれ、偶奇は自由に設定できることになる。
    この時、どの数字を固定したとしても偶奇は2^(N-1)通りになることは予想できる。
    なぜなら、その数字を選んでも結果に対称性があるからだ。
    この時、総数が2^(N-1)個を超えないのは重複するからである。
    計算式的には　2^(N-1)*N/N なので、Nがキャンセルされるわけである。
*/