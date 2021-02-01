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

typedef struct Edge{
    int to;
    int num;
} Edge;

vector<vector<Edge>> G;
vector<int> col;

void DFS(int v,int c=-1,int p=-1){
    int k = 1;
    rep(i,G[v].size()){
        int u = G[v][i].to;
        int id = G[v][i].num;
        if(u == p)continue;
        if(c == k)k++;
        col[id] = k;k++;
        DFS(u,col[id],v);
    }

    return;
}

int main(){
    // 入力
    int N;cin >> N;
    G.resize(N);
    col.resize(N);
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        G[a].push_back((Edge){b,i});
        G[b].push_back((Edge){a,i});
    }

    DFS(0);

    int ans = 0;
    rep(i,N){
        ans = max(ans,(int)G[i].size());
    }
    cout << ans << endl;
    rep(i,N-1)cout << col[i] << endl;
}

// 解説放送を見て作ったコード。
// 最初はDFS内の c をboolの二次元vectorで作ってたけど、実行時間もメモリ使用量もすごいことになったので、
// 解説放送みたいにDFSの時に重複判定するようにしたら、かなり軽くなった。
// 二次元でサイズが10^5*10^5とかを作るとやばい。
// あと、なるだけDFS内でのwhileは避けたほうがいい。
// というか、処理がえぐいことになる。

// ブログに書くときは提出欄からサルベージしよう。