#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
class Item{
public:
	int price;
	int count;
	Item(int p, int c):price(p),count(c) {}
};
bool cmp(Item a, Item b) 
{
	return a.price < b.price;
}

int main()
{
	int N, M, Pi, Ai;
	cin >> N >> M;
	vector<Item> v;
	for (int i = 0; i < M; ++i) {
		cin >> Pi >> Ai;
		v.push_back(Item(Pi, Ai));		
	}
	sort(v.begin(), v.end(), cmp);
	int price = 0, count = 0;
	for (vector<Item>::iterator it = v.begin();
		it != v.end(); ++it) {
		if (it->count + count <= N) {
			price += it->count * it->price;
			count += it->count;
		}
		else {
			price += (N - count) * it->price;
			break;
		}
	}
	cout << price << endl;
	return 0;
}
