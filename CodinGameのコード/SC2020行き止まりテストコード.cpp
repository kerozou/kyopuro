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
    int height;
    int width;    
    int dp[4] = {0,-1,0,1};
    int dq[4] = {-1,0,1,0};

    int ep[8] = {-1,-1,-1,0,1,1,1,0};
    int eq[8] = {-1,0,1,1,1,0,-1,-1};
    vector<string> fie; // マップ情報
    vector<pair<int,int>> mp;   // 歩行可能マス
    vector<bool> p_received(10,false);  // パックマンが指示を貰っているか true で貰ってる
    vector<pair<int,int>> p_destination(10,{-1,-1});    // パックマンの目的地
    vector<vector<bool>> peret_my_checked(100,vector<bool>(100,true));  // 見たペレットの情報
    pair<int,int> nex;  //  dfsで見つけた座標を返すときの変数
    vector<queue<pair<int,int>>> dfs_queue(10);
    vector<vector<bool>> rock_area; // 行き止まりエリア


void rock_dfs(pair<int,int> pos,pair<int,int> pre,int n){
    // 行き止まりから始めて行動不能エリアを増やしていく。三叉路に出たら終了。
    if(n == 4)return;
    int ct = 0;
    pair<int,int> next;
    rep(i,4){
        int ny = pos.F + dp[i];
        int nx = pos.S + dq[i];
        if(ny < 0 || height <= ny || nx < 0 || width <= nx)continue;
        if(fie[ny][nx] == '#')ct++;
        else{
            if(ny == pre.F && nx == pre.S)continue;
            next = {ny,nx};
        }
    }
    if(ct >= 2){
        rock_area[pos.F][pos.S] = true;
        rock_dfs(next,pos,n+1);
    }
}


int main() {

    cin >> width >> height; cin.ignore();
    fie.resize(height);         // マップ情報
    rock_area.resize(height,vector<bool>(width,false)); // 行き止まり付近
    vector<pair<int,int>> rock_st;  // 行き止まりの保管

    
    // マップの入力
    for (int i = 0; i < height; i++) {
        string row;
        getline(cin, row); // one line of the grid: space " " is floor, pound "#" is wall
        fie[i] = row;
    }

    rep(i,height)rep(j,width)if(fie[i][j] == '#')rock_area[i][j] = true;    // 壁判定 

    rep(i,height)rep(j,width){
        if(fie[i][j] == ' '){
            int ct = 0;
            rep(k,4){
                int ny = i + dp[k];
                int nx = j + dq[k];
                if(ny < 0 || height <= ny || nx < 0 || width <= nx)continue;
                if(fie[ny][nx] == '#')ct++;
            }
            if(ct == 3)rock_st.push_back({i,j});
        }
    }

    int sz_r = rock_st.size();
    rep(i,sz_r){
        rock_dfs(rock_st[i],rock_st[i],0);
    }

    rep(i,height){
        rep(j,width){
            if(rock_area[i][j])cout <<'x';
            else cout << 'o';
        }
        cout << endl;
    }
}