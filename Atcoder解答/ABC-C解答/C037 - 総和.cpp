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
    vector<LL> a(N);
    rep(i,N)cin >> a[i];
    LL tmp = 0;
    rep(i,K)tmp += a[i];
    LL ans = tmp;
    for(LL i = 0;i < N-K+1;i++){
        if(i == 0)continue;
        else{
            tmp -= a[i-1];
            tmp += a[i+K-1];
            ans += tmp;
        }
    }
    cout << ans << endl;
}

// 列を一個ずつずらしていくだけ。