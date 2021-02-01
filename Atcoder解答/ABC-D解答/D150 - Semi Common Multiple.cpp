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

auto GCD(auto a,auto b){ //ユークリッドの互助法で最大公約数
    if (a%b == 0){
        return b;
    }
    else {
        return GCD(b,a%b);
    }
}

auto LCM(auto a,auto b){ //GCDを使って最小公倍数を求める
    auto g = GCD(a,b);
    return (a/g)*b;  // (a*b)/GCD(a,b) なんだけど、こうしないとa,b=INFとかだとはみ出しちゃう
}

int two(int x){
    LL ct = 0;
    while(x % 2 == 0){
        ct++;
        x /= 2;
    }
    return ct;
}

int main(){
    LL N,M;cin >> N >> M;
    vector<LL> a(N);
    rep(i,N)cin >> a[i];

    bool same = true;
    LL tmp = two(a[0]);
    rep(i,N){
        if(tmp != two(a[i]))same = false;
        a[i] /= 2;
    }


    if(same){
        LL lcm = a[0];
        rep(i,N)lcm = LCM(lcm,a[i]);
        LL ans = M/lcm;
        ans = (ans + 2 -1)/2;
        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
    }
}

// ABC150 D - Semi Common Multiple

// 解説放送の解放で解くといい
// X = a/2 * (2p + 1)   とすると0.5を消せて、しかも後ろが奇数固定になる。
// なので、X と a/2 の偶奇は一致し、2で何回割れるかが焦点になる。
// a/2を2で何回割れるかをtwoでカウントして、各aiが同じ回数われなければNG。
// また、そのあとはa/2の最小公倍数を拾って、Mから割ったものを切り上げれば答えになる。
// a[i] /= 2　のし忘れと、LLにしわすれでオーバーフローの内容にする。
