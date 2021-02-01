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

vector<vector<bool>> in;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void bfs(int i,int j,vector<vector<bool>> &b,int &sum){    
    rep(k,4){
        if(i + dx[k] < 0 || i + dx[k] > 9 || j + dy[k] < 0 || j + dy[k] > 9)continue;
        if(!in[i + dx[k]][j + dy[k]])continue;
        if(b[i +dx[k]][j + dy[k]])continue;
        b[i + dx[k]][j + dy[k]] = true;
        sum++;
        bfs(i + dx[k],j + dy[k],b,sum);
    }
}


int main() {

    in.resize(10,vector<bool>(10,false));
    rep(i,10)rep(j,10){
        char a;cin >> a;
        if(a == 'o')in[i][j] = true;
    }

    int num = 0;
    rep(i,10)rep(j,10)if(in[i][j])num++;

    bool ans = false;

    rep(i,10)rep(j,10){
        if(in[i][j])continue;
        in[i][j] = true;
        int sum = 0;
        vector<vector<bool>> b(10,vector<bool>(10,false));
        b[i][j] = true;
        bfs(i,j,b,sum);
        in[i][j] = false;

        if(sum == num)ans = true;
    }

    if(ans)cout << "YES" << endl;
    else cout << "NO" << endl;
}

// ARC031 B - 埋め立て

/*
    各マスからbfsして埋めたマスの数を判定すればいい
*/