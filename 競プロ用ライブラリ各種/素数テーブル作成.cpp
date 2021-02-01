#define MAX 10005

bool pdp[MAX];
vector<int> makeprime(){
	vector<int> ret;
	for (int i = 2; i < MAX; i++)
	{
		if (pdp[i]) continue;
		ret.push_back(i);
		for (int j = i + i; j < MAX; j += i)
		{
			pdp[j] = true;
		}
	}
	return ret;
}




// 素数テーブルを作る