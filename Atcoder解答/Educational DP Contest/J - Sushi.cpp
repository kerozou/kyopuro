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

double dp[310][310][310];
int N;

double rec(int i,int j,int k){
    if(dp[i][j][k] >= 0)return dp[i][j][k];
    if(i == 0 && j == 0 && k == 0)return 0.0;

    double res = 0.0;
    if(i > 0)res += rec(i-1,j,k) * i;
    if(j > 0)res += rec(i+1,j-1,k) * j;
    if(k > 0)res += rec(i,j+1,k-1) * k;
    res += N;
    res *= 1.0 / (i+j+k);

    return dp[i][j][k] = res;
}

int main(){
    cin >> N;
    int one = 0,two = 0,thr = 0;
    rep(i,N){
        int a;cin >> a;
        if(a == 1)one++;
        else if(a == 2)two++;
        else thr++;
    }


    memset(dp,-1,sizeof(dp));   //初期化

    cout << fixed << setprecision(10) << rec(one,two,thr) << endl;

}

