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
    int from;
    int to;
    LL cost;
}Edge;

vector<Edge> G; // グラフ
vector<LL> D;   // 各ノードへの最短距離
int N;  // 頂点数

#define MINF -1000000000000000000

void Bellman_Ford(int a){   // a はスタート地点
    rep(i,N)D[i] = INF;
    D[a] = 0;   // 初期地点
    rep(i,N){   // N回繰り返すだけなので、indexは気にしない(頂点数)
        for(auto j : G){
            if(D[j.from] != INF && D[j.to] > D[j.from] + j.cost)D[j.to] = D[j.from] + j.cost;
        }
    }
}


// Bellman_Ford後に使用
void Nega_Search(){     // 負閉路を検知すると、その閉路に関わるノードのDを-INFに書き換える
    rep(i,N){
        for(auto j : G){
            if(D[j.to] != INF && D[j.to] > D[j.from] + j.cost)D[j.to] = MINF;
        }
    }
}


int main(){
    int M;cin >> N >> M;
    LL P;cin >> P;
    G.resize(N);
    D.resize(N);
    rep(i,M){
        int a,b;cin >> a >> b;
        LL c;cin >> c;
        a--;b--;
        G.push_back((Edge){a,b,P-c});
    }
    Bellman_Ford(0);
    Nega_Search();
    LL ans = max(-1*D[N-1],0LL);
    if(D[N-1] == MINF)cout << -1 << endl;
    else cout << ans << endl;
}

// ABC137 E - Coins Respawn

// 負閉路付きベルマンフォードを使うことで表現できる。
// 最後にコスト支払い済みの最短経路に-1をかけるのだが、この時に0未満の場合は0を出力することに注意（一敗）

