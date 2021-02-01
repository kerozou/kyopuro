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

LL calc(LL a){
    LL tmp = a/4 * 4;
    LL ans = 0;
    for(LL b = tmp;b <= a;++b)ans ^= b;
    return ans;
}

int main(){
    LL A,B;cin >> A >> B;
    LL res = 0;
    if(A != 0)res = calc(B) ^ calc(A-1);
    else res = calc(B);
    cout << res << endl;
}


// ABC-D121 D - XOR World

// XORの性質さえ知っていれば秒殺っぽい。
// kerozouは知らなかったので、解説を見ました。
// アルメリアさんの記事とけんちょんさんの記事を参照
// https://betrue12.hateblo.jp/entry/2019/03/09/224330
// http://drken1215.hatenablog.com/entry/2019/03/09/224100

// この問題で学ぶべきXORの性質とは、
// ・A以上B以下のXOR和は　B以下のXOR和 ^ A-1以下のXOR和　になるということ。
// これに関してはXORの計算ルールを考えると、
//      a ^ b の各bitが異なるとき1,同じなら0を与える
// というルールだった。

// この時　a ^ x = b となる x が何か考えると　a^a = 0になること、0^x = x であることから　a^a^x = a^b  , x = a^b となることがわかる。
// つまり、0~Nまでxorをとるとして、 0^1^2^3^...^n = x のとき、3~Nのxorは 3^4^...^n = 0^1^2^x となることが上の議論からわかる。

// これより、B以下のxor　に　A以下のxorを xor すると　A+1 ~ B のxorが得られるということ。
// 整理すると [A,B] のxor　は　Bxor ^ A-1xor で与えられるということ。
