#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

void readNumber(int number[], int &count)
{
	char ch;

	cin.get(ch);
	while (ch != '\n' && count < MAX_SIZE)
	{
		number[count] = ch - '0';
		count++;

		cin.get(ch);
	}
}

void reverseDigits(int number[], int count)
{
	int i = 0;
	int j = count - 1;

	while (i < j)
	{
		int temp = number[i];
		number[i] = number[j];
		number[j] = temp;

		i++;
		j--;
	}
}

bool addNumbers(int number1[], int count1, int number2[], int count2,
		int result[], int &size)
{
	int sum = 0;
	int carry = 0;
	int i = 0;
	int j = 0;

	while (i < count1 && j < count2 && size < MAX_SIZE)
	{
		sum = number1[i] + number2[j] + carry;

		if (sum > 9)
		{
			carry = sum / 10;
			sum = sum % 10;
		}
		else
		{
			carry = 0;
		}

		result[size] = sum;
		size++;
		i++;
		j++;

		if(carry != 0 && size == MAX_SIZE)
			return false;
	}

	while (i < count1 && size < MAX_SIZE)
	{
		sum = number1[i] + carry;

		if (sum > 9)
		{
			carry = sum / 10;
			sum = sum % 10;
		}
		else
		{
			carry = 0;
		}

		result[size] = sum;
		size++;
		i++;

		if(carry != 0 && size == MAX_SIZE)
			return false;
	}

	while (j < count2 && size < MAX_SIZE)
	{
		sum = number2[j] + carry;

		if (sum > 9)
		{
			carry = sum / 10;
			sum = sum % 10;
		}
		else
		{
			carry = 0;
		}

		result[size] = sum;
		size++;
		j++;

		if(carry != 0 && size == MAX_SIZE)
			return false;
	}

	if (carry > 0)
	{
		result[size] = carry;
		size++;
	}

	return true;
}

void printNumber(int number[], int count)
{
	for (int i = count - 1; i >= 0; i--)
	{
		cout << number[i];
	}
}

int main()
{
	int number1[MAX_SIZE];
	int number2[MAX_SIZE];
	int result[MAX_SIZE];
	int count1 = 0;
	int count2 = 0;
	int size = 0;

	cout << "Enter the first number:  ";
	readNumber(number1, count1);

	cout << "Enter the second number: ";
	readNumber(number2, count2);

	reverseDigits(number1, count1);
	reverseDigits(number2, count2);

	bool success = addNumbers(number1, count1, number2, count2, result, size);

	if(success)
	{
		cout << endl;
		printNumber(number1, count1);
		cout << " + ";
		printNumber(number2, count2);
		cout << " = ";
		printNumber(result, size);
		cout << endl;
	}
	else
	{
		cout << "integer overflow" << endl;
	}

	return 0;
}
