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
    map<char,int> m;

    for(auto s : S){
        m[s]++;
    }   

    vector<int> od;
    vector<int> ev;
    for(auto t : m){
        int u = t.S;
        if(u % 2 == 0)ev.push_back(u);
        else od.push_back(u);
    }

    sort(all(od));
    sort(all(ev));
    int evn = 0;
    for(auto t : ev)evn += t;
    for(auto t : od)evn += (t-1);


    if(od.empty())cout << S.size() << endl;
    else{
        priority_queue<int,vector<int>,greater<int>> que;
        for(auto t : od)que.push(1);
        while(evn > 0){
            int tmp = que.top();
            que.pop();
            tmp += 2;
            evn -= 2;
            que.push(tmp);
        }
        cout << que.top() << endl;
    }
}

// ARC053 B - 回文分割

/*
    解説では一般化した数式で表していたが、ここではシステム化してみる。
    奇数が0ならば、すべて偶数なのでS.size()になるのは明らか。
    それ以外の場合、奇数をすべて分解して 1 と 偶数 に分ける。
    分けた偶数と元々ある偶数の個数を変数としてもち、それが0になるまで小さい奇数に2を加え続ける。
    priority_queue に分解して発生した 1 を突っ込んでおき、それに evn/2 回 2を加えて戻す操作をすればいい。
    O(N/2)で解ける。
*/