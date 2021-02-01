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
    int N;cin >> N;
    vector<LL> a(N+1);
    vector<pll> L(N);
    vector<LL> ans(N,INF);
    rep(i,N+1){
        if(i == 0)a[0] = INF;
        else cin >> a[i];
    }
    rep(i,N){           // 上からi番目までを引いたときのx
        if(i == 0){
            L[0].F = 0;
        }
        else L[i].F = L[i-1].F + a[i];
    }
    for(int i = N-1;i>=1;i--){  // 上からi番目までを引いた時のy
        if(i == N-1){
            L[N-1].S = a[N];
        }
        else L[i].S = L[i+1].S + a[i+1];
    }
    rep(i,N){
        if(i == 0)continue;
        ans[i] = abs(L[i].F - L[i].S);
    }
    sort(all(ans));

    cout << ans[0] << endl;
}

// 上下の累積和をとって、絶対値をとって終わり。