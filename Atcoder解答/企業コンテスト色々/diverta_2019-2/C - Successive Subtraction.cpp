#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> A;

void solve() {
    vector<long long> plus, minus;
    for (int i = 0; i < N; ++i) {
        if (A[i] >= 0) plus.push_back(A[i]);
        else minus.push_back(A[i]);
    }
    sort(plus.begin(), plus.end(), greater<long long>());
    sort(minus.begin(), minus.end());
    if (minus.empty()) minus.push_back(plus.back()), plus.pop_back();
    if (plus.empty()) plus.push_back(minus.back()), minus.pop_back();

    vector<pair<long long, long long> > res;
    long long cur = minus[0];
    for (int i = 0; i+1 < plus.size(); ++i) {
        res.push_back({cur, plus[i]});
        cur -= plus[i];
    }
    res.push_back({plus.back(), cur});
    cur = plus.back() - cur;

    for (int i = 1; i < minus.size(); ++i) {
        res.push_back({cur, minus[i]});
        cur -= minus[i];
    }

    cout << cur << endl;
    for (auto p : res) cout << p.first << " " << p.second << endl;
}

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    solve();
}
// 自分で書いたら通らなかったので、
// けんちょんさんのコードまんま