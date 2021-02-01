// max_element() , min_element()　の使用例

// min_element, max_element は，最小値，最大値のイテレータを返してくれる関数．



std::vector<int> vec(100);
for (size_t i = 0; i < vec.size(); ++i) {
    vec[i] = i;
}

std::random_shuffle (vec.begin(), vec.end());

// std::*_element は，イテレーターを返すので '*' で値を取得する
int min = *std::min_element(vec.begin(), vec.end());
int max = *std::max_element(vec.begin(), vec.end());



// とこのようにイテレーターを取得するすることができる．
// ここで，最大値と最小値の添え字を取得したい場合も多いその場合は，std::distance と組み合わせればうまいこと取得できる．


std::vector<int>::iterator minIt = *std::min_element(vec.begin(), vec.end());
std::vector<int>::iterator maxIt = *std::max_element(vec.begin(), vec.end());

// distance で vec の先頭イテレーターと minIt, maxIt との距離を取得する．
// インデックスを取得したいときは，vec の先頭イテレーターを指定する必要がある．
// 例えば，vec.begin() + 1 とか指定すると答えは変わる．
size_t minIndex = std::distance(vec.begin(), minIt);
size_t maxIndex = std::distance(vec.begin(), maxIt);


