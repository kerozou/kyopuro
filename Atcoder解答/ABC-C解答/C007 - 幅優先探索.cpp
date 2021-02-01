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

vector<vector<int>> dp;
int R,C;
int sx,sy;
int gx,gy;
queue<pair<int,int>> q; 
vector<string> c;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void bfs(){
    pair<int,int> t = q.front();
    q.pop();
    int a = t.F;
    int b = t.S;
    if(a == gx && b == gy)return;
    rep(i,4){
        if(a+dy[i] <= 0 || a+dy[i] >= R-1 || b+dx[i] <= 0 || b+dx[i] >= C-1)continue;
        if(c[a+dy[i]][b+dx[i]] == '#')continue;
        if(dp[a][b]+1 < dp[a+dy[i]][b+dx[i]]){              // ここをdp[a][b]にしてたらMLEした。
            dp[a+dy[i]][b+dx[i]] = dp[a][b] + 1;
            q.push({a+dy[i],b+dx[i]});
        }
    }
    bfs();
    return;
}

int main() {
    cin >> R >> C;
    cin >> sx >> sy;
    cin >> gx >> gy;
    sx--;sy--;gx--;gy--;
    dp.resize(R,vector<int>(C,10000));
    dp[sx][sy] = 0;
    q.push({sx,sy});
    c.resize(R);rep(i,R)cin >> c[i];
    bfs();

    cout << dp[gx][gy] << endl;


}

// C007 - 幅優先探索

/*
    幅優先探索するだけ
    ただ、バグに注意。
    あと、indexがずれることに注意。
*/