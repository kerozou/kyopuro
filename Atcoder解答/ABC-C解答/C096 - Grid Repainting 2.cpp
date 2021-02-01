#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

// 問題の性質的に、'＃'の上下左右すべてが　場外　もしくは　'.'　の時OUT。逆に四方のどこか一つでも＃同士でつながってればOK。
// 制約的に50^2＝2500要素の行列の全要素に対して4方向をかけて10000通りなので、全探索すればいい。

int main(){
    int H,W;cin >> H >> W;
    char e[51][51] = {'.'};
    rep(i,H) rep(j,W){
        cin >> e[i][j];
    }

    int dx[4] = {-1,0,1,0};     //方向ベクトルを作っておくと探索が楽。
    int dy[4] = {0,-1,0,1};
    
    bool ans = true;
    rep(i,H) rep(j,W){
        if(e[i][j] == '#'){
            int ct = 0;
            rep(k,4){
                if(i+dy[k] < 0 || i+dy[k] >= H || j+dx[k] < 0 || j+dx[k] >= W){     // 場外OUT
                    ct++;
                }
                else if(e[ dy[k]+i ][ dx[k]+j ] == '.'){                            // .でOUT
                    ct++;
                }
            }
            if(ct == 4)ans = false;     // 4OUT で　false
        }
    }

    // 全部真っ白は true
    
    if(ans)cout << "Yes" << endl;
    else cout << "No" << endl;

    
}