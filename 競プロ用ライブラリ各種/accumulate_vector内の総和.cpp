// std::accumulate の使い方
総和を自分で実装している人は多いのでは，accumulate を使えば一発でできる．

#include <numeric>

int main() 
{
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const size_t size = sizeof(list) / sizeof(list[0]);

    int sum = std::accumulate(list, list + size, 0);    // ans = 55
    return 0;
}

