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
    int H,W;cin >> H >> W;
    vector<string> s(H);
    rep(i,H)cin >> s[i];

    vector<vector<int>> dp(H,vector<int>(W,1000));
    dp[0][0] = 0;
    if(s[0][0] == '#')dp[0][0] = 1;

    rep(i,H)rep(j,W){
        char c = s[i][j];
        if(c == '#'){

            if(i < H-1)chmin(dp[i+1][j],dp[i][j]);
            if(j < W-1)chmin(dp[i][j+1],dp[i][j]);
        }
        else{
            if(i < H-1 && s[i+1][j] == '#')chmin(dp[i+1][j],dp[i][j]+1);
            else if(i < H-1) chmin(dp[i+1][j],dp[i][j]);

            if(j < W-1 && s[i][j+1] == '#')chmin(dp[i][j+1],dp[i][j]+1);
            else if(j < W-1)chmin(dp[i][j+1],dp[i][j]);
        }
    }

    cout << dp[H-1][W-1] << endl;
}

// AGC043 A - Range Flip Find Route

/*
    反転が選んだ経路について、任意の区間で行えることに気づくと、あとはDPするだけになる。
*/