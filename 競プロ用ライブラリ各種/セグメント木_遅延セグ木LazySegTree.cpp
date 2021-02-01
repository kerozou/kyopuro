// LazySegTree
// ACL の遅延セグ木の前準備として必要な者たち
// 以下のサイトを参考
// https://opt-cp.com/cp/lazysegtree-aclpc-k/


/*
    遅延セグ木は S[l,r) の定義の仕方と、全部で5つに分かれる条件をクリアする関数の設定の仕方が重要。
    上のサイトで説明されているので、その辺をよく理解して使うこと。
*/


// コンストラクタ
lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);
lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<T> v);


// モノイド S
struct S {
    mint sum,len;
}


// 演算の関数 op (S × S → S)
S op(S sl,S sr){
    return {sl.sum + sr.sum , sl.len + sr.len};
    // この例だとSで定義したsumとlenの和を返してる
    // Sが一つしか変数を持たないときは一つ返せばいい
}


// 単位元 e
S e(){
    return {0,0};
    // 単位元を返す
}


// 写像の型 F
struct F {
    mint b,c;
    // クエリで与えられる定数など 
    // この場合は 配列 a[i] にたいする a[i]*b + c の b と c
    // つまり、 写像の集合Fが持つ写像達は　b[x] = b*x と c[x] = x + c ということ。
}


// f(x)を返す関数 mapping
S mapping(F f,S s){
    return {f.b * s.sum + f.c * s.len , s.len};
    // 更新クエリによる式を書けばいい
    // 今回の式は b*sum[ai] + c*区間長 , 区間長　を返してる。
}

// f●g を返す関数 composition
F composition(F f,F g){
    return {f.b * g.b , f.b * g.c + f.c};
    // クエリ適用順は代数と同じで　g , f の順に注意 かくときは f, g の順
    // bfg := bf*bg , cfg := bf*cg + cf ということ
    // これは自分で手計算して確認する
}

// 恒等写像 id
F id(){
    return {1,0};
    // 区間長は0になる
}



/*
何もしない更新クエリ id が {1,0} のようにきれいに書けない場合は，
INF などの「ありえない値」が id に対応する，と自分で勝手に決めてしまい，
関数 mapping, composition 内ではクエリを表す変数が「ありえない値」かどうかで場合分けをすれば上手くいきます．
*/



// 貼り付け用

// コンストラクタ
lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);
lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<T> v);



struct S {

};

S op(S sl,S sr){
    return ;
}

S e(){
    return ;
}

struct F {

};

S mapping(F f,S s){
    return ;
}

F composition(F f,F g){
    return ;

}

F id(){
    return ;
}





////////////////////////////////////////////////////////////////////////
外部サイトに張るときに必要な奴
上にある atcoder や mint 類を消してから貼る
////////////////////////////////////////////////////////////////////////


namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

using namespace atcoder;

///////////////////////// ここまでAtCoder Library /////////////////////////

