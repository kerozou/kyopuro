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
    vector<int> t(N);
    vector<double> v(N);
    rep(i,N)cin >> t[i];
    rep(i,N)cin >> v[i];

    int T = 0;
    rep(i,N)T += t[i];

    vector<int> rui(N+1);
    rep(i,N)rui[i+1] = rui[i] + t[i];

    vector<double> maxv(2*T+1,0);
    for(int i = 0;i < N;++i){
        for(int j = 2*rui[i];j <= 2*rui[i+1];++j){
            if(j == 2*rui[i] && j != 0)maxv[j] = min(v[i-1],v[i]);
            else if(j == 2*rui[i+1] && j != 2*T)maxv[j] = min(v[i+1],v[i]);
            else maxv[j] = v[i];
        }
    }

    maxv[0] = 0;
    for(int i = 1;i <= 2*T;++i){
        maxv[i] = min(maxv[i],maxv[i-1] + 0.5);
    }

    maxv[2*T] = 0;    
    for(int i = 2*T-1;i >= 0;--i){
        maxv[i] = min(maxv[i],maxv[i+1] + 0.5);
    }

    double ans = 0;
    rep(i,2*T){
        ans += (maxv[i] + maxv[i+1])*0.5*0.5;
    }

    cout << std::fixed << std::setprecision(5) << ans << endl;
}

// ABC076 D - AtCoder Express

// 解説放送の区間更新がすごく頭良い
// 最終的に誤差を10^-3で評価しなきゃいけなくて、それを忘れてて無限にWAでた。
// あと、maxvの作り方はもう少し簡潔にできそう。

// maxvに関してはグラフを作った時に、閉区間の端っこ同士が重なり合うので、その両端2点に関してはminをとって小さいほうをmaxvとしておく必要がある
// これで少しバグらせた。
// 二重ループ内の分岐がこれ。

// 今回のは「加速度」の問題らしく、まあまあよくある感じの設定っぽい。
// グラフ化するときの注意点として
// ・maxvの端点のmin
// ・0.5刻みだったり、0.25刻みだったり、加速度の上限によって区間の数が変化すること
// ・連続なので、DP的に　前後　+　加速度　で区間更新することができること
// がありそう。