// BIT

/*
Fenwick Tree とも呼ばれる。
数列に対し, ある要素に値を加える操作と, 区間和を求める操作をそれぞれ対数時間で行うことが出来るデータ構造。
セグメント木や平衡二分探索木の機能を制限したものであるが, 実装が非常に単純で定数倍も軽いなどの利点がある。
*/

//ei1333 の人のそのまま https://ei1333.github.io/luzhiled/snippets/structure/binary-indexed-tree.html

// クエリ　O(logN)


// BinaryIndexedTree(sz):長さszで初期化する。
// sum(k):区間[0,k]の合計を求める（閉区間）
// add(k,x):要素kに値xを加える。

// BIT がおいしいのは累積和の更新ができる点だと思う。
// 累積和だと一度作った後に各要素に足したり引いたりするときに一つの要素をいじるだけでO(N)の時間がかかる。
// しかし、BITではその操作が1クエリ当たりO(logN)でできる。
// 例えばN個の要素に数字を足していくとき、累積和だとO(N^2)となるところをBITではO(NlogN)で更新できることになる。
// つまり、要素数N=10^5とかにたいして区間の増減が可能になるというところが利点。
// ただ、これだと更新回数がN回とかになると、結局O(N^2*logN)とかになって無意味なので、
// 区間更新1クエリがO(logN)になる必要がある。

// 1-index になることに注意！！！

template< typename T >
struct BIT {
  vector< T > data;

  BIT(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};


// 基本的な使い方
// この時、あらかじめ使う入力で得たベクトルなんかはindex+1しておいて 1-indexed にしといたほうが楽。

BIT<LL> q(N+1); // で宣言　vecter的な感覚
q.add(a,w);
q.add(b+1,-w);

// ランダムアクセス
//q.sum(x) でBIT配列のx番目の計算結果を取得でき、それを元の計算付与前の配列の要素に足し合わせて取得する。

LL ans = v[x] + q.sum(x);

// 区間更新後の区間和 (これもBIT上なので、O(logN）)
    // [0,c]　の和が欲しい。
LL tmp1 = p.sum(c);
LL tmp2 = q.sum(c);
LL ans = tmp1 + tmp2*c;

//////////////////ここから下は

// 区間に対する更新、更新後のランダムアクセス、更新後の区間の和について

// 1-index になることに注意！！！

BITを二つほど用意して、
    p:[a,b]にwを足したとき、p[a] += -w*a; p[b+1] += w*(b+1);
    q:[a,b]にwを足したとき、q[a] += w; q[b+1] += -w;
とする処理を描く。 

・区間更新
BIT<LL> p(N+1); //最後の部分のため＋１
BIT<LL> q(N+1);
vector<LL> v(N);  //入力用
    // [a,b] に w を足す
p.add(a,w*a);
p.add(b+1,-w*(b+1));
q.add(a,w);
q.add(b+1,-w);

・区間更新後のランダムアクセス (sum は BIT 上なので、O(logN))
    // v[x]が欲しい
LL tmp = q.sum(x);
LL ans = v[x] + tmp;

・区間更新後の区間和 (これもBIT上なので、O(logN）)
    // [0,c]　の和が欲しい。
LL tmp1 = p.sum(c);
LL tmp2 = q.sum(c);
LL ans = tmp1 + tmp2*c;


区間更新の概念は　http://hos.ac/slides/20140319_bit.pdf　を参考にした。
区間和については、[a,b] と　c の位置関係を場合分けして実際に試してみるとよくわかる。

// 1-index 
// C035 - オセロ で区間更新とランダムアクセスしよう。