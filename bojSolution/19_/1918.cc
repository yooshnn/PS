#include <bits/stdc++.h>
using namespace std;

/*

# Time complexity for both implementations:

# empty()	O(1)
# top()		O(1)
# push()	O(1)
# pop()		O(1)
# size()	O(1)

*/

struct ArrayStack {
	char* stack;
	int maxSize, sz;

	ArrayStack(int ms) {
		maxSize = ms;
		sz = 0;
		stack = new char[maxSize];
		for (int i = 0; i < maxSize; ++i) stack[i] = 0;
	}

	bool empty() {
		return (sz == 0);
	}
	char top() {
		if (empty()) return -1;
		return stack[sz - 1];
	}
	void push(int data) {
		stack[sz] = data;
		sz++;
	}
	char pop() {
		if (empty()) return -1;
		int ret = stack[sz - 1];
		sz--;
		return ret;
	}
	int size() {
		return sz;
	}
};

struct Node {
	char data;
	Node* next;

	Node(int d) {
		data = d;
		next = nullptr;
	}
};
struct SLLStack {
	Node* head;
	int sz;

	SLLStack() {
		head = nullptr;
		sz = 0;
	}

	bool empty() {
		return (!head);
	}
	char top() {
		if (empty()) return -1;
		return head->data;
	}
	void push(char data) {
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		sz++;
	}
	char pop() {
		if (empty()) return -1;
		Node* tar = head;
		int ret = tar->data;
		head = tar->next;
		delete tar;
		sz--;
		return ret;
	}
	int size() {
		return sz;
	}
};

int prec(char t) {
	if (t == '(') return 0;
	if (t == '+' || t == '-') return 1;
	if (t == '*' || t == '/') return 2;
	return -1;
}

bool hasNo(string s) {
	for (char& c : s) {
		if ('1' <= c && c <= '9') return true;
	}
	return false;
}

int main() {
	//int TEST; cin >> TEST; while (TEST--) {
		SLLStack A;
		string s; cin >> s;
		
		for (char& c : s) {
			if ('A' <= c && c <= 'Z') cout << c;
			else if (c == '(') A.push(c);
			else if (c == '+' || c == '-' || c == '*' || c == '/') {
				while (!A.empty() && prec(c) <= prec(A.top())) cout << A.pop();
				A.push(c);
			}
			else if (c == ')') {
				while (!A.empty() && A.top() != '(') cout << A.pop();
				A.pop();
			}
		}
		while (!A.empty()) cout << A.pop();
		cout << "\n";
	//}

	return 0;
}