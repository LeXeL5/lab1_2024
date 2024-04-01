#include <iostream>
using namespace std;

struct node {
	int value = 0;
	node* prev_node = nullptr;
};

struct stack {
	node* current_node = nullptr;
	int count = 0;
	void push_back(int value) {
			node* new_node = new node();
			new_node->value = value;
			new_node->prev_node = current_node;
			current_node = new_node;
			count++;
	}
	void pop_back() {
		node* prev_node = current_node->prev_node;
		delete current_node;
		current_node = prev_node;
		count--;
	}
	int size() {
		return count;
	}
	void pop_all() {
		int temp = size();
		for (int i = 0; i < temp; i++) {
			pop_back();
		}
	}
};

void main(int argc, char* argv[]) {
	bool interface = true;
	string argument;
	if (argc > 1) { argument = argv[1]; }
	if (argument == "false" || argument == "0") { interface = false; }
	stack list;
	int value;
	if (interface) {
		cout << "Enter sequence of numbers (sequence end sign 0):" << endl;
	}
	while (true) {
		cin >> value;
		if (value != 0) {
			list.push_back(value);
		}
		else {
			break;
		}
	}
	if (interface) {
		cout << "Positive numbers from the sequence in reverse order:" << endl;
	}
	node* output_node = list.current_node;
	for (int i = 0; i < list.size(); i++) {
		if (output_node->value>0) {
			cout << output_node->value << endl;
		}
		output_node = output_node->prev_node;
	}
	list.pop_all();
	if (interface) {
		system("pause");
	}
}