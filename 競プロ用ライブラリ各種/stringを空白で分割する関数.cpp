

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
