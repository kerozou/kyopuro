#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    int N;cin >> N;
    vector<LL> X(N);
    rep(i,N)cin >> X[i];

    X.push_back(INF);   //  末尾にINFを足して奇数個にする。
    auto stock = X;     //  sort するために保存しておく。
    vector<LL> B(N);    //  答えの配列

    sort(all(X));       //  共通のmedian を取得するためにソート
    LL med = X[N/2];    //  共通のmedian を取得
    rep(i,N){
        if(stock[i] == med){
            B[i] = X[N/2 -1];
        }
        else if(stock[i] < med){
            B[i] = X[N/2];
        }
        else{ //stock[i] > med
            B[i] = X[N/2 -1];
        }
    }
    rep(i,N)cout << B[i] << endl;
}

// ABC094 C-Many Medians
// ・偶数個の　int　から1つ抜いて、残りの中央値を得る。(LLでもおｋ)

// これは、中央値の性質から考えると、中央値を選ぶ際は配列が　奇数　個の要素を持っていることが望ましい。
// つまり、偶数個の要素を持つ配列から　Ai　だけ抜き出すと　奇数個　から中央値を選べるようになる。
// しかし、これを実行した場合、ソートだったりindexのタグ付けがすごい面倒。
// 例えば、上でやってるように　中央値とAiの位置関係　をめちゃくちゃ細かく整理しつつ、バグが出ないようにindexに細心の注意を払う必要がでてきそう。

// なので、Aiが抜けることで順番が変わってしまうなら、いっそAiは残したまま配列の末尾に　INF　を付け足して　奇数個　要素の配列を作ることを考える。
// こうしたとき、INFは配列内の最大値であることは確定なので、結果として中央値は一つ左にずれることになる。
// さらに、計算後にAiを抜き取るので、Aiが中央値の左右どちらかに存在するかによって、最終的な中央値のindexは一つずれることになる。

// 1. Ai == median のとき
//      N == 11　とすると　Ai　のiは i==6 となり、　（　5個、Ai、4個、INF　）という並びになる。
//      これより、最終的な中央値はAi,INFを抜き去った時、左から5個目、0indexで i == 4 となる。
//      つまり、i == N/2 -1 となる。（iはXのindex）

// 2. Ai < median のとき
//      1と同様に N == 11, Ai i == 3　としてみると、　（　2個、Ai、7個、INF　）という並びになる。
//      これより、AiとINFを抜き取ると、medはひとつ左にずれる。ゆえに、i == 6 だったmedは　i == 5 となる。これを0indexにすると、i == 6 である。
//      つまり、i == N/2 のままでいい。（iはXのindex）

// 3. Ai < med のとき
//      1,2と同様にして　i == N/2 -1 