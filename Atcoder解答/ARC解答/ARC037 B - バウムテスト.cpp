#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

vector<vector<int>> G;
vector<bool> ok;
bool ch;

void dfs(int v,int p){
    if(p == -1){
        ok[v] = true;
    }
    for(auto nv : G[v]){
        if(nv == p)continue;
        if(ok[nv]){
            ch = false;
            return;
        }
        ok[nv] = true;
        dfs(nv,v);
    }
}


int main() {
    int N,M;cin >> N >> M;
    G.resize(N);
    ok.resize(N,false);
    

    rep(i,M){
        int a,b;cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;

    rep(i,N){
        ch = true;
        dfs(i,-1);
        if(ch)ans++;
    }

    cout << ans << endl;
}

// ARC037 B - バウムテスト

/*
    木のDFSをN回やればいいので、計算量はO(N^2)で間に合う。
    また、最大深度が2となる木を検出したときに重複カウントしてしまうので、根っこもbool配列をtrueにする点に注意。
*/