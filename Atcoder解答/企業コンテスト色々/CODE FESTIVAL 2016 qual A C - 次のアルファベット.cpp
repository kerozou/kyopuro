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

int main() {
    string s;cin >> s;
    int K;cin >> K;
    int N = s.size();
    vector<int> num(N);
    rep(i,N){
        int start = 'a' + 0;
        for(int j = start;j < s[i] + 0;j++){
            num[i]++;
        } 
    }

    int ct = 0;
    rep(i,N){
        if(num[i] == 0 && i != N-1)continue;
        int tm = K - ct;

        if(i == N-1){
            int tmp = (num[N-1] + tm) % 26;
            num[N-1] = tmp;
            break;
        }
        else if(26 - num[i] > tm){
            continue;
        }
        else{
            int tmp = 26 - num[i];
            num[i] = 0;
            ct += tmp;
        }
    }

    string ans;
    rep(i,N){
        char c = 'a' + num[i];
        ans.push_back(c);
    }

    cout << ans << endl;
}

// CODE FESTIVAL 2016 qual A C - 次のアルファベット

/*
    if　で最後尾の処理、
    else if で残り回数が25回以下で、なおかつ'a'に移行する間でに足りないときの処理
    else は'a'に届くとき通す
*/