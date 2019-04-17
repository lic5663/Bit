//vector////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <vector>
//using namespace std;
//
//template <typename T>
//ostream& operator << (ostream& os, vector<T>& v) {
// os << "<";
// for (int i = 0; i < v.size(); i++)
//  os << v[i] << " ";
// os << ">";
// return os;
//}
//void main()
//{
// vector<int> vec(10);
// for (int i = 0; i < vec.size(); i++)
//  vec[i] = rand() % 100;
// cout << "Before: " << vec << endl;
//
// 
// for (vector<int>::iterator it = vec.begin(); it != vec.end(); ) {
//  if (*it % 2 == 0) 
//   it = vec.erase(it);
//  else ++it;  
// }
// cout << "After : " << vec << endl;
//}


//list////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <list>
//#include<string>
//using namespace std;
//
//template <typename T>
//void printContainer(T& v, string msg= "container") {
// cout << msg << "<";
// for (auto it = v.begin(); it != v.end(); ++it)
//  cout << *it << " ";
// cout << ">\n";
//}
//
//int main()
//{
// list<int> sortList;
// for (int i = 0; i < 10; i++) {
//  int val = rand() % 100;
//  auto curr = sortList.begin();
//  for (; curr != sortList.end(); ++curr)
//   if (val >= *curr) break;
//  sortList.insert(curr, val);
// }
// printContainer(sortList, "Sorted List: ");
// return 0;
//}


////deque////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <deque>
//using namespace std;
//
//void main()
//{
// deque<int> dq;
// for (int i = 0; i < 10; i++) {
//  int val = rand() % 100 + 1;
//  if (val % 2 == 0) dq.push_back(val);
//  else dq.push_front(val);
// }
// cout << "deque(�ε���): ";
// for (int i = 0; i < dq.size(); i++)
//  cout << dq[i] << " ";
//
// cout << endl << "deque(�ݺ���): ";
// for (auto curr = dq.begin(); curr != dq.end(); ++curr)
//  cout << *curr << " ";
// cout << endl;
//}


////stack////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//void main()
//{
// stack<char> st;
// string line;
// cout << "������ �Է��ϼ��� : ";
// getline(cin, line);
// for (int i = 0; i < line.length(); i++)
//  st.push(line[i]);
// cout << "�Է� = " << line << endl;
// cout << "��� = ";
// while (!st.empty()) {
//  cout << st.top();
//  st.pop();
// }
// cout << endl;
//}

////queue////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <queue>
//using namespace std;
//
//void main()
//{
// queue<int> que;
// int count;
// cout << "�Ǻ���ġ ���� ������ �Է��ϼ���: ";
// cin >> count;
//
// cout << "�Ǻ���ġ ���� = ";
// que.push(0);
// que.push(1);
// for (int i = 0; i < count; i++) {
//  int fibo = que.front();
//  que.pop();
//  cout << fibo << " ";
//  que.push(fibo + que.front());
// }
// cout << endl;
//}
////priority_queue////////////////////////////////////////////////////////////////////
//
//
////set////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <set>
//using namespace std;
//
//
//template <typename T>
//void printContainer(T& v, char* msg = "container") {
// cout << msg << "<";
// for (T::iterator it = v.begin(); it != v.end(); ++it)
//  cout << *it << " ";
// cout << ">\n";
//}
//
//void main()
//{
// set<int> simple;
// multiset<int> multiple;
//
// for (int i = 10; i < 15; i++)
//  simple.insert(i);
//
// multiple.insert(simple.begin(), simple.end());
// for (int i = 13; i < 18; i++)
//  multiple.insert(i);
//
// printContainer(simple, "Simple   Set = ");
// printContainer(multiple, "Multiple Set = ");
// cout << "simple.count(14)   = " << simple.count(14) << endl;
// cout << "multiple.count(14) = " << multiple.count(14) << endl;
//}
//
////map////////////////////////////////////////////////////////////////////

//#include <iostream>
//#include <iomanip>
//#include <map>
//#include <string>
//using namespace std;
//
//void main()
//{
// map<string, string> myDic;
// map<string, string>::iterator dp;
// myDic["hello"] = "�ȳ��ϼ���?";
// myDic["world"] = "�Ƹ��ٿ� ����";
// myDic["data"] = "�ڷ�";
// myDic["structure"] = "����";
// myDic["list"] = "����Ʈ";
//
// for (dp = myDic.begin(); dp != myDic.end(); ++dp)
//  cout << setw(12) << dp->first << " == " + dp->second + "\n";
//
// dp = myDic.find("structure");
// if (dp == myDic.end())
//  cout << "[�˻� ����] ã�� �ܾ �����ϴ�.\n";
// else cout << "[�˻� ����] " << dp->first + " " + dp->second << endl;
//
// if (myDic.find("C++") == myDic.end())
//  cout << "[�˻� ����] ã�� �ܾ �����ϴ�.\n";
//
// myDic.erase("structure");
//
// for (dp = myDic.begin(); dp != myDic.end(); ++dp)
//  cout << setw(12) << dp->first << " == " + dp->second + "\n";
//}