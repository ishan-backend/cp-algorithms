#include<iostream>
using namespace std;

class Fraction{

private:
	int numerator;
	int denominator;

public:

	//default constructor
	Fraction()
	{

	}

	//parametrized constructor
	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}

	//getters
	int getNumerator() const
	{
		return numerator;
	}

	int getDenominator() const
	{
		return denominator;
	}

	//setters
	void setNumerator(int n)
	{
		numerator = n;
	}

	void setDenominator(int d)
	{
		denominator = d;
	}

	void print() const
	{
		cout<<this->numerator<<" / "<<this->denominator<<endl;
	}

	void simplify()
	{
		int gcd=1;
		int j = min(this->numerator, this->denominator);
		for(int i=1; i<=j; i++)
		{
			if(this->numerator % i == 0 && this->denominator % i == 0)
			{
				gcd = i;
			}
		}

		this->numerator = this->numerator / gcd;
		this->denominator = this->denominator / gcd;
	}

	void add(Fraction const &f2)// values of passed in f2 object doesnt change as it is kept const
	{
		// numerator means this->numerator
		//denominator means this->denominator

		int lcm = denominator*f2.denominator;
		int x = lcm/denominator;
		int y = lcm/f2.denominator;

		int num = x*numerator + (y*f2.numerator);

		numerator = num;
		denominator = lcm;
		simplify();
	}

	void multiply(Fraction const &f2)
	{
		numerator = numerator* f2.numerator;
		denominator = denominator* f2.denominator;

		simplify();
	}
};


int main()
{
	Fraction f1(10, 2);
	Fraction f2(15, 4);


	//CONSTANT OBJECT:
	const Fraction f3;	//f3's any data members cant be changed // default constructor initialises f3 with garbage
	
	// COMPILER DOESNT ALLOW CALLING OF NORMAL FUNCTIONS WITH CONST OBJECTS
	// IT IS WORRIED THAT WE WILL USE IT TO CHANGE VALUES
	cout<<f3.getNumerator()<<" "<<f3.getDenominator()<<endl;	//gives error
	f3.setDenominator(13);// not allowed

	//WITH CONSTANT OBJECTS:WE CAN CALL ONLY CONSTANT FUNCTIONS
	// CONSTANT FUNCTIONS DONT CHANGE ANY PROPERTY OF CURRENT OBJECTS
	// that , which doesnt change any property of this(current object)

	// change getNumerator and getDenominator functions to const, because it doesnt change this
	// this will allow us to call above functions
	// syntax: int getNumerator() const{} or int const getNumerator(){}

	cout<<f3.getNumerator()<<" "<<f3.getDenominator()<<endl; //successful
	return 0;
}
