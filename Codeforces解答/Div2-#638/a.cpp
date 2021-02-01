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
    int t;cin >> t;
    rep(k,t){
        int n;cin >> n;
        vector<int> rui(n+1);
        rep(i,n){
            rui[i+1] = rui[i] + pow(2,i+1);
        }
        LL sum = rui[n];
        LL ans = 1e9;
        if(n == 2)cout << 2 << endl;
        else{
            for(int i = 1;i < n;i++)for(int j = i+1;j <= n;j++){
                if(j-i+1 != n/2)continue;
                LL tmp = abs(rui[j] - rui[i-1]);
                LL noko = sum - tmp;
                tmp = abs(tmp-noko);
                ans = min(ans,tmp);
            }
            cout << ans << endl;
        }

    }  
}