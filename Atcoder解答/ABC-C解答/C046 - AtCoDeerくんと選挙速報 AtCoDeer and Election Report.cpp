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
    vector<LL> a(N);
    vector<LL> b(N);
    rep(i,N)cin >> a[i] >> b[i];
    vector<LL> ans(N);
    LL A = 1;
    LL B = 1;
    rep(i,N){
        ans[i] = max((A+a[i]-1)/a[i],((B+b[i]-1)/b[i]));
        A = ans[i]*a[i];
        B = ans[i]*b[i];
    }
    cout << A + B << endl;
}

// double は15桁以上で値がずれるらしい。浮動小数点の宿命。
// なので、最後にキャストして整数化するときとかに小数で計算するのは危険。
// また、ceilは小数にしか使えないので、LLに適応したいときは
//      (a + (b - 1)) / b 
// とするとよい。


// 20200309追記
// あさかつの問題だったが、解けず。
// 解法としては
// 入力例1を例にすると、
// 2 3 を3 3 にしたければ、2 に 1 を足せばいい。
// それを一般化するためには、前回操作分の投票数を超える最小のペアを見つける必要がある。
// この時、現在見ている数字のペアにたいして、前回の票数/現在の比率　を切り上げで求めて、
// その大きいほうを現在の比率にかければ、どちらも前回の投票数以上になることがわかる。

// この時、なぜ前回投票数を超える最小の票数になるかを考える。
// 疑問の可能性としては、「投票数を比率で割ってでた値はdoubleでないといけないのでは？」
// というものがある。
// これは、問題でTとAは互いに素とあるので、両者が共に偶数になることはありえないので、1.5倍といった小数倍が候補に入ることはないのである。
// したがって、大きいほうの比率を切り上げたもので両者を乗じたものが考えうる最小のペアである。

