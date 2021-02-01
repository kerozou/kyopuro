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

    int N,M,Q;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;
    int ans = 0;


void cal(int n,vector<int> st){
    if(n == N){
        int tmp = 0;
        rep(i,Q){
            if(st[b[i]-1] - st[a[i]-1] == c[i])tmp += d[i];
        }
        ans = max(ans,tmp);
        return;
    }

    
    int start;
    if(n != 0)start = st[st.size()-1];
    else start = 1;

    for(int i = 1;i <= M;i++){
        if(i < start)continue;
        vector<int> v = st;
        v.push_back(i);
        cal(n+1,v);
    }

}


int main() {
    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    rep(i,Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<int> v;

    cal(0,v);

    cout << ans << endl;

    
}

// C165 - Many Requirements

/*  
    19 C 10 が10^5 程度なので、重複組み合わせの仕切り問題のように考えて、ありうるAの配列を全列挙し、
    そのすべてにクエリを50回投げる。

    全体で計算量はO(10^6)程度

    配列生成はDFSでやると楽。
    その際に、入力で与えられたindexが1-indexなのに注意。
*/
