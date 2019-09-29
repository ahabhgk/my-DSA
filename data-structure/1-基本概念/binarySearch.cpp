/**
 * 给定N个从小到大排好序的整数序列List[]，以及某待查找整数X，
 * 我们的目标是找到X在List中的下标。
 * 即若有List[i]=X，则返回i；否则返回-1表示没有找到。
 * 二分法是先找到序列的中点List[M]，与X进行比较，若相等则返回中点下标；
 * 否则，若List[M]>X，则在左边的子系列中查找X；
 * 若List[M]<X，则在右边的子系列中查找X。
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * 当编译器检测到一个函数调用是尾递归的时候，
 * 它就覆盖当前的活动记录而不是在栈中去创建一个新的。
 * 编译器可以做到这点，因为递归调用是当前活跃期内最后一条待执行的语句，
 * 于是当这个调用返回时栈帧中并没有其他事情可做，
 * 因此也就没有保存栈帧的必要了。
 * 通过覆盖当前的栈帧而不是在其之上重新添加一个，
 * 这样所使用的栈空间就大大缩减了，这使得实际的运行效率会变得更高。
 */
template <typename T>
int binarySearch_tailRecursive(vector<T> vec, int start, int stop, int mid, T x) {
  if (start > stop) return -1;
  if (x == vec[mid]) return mid;
  if (x < vec[mid]) return binarySearch_tailRecursive(vec, start, mid - 1, (start + mid - 1) / 2, x);
  if (x > vec[mid]) return binarySearch_tailRecursive(vec, mid + 1, stop, (mid + 1 + stop) / 2, x);
  return -1;
}

template <typename T>
int binarySearch_loop(vector<T> vec, int x) {
  int start = 0;
  int stop = vec.size();
  int mid = (start + stop) / 2;
  while (vec[mid] != x) {
    if (start >= stop) return -1;
    if (x > mid) {
      start = mid + 1;
      mid = (start + stop) / 2;
    }
    if (x < mid) {
      stop = mid - 1;
      mid = (start + stop) / 2;
    }
  }
  return mid;
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << binarySearch_tailRecursive(v, 0, v.size(), (0 + v.size()) / 2, 1) << endl;
  cout << binarySearch_loop(v, 2) << endl;

  return 0;
}
