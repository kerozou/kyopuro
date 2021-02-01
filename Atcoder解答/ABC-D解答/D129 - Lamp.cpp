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

typedef struct houi{
    int L;
    int R;
    int U;
    int D;
}houi;

int main(){
    int H,W;cin >> H >> W;
    vector<string> s(H+10);
    rep(i,H)cin >> s[i];

    vector<vector<houi>> A(H+10,vector<houi>(W+10,{0,0,0,0}));


    rep(i,H){
        int tmp = 0;
        rep(j,W){   // L
            if(s[i][j] == '#')tmp = 0;
            else ++tmp;
            A[i][j].L = tmp;
        }
    }


    rep(i,H){
        int tmp = 0;
        for(int j = W-1;j >= 0;--j){   // R
            if(s[i][j] == '#')tmp = 0;
            else ++tmp;
            A[i][j].R = tmp;
        }
    }


    rep(j,W){
        int tmp = 0;
        rep(i,H){   // U
            if(s[i][j] == '#')tmp = 0;
            else ++tmp;
            A[i][j].U = tmp;
        }
    }


    rep(j,W){
        int tmp = 0;
        for(int i = H-1;i >= 0;--i){   // D
            if(s[i][j] == '#')tmp = 0;
            else ++tmp;
            A[i][j].D = tmp;
        }
    }


    int ans = 0;
    rep(i,H)rep(j,W){
        int t = A[i][j].L + A[i][j].R + A[i][j].U + A[i][j].D - 3;
        ans = max(ans,t);
    }

    cout << ans << endl;
}

// ABC-D 129 D - Lamp

// 縦＊横の全マスを調べ上げると、O(HW)だけかかり、
// さらに各マスについて愚直に行と列を探索すると、O(H)、O(W)だけかかり、O(HW^2)となってしまう。

// これをなんとかO(HW)にするべく考えると、
// 各マスから、上下左右に移動していくときを独立に考えることができる。
// それぞれの場合に関して、進んだマスをカウントしていき、壁に乗っかると0を代入として tmp をためていく。  
// すると、各行と列のカウントを移動と同時に行うことができる。
// これによってO(HW)を実現可能。

// けんちょんさんの記事を参考
// http://drken1215.hatenablog.com/entry/2019/06/10/143300