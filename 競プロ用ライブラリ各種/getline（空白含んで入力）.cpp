

vector<vector<bool>> on;
int N,L;

int ami(int mp){
    int tmp = mp;
    for(int h = L-1;h >= 0;h--){
        if(tmp != 2*N-2 && on[h][tmp+1])tmp += 2;
        else if(tmp != 0 && on[h][tmp-1])tmp -= 2;
    }
    return tmp;
}

int main(){
    cin >> N >> L;
    vector<string> hyou(L);
    on.resize(L,vector<bool>(2*N-1,false));

    string dummy;getline(cin,dummy);      // N L を吸い取った後の空白行を吸ってる。
    
    rep(i,L)getline(cin,hyou[i]);        // あみだくじを作ってる

    string maru;getline(cin,maru);       // o を吸ってる

    rep(i,L)rep(j,2*N-1)if(hyou[i][j] == '-')on[i][j] = true;   // - の位置を検出

    int mp;rep(i,2*N-1)if(maru[i] == 'o')mp = i;    // o の位置検出

    int ans = ami(mp);
    ans = (ans / 2) + 1;
    cout << ans << endl;
    
}   


// ARC006 B - あみだくじ

// 古い問題で、空白を含めた入力を余儀なくされる。
// この時 std::getline を使う。

// 使い方は
// string s;
// getline(cin,s);
// でsに入力が入る。

// 注意する点として、それ以前に入力を受けとった行も空白行として残っているので、それをdummyに吸わせる必要がある。





// stringを" "で分割する関数

vector<string> div(string& s) {
    int start = 0;
    int N = s.length();
    vector<string> ret;
    for (int i = 0; i < N; i++) {
        if (s[i] == ' ') {
            ret.push_back(s.substr(start, i - start));
            start = i + 1;
        } else if (i == N - 1) {
            ret.push_back(s.substr(start, i - start + 1));
        }
    }
    return ret;
}



// 特定の文字が一致しているか、"*"と一致しているかチェックする関数

// aaa == aaa
// aa*ab == aatab
// のように、

bool match(string s, string t) {
    int N = s.length();
    int M = t.length();
    if (N != M) {
        return false;
    }
    for (int i = 0; i < N; i++) {
        if (t[i] != s[i] && t[i] != '*') {
            return false;
        }
    }
    return true;
}