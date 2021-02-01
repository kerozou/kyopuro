#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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

double dp[103][103][103];
double func(int a,int b,int c){
    if(a >= 100 || b >= 100 || c >= 100)return 0.0;// stop
    if(dp[a][b][c] >= 0.0)return dp[a][b][c]; // メモ化再帰

    double ans = 0;
    ans += ( (double)(a)/(a+b+c) * (func(a+1,b,c) + 1) );
    ans += ( (double)(b)/(a+b+c) * (func(a,b+1,c) + 1) );
    ans += ( (double)(c)/(a+b+c) * (func(a,b,c+1) + 1) );
    dp[a][b][c] = ans;
    
    return ans;
}

int main() {
    int A,B,C;cin >> A >> B >> C;
    memset(dp,-1,sizeof(dp));
    cout << std::fixed << std::setprecision(15) << func(A,B,C) << endl;
}

// ABC184 D - increment of coins