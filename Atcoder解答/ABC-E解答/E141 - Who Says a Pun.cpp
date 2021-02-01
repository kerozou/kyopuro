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

vector<int> Zalgo(const string &S) {
    int N = (int)S.size();
    vector<int> res(N);
    res[0] = N;
    int i = 1, j = 0;
    while (i < N) {
        while (i+j < N && S[j] == S[i+j]) ++j;
        res[i] = j;
        if (j == 0) {++i; continue;}
        int k = 1;
        while (i+k < N && k+res[k] < j) res[i+k] = res[k], ++k;
        i += k, j -= k;
    }
    return res;
}

// Z-algorithm
// Zalgoでは、Sの部分文字列の被りを調べる。
// 上のコードを解説すると、
//  1,頭から順に調べ
//  2,連続部分がでてきたら、その連続部分の個数を検出して再利用する。
// 例えば、abcdabcd があったとしたら、　abcd    abcd   とi=4の時二つになる。
// この時、i=5 は　S[5]='b'　と S[0]='a' を比べ始めるわけだが、前のabcd と 後ろのabcd は一致しているので、S[5]以降とS[4]以降を比べても問題ないはず。
// また、この考え方で行くと、S[5]以降とS[4]以降の一致個数は、S[1]以降とS[0]以降の一致個数に等しくなるはず。
// ということは、a->b ^ b->c なら a->c 的な考え方で、S[5]以降のS[0]以降との一致個数は、S[1]以降のS[0]以降との一致個数に等しくなる。
// これは、res[5] = res[1] に他ならない。
// 一般化すると、res[i+k] = res[k] になるということ。
// j回までなのは、そもそも初めの一致個数をオーバーしてしまったら、前のabcd と 後ろのabcd が一致するという前提がなくなるからダメということ。
// 終わりの+=と-=はiを進めるのと、jを0に戻すため。
// 以上の動きによってどのルートを進んでも一回ごとにi++されるのでO(N)でlcp[]が求まる。

int main() { 
    int N;
    string S;
    cin >> N >> S;

    int res = 0;
    for (int i = 0; i < N; ++i) {
        string T = S.substr(i);
        auto lcp = Zalgo(T);

        for (int j = 0; j < T.size(); ++j) {
            int l = min(lcp[j], j);     //この問題では部分文字列の重複（重なり）を許していないので、各先頭文字列のindexより大きい長さはありえないので、カットしている。
            res = max(res, l);
        }
    }
        
    cout << res << endl;
}

// Z-algorithmはSの0文字目からとi文字目からしか比較できないので、Tをi文字目から始まる部分文字列としてj文字目と比較していく。
// あとは各番号から始まる文字列ごとにZ-algorithmを適用していき、重なりを排除して最大値を更新していく。この動作でO(N^2)となる。

// けんちょんさんのコードまんま