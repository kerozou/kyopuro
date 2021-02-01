#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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

int main() {
    LL N,C;cin >> N >> C;
    vector<LL> a(N);
    vector<LL> b(N);
    vector<LL> c(N);
    rep(i,N)cin >> a[i] >> b[i] >> c[i];

    vector<pair<LL,LL>> ev;

    rep(i,N){
        ev.push_back({a[i]-1,c[i]});
        ev.push_back({b[i],-c[i]});
    }

    sort(all(ev));

    LL ans = 0;
    LL prev = 0;
    LL fee = 0;

    for(auto [x,y] : ev){
        if(x != prev){
            ans += (min(C,fee) * (x - prev));
            prev = x;
        }
        fee += y;
    }

    cout << ans << endl;


}

// ABC188 D - Snuke Prime

/*
    問題文を見ると、なんとなく[a,b]が被った範囲を足し合わせて　C　と比較するとよさそうな感じがする。
    しかし、a,b の 制約が10^9なので、値を1ずつ動かしてチェックしていくと、O(10^9)となり間に合わない。
    なので、この問題では区間を圧縮するための何か工夫が必要なことが分かる。

    そこで、[a,b]　に対して、
    ・a : a日目に c 円料金があがる。
    ・b : b日目に c 円料金が下がる。
    と考える。
    すると、a1,a2,b1,b2,a3,a4,a5,b3,a6,……とイベント発生時の日付を並べることができる。
    これによって、それぞれの要素間での値段とサブスク料金とを比較して安いほうに区間長をかけてあげれば最小金額が得られることが分かる。
*/