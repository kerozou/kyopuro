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

int H,W,K;
vector<vector<int>> ans;
vector<string> s;

void left(int p,int q){
    for(int i = q+1;i < W;i++){
        if(ans[p][i] == 0)ans[p][i] = ans[p][i-1];
    }
}

void right(int p,int q){
    for(int i = q-1;i >= 0;i--){
        if(ans[p][i] == 0)ans[p][i] = ans[p][i+1];
    }
}

void up(int p,int q){
    for(int i = p-1;i >= 0;i--){
        if(ans[i][q] == 0)ans[i][q] = ans[i+1][q];
    }
}

void down(int p,int q){
    for(int i = p+1;i < H;i++){
        if(ans[i][q] == 0)ans[i][q] = ans[i-1][q];
    }
}

int main() {
    cin >> H >> W >> K;
    s.resize(H);rep(i,H)cin >> s[i];

    ans.resize(H,vector<int>(W,0));

    int ind = 1;
    rep(i,H)rep(j,W){
        if(s[i][j] == '#'){
            ans[i][j] = ind;
            ind++;
        }
    }

    rep(i,H)left(i,0);

    rep(i,H)right(i,W-1);

    rep(j,W)up(H-1,j);

    rep(j,W)down(0,j);

    rep(i,H){
        rep(j,W){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

// DISCO presents ディスカバリーチャンネル コードコンテスト2020 予選 C - Strawberry Cakes

/*
    各イチゴから左右上下にイチゴを伸ばしていく操作をする。
    4方位全てが終わると完成してる。
    O(4*H*W)程度
*/