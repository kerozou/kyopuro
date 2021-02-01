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
    vector<int> b(N);
    rep(i,N)cin >> a[i] >> b[i];

    map<pair<int,int>,bool> m;
    map<pair<int,int>,bool> ch;
    rep(i,N)m[{a[i],b[i]}] = true;


    int ds[9] = {-1,-1,-1,0,0,0,1,1,1};
    int dt[9] = {-1,0,1,-1,0,1,-1,0,1};

    vector<LL> ans(10,0);
    ans[0] = H*W;
    rep(i,N)rep(j,9){
        int ct = 0;
        int s = a[i] + ds[j];
        int t = b[i] + dt[j];
        if(s >= 2 && s <= H-1 && t >= 2 && t <= W-1 && !ch[{s,t}]){
       //     cout << "(" << s << "," << t << ")" << endl;
            ch[{s,t}] = true;
            int tmp = 0;
            rep(k,9){
                int s2 = s + ds[k];
                int t2 = t + dt[k];
                if(m[{s2,t2}])tmp++;
            }
            if(tmp != 0)ans[tmp]++;
        }
        else{
            continue;
        }     
    }

    LL sum = 0;
    for(int i = 1;i < 10;++i)sum += ans[i];
    ans[0] = (LL)(H-2)*(W-2) - sum;

    rep(i,10)cout << ans[i] << endl;
}

// ABC045 D - すぬけ君の塗り絵 / Snuke's Coloring

// https://emtubasa.hateblo.jp/entry/2018/11/03/000000

// 解説記事とかにもあるように、黒点の周りのパターンは9通りしかない。
// その9通りをそれぞれ中心として持つ正方形を総当たりすると計算量は　N*9*9となり、ギリギリ間に合う。

// 座標軸の取り方に注意。あと、ans[0]がLLからはみってオーバーフローすることにも注意。