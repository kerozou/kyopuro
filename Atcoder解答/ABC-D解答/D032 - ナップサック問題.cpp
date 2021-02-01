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
    // 入力
    int N;cin >> N;
    LL W;cin >> W;
    vector<LL> w(N);
    vector<LL> v(N);
    rep(i,N)cin >> v[i] >> w[i];

if(N <= 30){

    vector<int> bit_flag(30);
    rep(i,30){
        bit_flag[i] = (1 << i);
    }

    // 半分集合の前半
    int sz = N/2;
    int lim = (1 << sz);
    vector<pll> A(lim);
    for(int bit = 0;bit < (1 << sz);bit++){
        LL weight = 0;
        LL value = 0;
        rep(i,sz){
            if(bit & bit_flag[i]){
                weight += w[i];
                value += v[i];
            }
        }
        A[bit] = make_pair(weight,value);
    }


    // 無駄な部分を省く(この流れが天才すぎる)
    sort(all(A));
    int m = 1;
    rep(i,lim)if(A[m-1].S < A[i].S)A[m++] = A[i];       
    
    // if内でソート済み連番を比較して、w[i]<w[j] ^ v[i]>v[j] なる雑魚いやつを全部前へ前へ詰めていってる。
    // つまり、(2,3)(2,4)(2,4)(2,5)(3,1)(3,2)(3,6) ってあったら、(2,4)被りで一回mが止まり、1個ずれたiが(2,5)を前に押し出す。
    // (2,5)から(3,6)までは、(3,1)(3,2)が押しつぶされて消える。
    // 最終的に残るのは、(2,3)(2,4)(2,5)(3,6)だけになる。
    // このとき、この7組でやったとしたら、m=1は3回インクリメントされて、m=4になる。このmは後半の二分探索のイテレータ指定に使う。
    


    /////////////////////////////////////////////
    // 半分集合の後半
    int sz2 = (N - (N/2) );
    int lim2 = (1 << sz2);
    LL ans = 0;
    for(int bit = 0;bit < (1 << sz2);bit++){
        LL weight = 0;
        LL value = 0;
        rep(i,sz2){
            if(bit & bit_flag[i]){
                weight += w[i+N/2];     // N/2 を足すのは、全体集合を二つに分けているから
                value += v[i+N/2];
            }
        }
        if(weight <= W){
            LL temp_v = (lower_bound(A.begin(),A.begin()+m,make_pair(W - weight,INF)) -1) -> S;     // (2,5)(2,6)(2,7)(3,9)とあったら、lower_boundは(3.9)のitrを返すので、それから-1したものが求めたいもの。
            ans = max(ans,value + temp_v);
        }
    }
    cout << ans << endl;

}
else{
    LL wmax = 0;rep(i,N)wmax = max(wmax,w[i]);
    LL vmax = 0;rep(i,N)vmax = max(vmax,v[i]);

    if(wmax <= 1000){
        if(W > 200000)W = 200000;
        vector<vector<LL>> dp(220,vector<LL>(200100,0));        // 静的配列だとdp[220][200100]にするとなんかメモリリークなのか知らんけど壊れる。[100100]はいけるのに謎。

        rep(i,N) for(int sum_w = 0;sum_w <= W;sum_w++){
            if(sum_w - w[i] >= 0)chmax(dp[i+1][sum_w],dp[i][sum_w - w[i]]+v[i]);
            chmax(dp[i+1][sum_w],dp[i][sum_w]);
        }

        cout << dp[N][W] << endl;
    }
    else if(vmax <= 1000){
        vector<vector<LL>> dp(220,vector<LL>(200100,INF));      // これを静的配列dp[220][200200]にしてると無限にばぐった。やっぱvector使うべきだわ。
        rep(i,220) rep(j,1100)dp[i][j] = INF;
        dp[0][0] = 0;

        rep(i,N) for(int sum_v = 0;sum_v <= 200000;sum_v++){
            if(sum_v - v[i] >= 0)chmin(dp[i+1][sum_v],dp[i][sum_v - v[i]]+w[i]);
            chmin(dp[i+1][sum_v],dp[i][sum_v]);
        }
        LL ans = 0;
        rep(i,200000)if(dp[N][i] <= W)ans = i;
        cout << ans << endl;
    }
}
    
}


