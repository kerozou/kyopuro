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
    string L;cin >> L;
    LL dp[100010][2] = {0};
    int N = L.size();
    dp[0][0] = 1;

    rep(deg,N) rep(isless,2){
        // a,b = 0,0
        if(L[deg] == '1')dp[deg + 1][1] = (dp[deg+1][1] + dp[deg][isless]) %MOD;
        else dp[deg + 1][isless] += (dp[deg+1][isless] + dp[deg][isless]) %MOD;

        // a,b = 1,0 0,1
        if(L[deg] == '1' || isless)dp[deg + 1][isless] = (dp[deg+1][isless] + (dp[deg][isless]) * 2) %MOD;
    }

    cout << (dp[N][0] + dp[N][1]) %MOD << endl;
}
