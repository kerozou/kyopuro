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

LL ch(vector<LL> &v){
    LL ans = 0;
    for(auto t : v){
        ans += t;
    }
    
    return ans;
}

int main() {
    int t;cin >> t;
    rep(k,t){
        int n;cin >> n;
        vector<LL> v;
        bool posi = true;
        LL tmp = 0;
        rep(i,n){
            LL a;cin >> a;
            if(i == 0){
                if(a > 0)posi = true;
                else posi = false;
                tmp = a;
                if(n == 1){
                    v.push_back(tmp);
                }
                continue;
            }

            
            if(posi){
                if(a > 0){
                    tmp = max(tmp,a);
                    if(i == n-1)v.push_back(tmp);
                }
                else{
                    v.push_back(tmp);
                    tmp = a;
                    posi = !posi;
                    if(i == n-1)v.push_back(tmp);
                }
            }
            else{
                if(a < 0){
                    tmp = max(tmp,a);
                    if(i == n-1)v.push_back(tmp);
                }
                else{
                    v.push_back(tmp);
                    tmp = a;
                    posi = !posi;
                    if(i == n-1)v.push_back(tmp);
                }
            }
        }

        vector<LL> hi;
        for(auto t : v){

        }

        LL ans = ch(v);
        cout << ans << endl;
    }
}