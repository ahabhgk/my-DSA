#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
using namespace std;

int main() {
  string s1 = "hello";
  string s2 = " world!";
  string str = s1 + s2;
  for (string::iterator it = str.begin(); it != str.end(); it++) cout << *it; // 能读不能写
  cout << "\n---------\n";
  for (int i = 0; i < str.size(); i++) cout << str[i]; // 可读可写
  cout << "\n---------\n";
  cout << (str == s1 + s2);
  cout << boolalpha << (str == s1 + s2) << str.empty();
  cout << "\n---------\n";

  vector<int> v1(5, 1);
  vector<vector<int> > v2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<string> v3 = {"hello", "world", "hah"};
  vector<int> v4(5);
  for (int i = 0; i < v4.size(); i++) {
    v4[i] = 1;
    cout << v4[i];
  }
  cout << "\n---------\n";
  cout << (v4 == v1);
  cout << "\n---------\n";
  v3.push_back("ahab");
  v3.pop_back();
  cout << v3.front() << v3.back();
  cout << "\n---------\n";
  for (vector<string>::reverse_iterator it = v3.rbegin(); it != v3.rend(); it++)
    cout << it->empty(); // (*it).empty()
  cout << "\n---------\n";
  v3.insert(v3.begin() + 2, "yah");
  cout << v3[2];
  cout << "\n---------\n";
  v3.erase(v3.begin() + 2);
  cout << v3[2];
  cout << "\n---------\n";
  v3.clear();

  set<int> s = {1, 2, 3, 4}; // 集合

  list<int> li = {8, 5, 7, 6, 1, 2, 3, 4, 5, 5, 6, 7, 7};
  for (list<int>::iterator it = li.begin(); it != li.end(); it++) cout << *it;
  cout << "\n---------\n";
  li.sort();
  for (list<int>::iterator it = li.begin(); it != li.end(); it++) cout << *it;
  cout << "\n---------\n";

  map<string, int> m1;
  m1["Bob"] = 20;
  m1["Jane"] = 18;
  string name = "Ahab";
  m1[name] = 19;
  cout << m1["Bob"] << m1["Jane"] << m1[name];
  m1.erase(name);
  cout << "\n---------\n";
  for (map<string, int>::iterator it = m1.begin(); it != m1.end(); it++)
    cout << it->first << it->second; // first 是 key，second 是 value
  m1.clear();
  cout << "\n---------\n";
  cout << m1.count(name);

  return 0;
}