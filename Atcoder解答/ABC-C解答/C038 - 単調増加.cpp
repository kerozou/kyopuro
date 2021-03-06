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
    LL N;cin >> N;
    vector<LL> a(N);
    rep(i,N)cin >> a[i];
    LL ct = 1;
    LL ans = 0;
    rep(i,N){
        if(i == 0)ans += ct;
        else{
            if(a[i] > a[i-1]){
                ct++;
                ans += ct;
            }
            else{
                ct = 1;
                ans += ct;
            }
        }
    }
    cout << ans << endl;
}

// 単調増加がいくつ続くかをカウントしていくだけ。
// たとえば、1,4,5,2なら1,4,5と2に分けることができて、1,4,5がつくる大小のペアは3+2+1個になる。なぜなら、(1,1)とかも含めるので。
// なので、そのつど自分までのカウント数を加えていくだけでよい。