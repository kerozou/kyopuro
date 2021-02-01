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
    vector<LL> a(N);
    LL x;cin >> x;
    rep(i,N)cin >> a[i];
    LL ans = 0;
    rep(i,N){
        if(i == 0)continue;
        if(a[i-1] >= x){
            ans += a[i-1] - x;
            a[i-1] = x;
            ans += a[i];
            a[i] = 0;
        }
        else{
            if(a[i]+a[i-1] > x){
                LL tmp = a[i]+a[i-1]-x;
                ans += tmp;
                a[i] -= tmp;
            }
            else continue;
        }
    }
    cout << ans << endl;
    
}

// 左から順に飴の数をカウントしてあげて、二個ずつチェックしていく
// 左がx個以上あるときには、左をx個、右を０個にする。
// それ以外はxの超過分を右から引いていけばいい。

