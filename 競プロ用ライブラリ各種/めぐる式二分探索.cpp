#include <iostream>
#include <vector>
using namespace std;

// https://qiita.com/drken/items/97e37dd6143e33a64c8c けんちょんさんのqiita参照

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

// index が条件を満たすかどうか
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int Binary_search(int key) {                                    // binary_search()だと、stdのバイナリサーチと被ってやばそうなので、大文字化した。
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    cout << Binary_search(51) << endl; // a[3] = 51 (さっきは 4 を返したが今回は「最小の index」なので 3)
    cout << Binary_search(1) << endl; // a[0] = 1
    cout << Binary_search(910) << endl; // a[9] = 910

    cout << Binary_search(52) << endl; // 6
    cout << Binary_search(0) << endl; // 0
    cout << Binary_search(911) << endl; // 10 (場外)
}

// この二分探索では、与えたkeyに一致するものがあれば、その中で一番小さいindexを返す。
// もし存在しなければ、ソートされた配列に挿入される形でindexを返す。
// index の有無のみ知りたいときは、binary_search(all(x),key) を使おう！(std) 