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
    string S;cin >> S;
    int ans = 0;
    rep(i,N){
        if(i==0)if(S[0] == 'L')continue;
        if(i==N-1)if(S[N-1] == 'R')continue;
        if(S[i] == 'L')if(S[i-1] == 'L')ans++;
        if(S[i] == 'R')if(S[i+1] == 'R')ans++;
    }
    ans = min(ans + K*2,N-1);
    cout << ans << endl;
}

// ABC140 D - Face Produces Unhappiness
// N 人の最大幸福度は N-1 である。これは後述する。
// [l,r] で反転させたとき、その内部の文字が全部反転するので、区間内部の幸福な人数は変化しない。

// 例：LLRRLを反転させるとRLLRRになって同じ文字が隣り合う数は変わらない。

// つまり、一回の操作によって幸福度を上げたい場合、反転する区間に隣接する人同士の向きが揃うことが必要。

// 例：LLRLLRRL を 1-index で [6,7] で操作すると、LLRLL LL L となり、[6,7] の中身の幸福度は変化しないけど、
// その両脇の幸福度が1+1=2だけあがる。

// また、両端はそれぞれ左がL、右がRの時は必ず不幸になる。
// 理論上、最も幸福な人数が多いときは「すべての文字が同じ」時であり、この時のどちらか一方の端っこは不幸になる。
// なので、その場合の幸福度は N-1 となるのである。

// 最適な操作は、選んだ区間の中身は変化しない以上、連続する同じ文字の区間を選ぶことになる。
// このとき、一文字を選ぶこともできるので、LRLRL のようなときも、最小操作回数は2となる。
// 逆に、無限回操作可能な時も、LLLLLが完成した時点でMAXの更新はない。
// つまり、操作可能回数 K*2 に初期の幸福度 H を足したものと、N-1 のminをとればそれが答えになる。

