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
    LL N,H;cin >> N >> H;
    priority_queue<pll> pque;
    rep(i,N){
        LL a,b;
        cin >> a >> b;
        pque.push({a,0});
        pque.push({b,1});
    }
    LL HP = H;
    LL ct = 0;
    while(H > 0){
        pll tmp = pque.top();
        H -= tmp.F;
        ct++;
        if(tmp.S == 1)pque.pop();
        else{
            if(H > 0)ct += (H+tmp.F-1)/tmp.F;
            break;
        }
    }
    cout << ct << endl;
}

// ABC085 D - Katana Thrower

// 攻撃力の高い刀を振り続けて、最後にピッタリ削り切れるように順に刀を投げればいい。
// つまり、逆から貪欲に攻撃をすればよく、この場合刀を投げてからも刀で切れるような感覚でいけるので、それを実装。
// ただ、愚直に描くとTLEしたので、(H=10^9のとき)刀を投げ切った段階であとはAによるHPの除算で求まる。
// この時、ceilを使うとバグったのでceilとfloorは使うのやめよう。

// ceil = (H+i-1)/i でいける。