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


// DAGなので、トポロジカルソート後の入次数0の頂点から右に進んで、dp[i]:= 頂点iが終点としたときにの最長の長さ　とおけば、
// chmax(dp[nv],dp[v]+1) とすればいい。　(nvは頂点vから刺さる先の頂点)
// これを考えてみると、vからスタートすると、vは0、nvは１になって・・・・・・と更新が続いていく。
// 結局、入次数0 の頂点からスタートして、進むごとに辺を消去していくので入次数0の頂点を次々と始点としてループしていけば、いずれすべてのルートを通りつくす。
// このとき、一度通った流れはdpに記録されているので、その経路を別から通った時には大きくなるほうにchangeしていく。
// 例としては、 0→1→2→3→4 5→6   h[]は入り次数
//             ↓→→→→→↑ ↓→→→↑
// とあったら、０から始まって、dp[1] = 1 , dp[3] = 1, h[1] = 0 →　dp[2] = 2 h[2] = 0 → chmax(dp[3],dp[2]+1) で dp[3] = 1, dp[2]+1 = 3　なので dp[3] = 3に更新
//                          dp[4] = dp[3]+1 = 4 , dp[6] = dp[4]+1 = 5, chmax(dp[6],dp[5]+1) だけど、dp[5]+1 = 1 なので、dp[6] = 5 が採用。
// よって、dpは [1] = 1
//             [2] = 2
//             [3] = 3
//             [4] = 4
//             [5] = 1
//             [6] = 5
// となる。
// なので、repなり、max_elementなりすれば ans = 5 となる。
// つまり、上の矢印のDAGを作ったあとは、chmaxの回数は結局辺の数になっている。
// よって、トポロジカルソートはO(V+E)なので、全体での計算量は O(V+E+E)になっているような気がする。

// トポロジカルソートをしないと、
//             ↓←←←←←←←←←↑
// 例としては、 0→1→2→3→4 5→6   
//             ↓→→→→→↑ ↓→→→↑

// みたいに、後ろに戻っちゃうやつがでてきたら困るから？こうなると、DPを頭からやっていって答えが一意になる保証がなくなる。
// 仮に上の例だと、トポロジカルソートすると、
//             ↑→→→→→→→→→→→↓
//             5→0→1→2→3→4→6
//               ↓→→→→→↑
// みたいになって確かに、DPしていける感じになる。


int main(){
    int N,M;cin >> N >> M;
    vector<vector<int>> G(N,vector<int>());           // ここをvector<int> G(N+1) にしたら alloc関連のバグが出た。これって、あらかじめ二次元配列ですって宣言しておくと回避できたってこと？
    vector<int> h(N);

    //グラフ化と入次数
    rep(i,M){
        int a,b;cin >> a >> b;
        a--; b--;   //0-index化
        G[a].push_back(b);
        h[b]++;
    }

    //入0のキュー           // スタックで作ったらWAでまくった。しかし、スタックでも80行目のchmaxをifの外に出してあげると通過した。　※2
    queue<int> zero;

    //zero作成
    rep(i,N)if(h[i] == 0)zero.push(i);

    // BFS
    vector<int> dp(N);
    while(zero.size()){
        int v = zero.front();zero.pop();
        for(auto nv : G[v]){
            h[nv]--; // 辺を破壊する
            if(h[nv] == 0){
                zero.push(nv);  //  入次数0になったのでスタックにつっこむ
                chmax(dp[nv],dp[v]+1);  // この時、トポロジカルソートは頂点nvの周りでは完了していると考えられるので、同時並行でDPテーブルを作っちゃう。 ※1
            }
        }
    }

    int res = 0;
    rep(i,N)chmax(res,dp[i]);
    cout << res << endl;

}

// push_back() した時の alloc バグの原因がここにきて2か月ぶりくらいにやっと解明された感ある。
// ※1,2　スタックの場合はpushされた頂点がぐちゃぐちゃに入っていって、出てくる順番もめちゃめちゃになってるので、入次数が0になった時だけのchmaxじゃだめっぽい。
// 逆にキューで実装すると、基本的にdpが小さい値から順に入っていくから、nvが入次数0になった最後のタイミングでchmaxすれば最大化されるということらしい。
// 例えば上に乗せた 5 0 1 2 3 4 6 のパターンだと、初めのforで　5→0　と　5→6　が破壊されるのだが、0の方はすぐに入次数0になるけど、6の方は4からのルートが残っているのでスタックされない。
// この時、dp[6]=1 の更新が行われなくなってしまう。これが大きい値になればなるほど、まずくなって、スタックで実装するとFILOなので、埋まったまんま謎のタイミングで謎の更新が発生するリスクがある。
// このへんは詳しくイメージできないけど、キューの場合を考えることで解決を試みる。
// キューだと、FIFOなので、dp[6]は最後にキューに入って、4からたどるときにキューに入る。そんで、そこでchmaxが発生するので、この時はdp[6]の値は最後の一回のmax比較で済んでも大丈夫ということ。


// 結局うまく理解できないので、質問コーナーを参照したところ、
// キューは最長距離が短い順に入っていくので、最後に一回chmaxするだけでも問題ないということだった。
// スタックで毎回更新しないとやばい例を下に記す。
//  
//             ↑→→→→→→→→→→→→→→→→→→→→→↓
//             5→0→1→2  7→10→9→8→3→4→6
//               ↓→→→→→→→→→→→→→→→↑

// みたいなときに、仮に7スタートで行ったとしたとき、dp[8]=3 なのに、dp[3]は0からルートがあるので、入次数0 にならずchmaxが挟まらないことに。
// このとき、後からやってきた503のルートだと、dp[3] = 2　になって最大ルートの大きさは4になっておかしい。ということ。

