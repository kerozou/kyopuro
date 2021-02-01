#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    string S;cin >> S;   
    int sz = S.size();
    int mod = 2019;
    vector<LL> ten_dp(sz + 4);
    ten_dp[0] = 1 % mod;
    for(int i = 1;i <= sz;i++){
        ten_dp[i] = ((ten_dp[i-1]) * 10) % mod;
    }



    vector<LL> dp(sz+4);
    dp[sz-1] = (S[sz-1] - '0') * ten_dp[0];
    for(int i = 1;i < sz;i++){
        int num = S[sz-1-i] - '0';
        dp[sz-1-i] = (((num * ten_dp[i]) % mod) + dp[sz-i]) % mod;
    }

    map<int,int> m;
    rep(i,sz){
        m[dp[i]]++;
    }

    LL ans = 0;

    for(auto t : m){
        ans += (t.S*(t.S - 1)/2);
        if(t.F == 0)ans += t.S;
    }

    cout << ans << endl;
}

// ABC164 D - Multiple of 2019

/*
    2019の倍数になる部分は 
    （　右から　i桁目まで　の数　mod2019　- 右から j桁目まで　の数　mod2019 == 0）
    となるi,jによって指定される区間である。
    すなわち、2019の剰余に関しての同値類を考えればいい。
    あとは、求まった剰余の数値をmapか何かでカウントし、全てに関し nC2　したものを加算すれば終わり。

    この問題の肝心の部分は考えるべき数が容易に「18桁を超える」ところである。(上限が200000桁の時点でいろいろ察する)
    つまり、単純計算するとオーバーフローしてしまう。
    なので、ここは剰余類の性質を生かして「k桁目までを求める際に、k-1桁目の結果を利用する」方針を考えることでこれを回避する。

    とりあえず、剰余演算は和差積に関して閉じているので 右からi桁目の数字を num[i] とすると、
    右からi桁目までのi桁の数は　num[i] * 10^i + num[i-1] * 10^(i-1) * ・・・ * num[0] * 10^0 となる。
    すなわち、Σ num[k]*10^k となるわけだ。
    これだとk > 18でオーバーフローするので、 10^k をあらかじめ mod2019 で剰余演算しておいたものを配列として準備しておく。
    num[k] * (10^k % 2019) は高々10^5程度なので10^18をはみ出ることはあり得ない。
    また、 (num[k] * (10^k % 2019) ) % 2019 の正当性は、mod演算が和差積で閉じてることから示される。
*/



    