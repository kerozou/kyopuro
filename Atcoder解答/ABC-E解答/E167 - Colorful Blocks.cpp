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

template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

const int MAX = 200002;
const int MOD = 998244353;
 ;
LL N,M,K;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

LL modPow(LL x, LL y){
    LL r = 1, a = x % MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}


LL calc(LL a){
    LL res = COM(N-1,a);
    res *= M;
    res %= MOD;
    LL tmp = modPow(M-1,N-1-a);
    res = (res * tmp) % MOD;
    return res;
}


int main() {
    cin >> N >> M >> K;
    LL ans = 0;

    COMinit();
    rep(i,K+1){
        ans += calc(i);
    }

    ans %= MOD;

    cout << ans << endl;

}

// ABC E167 - Colorful Blocks

/*
    ブロックの隙間はN-1箇所あり、この隣り合う隙間がについて考える。
    というのも、同じ色で塗られたブロックは長い一つの塊としてとらえられるからである。
    つまり、同じ色で連なるブロックの塊がK個以下になるときをすべて拾いあげればよいということになる。

    この時、無色のブロックの塊を錬成し、そのグループに色を塗っていくと考える。
    すると、ひとつの集合に対して色の対称性から n-1Ck 通りの色の選び方が存在することが分かる。
    なので、塊に左から順に色を塗っていくと、M*(M-1)^(N-1-k)通りの塗り方がある。
    後は、これに組み合わせのn-1Ck をかけて k=0~K まで加えあげればよい。

    この問題のポイントは「同色で隣り合うブロック」を「連結して考える」ところにある。
    具体的には、ブロック同士の関係を「接している境界」で考え直すというところにテクニックを感じる。
    境界はN-1個あり、そこからk個の隙間を選ぶと連結されたブロックの塊はk+1個になる。
    これが重要な置き換えだと感じた。
    この置き換えが出来れば後は「ブロックを塗る」問題に帰着できる。
*/
