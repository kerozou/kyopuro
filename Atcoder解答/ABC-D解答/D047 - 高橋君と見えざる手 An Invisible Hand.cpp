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
    LL N;cin >> N;
    LL T;cin >> T;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];

    vector<LL> m(N);
    m[0] = INF;
    LL tmp = INF;
    for(int i = 1;i < N;++i){
        if(A[i-1] < tmp)tmp = A[i-1];
        m[i] = tmp;
    }

    vector<LL> gain(N);
    rep(i,N)gain[i] = A[i] - m[i];
    sort(rall(gain));

    LL ct = 0;
    rep(i,N)if(gain[i] == gain[0])ct++;

    cout << ct << endl;
}

// ABC047 D - 高橋君と見えざる手 / An Invisible Hand

// 簡単すぎわろち

// 入力T　がまったく無意味だった。
// そもそも、制約がそんなにないので、最適なムーブは「最安で買えるだけ買って、最高値で売る」ことになる。
// この時、重要なのは「ある最安値とその地点以降の最高値のペア」を知ることであり、ある地点までの最安値をもつ配列を用意することが必要。
// これを用意すると、   入力A - 最安値    でその地点でものを売った時の「単価当たりの利益」を得られる。
// 青木君はこの利益が最大となる場所の値段Aiを１だけあげてあげれば、高橋君の妨害に成功することになる。
// 利益が最大化される場所が複数ある場合は、そのすべての単価を1あげることになるので、利益配列を降順にソートして頭から同じ値になるものの数を調べればそれが答えになる。
