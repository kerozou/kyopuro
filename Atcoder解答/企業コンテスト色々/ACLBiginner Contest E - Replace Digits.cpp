#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using mint = modint998244353;
//using mint = modint1000000007;
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

vector<mint> ten,one;

struct S {
    mint val;
    int len;
};

S op(S sl,S sr){
    return {sl.val * ten[sr.len] + sr.val , sl.len + sr.len};
}

S e(){
    return {0,0};
}

struct F {
    int a;
};

S mapping(F f,S s){
    if(f.a == -1)return s;// 恒等写像
    return {f.a * one[s.len] , s.len};
}

F composition(F f,F g){
    if(f.a == -1)return g;
    return f;
}

F id(){
    return {-1};
}


int main() {
    int N,Q;cin >> N >> Q;
    ten.resize(N+1,0);
    one.resize(N+1,0);
    ten[0] = 1;
    rep(i,N)ten[i+1] = ten[i] * 10;
    rep(i,N)one[i+1] = one[i] + ten[i];

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<S>(N,{1,1}));

    rep(_,Q){
        int l,r,d;cin >> l >> r >> d;
        l--;
        seg.apply(l,r,{d});
        cout << seg.all_prod().val.val() << endl;
    }
}