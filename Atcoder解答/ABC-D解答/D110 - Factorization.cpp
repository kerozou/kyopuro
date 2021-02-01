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

const int MAX = 2*1e5;     //  ここのサイズ選びめっちゃ注意。5*10^5とかにしてたら余裕でTLEこく。

LL fac[MAX], finv[MAX], inv[MAX];

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
LL COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// nHm
int count_9(int n, int m){
    // 範囲外アクセスに注意して下さい
    // 前処理
    COMinit();
    return COM(n+m-1,m);
}


map<LL,int> prime_factor(LL n){
  map<LL,int> ret;
  for(LL i = 2; i * i <= n; i++){
    while(n % i == 0){
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main(){
    LL N,M;cin >> N >> M;
    map<LL,int> ct = prime_factor(M);
    vector<LL> num;
    for(auto a : ct)num.push_back(a.S);
    LL ans = 1;
    for(auto a : num)ans = ans * count_9(N,a) % MOD;
    ans %= MOD;

    cout << ans << endl;
}


// ABC110 D - Factorization

// 自力AC

// 数列の各項の掛け算なので、とりあえずMを素因数分解する。
// すると、12 = 2^2 * 3^1 みたいになるので、  区別のない m(各項の指数)個の球　を　区別のある N個の箱から　無制限にとるときの場合の数の積が
// 求める場合の数になる。
// これは各場合について写像12相のcount_9を使えばよい。