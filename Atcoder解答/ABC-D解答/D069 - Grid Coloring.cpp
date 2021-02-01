#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    int H,W;cin >> H >> W;
    int N;cin >> N;
    vector<int> a(N);
    rep(i,N)cin >> a[i];

    vector<vector<int>> ans(H,vector<int>(W,0));
    int s = 0;
    int t = 0;  // (s,t)が現在地の座標になる。(行列表記)
    int dir = 0;    // dir は 0 → 1 ↓ 2 ← 3 ↑　とする
    int ct = 1; // 曲がった回数。これを4で割ると行き止まりの座標を取得可能

    // ぐるぐる回る
    rep(i,N){
        rep(j,a[i]){
            ans[s][t] = i+1;
            if(dir == 0){
                if(t != W-1 - ct/4)t++;
                else{
                    s++;
                    dir = 1;
                    ct++;
                }
            }     
            else if(dir == 1){
                if(s != H-1 - ct/4)s++;
                else{
                    t--;
                    dir = 2;
                    ct++;
                }
            }
            else if(dir == 2){
                if(t != 0 + ct/4)t--;
                else{
                    s--;
                    dir = 3;
                    ct++;
                }
            }
            else if(dir == 3){
                if(s != 0 + ct/4)s--;
                else{
                    t++;
                    dir = 0;
                    ct++;
                }
            }
        }
    }

    rep(i,H){
        rep(j,W)cout << ans[i][j] << " ";
        cout << endl;
    }
}

// ABC069 	D - Grid Coloring

// (0,0)をスタート地点として時計回りか反時計回りかにぐるぐる回ればおｋ。
// 発想としては、縦横に連続であるということは、二次元のマス目をぐるぐるした蛇みたいに1次元化してしまえばいいということ。