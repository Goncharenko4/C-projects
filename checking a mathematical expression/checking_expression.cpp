#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <set>

using namespace std;

bool correct_foo_and_trash(string s){
	set<char> whiteList = {
		'+','-','*','/','^',
		'1','2','3','4','5','6','7','8','9','0',
		'(',')',
		'x','y',
		's','c','t','l'
	};

	if ("" == s) { return false; } // str is empty

	char ch;
	int leftBracket = 0;
	int rightBracket = 0;

	for (int i = 0; i < s.length(); i++){
		ch = s.at(i);
		if (whiteList.count(ch) != 0){
			switch (ch) {
			case '(': leftBracket++; break;
			case ')': rightBracket++; break;

			case 'c': { // cos, ctg
				string caseC = s.substr(i + 1, i + 3);
				if ((caseC != "os(") && (caseC != "tg(")) { return false; } // 'c' founded, cos or ctg not founded
				leftBracket++;
				i += 3;
			}break;

			case 's': { // sin
				string caseS = s.substr(i + 1, i + 3);
				if (caseS != "in(") { return false; } // 's' founded, sin not founded
				leftBracket++;
				i += 3;
			}break;

			case 't': { // tg
				string caseT = s.substr(i + 1, i + 2);
				if (caseT != "g(") { return false; } // 't' founded, tg not founded
				leftBracket++;
				i += 2;
			}break;

			case 'l': { // log
				string caseL = s.substr(i + 1, i + 3);
				if (caseL != "og(") { return false; } // 'l' founded, log not founded
				leftBracket++;
				i += 3;
			}break;

			}
		}
		else return false; // string contains extraneous characters
	}

	if (leftBracket != rightBracket) {
		return false; // brackets do not match
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------

string convert(string a)
{
	string str;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != ' ') str.insert(str.end(), a[i]);
	}
	return str;
}

//----------------------------------------------------------------------------------------------------------

// проверка корректности выражения (последовательности чисел и знаков операции)
bool correct_operation_signs(string a)
{
	//bool rightness = true; // булева переменная для фиксирования ошибочного выражения
	set<char> operand = { '+', '*', '/', '-', '^' };
	if ((operand.count(a[0]) != 0 && a[0] != '-') || operand.count(a[a.size() - 1]) != 0) // проверка символа на наличие операнда
	{
		//rightness = false;
		return false;
	}

	else if (operand.count(a[a.size()]) != 0)
	{
		//rightness = false;
		return false;
	}
	/* если всё верно (в начале и в конце стоят не знаки), то выполняется цикл,
	 который прогоняет строку на предмет двух символов подряд. */
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (operand.count(a[i]) != 0 && operand.count(a[i + 1]) != 0)
			{
				//rightness = false;
				return false;
			}
			if ((a[i] == '/') && (a[i + 1] == '0')) // случай деления на 0
			{
				//rightness = false;
				return false;
			}
		}
	}
	return true; // если нигде ошибки не было, то rightness=true
}

//----------------------------------------------------------------------------------------------------------

// проверка корректности выражения (последовательности скруглых скобок)
bool correct_parenthesis(string a)
{
	stack<char> st; // стек в котором хранятся скобки
	set<char> opening_parenthesis = { '(', '{', '[' };
	set<char> closing_parenthesis = { ')', '}', ']' };

	for (int i = 0; i < a.size(); i++)
	{
		if (closing_parenthesis.count(a[i]) != 0)
		{
			if (st.size() != 0)
			{
				if ((a[i] == ')' && st.top() == '(') || (a[i] == '}' && st.top() == '{') || (a[i] == ']' && st.top() == '['))
				{
					st.pop();
				}
				return false;
			}
			return false;
		}
		else if (opening_parenthesis.count(a[i]) != 0)
		{
			st.push(a[i]);
		}
	}

	if (st.size() > 0)
	{
		return false;
	}
    
	return true;
}

//----------------------------------------------------------------------------------------------------------

int main()
{
	//string str; // исходная посл-ть
	//cin >> str; // getline
	//str = "1 -2";
	string test[] = {
		"11", "1-2", "x+1","+-",
		"sin", "cos", "cos()","cos(x)",
		"1--1", "1", "-1-", "-1-="
	};

	string spase = " ";
	cout.setf(ios::left);
	cout.width(10);
	cout << "Exp" << "trash"<< spase << "signs"<< spase << "parenthesis" << endl;

	for (string i : test) { // correct_foo_and_trash(i) && correct_operation_signs(i) && correct_parenthesis(i)
		cout.setf(ios::left);
		cout.width(10);

		cout << i;

		correct_foo_and_trash(i) ? cout << "True " << spase : cout << "False" << spase;
		correct_operation_signs(i) ? cout << "True " << spase : cout << "False" << spase;
		correct_parenthesis(i) ? cout << "True " << spase : cout << "False" << spase;
		
		cout << endl;
	}

	return 0;
}
