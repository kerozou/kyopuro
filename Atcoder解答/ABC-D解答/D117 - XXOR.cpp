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
    LL N,K;cin >> N >> K;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];

    LL dp[62][2];   // 1 でぴったり 0 で自由
    rep(i,62)dp[i][0] = dp[i][1] = -1;
    dp[61][1] = 0;

    for(int i = 60;i >= 0;--i){
        LL mask = 1LL << i;
        LL num = 0;
        rep(j,N) if(A[j] & mask) ++num;
        LL cost0 = mask * num;
        LL cost1 = mask * (N-num);

        if(dp[i+1][1] >= 0){
            // ぴったり　→　ぴったり
            if(K & mask)chmax(dp[i][1],dp[i+1][1] + cost1);  // X の i桁目が 1 の時
            else chmax(dp[i][1],dp[i+1][1] + cost0);         // X の i桁目が 0 の時
            // ぴったり　→　ゆるい
            if(K & mask)chmax(dp[i][0],dp[i+1][1] + cost0);
        }

        if(dp[i+1][0] >= 0){
            // ゆるい　→　ゆるい
            chmax(dp[i][0],dp[i+1][0] + max(cost0,cost1));
        }
    }

    LL ans = max(dp[0][0],dp[0][1]);
    cout << ans << endl;
}

// ABC117 D - XXOR

// XOR　を無限にとるとき、桁DPが相性がいい。
// 桁DPは
// ・上限ぴったり、それ以外
// の二つの場合をDPで遷移していく。
// このへんの説明は桁DPで調べよう。
// http://drken1215.hatenablog.com/entry/2019/02/04/013700

// 初期条件を逆にしててバグってた。


// >= 0 っていうのは前の位が更新済みかを確認することと同義で、
// ぴったり　→　ゆるい　のパターンが発生しないまま下層まで進むことが考えられるため、
// それまでは　ゆるい　→　ゆるい　の操作が発生しないことを保証している。

// 桁DPの学び
// ・3種類の遷移のうち、ゆるゆるのときに上記のことに注意すること。
// ・スタート地点は完全一致してる要素が0桁目に該当とかんがえて dp[start][1]からはじめること。（これでバグりまくった）


