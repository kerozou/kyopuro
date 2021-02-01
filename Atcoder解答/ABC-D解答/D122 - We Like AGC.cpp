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

void add(LL &a,LL b){
    a = (a+b) % MOD;
}

bool ng(int a,int b,int c){ //true で”AGC”
    return (a==1 && b==2 && c==3);
}

int main(){
    int N;cin >> N;
    // TAGC を0123 とする。
    LL dp[110][4][4][4];
    dp[0][0][0][0] = 1; // T のみからなる0文字の文字列の数として初期条件を置く。
    
    rep(i,N) rep(a,4) rep(b,4) rep(c,4) rep(d,4){   // i は n文字目まで、a,b,cは最後尾の左から1,2,3個の文字、dは後ろに付け足す文字
        // 3文字でNGの時 AGC, GAC, ACG
        if( ng(b,c,d) || ng(c,b,d) || ng(b,d,c) )continue;
        // 4文字でNGの時 AXGC, AGXC
        if( ng(a,b,d) || ng(a,c,d))continue;
        // dp遷移
        add(dp[i+1][b][c][d],dp[i][a][b][c]);
    }

    LL ans = 0;
    rep(a,4)rep(b,4)rep(c,4) add(ans,dp[N][a][b][c]);
    cout << ans << endl;

}

// ABC-D122 D - We Like AGC

// 手始めに包徐原理で解こうとしたけど、肝心のP(i)⋀P(j)が不明でもう大変。
// 解説見たらDPでやっててたまげた。

// アルメリアさんの解説頭良すぎるのと、バグりにくくてすっきりしてていい。
// https://betrue12.hateblo.jp/entry/2019/03/24/224052

// こういう問題がどうしてDPだとひらめくのかは謎。
// 可能性としては、選ばれる文字の可能性が4つと絞られていて、なおかつN=100が最大なので、4次元DPとかでも楽勝ってことから気づく？
// あとは、単純に後ろ3文字と付け足す文字1つの合わせて4文字だけが問題の条件にかかわるという「不変」的な発送なのかもしれない。
// あらかじめ条件を通過した文字列の後ろに文字を足していく発想は確かにDPだと思った。
// 後ろ3文字のパターンの場合の数が、全体文字列全部でn文字の時にそれぞれ排反になることもDPの選択要因だと思った。
// なので、今回の学びは
// ・「TAGCの4文字から作られる文字列がOKと仮定したときに、後ろに文字を足していく方法」を思いつく。
// ・その時に、NG条件を通過できるかをDPしていく。
// ・あらかじめ、add,ng といった記述をすっきりさせる関数を用意する。
// ・bool関数は、こういう複数条件を書くときに使いやすい
// ということらへんを覚えておこうと思った。