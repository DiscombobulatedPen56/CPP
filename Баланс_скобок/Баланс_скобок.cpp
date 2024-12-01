#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

bool check_brackets(string bracket_row) {
    stack<char> brackets;
    for (int i = 0; i < bracket_row.size(); i++) {
        if (bracket_row[i] == '(' || bracket_row[i] == '[' || bracket_row[i] == '{') {
            brackets.push(bracket_row[i]);
        }
        else {
            if (brackets.empty()) {
                return false;
            }
            if (bracket_row[i] == ')') {
                if (brackets.top() != '(') {
                    return false;
                }
                brackets.pop();
            }
            if (bracket_row[i] == ']') {
                if (brackets.top() != '[') {
                    return false;
                }
                brackets.pop();
            }
            if (bracket_row[i] == '}') {
                if (brackets.top() != '{') {
                    return false;
                }
                brackets.pop();
            }
        }
    }
    if (brackets.empty()) {
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    ifstream in("INPUT.TXT");
    ofstream out("OUTPUT.TXT");
    string bracket_row;
    while (!in.eof()) {
        in >> bracket_row;
        out << (check_brackets(bracket_row) ? 0 : 1);
    }
    out.close();
    in.close();
    return 0;
}
