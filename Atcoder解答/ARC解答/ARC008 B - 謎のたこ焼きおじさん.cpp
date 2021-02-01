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
    int N,M;cin >> N >> M;
    string name;cin >> name;
    string kit;cin >> kit;
    map<char,int> nm;
    map<char,int> km;

    for(auto t : name)nm[t]++;
    for(auto t : kit)km[t]++;

    bool ch = true;
    for(auto t : nm){
        if(km[t.F] <= 0)ch = false;
    }

    if(!ch)cout << -1 << endl;
    else{
        int ct = 0;

        while(true){
            ct++;
            for(auto t : km){
                nm[t.F] -= t.S;
            }

            bool ok = true;
            for(auto t : nm){
                if(t.S > 0)ok = false;
            }
            if(ok)break;
        }

        cout << ct << endl;
    }
}

// ARC008 B - 謎のたこ焼きおじさん

/*
    mapを使って、kitの文字をnameの文字数から引いていく。
    name内の文字カウントが全て0以下になったら終了。

    そもそもkit内にnameを作れる文字が入ってない場合-1
*/