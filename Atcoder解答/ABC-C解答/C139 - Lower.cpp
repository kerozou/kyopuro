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
    vector<int> H(N);
    rep(i,N)cin >> H[i];
    vector<int> rui(N,0);
    for(int i = N-1;i >= 0;i--){
        if(i == N-1)rui[N-1] = 0;
        else {
            if(H[i] - H[i+1] >= 0){
                rui[i] = rui[i+1] + 1;
            }
            else{
                rui[i] = 0;
            }
        }
    }
    sort(rall(rui));
    cout << rui[0] << endl;
}

// 逆から累積和とるだけ