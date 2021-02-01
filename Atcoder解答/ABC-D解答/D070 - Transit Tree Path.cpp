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
    LL w;
}Edge;

vector<vector<Edge>> G;
vector<LL> d;

void DFS(int v,int p = -1,LL nd = 0){   // nd = 現在地までの根からの距離 を更新していく
    for(auto nv : G[v]){
        int a = nv.to;
        LL b = nv.w;
        if(a == p)continue;
        d[a] = nd + b;
        DFS(a,v,nd + b);
    }
}

int main(){
    int N;cin >> N;

    d.resize(N,0);
    G.resize(N,vector<Edge>());
    rep(i,N-1){
        int a,b;
        LL c;cin >> a >> b >> c;
        a--;b--;
        G[a].push_back((Edge){b,c});
        G[b].push_back((Edge){a,c});
    }

    int Q,K;cin >> Q >> K;
    vector<int> x(Q);
    vector<int> y(Q);
    rep(i,Q){
        int a,b;cin >> a >> b;
        a--;b--;
        x[i] = a;
        y[i] = b;
    }

    DFS(K-1);
    rep(i,Q){
        cout << d[x[i]] + d[y[i]] << endl;
    }

}

// ABC070 	D - Transit Tree Path

// 木のDFS　自力AC
// 指定された点Kを根として、根からの距離を各点に確保したい。
// これは木のDFSで書くことができる。

// 木のDFSのイメージは
// ・根から順に深く掘っていく
// ということであり、（DFSの基本的な考え方だが）ある地点を調べているときはその地点の深さが最大になっている。
// 根からの距離は累積和的に　直前の親の根からの距離　＋　辺の重さ　で表現できるので
// この事実とDFSの特徴的に考えて、木のDFSをかますことで各点の根からの距離はすべて奇麗に求まる。

// あとは、求まった距離をそれぞれ足し上げていくので各クエリはO(1)で消化できる。
// DFSは木の構造的に同じ点を二回以上調べることはなく、O(N)程度ででできるはず。