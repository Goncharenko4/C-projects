#include <cmath>
#include <iostream>
#include <set>
#include <stack>
#include <string>

using namespace std;

bool correct_foo_and_trash(string s) {
    set<char> whiteList = {
        '+','-','*','/','^',
        '1','2','3','4','5','6','7','8','9','0',
        '(',')',
        'x','y',
        's','c','t','l'
    };
    
    // If the string is empty:
    if ("" == s) {
        return false;
    }
    
    char ch;
    int leftBracket = 0;
    int rightBracket = 0;
    
    for (int i = 0; i < s.length(); i++) {
        ch = s.at(i);
        if (whiteList.count(ch) != 0) {
            switch (ch) {
                case '(': {
                    leftBracket++;
                    break;
                }
                case ')': {
                    rightBracket++;
                    break;
                }
                // This is presumably: cos(), ctg()
                case 'c': {
                    string caseC = s.substr(i + 1, i + 3);
                    
                    // No functions found:
                    if ((caseC != "os(") && (caseC != "tg(")) {
                        return false;
                    }
                    leftBracket++;
                    i += 3;
                    break;
                }
                // This is presumably sin()
                case 's': {
                    string caseS = s.substr(i + 1, i + 3);
                    
                    // No functions found:
                    if (caseS != "in(") {
                        return false;
                    }
                    leftBracket++;
                    i += 3;
                    break;
                }
                // This is presumably tg()
                case 't': {
                    string caseT = s.substr(i + 1, i + 2);
                    
                    // No functions found:
                    if (caseT != "g(") {
                        return false;
                    }
                    leftBracket++;
                    i += 2;
                    break;
                }
                // This is presumably log()
                case 'l': {
                    string caseL = s.substr(i + 1, i + 3);
                    
                    // No functions found:
                    if (caseL != "og(") {
                        return false;
                    }
                    leftBracket++;
                    i += 3;
                    break;
                }
            }
        }
        // The string contains extraneous characters:
        else return false;
    }
    
    if (leftBracket != rightBracket) {
        return false; // brackets don't match
    }
    
    return true;
}

string convert(string a) {
    string str;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != ' ') str.insert(str.end(), a[i]);
    }
    return str;
}

/*
    Checking the correctness of the expression:
    (sequence of numbers and signs of the operation)
*/
bool correct_operation_signs(string a) {
    set<char> operand = { '+', '*', '/', '-', '^' };
    
    // Checking a character for an operand:
    if ((operand.count(a[0]) != 0 && a[0] != '-') || operand.count(a[a.size() - 1]) != 0) {
        return false;
    } else if(operand.count(a[a.size()]) != 0) {
        return false;
    } else {
        /*
            If everything is correct (there are no signs
            at the beginning and end), then a loop is executed
            that checks the string for two consecutive characters
         */
        for (int i = 0; i < a.size(); i++) {
            if ((operand.count(a[i]) != 0) && (operand.count(a[i + 1]) != 0)) {
                return false;
            }
            
            // If division by 0:
            if ((a[i] == '/') && (a[i + 1] == '0')) {
                return false;
            }
        }
    }
    return true;
}

/*
    Checking the correctness of the expression (a sequence of parentheses):
*/
bool correct_parenthesis(string a) {
    stack<char> st; // stack where brackets are stored
    set<char> opening_parenthesis = { '(', '{', '[' };
    set<char> closing_parenthesis = { ')', '}', ']' };
    
    for (int i = 0; i < a.size(); i++) {
        if (closing_parenthesis.count(a[i]) != 0) {
            if (st.size() != 0) {
                if ((a[i] == ')' && st.top() == '(') || (a[i] == '}' && st.top() == '{') || (a[i] == ']' && st.top() == '[')) {
                    st.pop();
                }
                return false;
            }
            return false;
        } else if (opening_parenthesis.count(a[i]) != 0) {
            st.push(a[i]);
        }
    }
    
    if (st.size() > 0) {
        return false;
    }
    return true;
}

int main() {
    string test[] = {
		"11", "1-2", "x+1","+-",
		"sin", "cos", "cos()","cos(x)",
		"1--1", "1", "-1-", "-1-="
    };
    
    string spase = " ";
    cout.setf(ios::left);
    cout.width(10);
    cout << "Exp" << "trash" << spase << "signs"<< spase << "parenthesis" << endl;
    
    for (string i : test) {
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
