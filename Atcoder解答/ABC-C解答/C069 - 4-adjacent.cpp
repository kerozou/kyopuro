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
    vector<LL> a(N);
    rep(i,N)cin >> a[i];
    int odd_ct = 0;
    int mod_4 = 0;
    rep(i,N){
        if(a[i] % 4 == 0)mod_4++;
        else if((a[i]%4)%2 != 0)odd_ct++;
    }
    bool ok = false;
    if(odd_ct - mod_4 < 1 || (odd_ct - mod_4 == 1 && odd_ct + mod_4 == N))ok = true;

    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
}

// ABC069 C - 4-adjacent
//・隣同士の積が4の倍数のとき、どんな組み合わせがあるか

// 1,modが 2,2
// 2,modが 4,k

// のいずれかの時成立。
// さらに、1が成立するのは、すべて偶数の時。上の回答ではこれ意識してなかったけど、嘘解法？
// なので、2を攻めるとき、奇数の存在が問題になる。
// 奇数は両サイドを4で覆ってなくてはならない。なので、まず両端に奇数を追いやり、その隣をサンドイッチしていけばおｋ。
// 例外として、3454749 みたいなときは奇数-1個4があればいい。それ以外は同じ数必要。