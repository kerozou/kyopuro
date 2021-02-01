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
int N,K;
vector<vector<int>> T;
bool bug;
void dfs(int n,int x=-1){
    if(n == N-1){
        rep(i,K){
            int ans;
            if(x == -1)ans = T[n][i];
            else ans = x ^ T[n][i];
            if(ans == 0)bug = true;
        }
        return;
    }

    int ans;
    rep(i,K){
        if(x == -1)ans = T[n][i];
        else ans = x ^ T[n][i];
        dfs(n+1,ans);
    }
}

int main() {
    cin >> N >> K;
    T.resize(N,vector<int>(K));
    rep(i,N)rep(j,K)cin >> T[i][j];

    dfs(0);
    if(bug)cout << "Found" << endl;
    else cout << "Nothing" << endl;

}

// ABC015 C - 高橋くんのバグ探し

/*
    全部で5^5通りなので、全探索する。
    DFSでやったけど、それすらもいらないかもしらん。
*/