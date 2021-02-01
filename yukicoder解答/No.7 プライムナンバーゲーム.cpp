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

#define MAX 10005

bool pdp[MAX];
vector<int> makeprime(){
	vector<int> ret;
	for (int i = 2; i < MAX; i++)
	{
		if (pdp[i]) continue;
		ret.push_back(i);
		for (int j = i + i; j < MAX; j += i)
		{
			pdp[j] = true;
		}
	}
	return ret;
}


bool win[MAX];

int main(){
    int N;cin >> N;
    auto v = makeprime();


    win[0] = true;
    win[1] = true;
    for(int i = 2;i <= N;i++){
        for(int j : v){
            if(i - j < 0)break;
            win[i] |= !win[i-j];
        }
    }

    if(win[N])cout << "Win" << endl;
    else cout << "Lose" << endl;
}


// グローバル変数は初期値で初期化されることに注意。