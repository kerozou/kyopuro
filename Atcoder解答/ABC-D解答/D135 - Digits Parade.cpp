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
    string S;cin >> S;
    LL N = S.size();
    vector<vector<LL>> dp(100010,vector<LL>(13,0));

    if(S[0] == '?')rep(j,10)dp[0][j] = 1;
    else{
        int tmp = S[0] - '0';
        dp[0][tmp] = 1;
    }
    
    rep(i,N-1)  rep(k,13){
            if(S[i+1] == '?')rep(j,10)dp[i+1][(10*k + j) % 13] += dp[i][k] % MOD;
            else{
                int t = S[i+1] - '0';
                dp[i+1][(10*k + t) % 13] += dp[i][k] % MOD;
            }        
    }  

    LL ans = dp[N-1][5] % MOD;
    cout << ans << endl;

}

// 正解にはたどり着いてないけど、貰うDPでやろうとしたらエラー吐いて死んだ。
// おそらくif(i == 0) を作ってたのが原因っぽい。

// 正解したので記述する
// この問題は桁DPで解く。
// 13のMODは 0~12の13個なので、
// DP[i][j] := i番目の桁を1の位としたときのMOD13=ｊの個数　とする。
// 遷移式は、配るDPで考えて
// i桁までのMODは合同式から 今の数字をAとすると
//       A ≡ k (MOD13)
//   10*A  ≡ 10*k
//  10*A+a ≡ 10*k + a
// に等しくなるはず。
// なので、
//      dp[i+1][(10*k + a) % 13] := dp[i][k]
// という遷移式がかける。
// あとは、初期条件とかいろいろバグんないように気を付けながらこれを実装するだけ。
// 20191027 AC