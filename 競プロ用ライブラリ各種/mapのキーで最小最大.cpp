C++のstd::mapのキーで最小のキーはbegin()を使用し,最大のキーはrbegin()を使用すればよい.

間違えて最大のキーを取得する際にend()を使ってしまったのでメモ.
endは最終要素の次にアクセスしてしまうので値が不定になる(多分).
未定義動作になるらしいです
map::end - C++ Reference
実際に" It does not point to any element, and thus shall not be dereferenced."とある.

#include <iostream>
#include <map>

int main(){
    std::map<int,int> mp = {
        {2,20},
        {5,50},
        {4,40},
    };

    int minv = mp.begin()->first;
    int maxv = mp.rbegin()->first;
    std::cout << minv << std::endl; // 2
    std::cout << maxv << std::endl; // 5

    int e = mp.end()->first;
    std::cout << e << std::endl;    // 3 (最後の要素の次を指してるので何が入ってるか不明)

}