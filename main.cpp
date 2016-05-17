#include <iostream>
using namespace std;
#include "HugeInt.h"
int main()
{
	HugeInt	x(1);
	HugeInt	y(28825252);
	HugeInt	z("314159265358979323846");
	HugeInt	result;
	result	=	x+y;
	cout << x	 <<	 "+" << y	 << "	=	"	<<	result	<<	endl;
	return	0;
}
