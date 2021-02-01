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
unsigned GetDigit(unsigned num){
    if(num == 0)return 1;
    return log10(num)+1;
}

int main(){
    int N,K;cin >> N >> K;
    vector<int> D(K);
    rep(i,K)cin >> D[i];
    int ans = N;
    bool ok = true;
    for(int i = N;i < 100000;i++){
        int keta = GetDigit(i);
        ok = true;
        for(int j = 1;j <= keta;j++){
            int tmp = 0;
            tmp = i % (int)pow(10,j);
            tmp = tmp / (int)pow(10,j-1);      //  tmpにj桁目の数字を格納  
            rep(k,K){
                if(tmp == D[k])ok = false;
            }
        }
        if(ok){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

// 桁数の扱いに注意。10^2は100であるところを10と勘違いしないように(一敗）