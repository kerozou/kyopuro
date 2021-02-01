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

LL p(LL a){
    LL t = pow(2,a-1);
    return t;
}

int main() {
    int t;cin >> t;
    rep(i,t){
        LL n;cin >> n;
        LL ans = -1;
        for(int j = 1;j < 30;j++){
            LL tmp = 0;
            if(j == 1)continue;
            for(int k = 1;k <= j;++k)tmp += p(k);
            if(tmp != 0 && n % tmp == 0){
                ans = n/tmp;
                break;
            }
        }
        cout << ans << endl;
    }
}