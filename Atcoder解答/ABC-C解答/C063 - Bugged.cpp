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
    vector<int> s(N);
    rep(i,N)cin >> s[i];
    int ans = 0;
    rep(i,N)ans += s[i];
    map<int,int> L;
    rep(i,N){
        int tmp = s[i] % 10;
        L[s[i]] = tmp;
    }
    if(ans % 10 != 0)cout << ans << endl;
    else{
        int t = 0;
        for(auto itr = L.begin();itr != L.end();itr++){
            if(itr -> S % 10 != 0){
                t = itr -> F;
                break;
            }
        }
        if(t == 0)cout << 0 << endl;
        else cout << ans - t << endl;
    }
}

// ABC063 C - Bugged
// ・bit全探索に行きたいけど、2^100はむり。

// 後ろから貪欲すればいい。
// 全部の和sumをとりながら、mapにkeyを数値、valueをmod10で保存していく。
// 総和のmod10が0以外の時ここで終わり。
// 0の時,mapの昇順からvalueが0でないものを発見して、そのkeyをansから引いたら終わり。
// また、例外としてvalが全部0の時0点。