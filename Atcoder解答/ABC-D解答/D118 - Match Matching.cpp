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

string dp[10010];       // dpはn文字目までの最大値

const string MININF = "-";

// string の大小は　・sizeがデカい方がデカい　・同サイズなら辞書順にデカいほうがデカい　を使う。
// しかし、サイズがデカくても辞書順にソートしたら 11111より9の方がデカいことに注意。
void csmax(string& a,const string& b){
    int as = a.size();
    int bs = b.size();

    if(a == MININF)a = b;
    else if(as == bs)a = max(a,b);
    else if(as < bs)a = b;
}


int main(){
    int N,M;cin >> N >> M;
    vector<int> A(M);
    rep(i,M)cin >> A[i];
    LL match[10] = {2,5,5,4,5,6,3,7,6};

    rep(i,10010)dp[i] = MININF;
    dp[0] = "";

    rep(i,N+1){
        if(dp[i] == MININF)continue;
        for(auto a : A)csmax(dp[i + match[a-1]] , dp[i]+(char)('0' + a));
    }

    cout << dp[N] << endl;
}


// ABC118 D - Match Matching

// けんちょんさんのコード参照
// http://drken1215.hatenablog.com/entry/2019/02/16/224100

// MININF　を　”MININF"　にしててバグりまくった。
// 今回の学びは
// ・文字列の大小の取り扱いに関して
// だった。
// dpの要素に文字列をとることとか初めてだった。

