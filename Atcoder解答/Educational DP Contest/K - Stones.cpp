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

bool dp[100100];        // こいつをメイン関数内で宣言するとfalseに初期化されないっぽい。や静糞。

int main(){
    int N,K;cin >> N >> K;
    vector<int> a(N);
    rep(i,N)cin >> a[i];



    for(int i = 1;i <= K;++i) rep(j,N) if(i - a[j] >= 0)dp[i] |= !dp[i - a[j]];

    string ans = "";
    if(dp[K])ans = "First";
    else ans = "Second";
    cout << ans << endl;
}

