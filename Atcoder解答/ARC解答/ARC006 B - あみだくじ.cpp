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


vector<vector<bool>> on;
int N,L;

int ami(int mp){
    int tmp = mp;
    for(int h = L-1;h >= 0;h--){
        if(tmp != 2*N-2 && on[h][tmp+1])tmp += 2;
        else if(tmp != 0 && on[h][tmp-1])tmp -= 2;
    }
    return tmp;
}

int main(){
    cin >> N >> L;
    vector<string> hyou(L);
    on.resize(L,vector<bool>(2*N-1,false));

    string dummy;getline(cin,dummy);      // N L を吸い取った後の空白行を吸ってる。
    
    rep(i,L)getline(cin,hyou[i]);        // あみだくじを作ってる

    string maru;getline(cin,maru);       // o を吸ってる

    rep(i,L)rep(j,2*N-1)if(hyou[i][j] == '-')on[i][j] = true;   // - の位置を検出

    int mp;rep(i,2*N-1)if(maru[i] == 'o')mp = i;    // o の位置検出

    int ans = ami(mp);
    ans = (ans / 2) + 1;
    cout << ans << endl;
    
}   


// ARC006 B - あみだくじ

// 古い問題で、空白を含めた入力を余儀なくされる。
// この時 std::getline を使う。

// 使い方は
// string s;
// getline(cin,s);
// でsに入力が入る。

// 注意する点として、それ以前に入力を受けとった行も空白行として残っているので、それをdummyに吸わせる必要がある。
