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
    rep(l,t){
        int n,k;cin >> n >> k;
        vector<int> v(n);rep(i,n)cin >> v[i];
        vector<int> ans;
        rep(i,k){
            ans.push_back(v[i]);
        }
        int st = ans.size();
        int ind = 0;
        bool ch = true;
        for(int i = st;i < n;i++){
            bool ok = true;
            while(ok){
            if(ind > n-k){
                ch = false;
                break;
            }
            if(ans[ind] == v[i]){
                ans.push_back(v[i]);
                ind++;
                ok = false;
                break;
            }
            ans.push_back(ans[ind]);
            ind++;
            }
        }
        if(!ch)cout << -1 << endl;
        else{
            cout << ans.size() << endl;
            for(auto e : ans)cout << e << " ";
            cout << endl;
        }
    }

}
