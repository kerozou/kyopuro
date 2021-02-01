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

int main(){
    int N,M;cin >> N >> M;
    vector<LL> A(N);
    vector<LL> B(M);
    vector<LL> C(M);
    rep(i,N)cin >> A[i];
    rep(i,M)cin >> B[i] >> C[i];

    // ランレングス圧縮
    vector<pll> v;
    rep(i,N)v.push_back({A[i],1});
    rep(i,M)v.push_back({C[i],B[i]});
    sort(rall(v));

    LL ct = 0;
    LL ans = 0;
    for(auto a : v){
        if(ct + a.S > N){
            int tmp = N - ct;
            ans += a.F * tmp;
            break;
        }
        else{
            ct += a.S;
            ans += a.F * a.S;
        }
    }

    cout << ans << endl;

}


// ABC-D127 D - Integer Cards 
// priority_queue で実装できそう。
// 入力のカードたちは順序に制限がなさそうなので、ソートしてもよい。
// ということは、毎操作後にソートすればよさそうだけど、O(NlogN)だけ毎回かけてるとやばいので、ソートしなくてもいいように
// priority_queueを使う。
// O(logN)でpush,popが可能なのだが、これでも愚直に行くと計算量が爆発する。

// そこで、ランレングス圧縮をして、数字を管理すればよいらしい。
// 探しても実装例が見つからないので自作する。
// 今回の場合はmapにぶちこめばおｋ。
// あとは大きいものからN個足せばいい。

// map でやろうとしたらバグった。
// やっぱりちゃんと使えばvector強い


/*     map<LL,LL> m;
    rep(i,N)m[A[i]]++;
    rep(i,M)m[C[i]] += B[i];

/*  for(auto itr = m.begin();itr != m.end();++itr){
        cout << "(" << itr -> F << "," << itr -> S << ")" << endl; 
    } */

//    cout << m.begin() -> F <<  " " << m.end() -> F << endl;

    // N枚取り出す
/*    LL ans = 0;
    int ct = 0;
    for(auto itr = m.end();itr != m.begin();--itr){
        if(itr == m.end())continue;                             // m.end() -1 としたいけど、itrだからなんかおかしなことになるので

        ct += itr -> S;
        if(ct > N){
            ct -= itr -> S;
            int tmp = N - ct;
            if(tmp > 0)ans += (itr -> F)*tmp;
            break;
        }
        ans += (itr -> F)*(itr -> S);
    }
    if(ct < N){                                                 // for で m.begin() を通過してしまうのでここで追加
        int tmp = N - ct;
        ans += (m.begin() -> F)*tmp;
    }

    cout << ans << endl; */