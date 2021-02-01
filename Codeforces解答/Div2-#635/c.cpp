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
vector<int> euler;
vector<int> beg;
vector<int> en;
int ct_e = 0;

vector<int> roo;

void dfs_root(int v,int p,int ct){
    roo[v] = ct;
    for(auto nv : G[v]){
        if(nv == p)continue;
        dfs_root(nv,v,ct+1);
    }
}

void dfs_Euler(int v,int p){
    beg[v] = ct_e;
    euler.push_back(v);
    ct_e++;
    for(auto nv : G[v]){
        if(nv == p)continue;
        dfs_Euler(nv,v);
        euler.push_back(v);
        ct_e++;
    }
    en[v] = ct_e;
}

int main() {
    int n,k;cin >> n >> k;
    G.resize(n);
    beg.resize(n);
    en.resize(n);
    roo.resize(n);
    rep(i,n-1){
        int a,b;cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs_root(0,-1,0);
    dfs_Euler(0,-1);
    vector<int> ans;
    rep(i,n){
        int tmp = (en[i] - beg[i])/2 - roo[i]; 
        ans.push_back(tmp);
    }
    sort(rall(ans));
    LL res = 0;
    rep(i,n-k)res += ans[i];

    cout << res << endl;

    
}