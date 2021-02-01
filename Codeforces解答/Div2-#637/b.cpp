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


template< typename T >
struct BIT {
  vector< T > data;

  BIT(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};


int main() {
    int t;cin >> t;
    rep(k,t){
        int n,m;cin >> n >> m;
        vector<LL> a(n);rep(i,n)cin >> a[i];

        BIT<LL> q(n+2);
        for(int i = 1;i <= n;i++){
            int left = i-m+2;

            if(left < 1){
                left = 1;
            }

            if(1 < i && i < n && a[i-2] < a[i-1] && a[i-1] > a[i]){
                q.add(left,1);
                q.add(i,-1);
            }
        }

        LL su = 0;
        int ind = 0;
        for(int i = 1;i <= n;i++){
            LL tmp = q.sum(i);
            if(su < tmp){
                su = tmp;
                ind = i;
            }
        }

        su++;
        if(ind == 0)ind = 1;
        cout << su << " " << ind << endl;
    }

}