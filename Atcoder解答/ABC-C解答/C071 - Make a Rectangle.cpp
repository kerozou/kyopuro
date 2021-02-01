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
    int N;cin >> N;
    map<LL,LL> L;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];
    rep(i,N)L[A[i]]++;
    vector<LL> ct;
    for(auto itr = L.begin();itr != L.end();itr++){
        while(itr -> S > 1){
            ct.push_back(itr -> F);
            itr -> S -= 2;
        }
    }
    sort(rall(ct));
    if(ct.size() < 2)cout << 0 << endl;
    else cout << ct[0]*ct[1] << endl;

}

// 使える辺の組を探し出して、降順に並べて頭から2つの積をとる。