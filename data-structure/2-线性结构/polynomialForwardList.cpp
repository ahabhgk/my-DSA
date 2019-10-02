// 顺环队列根据 rear 和 front 的距离判断是满（rear == front - 1）是空（rear == front）
// 解决空一个位置：
// 1. size 表示长度
// 2. tag 表示最后一个操作是入队还是出队
// 顺环队列的入队可以用 (rear + 1) % MAXSIZE：
// void addQ(T el) {
//   if ((rear + 1) % MAXSIZE == front) cout << "full!!!";
//   else {
//     rear = (rear + 1) % MAXSIZE;
//     Q[rear] = el;
//   }
// }
// 单向链表移动是单向的，所以单向链表实现的队列 front 不能是链尾；
// 同理，单向链表实现的栈，只能头是 top，尾不能是 top

#include <iostream>
#include <forward_list>
using namespace std;

struct polyNode {
  int coef; // 系数
  int expon; // 指数
};

forward_list<polyNode> polyAdd(forward_list<polyNode> p1, forward_list<polyNode> p2) {
  forward_list<polyNode> res;
  while (!p1.empty() && !p2.empty()) {
    if (p1.front().expon == p2.front().expon) {
      int coef = p1.front().coef + p2.front().coef;
      if (coef != 0) res.push_front(polyNode{coef, p1.front().expon});
      p1.pop_front();
      p2.pop_front();
    } else if (p1.front().expon > p2.front().expon) {
      res.push_front(p1.front());
      p1.pop_front();
    } else if (p1.front().expon < p2.front().expon) {
      res.push_front(p2.front());
      p2.pop_front();
    }
  }
  while (!p1.empty()) {
    res.push_front(p1.front());
    p1.pop_front();
  }
  while (!p2.empty()) {
    res.push_front(p2.front());
    p2.pop_front();
  }
  res.reverse();
  return res;
}

forward_list<polyNode> polyMult(forward_list<polyNode> p1, forward_list<polyNode> p2) {
  forward_list<polyNode> res;
  for (forward_list<polyNode>::iterator it1 = p1.begin(); it1 != p1.end(); it1++) {
    forward_list<polyNode> item;
    for (forward_list<polyNode>::iterator it2 = p2.begin(); it2 != p2.end(); it2++) {
      item.push_front(polyNode{it1->coef * it2->coef, it1->expon + it2->expon});
    }
    item.reverse();
    res = polyAdd(res, item);
  }
  return res;
}

int main() {
  forward_list<polyNode> polynomial1 = {
    polyNode{3, 5},
    polyNode{4, 4},
    polyNode{-1, 3},
    polyNode{2, 1},
    polyNode{-1, 0},
  };
  forward_list<polyNode> polynomial2 = {
    polyNode{2, 4},
    polyNode{1, 3},
    polyNode{-7, 2},
    polyNode{1, 1},
  };

  forward_list<polyNode> pa = polyAdd(polynomial1, polynomial2);
  for (forward_list<polyNode>::iterator it = pa.begin(); it != pa.end(); it++) {
    cout << "coef: " << it->coef << " expon: " << it->expon << endl;
  }

  cout << endl;

  forward_list<polyNode> pm = polyMult(polynomial1, polynomial2);
  for (forward_list<polyNode>::iterator it = pm.begin(); it != pm.end(); it++) {
    cout << "coef: " << it->coef << " expon: " << it->expon << endl;
  }
}
