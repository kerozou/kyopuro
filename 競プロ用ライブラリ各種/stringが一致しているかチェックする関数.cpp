// 特定の文字が一致しているか、"*"と一致しているかチェックする関数
// aaa == aaa
// aa*ab == aatab
// のように、

//


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



// "*" の *を変えたら何でも使える。
// 後ろの引数に　*　ありをおく