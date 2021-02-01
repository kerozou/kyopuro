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
    LL N,A;cin >> N >> A;
    vector<LL> x(N+1);
    rep(i,N)cin >> x[i];
    LL dp[52][52][52*(N+1)] = {0};
    rep(i,N+1) rep(j,N+1) for(LL k = 0;k<50*(N+1);k++){
        if(i == 0 && j == 0 && k == 0)dp[0][0][0] = 1;
        else if(i == 0)continue;
        else if(i < j)continue;
        dp[i+1][j][k] += dp[i][j][k];       // 次のカードを引かないとき
        dp[i+1][j+1][k+x[i]] += dp[i][j][k];    // 次のカードを引くとき
    }
    LL ans = 0;
    for(LL j = 1;j<N+1;j++){
        ans += dp[N][j][A*j];
    }
    cout << ans << endl;
}

// 配列の要素の中に [k+x[i]] というのがあるが、ここでrep(k,50*N)としていたため、k は int であり、
// k + x[i] が int + LL となっておかしな挙動になっていた。
// for になおしたらそれだけで治った。

// ありがちなエラーとして、ans が int で桁あふれがある(一敗）