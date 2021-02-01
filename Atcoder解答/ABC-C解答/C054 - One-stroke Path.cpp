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
    int N,M;cin >> N >> M;
    vector<vector<bool>> ab(N,vector<bool>(N,false));   // 隣接行列
    vector<int> p(N);
    rep(i,N)p[i] = i;       //  順列
    rep(i,M){       //  グラフ作成
        int a,b;cin >> a >> b;
        a--,b--;
        ab[a][b] = true;
        ab[b][a] = true;
    }
    bool ok = true;
    LL ans = 0;
    do{
        ok = true;
        if(p[0]!=0)continue;
        rep(i,N-1)if(ok)if(!ab[p[i]][p[i+1]])ok = false;
        if(ok)ans++;
    }while(next_permutation(all(p)));
    cout << ans << endl;
}


// next_permutation の使い方を覚えるいい問題。
// 解説ではDFSによるbitを用いた手法もできるようになるといいと言っていた。
// あとは、next_permutationの自作も。
// n_permutationは順列なので、もちろんオーダーはO(N!)になるので、N>=16の時くらいから死亡する。
// これを解くためにはbitDPの考え方を使うらしく、D問題程度の難易度になるらしい。

