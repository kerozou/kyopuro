#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;
const long long INF = 1LL<<40;

int main() {
    long long N, K; cin >> N >> K;
    vector<vector<long long> > s(N); // s[i] := 種類 i の美味しさの集合
    for (int i = 0; i < N; ++i) {
        long long t, d; cin >> t >> d; --t;
        s[t].push_back(d);
    }

    // 各種類について、美味しい順に並べる
    for (auto &v : s) {
        sort(v.begin(), v.end(), greater<long long>());
        if (v.empty()) v.push_back(-INF); // 番兵
    }

    // 「美味しさの最大値」の大きいネタ順
    sort(s.begin(), s.end(), [&](vector<long long> a, vector<long long> b) {
            return a[0] > b[0];});
 
    // まず K 種類選ぶ場合
    long long cur = 0;
    priority_queue<long long> que;
    for (int i = 0; i < K; ++i) {
        cur += s[i][0];
        for (int j = 1; j < s[i].size(); ++j) que.push(s[i][j]);
    }
    for (int i = K; i < N; ++i) for (int j = 0; j < s[i].size(); ++j) que.push(s[i][j]);

    // 走査
    long long res = cur + K*K;
    for (long long x = K-1; x >= 1; --x) {
        long long v = s[x][0];
        long long w = que.top();
        if (v < w) {
            que.pop(); cur += w;
            que.push(v); cur -= v;
        }
        res = max(res, cur + x*x);
    }
    cout << res << endl;
}


// ABC 116 D - Various Sushi

// けんちょんさんのコードまんま
// http://drken1215.hatenablog.com/entry/2019/05/15/002400

// この問題に関してはすごい時間かけたうえで、自分で実装した挙句間違えまくったので、学びの多い問題だった。

// ・二次元のベクトルの二つ目達をソートする方法にびびった（拡張for文）

// ・中身がからっぽなvectorをempty()で判定できるのも初めて知ったし、番兵として-INFを入れ解くことで　無　として扱えるようになるのすごい。
//   これによって、存在しないはずの種類目を扱えるようになり、最大値以上の数となってもK種類選ぶ時の挙動を描けるようになる。

// ・vectorの二次元目の先頭の要素の大小でvectorの1次元目のでかい箱を並べ替えるのやばい。
//   これを手で実装しようとして無限に終わってたので、ラムダ式によるソートの記法は覚えておくべき。

// ・考えた時は面倒そうに思えたけど、priority_queueを使った実装が思ったよりシンプルだった。
//   存在しないはずの種類を指定しているときは番兵により、答えが-INFになってることで成立しててすごいと思った。

// ・pop してcur+して push してcur-するの動きが見えやすくて良いと思った。


// ラムダ式の説明に関しては
// https://gintenlabo.hatenablog.com/entry/20130526/1369565989
// こことか見るとよさそう。

// [&]はローカル関数にアクセスできるようにするためのもの。
// a,bはsの1次元目のvectorを参照するってことだと思う。