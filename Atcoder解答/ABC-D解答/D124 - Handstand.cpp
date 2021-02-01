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

int main() {
    int N, K; cin >> N >> K;
    string S; cin >> S;

    // 「1 の個数」「0 の個数」を交互に記録していく
    vector<int> nums;    
    if (S[0] == '0') nums.push_back(0); // 先頭が 0 だったら
    for (int i = 0; i < S.size();) {
        int j = i;
        while (j < S.size() && S[j] == S[i]) ++j; // S[i] の数値がどこまで続くか
        nums.push_back(j - i);
        i = j;
    }
    if (S.back() == '0') nums.push_back(0); // 最後尾が 0 だったら

    // 累積和
    vector<int> sums((int)nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); ++i) sums[i+1] = sums[i] + nums[i];

    // 偶数番目の添字から始まる、長さ 2K+1 (以下) の区間の総和のうち、最大値を求める
    int res = 0;
    for (int left = 0; left < sums.size(); left += 2) {
        int right = left + K*2+1;
        if (right >= sums.size()) right = (int)sums.size() - 1;
        res = max(res, sums[right] - sums[left]);
    }
    cout << res << endl;
}

// ABC-D124 D-Handstand

// 一列に並ぶ人の区間は、区間同士が被るとき、2回ひっくり返り、元に戻ることになる。
// なので、区間被りが発生するときは、区間被りがいずれかの場合と一致することになる。
// よって、区間は被らないものとして考察を進めても構わない。

// 次に、0の塊、1の塊というように並んでいる人をグループにしていくことを考える。
// すると、先ほどの議論からいくと、1と1の隙間にある0を反転させていくことが最適な行動になるはず。
// このとき、1が連続する区間を最大にしたいので、0の塊群は隣り合ったものを選択していくのが最適な行動のはず。
// つまり、この問題は
// 「1の塊、0の塊の内部の要素の個数を並べた数列 A0,A1,A2,...,An の部分列の要素の和が最大となるものを 要素数2K-1から探り当てる問題」
// になる。

// 用意した数列の両端の塊が1によるものでないとき、その部分にある0を反転する処理を場合分けするのは面倒なので、
// あらかじめ両端が0のときは 「1の個数が0個のかたまり 0 」を設置する
// これで、0,2,4,...と偶数個目の塊は1のもの、1,3,5....と奇数個目の塊は0のものというように分類がすんだ。

// 実装するにあたっては、部分列をとっていくだけなので、累積和または尺取り法でO(N)で実装可能。
// けんちょんさんの記事では累積和でやってるので、今回はしゃくとりの練習もかねてしゃくとる。

// この問題に関しては尺取り法でやるメリットがないので、普通に累積和でやる。


// 自分で実装したらバグり散らかしたのでけんちょんさんのコードでAC。
// http://drken1215.hatenablog.com/entry/2019/04/14/222900

// 今回の学びは
// ・問題を読み下して、条件が不変な状態で簡単な問題へと切り替えていく手法
// ・実装がややこしい問題は、実装をシンプルに一方向へ進むように作ること。
// こういう問題に弱すぎる。

