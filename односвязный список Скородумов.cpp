#include <iostream>

using namespace std;

struct Node {

	int flag = 0;
	Node* current_ptr;
	string val;
	Node* next;
	Node() : val("no value"), next(nullptr) {}

	void empty(Node check_Node) {
		if (check_Node.val == "no value") {
			cout << "list is empty" << endl;
		}
		else {
			cout << "list is not empty" << endl;
		}

	}
	void add(string new_value) {
		if (flag == 0) {
			val = new_value;
			flag = 1;
		}
		else if(flag == 1) {
			Node* ptr = new Node;
			ptr->val = new_value;
			ptr->flag += 1;
			flag += 1;
			next = ptr;
			current_ptr = ptr;
		}
		else{
			Node* ptr = new Node;
			current_ptr->next = ptr;
			ptr->val = new_value;
			ptr->flag += 1;
			flag += 1;
			current_ptr = ptr;
		}
	}
	void size(Node list_lenght) {
		cout << flag << endl;
	}
	void print(Node list) {
		if (flag == 0) {
			cout << "list is empty" << endl;
		}
		else {
			cout << val << " ";
			Node* ptr = next;
			while (ptr != nullptr) {
				cout << ptr->val << " ";
				ptr = ptr->next;

			}
			cout << endl;
		}
	}
	void find(string element) {
		if (flag == 0) {
			cout << "error: list is empty" << endl;
		}
		else if (val == element) {
			cout << "this is first elemenent" << endl;
		}
		else {
			Node* ptr = next;
			while (ptr != nullptr) {
				if (ptr->next == nullptr && ptr->val != element) {
					cout << "this element is not in the list" << endl;
				}
				if (ptr->val == element) {
					cout << ptr << endl;
					break;
				}
				ptr = ptr->next;
			}
		}
	}
	void remove(string element) {
		Node* p;
		int f = 1;
		if (flag == 0) {
			cout << "error: list is empty" << endl;
		}
		if (val == element && flag != 1) {
			val = next->val;
			p = next;
			next = next->next;
			delete p;
			flag -= 1;
		}
		else if (val == element && flag == 1) {
			val = "no value";
			next = nullptr;
			flag = 0;
		}
		else {
			Node* p = next;
			Node* ptr = next;
			while (ptr != nullptr) {
				if (ptr->next == nullptr && ptr->val != element) {
					cout << "this element is not in the list" << endl;
					break;
				}
				if (f == 1 && ptr->val == element) {
					next = ptr->next;
					delete ptr;
					flag -= 1;
					break;
				}
				if (ptr->val == element) {
					p->next = ptr->next;
					delete ptr;
					flag -= 1;
					break;
				}
				f += 1;
				p = ptr;
				ptr = ptr->next;
			}
		}
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	Node n;

	cout << "проверка на empty не пустого списка" << endl;
	n.add("1");
	cout << "список: ";
	n.print(n);
	n.empty(n);
	cout << endl;

	//------
	n.remove("1");
	//------

	cout << "проверка на empty пустого списка" << endl;
	n.empty(n);
	cout << endl;
	//------

	cout << "проверка на size" << endl;
	n.add("1");
	n.add("2");
	n.add("3");
	cout << "список: ";
	n.print(n);
	cout << "size: ";
	n.size(n);
	cout << endl;

	//-------
	n.remove("1");
	n.remove("2");
	n.remove("3");
	//-------

	cout << "проверка на find" << endl;
	n.add("123");
	n.add("666");
	n.add("777");
	n.add("524");
	cout << "список: ";
	n.print(n);
	cout << "ищем ячейку куда записано 777" << endl << "вывод: ";
	n.find("777");
	cout << endl;
	//-------

	cout << "проверка на add" << endl;
	cout << "список: ";
	n.print(n);
	cout << "добавим 000:" << endl;
	n.add("000");
	cout << "список: ";
	n.print(n);
	cout << endl;
	//-------

	cout << "проверка на remove" << endl;
	cout << "список: ";
	n.print(n);
	cout << "удалим 777:" << endl;
	n.remove("777");
	cout << "список: ";
	n.print(n);
	return 0;
}