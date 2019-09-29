#include <iostream>
#include <vector>
using namespace std;

int scanForMin(vector<int> vec, int start, int stop) {
  int res = start;
  for (int i = start + 1; i <= stop; i++) {
    if (vec[i] < vec[res]) {
      res = i;
    }
  }
  return res;
}

template <typename T>
void swapInVector(vector<T> &vec, int a, int b) { // &vec 引用传递
  T tmp = vec[a];
  vec[a] = vec[b];
  vec[b] = tmp;
}

// 选择排序算法
vector<int> slectionSort(vector<int> vec) {
  vector<int> res = vec;
  for (int i = 0; i < vec.size(); i++) {
    int minPosition = scanForMin(res, i, vec.size() - 1);
    swapInVector(res, i, minPosition);
  }
  return res;
}

int main() {
  vector<int> v = {6, 4, 8, 2, 9, 5, 1, 0, 3};
  vector<int> sortedV = slectionSort(v);
  for (int i = 0; i < sortedV.size(); i++) {
    cout << sortedV[i];
  }
}
