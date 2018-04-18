#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

class fraction
{
	int numerator, denominator, gcd;

public:

	int divisor(int num, int den)
	{
		if (num == 0)
		{
			return den;
		}

		return divisor(den%num, num);
	}

	void add(int val_num, int val_den)
	{
		numerator = val_num;
		denominator = val_den;
	}

	fraction operator+(fraction f_addition)
	{
		fraction fra;
		fra.numerator = numerator*f_addition.denominator + denominator*f_addition.numerator;
		fra.denominator = denominator*f_addition.denominator;
		if (numerator != 0)
		{
			gcd = divisor(fra.numerator, fra.denominator);
			fra.numerator = fra.numerator / gcd;
			fra.denominator = fra.denominator / gcd;
		}
		return fra;
	}

	void subtract(int val1_num, int val1_den, int val2_num, int val2_den)
	{
		numerator = val1_num*val2_den - val2_num*val1_den;
		denominator = val1_den*val2_den;
		if (numerator != 0)
		{
			gcd = divisor(numerator, denominator);
			numerator = numerator / gcd;
			denominator = denominator / gcd;
		}
	}

	void multiply(int, int, int, int);
	void divide(int, int, int, int);

	friend ostream & operator<< (ostream &os, fraction &fr) 
	{
		os << endl << "Value: numerator / denominator = " << fr.numerator << "/" << fr.denominator;
		return os;
	}

	/*
	void display()
	{
		if (numerator != 0)
		{
			gcd = divisor(numerator, denominator);
			cout << endl << "Value: numerator / denominator = " << numerator / gcd << "/" << denominator / gcd;
		}
		else
			cout << endl << "Value: numerator / denominator = " << numerator << "/" << denominator;
	}
	*/
};

void fraction::multiply(int val1_num, int val1_den, int val2_num, int val2_den)
{
	numerator = val1_num * val2_num;
	denominator = val1_den * val2_den;
	if (numerator != 0)
	{
		gcd = divisor(numerator, denominator);
		numerator = numerator / gcd;
		denominator = denominator / gcd;
	}
}

void fraction::divide(int val1_num, int val1_den, int val2_num, int val2_den)
{
	numerator = val1_num * val2_den;
	denominator = val1_den * val2_num;
	if (numerator != 0)
	{
		gcd = divisor(numerator, denominator);
		numerator = numerator / gcd;
		denominator = denominator / gcd;
	}
}

int main()
{
	fraction f[2];
	fraction f_add;
	fraction fractions;
	int num;
	int flag = 1;
	int val_num_main[2];
	int val_den_main[2];

	cout << setw(40) << "***WELCOME***";

	while(flag)
	{
		cout << endl << endl << "Press the number corresponding to the operation name to perform the desirable operation." << endl;
		cout << "1. Addition" << endl << "2. Subtraction" << endl << "3. Multiplication" << endl << "4. Division" << endl << "5. Exit" << endl;
		cin >> num;
		
		switch (num) 
		{
		case 1: cout << endl << "Enter the numerators and denominators of both the fractions you want to add respectively." << endl;
			for (int i = 0; i < 2; i++)
			{
				cin >> val_num_main[i] >> val_den_main[i]; 
				cout << endl;
				if (val_den_main[i] == 0)
				{
					cout << "Denominator can not be zero. Re-enter another value of denominator." << endl;
					cin >> val_den_main[i];

					if (i != 1 && i<2 && i>-1)
					{
						cout << endl << "Continue entering the values of second fraction." << endl << endl;
					}
				}
				f[i].add(val_num_main[i], val_den_main[i]);
			}
			//f_add = f[0].operator+(f[1]);
			f_add = f[0] + f[1];
			cout << f_add;
			//f_add.display();
			flag = 1;
			break;

		case 2:  cout << endl << "Enter the numerators and denominators of both the fractions you want to subtract respectively." << endl;
			for (int i = 0; i < 2; i++)
			{
				cin >> val_num_main[i] >> val_den_main[i];
				cout << endl;
				if (val_den_main[i] == 0)
				{
					cout << "Denominator can not be zero. Re-enter another value of denominator." << endl;
					cin >> val_den_main[i];

					if (i != 1 && i<2 && i>-1)
					{
						cout << endl << "Continue entering the values of second fraction." << endl << endl;
					}
				}
			}
			fractions.subtract(val_num_main[0], val_den_main[0], val_num_main[1], val_den_main[1]);
			cout << fractions;
			//fractions.display();
			flag = 1;
			break;

		case 3:  cout << endl << "Enter the numerators and denominators of both the fractions you want to multiply respectively." << endl;
			for (int i = 0; i < 2; i++)
			{
				cin >> val_num_main[i] >> val_den_main[i];
				cout << endl;
				if (val_den_main[i] == 0)
				{
					cout << "Denominator can not be zero. Re-enter another value of denominator." << endl;
					cin >> val_den_main[i];

					if (i != 1 && i<2 && i>-1)
					{
						cout << endl << "Continue entering the values of second fraction." << endl << endl;
					}
				}
			}

			fractions.multiply(val_num_main[0], val_den_main[0], val_num_main[1], val_den_main[1]);
			cout << fractions;
			//fractions.display();
			flag = 1;
			break;

		case 4: cout << endl << "Enter the numerators and denominators of both the fractions you want to divide respectively." << endl;
			for (int i = 0; i < 2; i++)
			{
				cin >> val_num_main[i] >> val_den_main[i];
				cout << endl;
				if (val_den_main[i] == 0)
				{
					cout << "Denominator can not be zero. Re-enter another value of denominator." << endl;
					cin >> val_den_main[i];

					if (i != 1 && i<2 && i>-1)
					{
						cout << endl << "Continue entering the values of second fraction." << endl << endl;
					}
				}
			}
			fractions.divide(val_num_main[0], val_den_main[0], val_num_main[1], val_den_main[1]);
			cout << fractions;
			//fractions.display();
			flag = 1;
			break;

		case 5: flag = 0;
			break;
		}
	}
	_getch();
	return 0;
}