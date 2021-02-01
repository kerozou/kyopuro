/*  PrimeFact
    init(N): 初期化。O(N log log N)
    get(n): クエリ。素因数分解を求める。O(log n)
 */
template <typename T>
struct PrimeFact {
    vector<T> spf;
    PrimeFact(T N) { init(N); }
    void init(T N) { // 前処理。spf を求める
        spf.assign(N + 1, 0);
        for (T i = 0; i <= N; i++) spf[i] = i;
        for (T i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (T j = i * i; j <= N; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
    map<T, T> get(T n) { // nの素因数分解を求める
        map<T, T> m;
        while (n != 1) {
            m[spf[n]]++;
            n /= spf[n];
        }
        return m;
    }
};

/*
  Smallest Prime Factor(SPF) の気持ち
  ２つ目のアルゴリズムでは、Smallest Prime Factor(SPF) と呼ばれるものを利用します。これは、各数に対する最小の素因数(SPF) のことです。

  SPF の前計算により O(1) で n の素因数 p を一つ取得することができます。

  これを利用すると、例えば 48 の素因数分解は以下のように求めることができます。

  https://algo-logic.info/prime-fact/
*/







以下はこれまで使ってたやつ。







// 素因数分解(Prime-Factor)
// 計算量　O(rootN) 

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


// 素因数分解の結果をmap<LL,int> で返す。
// ei1333 さんのコピー　https://ei1333.github.io/luzhiled/

// 実行時間	719 ms
// メモリ	1296 KB


// 20200110 追記
// 2数の公約数を求めるときは、素因数分解ではなく「2数の約数列挙」から「bineary_search」で数え上げる。

