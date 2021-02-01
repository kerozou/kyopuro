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
    LL K;cin >> K;
    vector<LL> s(N);
    rep(i,N)cin >> s[i];
    LL ans = 0;
    LL ct = 0;
    LL tmp = 1;
    int L = 0;
    int R = 0;
    while(true){
        tmp *= s[R];
        ct++;
        if(tmp == 0){
            ans = N;
            break;
        }
        if(tmp > K){
            tmp /= s[L];
            ct--;
            if(L == R){
                L++;
                R++;                
            }
            else{
                L++;
                tmp /= s[R];
                ct--;
            }
        }
        else{
            R++;
        }
        ans = max(ans,ct);
        if(R == N || L == N-1)break;
    }
    cout << ans << endl;
}

// 尺取り法でかけていくだけ。
// 実装ミスがないようにする。
// どこかに0が含まれるとき、全部0になることに注意。