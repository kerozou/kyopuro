#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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
    // 入力
    string S;cin >> S;

    // 1~9 で構成される3桁の8の倍数
    vector<int> eight;
    int sum = 8;
    while(sum < 1000){
        eight.push_back(sum);
        sum += 8;
    }


    // S に含まれる桁の数字のリスト
    map<int,int> numlist;
    rep(i,S.size()){
        int tmp = S[i] - '0';
        numlist[tmp]++;
    }

    // S に含まれる文字で生成可能な3桁の数字のリスト
    map<int,int> m;
    if(S.size() >= 3){
        rep(i,10)rep(j,10)rep(k,10){
            if(i != j && j != k)if(numlist[i] >= 1)if(numlist[j] >= 1)if(numlist[k] >= 1)m[100*i+10*j+k]++;
            if(i == j && j != k)if(numlist[i] >= 2)if(numlist[k] >= 1)m[100*i+10*j+k]++;
            if(i != j && j == k)if(numlist[i] >= 1)if(numlist[k] >= 2)m[100*i+10*j+k]++;    
            if(i == k && j != k)if(numlist[i] >= 2)if(numlist[j] >= 1)m[100*i+10*j+k]++;    
            if(i == k && j == k)if(numlist[i] >= 3)m[100*i+10*j+k]++;      
        }
    }
    else if(S.size() == 2){
        int tmp = (S[0] - '0')*10 + (S[1] - '0');
        int tmp2 = (S[1] - '0')*10 + (S[0] - '0');
        m[tmp]++;
        m[tmp2]++;
    }
    else if(S.size() == 1){
        int tmp = (S[0] - '0');
        m[tmp]++;
    }

    // 確認
    bool ok = false;
    for(auto t : eight){
        if(m[t] > 0)ok = true;
    }

    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
}

// ABC181 D - Hachi