#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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

int H,W;
int ch,cw,dh,dw;
vector<vector<bool>> check;
queue<pair<int,int>> que_bfs;
queue<pair<int,int>> que_search;


// 操作A　隣り合ったマスを que_bfs に格納
void bfs(int num,int p,int q){
    queue<pair<int,int>> t_que;
    t_que.push({p,q});
    que_bfs.push({p,q});
    check[p][q] = true;
    while(!t_que.empty()){
        pair<int,int> tmp = t_que.front();
        t_que.pop();
        rep(i,4){
            int a = tmp.F + dy[i];
            int b = tmp.S + dx[i];
            if(a < 0 || H <= a || b < 0 || W <= b)continue;
            if(!check[a][b]){
                t_que.push({a,b});
                que_bfs.push({a,b});
                check[a][b] = true;
            }
        }
    }
}

// 操作B　sue_search に格納
void search(int p,int q){
    rep(i,5)rep(j,5){
        int a = p-2+i;
        int b = q-2+j;
        if(a < 0 || H <= a || b < 0 || W <= b)continue;
        if(!check[a][b]){
            check[a][b] = true;
            que_search.push({a,b});
        }
    }
}


int main() {
    cin >> H >> W;
    cin >> ch >> cw >> dh >> dw;
    ch--;cw--;dh--;dw--;

    vector<string> S(H);
    rep(i,H)cin >> S[i];
    check.resize(H,vector<bool>(W,false));
    rep(i,H)rep(j,W){
        if(S[i][j] == '#')check[i][j] = true;
    }

    int ans = -1;
    que_search.push({ch,cw});
    rep(i,3000000){

        // 操作A で隣り合ったマスを埋める
        while(!que_search.empty()){
            pair<int,int> tmp = que_search.front();
            que_search.pop();
            bfs(i,tmp.F,tmp.S);
        }

        // ゴールに到達してたら何週目かを返す
        if(check[dh][dw]){
            ans = i;
            break;
        }

        // 操作B でワープしていく
        while(!que_bfs.empty()){
            pair<int,int> tmp = que_bfs.front();
            que_bfs.pop();
            search(tmp.F,tmp.S);
        }

        // ゴールに到達してたら何週目かを返す
        if(check[dh][dw]){
            ans = i+1;
            break;
        }

    }
    
    cout << ans << endl;

}

// ABC176 D - Wizard in Maze