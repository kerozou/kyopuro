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
    int N,K;cin >> N >> K;
    LL ans = 0;

    if(K != 0){
        rep(b,N+1)if(b != 0)ans += N/b * max(0,(b - K)) + max(0,(N % b - K + 1)); 
    }
    else ans = (LL)N * (LL)N;
    cout << ans << endl;
}

// ABC090 D - Remainder Reminder

// ここのサイトに詳しい説明がのってる
// http://tutuz.hateblo.jp/entry/2018/07/16/135300

// 注意点として、
// ・ゼロ除算しないこと
// ・int * int で桁あふれが発生するので注意