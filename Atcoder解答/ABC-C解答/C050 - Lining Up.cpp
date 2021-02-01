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
    LL N;cin >> N;
    vector<LL> L(N,0);
    rep(i,N){
        LL a;
        cin >> a ;
        L[a]++;
    }
    bool ok = true;
    if(N % 2 != 0){
        if(L[0] != 1)ok = false;
        for(int i = 2;i<N;i += 2)if(L[i] != 2)ok = false;
    }
    if(N % 2 == 0){
        for(int i = 1;i<N;i += 2)if(L[i] != 2)ok = false;
    }
    if(ok){
        LL ans = 1;
        LL lim = N/2;
        rep(i,lim){
            ans *= 2;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    else cout << 0 << endl;
}

// Nの偶奇によって並び方が一意に決まるので、Nの偶奇で分けて考える。
// 1,Nが奇数の時
//  0が1名、それ以外の偶数が各2名ずつ。
// 2,Nが偶数
//  N-1以下の奇数が各2名ずつ。

//  あとは、これをifとループでクリアすればいい