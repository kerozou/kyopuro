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
    LL x;cin >> x;
    if(x < 11){
        LL ans = 0;
        if(ans + 6 >= x)cout << 1 << endl;
        else cout << 2 << endl;
    }
    else{
    LL q = x/11;
    LL ans = 0;
    if(q*11>=x)ans = q*2;
    else if(q*11+6 >= x)ans =q*2+1;
    else ans = q*2 +2;
    cout << ans << endl;  
    }
}

// q = N/11; として、あとはq*11に６，５，６，５と足していけばいい。その時にNを超えるかを判定。