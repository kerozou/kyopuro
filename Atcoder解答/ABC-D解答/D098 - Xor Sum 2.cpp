#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    /* 入力受け取り */
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    /* しゃくとり法 */
    long long res = 0;
    int right = 0;
    int sum = 0; // AND 和
    for (int left = 0; left < n; ++left) {
        while (right < n && (sum ^ a[right]) == (sum + a[right])) {
            sum += a[right];
            ++right;
        }
        res += right - left;
        if (left == right) ++right;
        else {
            sum -= a[left]; // a[left] を削除 (sum ^= a[left] でも OK)
        }
    }
    
    cout << res << endl;
}

// ABC098 D - Xor Sum 2

// XORの扱いについて、2進数の足し算の繰り上がりが影響するという問題。
// 繰り上がりによってある区間で条件を満たすときの部分列が条件を満たすということを証明しておく必要がある。

// https://kira924age.hatenadiary.com/entry/2019/03/29/140724
// これが分かりやすい

// これが証明できると、(l,r) の部分列の数をf(l)とするとf(l)は広義単調増加になるので、尺取り法で求まる。