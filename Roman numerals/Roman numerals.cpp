#include <iostream>
#include <map>
#include <fstream>
using namespace std;

string ToRoman(int a) {
	map<int, string, greater<int>> romanNumbers = { {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
		{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
		{10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
		{1, "I"} 
	};
	string Rnum;
	//for (map<int, string>::iterator it = romanNumbers.begin(); it != romanNumbers.end(); ++it) {
		//int a = 0;
	//}
	for (const auto& pair : romanNumbers) {
		while (a - pair.first >= 0) {
			Rnum += pair.second;
			a -= pair.first;
		}
	}

	return Rnum;
}

int FromRoman(string a) {

	map<char, int> romanNumbers;
	romanNumbers['M'] = 1000;
	romanNumbers['D'] = 500;
	romanNumbers['C'] = 100;
	romanNumbers['L'] = 50;
	romanNumbers['X'] = 10;
	romanNumbers['V'] = 5;
	romanNumbers['I'] = 1;
	int total = 0;
	int prevValue = 0;

	for (int i = a.size() - 1; i >= 0; i--) {
		int currentValue = romanNumbers[a[i]];

		if (currentValue < prevValue) {
			total -= currentValue;
		}
		else {
			total += currentValue;
		}

		prevValue = currentValue;
	}

	return total;
}

int main()
{
	ifstream in("p089_roman.txt");
	int a;
	int sum = 0;
	string nline;
	string line;
	while (!in.eof()) {
		in >> line;
		a = FromRoman(line);
		nline = ToRoman(a);
		sum += line.size() - nline.size();
	}
	cout << sum;
}
