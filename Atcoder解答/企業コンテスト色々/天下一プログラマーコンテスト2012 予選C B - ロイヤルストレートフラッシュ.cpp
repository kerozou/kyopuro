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
    vector<string> yama;
    map<string,int> m;
    char mark;

    while(true){
        char c;
        string s;

        cin >> c;   // mark
        s += c;

        cin >> c;   // num
        if(c == '1'){
            cin >> c;   // 0消し
            s += "10";
        }
        else{
            s += c;
        }

        yama.push_back(s);
        m[s] = 1;

        if(m["S10"] && m["SJ"] && m["SQ"] && m["SK"] && m["SA"]){
            mark = 'S';
            break;
        }
        if(m["H10"] && m["HJ"] && m["HQ"] && m["HK"] && m["HA"]){
            mark = 'H';
            break;
        }
        if(m["D10"] && m["DJ"] && m["DQ"] && m["DK"] && m["DA"]){
            mark = 'D';
            break;
        }
        if(m["C10"] && m["CJ"] && m["CQ"] && m["CK"] && m["CA"]){
            mark = 'C';
            break;
        }
    }

    for(auto t : yama){
        char c = t[0];
        if(c == mark)if(t[1] == '1' || t[1] == 'J' || t[1] == 'Q' || t[1] == 'K' || t[1] == 'A')continue;
        cout << t;
    }

    if(yama.size() == 5)cout << 0;

    cout << endl;
}


// 	天下一プログラマーコンテスト2012 予選C B - ロイヤルストレートフラッシュ

/*
    ただひたすら綺麗に実装する必要がある。
    これは解説ACだが、この解法の良いところはいろいろある。

    while で回しながら、一文字ずつ入力を受け取るところがいい。
    そして、stringに足していき、山札の配列に加えていくことでそのまま答えとして出力できる。
    余計な処理がほとんどないところが綺麗。
    こういう実装重たい問題は綺麗につくってかないとWA出た時に終わる。
*/