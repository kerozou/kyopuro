#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define pint pair<int, int>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

// dxdyは 0右 1下 2左 3上
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,-1,0,1};

int main(){
    int H,W;cin >> H >> W;
    vector<vector<int>> maze(H+2,vector<int>(W+2,-1));     // -1 は未到達、0は壁
    int wall = 0;
    rep(i,H)rep(j,W){
        char t = '-';
        cin >> t;
        if(t == '#'){
            wall++;
            maze[i+1][j+1] = 0;
        }
    }

    maze[1][1] = 1;
    queue<pair<int,int>> q;
    q.push(pint(1,1));
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        int x = now.S;
        int y = now.F;
            rep(i,4){   // xyは行列表記
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ny <= 0 || ny >= H+1 || nx <= 0 || nx >= W+1)continue;
            if(maze[ny][nx] == -1){
                maze[ny][nx] = maze[y][x] + 1;
                q.push(pint(ny,nx));
            }
        }
    }
 


    int ans = 0;
    ans = H*W - wall - maze[H][W];
    if(maze[H][W] == -1)cout << -1 << endl;
    else cout << ans << endl;
}

// ABC088 D - Grid Repainting

// 方針はあってたけど、肝心のBFSの描き方がわかってなかったので、調べた。
// BFSはqueueで描くってことを覚えておけば思い出せそう。
// https://pyteyon.hatenablog.com/entry/2019/03/01/211133

// あと、x,yの添え字は行列とかにしないで、s,tとかっておいて辞書順に並べておいたほうが幸せになれる。
// 添え字の順序めちゃくちゃになって爆死した。

