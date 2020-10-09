#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int fromBase, toBase;
string number, result;
vector<int> pureNum;
__int64 decimalNum;

//convert string representations of integers into any base between 2 and 62
void converter();

//convert an integer from any base to decimal
void decimalConvert();

//convert an integer from deciaml to any base
void baseConvert();

//convert string representations of integers into integer
void pureConvert();

//convert a char to a int
int charConvert(const char word);

//convert a int to a char
char intConvert(const __int64 num);

int main()
{
	cout << "Number which you would like to convert:";
	cin >> number;
	cout << "From which base you want to convert:";
	cin >> fromBase;
	cout << "To which base you want to convert:";
	cin >> toBase;
	converter();
	cout << "Here is the result:" << result << endl;
}

void converter()
{
	decimalConvert();
	baseConvert();
}

void decimalConvert()
{
	pureConvert();
	decimalNum = 0;
	for (int i = 0; i < pureNum.size(); i++)
		decimalNum += pureNum[i] * pow(fromBase, i);
}

void baseConvert()
{
	for (; decimalNum != 0; decimalNum /= toBase)
		result.push_back(intConvert(decimalNum % toBase));
	reverse(result.begin(), result.end());
}

void pureConvert()
{
	reverse(number.begin(), number.end());
	pureNum.resize(number.size());
	for (int i = 0; i < number.size(); i++)
		pureNum[i] = charConvert(number[i]);
}

int charConvert(const char word)
{
	if ('0' <= word && word <= '9')
		return word - '0';
	else if ('a' <= word && word <= 'z')
		return 10 + (word - 'a');
	else
		return 36 + (word - 'A');
}

char intConvert(const __int64 num)
{
	if (0 <= num && num <= 9)
		return num + '0';
	else if (10 <= num && num <= 35)
		return num - 10 + 'a';
	else
		return num - 36 + 'A';
}