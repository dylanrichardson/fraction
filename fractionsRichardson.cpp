#include <iostream>
#include "dric.h"
#include "fraction.h"

using namespace std;

int main()
{
	char ans;
	int n1,n2,d1,d2;
	Fraction f1,f2,add,sub,multi,div;
	do
	{
		cout<<"First numerator: ";
		input(&n1,6,INT_);
		cout<<"First denominator: ";
		input(&d1,6,INT_);
		cout<<"Second numerator: ";
		input(&n2,6,INT_);
		cout<<"Second denominator: ";
		input(&d2,6,INT_);
		cout<<endl;
		f1 = Fraction (n1,d1);
		f2 = Fraction (n2,d2);
		add = f1 + f2;
		sub = f1 - f2;
		multi = f1 * f2;
		div = f1 / f2;
		cout<<f1<<" + "<<f2<<" = "<<add<<endl;
		cout<<f1<<" - "<<f2<<" = "<<sub<<endl;
		cout<<f1<<" * "<<f2<<" = "<<multi<<endl;
		cout<<f1<<" / "<<f2<<" = "<<div<<endl;
		cout<<endl;
		cout<<"Do you want to run the program again? (y/n) ";
		cin>>ans;
	} while (ans=='y');
	system("pause");
	return 0;
}
