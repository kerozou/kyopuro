// mod 100,000,007 とかの話

// 1. なぜ 1000000007 で割るのか？
// A. 桁漏れを防いだり、言語間での条件を統一するため。
        また、100000007は10^9以上で最小の素数であるため都合がいい。　→　逆元の話につながる

// MODの計算について
     基本的に　和差積　で閉じている合同式であるが、競プロの場合　差　には注意がいる。
     和・積　は計算途中でMODをとっても結果は変わらないが（というか積に関しては毎計算ごとにとるべき）
     差　の場合は計算途中であまりをとってもいいことには変わりないのだが、最終結果が負の場合に10^9+7を足す必要がある。

// 割り算について
     割り算が登場してくると、純粋に多倍長整数で計算後に余りを出すしかないかといわれるとそうでもない。
     割り算には「逆元」を使うことで対応できる。

// フェルマーの小定理　と　逆元
    p を　素数とし、b を p で割り切れない整数とする。このとき a を整数として
            b*x　≡　a　(mod p)
    を満たすようなxはmodpにおいて一意に存在する。

    これを使うと、12345678900000÷100000=123456789　を 12345678900000  を 1000000007 で割ったあまり (678813585 になります) を出してから計算することができる。

    以上を踏まえて元の問題に戻ると、

        678813585÷100000(mod1000000007)
    はちゃんと一意に特定できます。答えは 123456789 です。実際

        100000×123456789≡678813585(mod1000000007)
    が成立しています。

    「a÷b(modp)」を計算する方法を考えます。実は少し考えてみると

        1÷b(modp)
    だけ計算できればいいことがわかります。なぜなら、

        a÷b≡a×(1÷b)(modp)
    が成り立つからです。つまり 1÷b さえ求めることができれば、これを a 倍すればよいです。このような 1÷b を「modp における b の逆元」と呼びます。これは

    b をかけると 1 になる数 (modp の意味で)
    でもあります。例えば mod13 において 2 の逆元は 7 です。b の逆元はしばしば b−1 という風に表記します。まとめると、

        a÷b≡a×b^(−1)(modp)
    です。

// 以下にライブラリと使用例(逆元は　拡張ユークリッド　を使っている)　拡張ユークリッドなので、法mは素数でなくてもよい。

// mod. m での a の逆元 a^{-1} を計算する　　
LL modinv(LL a, LL m) {
    LL b = m, u = 1, v = 0;
    while (b) {
        LL t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// a ÷ b mod. MOD を計算してみる
int main() {
    const int MOD = 1000000007;

    LL a = 12345678900000;
    LL b = 100000;

    // a を 10000000007 で割ってから b の逆元をかけて計算
    a %= MOD;
    cout << a * modinv(b, MOD) % MOD << endl;
}


// 計算ミスで死んでるので、基本modint使っとこう　

以下modint
// modint は　https://ei1333.github.io/luzhiled/snippets/math/mod-int.html　そのまま
// 下はmodint 導入　modint で宣言。あとは普通に計算すればいい。 ++,--は未定義

// 加減乗　算O(1)
// 除算　O(logN)　（Modは素数）

const int mod = MOD;
template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< mod >;