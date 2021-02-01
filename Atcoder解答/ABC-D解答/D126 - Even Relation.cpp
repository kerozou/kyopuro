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
    int w;
}Edge;


int N;
vector<vector<Edge>> g;
vector<int> col;

void DFS(int v,int p,int c){
    col[v] = c;
    for(auto a : g[v]){
        if(a.to == p)continue;
        // 行先での処理
        if(a.w & 1) DFS(a.to,v,1-c);
        else DFS(a.to,v,c);
    }
    return;
}

int main(){
    cin >> N;
    g.resize(N,vector<Edge>());
    col.resize(N,0);
    rep(i,N-1){
        int u,v,w;
        cin >> u >> v >> w;
        --u;--v;
        g[u].push_back((Edge){v,w});
        g[v].push_back((Edge){u,w});
    }
    

    DFS(0,-1,1);

    for(auto k : col)cout << k << endl;
}

// ABC-D126 D - Even Relation

// 木のDFSの基本通りにつくればおｋ。
// けんちょんさんの記事をみながら実装確認
// http://drken1215.hatenablog.com/entry/2019/05/19/224500

// bool vectorは危ないのでなるべく作らないほうが無難。
// resize と assign は細かい挙動は違うけど基本同じような感じ。
// (Egde) を忘れないように。
// --u;--v;がcin の手前に入ってて無限にbad_allocしてた。
