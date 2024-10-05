#include <iostream>
#include <stack>
#include <map>
using namespace std;
namespace {
	enum MathOperations {
		SUM,
		SUB,
		MUL,
		DIV,
	};
	enum brackets {
		START,
		END,
	};
	const map<brackets, char>BRACKETS_IN_EXPO{
		{brackets::START,'('},
		{brackets::END,')'},

	};
	const map<MathOperations, char>MATH_OPERATIONS_TO_CHAR_TABLE{
		{MathOperations::SUM,'+'},
		{MathOperations::SUB,'-'},
		{MathOperations::MUL,'*'},
		{MathOperations::DIV,'/'},
	};
}
struct Leksema
{
	char type; 
	double value;  
};
bool Maths(stack<Leksema>& Stack_n, stack<Leksema>& Stack_o, Leksema& item) {
	double a, b, c;
	a = Stack_n.top().value;
	Stack_n.pop();
	switch (Stack_o.top().type) {
	case'+':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a + b;
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;
	case '-':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = b - a;
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;
	case '*':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a * b;
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;
	case '/':
		b = Stack_n.top().value;
		if (a == 0) {
			cerr << "\nНа 0 делить нельзя!\n";
			return false;
		}
		else {
			Stack_n.pop();
			c = (b / a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}
	default:
		cerr << "Ошибка!\n";
		return false;
		break;
	}
	return true;
}
int getRang(char Ch) {
	if (Ch == '+' || Ch == '-') {
		return 1;
	}
	if (Ch == '*' || Ch == '/') {
		return 2;
	}
	else {
		return 0;
	}
}
int main() {
	setlocale(LC_ALL, "RU");
	char Ch;
	double value;
	bool flag = 1;     
	stack<Leksema> Stack_n;
	stack<Leksema> Stack_o;
	Leksema item;
	cout << "Введите выражение: ";
	while (true) {
		Ch = cin.peek();
		if (Ch == '\n')break;
		if (Ch == ' ') {
			cin.ignore();
			continue;
		}
		if (Ch >= '0' && Ch <= '9' || Ch == '-' && flag==1) {
			cin >> value;
			item.type = '0';
			item.value = value;
			Stack_n.push(item);
			flag = 0;
			continue;
		}
		if (Ch == '+' || Ch == '-' && flag == 0 || Ch == '*' || Ch == '/') {
			if (Stack_o.size() == 0) {
				item.type = Ch;
				item.value = 0;
				Stack_o.push(item);
				cin.ignore();
				continue;
			}
			if (Stack_o.size() != 0 && getRang(Ch) > getRang(Stack_o.top().type)) {
				item.type = Ch;
				item.value = 0;
				Stack_o.push(item);
				cin.ignore();
				continue;
			}
			if (Stack_o.size() != 0 && getRang(Ch) <= getRang(Stack_o.top().type)) {
				if (Maths(Stack_n, Stack_o, item) == false) {
					system("pause");
					return 0;
				}
				continue;
			}
		}
		if (Ch == '(') {
			item.type = Ch;
			item.value = 0;
			Stack_o.push(item);
			cin.ignore();
			continue;
		}
		if (Ch == ')') {
			while (Stack_o.top().type != '(') {
				if (Maths(Stack_n, Stack_o, item) == false) {
					system("pause");
					return 0;
				}
				else {
					continue;
				}
			}
			Stack_o.pop();
			cin.ignore();
			continue;
		}
		else {
			cout << "\nНеверно введено выражение!\n";
			system("pause");
			return 0;
		}
	}
	while (Stack_o.size() != 0) {
		if (Maths(Stack_n, Stack_o, item) == false) {
			system("pause");
			return 0;
		}
		else {
			continue;
		}
	}
	cout << "Ответ: " << Stack_n.top().value;
	return 0;
}