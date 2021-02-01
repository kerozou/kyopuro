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
    rep(r,t){
        int n,k;cin >> n >> k;
        vector<int> a(n);rep(i,n)cin >> a[i];
        vector<int> maxi;
        vector<int> mini;
        rep(i,n/2){
            int tmp = max(a[i],a[n-i-1]);
            int tmp2 = min(a[i],a[n-i-1]);
            maxi.push_back(tmp);
            mini.push_back(tmp2);
        }
        sort(all(maxi));
        sort(rall(mini));
        int lim = maxi[0] + k;
        int low = mini[0] + 1;

        int numm = 0;
       

        map<int,int> m;
        rep(i,n/2){
            int tmp = a[i] + a[n-i-1];
            m[tmp]++;
        }

        int check = 0;
        for(auto t : m){
            check = max(check,t.S);
        }

        int ctm = 0;
        for(auto t : m){
            if(low <= t.F && t.F <= lim){
                ctm = max(ctm,t.S);
            }
        }

        int ans = n/2 - ctm;

        ans = min(ans,n-(check*2));
        cout << ans << endl;
    } 
}