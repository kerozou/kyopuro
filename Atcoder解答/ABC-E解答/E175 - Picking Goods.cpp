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


LL dp[3100][3100][5];
LL it[3100][3100];

int main() {
    LL R,C,K;cin >> R >> C >> K;
    vector<LL> r(K);
    vector<LL> c(K);
    vector<LL> v(K);
    rep(i,K){
        int rr,cc,vv;cin >> rr >> cc >> vv;
        rr--;cc--;
        r[i] = rr;
        c[i] = cc;
        v[i] = vv;
    }

    memset(it,0,sizeof(it));

    rep(i,K)it[r[i]][c[i]] = v[i];

    memset(dp,0,sizeof(dp));

    rep(i,R){
        rep(j,C){
            if(i == 0 && j == 0){
                chmax(dp[0][0][1],it[0][0]);
            }
            for(int k = 0;k <= 3;k++){
                if(i != R-1){
                    chmax(dp[i+1][j][0],dp[i][j][k]);   // 拾わないで下
                    chmax(dp[i+1][j][1],dp[i][j][k] + it[i+1][j]);  // 拾って下
                }
                if(j != C-1){
                    chmax(dp[i][j+1][k],dp[i][j][k]);   // 拾わないで右
                    if(k != 3)chmax(dp[i][j+1][k+1],dp[i][j][k] + it[i][j+1]);    // 拾って右
                }
            }
        }
    }

    LL ans = 0;

    rep(i,4)chmax(ans,dp[R-1][C-1][i]);

    cout << ans << endl;
}


// ABC175 E - Picking Goods

/*
    問題の詰まったところは、
    ・dp配列の初期化に失敗
    ・mapを参照するのが重すぎてTLE
    という2点だった。

    dp配列の初期化をmain内で宣言し
    LL dp[R][C][4];
    rep(i,R)rep(j,C)rep(k,4)dp[i][j][k] = 0;
    とやってたらREになった。
    LL dp[3100][3100][5] をグローバルで宣言して、 memset(dp,0,sizeof(dp)) すると初期化されて問題なく回った。

    dpを配っていく3重ループ内でマス目のポイントをmapで参照しているとTLEになった。
    おそらく、mapの参照はO(N)とかそんな感じではないだろうか。
    これも配列としてグローバルでもっておいたら通った。


    ---


    問題自体は上から下に移動したときの場合分けが特殊なDPだった。
*/
