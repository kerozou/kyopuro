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

int H,W;
vector<string> S;
vector<vector<bool>> ok;
vector<string> T;

int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {-1,-1,-1,0,1,1,1,0};

bool search(int h,int w){
    bool ch = true;
    if(S[h][w] != '#')ch = false;
    rep(i,8){
        if(h+dy[i] < 0 || h+dy[i] >= H || w+dx[i] < 0 || w+dx[i] >= W)continue;
        if(S[h+dy[i]][w+dx[i]] != '#')ch = false;
    }
    return ch;
}

void write(int h,int w){
    if(ok[h][w]){
        rep(i,8){
            if(h+dy[i] < 0 || h+dy[i] >= H || w+dx[i] < 0 || w+dx[i] >= W)continue;
            T[h+dy[i]][w+dx[i]] = '#';
        }
        T[h][w] = '#';
    }    
}

int main() {
    cin >> H >> W;
    S.resize(H);rep(i,H)cin >> S[i];
    T = S;
    rep(i,H)rep(j,W)T[i][j] = '.';

    ok.resize(H,vector<bool>(W,false));   

    rep(i,H)rep(j,W)ok[i][j] = search(i,j);

   
    rep(i,H)rep(j,W)write(i,j);

    bool tmp = true;
    rep(i,H)rep(j,W){
        if(S[i][j] != T[i][j])tmp = false;
    }

    if(!tmp)cout << "impossible" << endl;
    else{
        cout << "possible" << endl;
        rep(i,H){
            rep(j,W){
                if(ok[i][j])cout << '#' ;
                else cout << '.';
            }
            cout << endl;
        }
    }

}

// D039 - 画像処理高橋君

/*
    バグらせないように気を付けるだけ
*/