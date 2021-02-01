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

int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};

int main() {
    int N,M;cin >> N >> M;
    vector<string> b(N);
    rep(i,N)cin >> b[i];

    vector<vector<int>> ans(N,vector<int>(M,0));

    rep(i,N)rep(j,M){
        if(b[i][j] > 0){
            int p = i+1;
            int q = j;
            if(p == N || q == M)continue;
            int bt = b[i][j] - '0';
            ans[p][q] = bt;
            rep(i,4){
                int y = p+dy[i];
                int x = q+dx[i];
                if(y == N || x == M)continue;
                b[y][x] -= bt;
            }
        }
    }

    rep(i,N){
        rep(j,M){
            cout << ans[i][j];
        }
        cout << endl;
    }
}

// ARC041 B - アメーバ

/*
    解説AC
    解説読むだけ
*/