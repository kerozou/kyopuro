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



int main() {
    int t;cin >> t;
    int hai[9] = {0,3,6,1,4,7,2,5,8};
    rep(k,t){
        vector<vector<char>> masu(10,vector<char>(10,0));
        rep(i,9)rep(j,9){
            cin >> masu[i][j];
        } 
        rep(i,9){
            int c = hai[i];
            if(masu[i][c] != '9')masu[i][c] += 1 ;
            else masu[i][c] = '1';
        }
        rep(i,9){
            rep(j,9)cout << masu[i][j];
            cout << endl;
        }
    }
}