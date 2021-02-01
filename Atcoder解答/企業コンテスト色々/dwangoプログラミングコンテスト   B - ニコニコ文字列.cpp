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
    string S;cin >> S;

    vector<LL> st;
    LL niko = 0;
    LL pre = 0;
    rep(i,S.size()){
        if(pre == 5 && S[i] == '2'){
            niko++;
            pre = 2;
        }
        else if(pre == 2 && S[i] == '5'){
            niko++;
            pre = 5;
        }
        else{
            st.push_back(niko/2);
            niko = 0;
            pre = 0;
            if(S[i] == '2'){
                niko++;
                pre = 2;
            }
        }
    }   
    if(niko / 2 > 0){
        st.push_back(niko/2);
    }

    LL ans = 0;
    for(auto t : st){
        LL tmp = (t+1)*t/2;
        ans += tmp;
    }

    cout << ans << endl;
}

// dwangoプログラミングコンテスト   B - ニコニコ文字列

/*
    25の数をカウントして、その塊の長さを配列に保存。
    その塊ごとに t(t+1)/2 をansに加える。
*/
