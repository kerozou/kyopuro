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
    vector<LL> A(N,0);  // 入力用
    map<LL,bool> L;     // 真偽表
    rep(i,N){   // 入力と初期化
        cin >> A[i];
        L[A[i]] = false;
    }
    rep(i,N)L[A[i]] = !L[A[i]];     // 真偽の反転
    LL ans = 0;
    for(auto itr = L.begin() ; itr != L.end() ;itr++)if(itr -> S)ans++;     // true の数だけ追加する。
    cout << ans << endl;


}

// カウントしたものの真偽をその都度反転すればいい。
// 重複を省くために、というか重複がこの問題のテーマだから、mapを使う。