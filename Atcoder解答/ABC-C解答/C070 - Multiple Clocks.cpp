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

LL GCD(LL a,LL b){ //ユークリッドの互助法で最大公約数
    if (a%b == 0){
        return b;
    }
    else {
        return GCD(b,a%b);
    }
}

LL LCM(LL a,LL b){ //GCDを使って最小公倍数を求める
    LL g = GCD(a,b);
    return (a/g)*b;  // (a*b)/GCD(a,b) なんだけど、こうしないとa,b=INFとかだとはみ出しちゃう
}

int main(){
    LL N;cin >> N;
    vector<LL> T(N);
    rep(i,N)cin >> T[i];
    LL tmp = 0;
    if(N == 1)cout << T[0] << endl;
    else{
        tmp = LCM(T[0],T[1]);
        for(int i = 2;i<N;i++)tmp = LCM(tmp,T[i]);
        cout << tmp << endl;
    }
}

// 最小公倍数とるだけ。LLのはみ出しやN==1の時に注意（2敗）