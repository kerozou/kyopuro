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
    int N;cin >> N;

    vector<LL> x(N);
    vector<LL> y(N);
    vector<LL> z(N);

    int ind = 0;
    rep(i,N){
        cin >> x[i] >> y[i] >> z[i];
        if(z[i] > 0)ind = i;
    }

    int xp = -1;
    int yp = -1;
    LL ans = 0;
    int d = x[ind];
    int e = y[ind];
    int f = z[ind];

    rep(xx,101)rep(yy,101){
        LL h = abs(xx-d) + abs(yy-e) + f;

        bool ok = true;
        rep(i,N){
            int a = x[i]; int b = y[i]; int c = z[i];
            int dx,dy;
            dx = abs(xx-a);
            dy = abs(yy-b);
            if(c > 0 && h != dx + dy + c)ok = false;
            if(c == 0 && h > dx + dy + c)ok = false;
        }

        if(ok){
            xp = xx;
            yp = yy;
            ans = h;
        }
    }

    
    cout << xp << " " << yp << " " << ans << endl;
}


// 20200310 acしなおし

// あさかつ０３１０でといた

// まず、高さは決まっているので、逆説的に考えて与えられた高さ１以上の点から頂点の高さは一意に求まる。
// ただ、この時にその座標までは分からないので以降座標を求める。

// ind は　もとにする点を決めている。
// 問題の条件から、必ず１点以上高さが１以上の点がある。
// 高さ０の点を基準にしてしまうと、それがピラミッド内部か外部の埋まってる点なのかが分からないので、高さ１以上の点をなんでもいいから一個見つけてる。

// 頂点の高さを決めたら、与えられた各点の情報と照らし合わせていく。
// この時、ピラミッド内部の点から計測すると高さは正しい情報なのだが、高さ０の点でかつピラミッド外部にあるとき高さの情報は何の意味も持たない。
// というのも、０点からの頂点予測は「決まってる頂点の高さ」より高くなるか同じになるかの２通りしかないからである。

// 以上の議論から、ピラミッドの形状的に考えて内部の特定の二点が定まれば頂点の座標は一点に決まるはずなので、それを分岐で求めるといい。

