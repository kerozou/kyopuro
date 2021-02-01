#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
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
    LL N,K;cin >> N >> K;
    vector<pair<mint,mint>> LR(K);
    rep(i,K){
        int a,b;cin >> a >> b;
        LR[i] = {a,b};
    }   

    BIT<mint> q(N+2);
    q.add(1,1); // 初期地点
    q.add(2,-1);
    for(int i = 1;i < N;i++){
        for(auto [x,y] : LR){
            mint now = q.sum(i);
            if(i+x.val() <= N)q.add(i+x.val(),now);
            if(i+y.val()+1 <= N)q.add(i+y.val()+1,-1*now);
        }
    }


    cout << q.sum(N).val() << endl;
}

// ABC179 D - Leaping Tak