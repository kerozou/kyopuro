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
    LL N,T;cin >> N >> T;
    vector<LL> t(N);
    rep(i,N)cin >> t[i] ;
    LL ans = 0;
    rep(i,N){
        if(i != N-1){
            if(t[i]+T <= t[i+1])ans += T;
            else ans += t[i+1] - t[i];
        }
        else ans += T;
    }
    cout << ans << endl;
}

// 前の人がおした後にお湯が出る時刻はt[i]＋Tでこれが＜＝t[i+1]のときT増える。逆の時t[i+1]-t[i]だけふえる