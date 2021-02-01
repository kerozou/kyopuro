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
    int R,C,D;cin >> R >> C >> D;
    vector<vector<int>> A(R,vector<int>(C));
    rep(i,R)rep(j,C){
        cin >> A[i][j];
    }   

    // マス目づくり
    map<int,int> m;
    rep(i,R)rep(j,C){
        int tmp = i+j;
        m[tmp] = max(m[tmp],A[i][j]);
    }

    int ans = 0;
    for(int i = 0;i <= D;++i) {
        if(i % 2 != D % 2)continue;
        ans = max(ans,m[i]);
    }

    cout << ans << endl;
}

// ARC023 B - 謎の人物X

/*
    0 1 2 3
    1 2 3 4
    2 3 4 5 
    3 4 5 6

    といったように左上からジグザグに進むときの道のりごとにマスの種類を分けると、同じ数字のマス同士は
    その中でMAXの値段になるものを買うのが最適解であることがわかる。
    この時、進める距離Dマス以下のマスは　Dと偶奇が一致すればOK　なことに気づく。
    なので、DがデカすぎてもOKなようにするために　map　でマス目の最大値を用意しておいて、
    forループでmaxを更新し続ければいい。
*/