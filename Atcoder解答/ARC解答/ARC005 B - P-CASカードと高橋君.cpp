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

int dp[8] = {-1,-1,-1,0,1,1,1,0};
int dq[8] = {-1,0,1,1,1,0,-1,-1};
string st;
vector<string> c(27);

void move(pair<int,int> now,int dir,int n){
    char tmp = c[now.F][now.S];
    st += tmp;
    if(n == 3){
        return;
    }
    
    int a = now.F;
    int b = now.S;
    int na = a + dp[dir];
    int nb = b + dq[dir];

    move({na,nb},dir,n+1);
}


int main() {
    int x,y;cin >> x >> y;
    string W;cin >> W;
    
    rep(i,9){
        string q;
        string tmp;cin >> tmp;
        int lim = tmp.size();
        rep(j,3){
            q.push_back(tmp[3-j]);
        }
        q += tmp;
        rep(j,3){
            q.push_back(tmp[lim-2-j]);
        }
        c[9+i] = q;
        c[9-i] = q;
        c[25-i] = q;
    }
    

    if(W == "L")move({8+y,2+x},7,0);
    if(W == "U")move({8+y,2+x},1,0);
    if(W == "R")move({8+y,2+x},3,0);
    if(W == "D")move({8+y,2+x},5,0);
    if(W == "RU")move({8+y,2+x},2,0);
    if(W == "RD")move({8+y,2+x},4,0);
    if(W == "LU")move({8+y,2+x},0,0);
    if(W == "LD")move({8+y,2+x},6,0);

    cout << st << endl;

}

// ARC005 B - P-CASカードと高橋君

/*
    全方位に入力を広がるように付け足して、反転処理をそのまま進んでも可能にする。
*/