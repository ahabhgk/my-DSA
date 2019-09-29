#include <iostream>
#include <vector>
using namespace std;

int maxSubSeqSumN2(vector<int> arr) {
  int maxSum = 0;
  for (int i = 0; i < arr.size(); i++) {
    int thisSum = 0;
    for (int j = i; j < arr.size(); j++) {
      thisSum += arr[j];
      if (thisSum > maxSum) {
        maxSum = thisSum;
      }
    }
  }
  return maxSum;
}

// “分而治之”
// 求时间复杂度：
// T(N) = 2T(N / 2) + c * N
// T(N / 2) = 2T(N / 2 ^ 2) + c * N / 2
// T(N) = 2[2T(N / 2 ^ 2) + c * N / 2] + c * N
//  = 2 ^ k * T(N / 2 ^ k) + k * c * N
// 当 2 ^ k = N 时:
// k = logN
// T(N) = 2 ^ k + logN * c * N
//  = O(NlogN)
// 
// 递归的深度是 logN，又每一层的空间复杂度是 N，所以算法总空间复杂度为 NlogN
int maxSubSeqSumNLOGN(vector<int> arr, int start, int stop) {
  if (start == stop) return arr[start] > 0 ? arr[start] : 0;

  int mid = (start + stop) / 2;
  // 左边最大子序列和
  int maxLeftSum = maxSubSeqSumNLOGN(arr, start, mid);
  // 右边最大子序列和
  int maxRightSum = maxSubSeqSumNLOGN(arr, mid + 1, stop);

  // 带上 mid 的左边最大子序列和
  int maxLeftBorderSum = 0;
  int leftBorderSum = 0;
  for (int i = mid; i >= start; i--) {
    leftBorderSum += arr[i];
    if (leftBorderSum > maxLeftBorderSum) maxLeftBorderSum = leftBorderSum;
  }

  // 带上 mid 的右边最大子序列和
  int maxRightBorderSum = 0;
  int rightBoederSum = 0;
  for (int i = mid + 1; i <= stop; i++) {
    rightBoederSum += arr[i];
    if (rightBoederSum > maxRightBorderSum) maxRightBorderSum = rightBoederSum;
  }

  // 求出中间最大子序列和
  int maxBorderSum = maxLeftBorderSum + maxRightBorderSum;
  // 比较左边、右边、中间的最大子序列和，得出总最大子序列和
  int max = maxLeftSum > maxRightSum 
    ? maxLeftSum > maxBorderSum
    ? maxLeftSum
    : maxBorderSum
    : maxRightSum > maxBorderSum
    ? maxRightSum
    : maxBorderSum;
  return max;
}

// “在线处理”
// 指每输入一个数据就进行即时处理，在任何一个地方终止输入，算法都能正确给出当前的解
// 后面的比较找出 maxSum
// 前面的只需要抛弃小于 0 的部分，因为小于 0 时只能使后面的部分减小
int maxSubSeqSumN(vector<int> arr) {
  int maxSum = 0;
  int thisSum = 0;
  for (int i = 0; i < arr.size(); i++) {
    thisSum += arr[i];
    if (thisSum > maxSum) maxSum = thisSum;
    if (thisSum < 0) thisSum = 0;
  }
  return maxSum;
}

int main() {
  vector<int> arr = {5, 6, 9, -4, 2, 4, 0, 1, -5, -2, 6};
  cout << "O(n^2): " << maxSubSeqSumN2(arr) << endl;
  cout << "O(nlogn): " << maxSubSeqSumNLOGN(arr, 0, arr.size() - 1) << endl;
  cout << "O(n): " << maxSubSeqSumN(arr) << endl;
}