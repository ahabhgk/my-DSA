#include <iostream>
#include <vector>
using namespace std;

struct HaffNode {
	int parent;
	int lchild;
	int rchild;
	int weight;
};

void select(vector<int>& arr, int& min1, int& min2) {
	min1 = arr[0] < arr[1] ? 0 : 1;
	min2 = arr[0] < arr[1] ? 1 : 0;
	for (int i = 2; i < arr.size(); i++) {
		if (arr[i] < arr[min1]) {
			int tmp = min1;
			min1 = i;
			min2 = tmp;
		} else if (arr[i] < arr[min2]) {
			min2 = i;
		}
	}
	arr[min1] = 100000;
	arr[min2] = 100000;
}

vector<HaffNode> Haffman(vector<int> weightList) {
	int len = weightList.size();
	vector<HaffNode> HaffList(2 * len - 1);
	vector<int> selectFrom(2 * len - 1);
	for (int i = 0; i < selectFrom.size(); i++) selectFrom[i] = 100000;
	for (int i = 0; i < HaffList.size(); i++) {
		HaffNode node;
		node.lchild = node.rchild = node.parent = -1;
		HaffList[i] = node;
	}
	for (int i = 0; i < len; i++) {
		cout << weightList[i] << endl;
		HaffList[i].weight = selectFrom[i] = weightList[i];
	}

	for (int i = len; i < 2 * len - 1; i++) {
		int i1, i2;
		select(selectFrom, i1, i2);
		cout << "i1: " << i1 << "   i2: " << i2 << endl;

		HaffNode node;
		int w = HaffList[i1].weight + HaffList[i2].weight;
		node.weight = w;
		node.rchild = i1;
		node.lchild = i2;
		HaffList[i1].parent = HaffList[i2].parent = i;

		selectFrom[i] = w;
    cout << "node weight: " << node.weight << endl;
		HaffList[i] = node;
	}

	return HaffList;
}

int main() {
	vector<HaffNode> list = Haffman(vector<int> {2, 4, 5, 3});

	for (int i = 0; i < list.size(); i++) cout << list[i].weight << endl;
}