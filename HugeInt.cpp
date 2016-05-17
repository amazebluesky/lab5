#include <cctype>
#include <cstring>

#include "HugeInt.h"

HugeInt::HugeInt( long value )
{
	for ( int i = 0; i <= 29; i++ )
		integer[ i ] = 0;

	for ( int j = 29; value != 0 && j >= 0; j-- ){
		integer[ j ] = value % 10;
		value /= 10;

	}
}

HugeInt::HugeInt( const char *string )
{
	for ( int i = 0; i <= 29; i++ )
		integer[ i ] = 0;

	int length = strlen( string );

	for ( int j = 30 - length, k = 0; j <= 29; j++, k++ )

		if ( isdigit( string[ k ] ) )
			integer[ j ] = string[ k ] - '0';

}

HugeInt HugeInt::operator + ( const HugeInt &op2 )
{
	HugeInt temp;
	int carry = 0;

	for ( int i = 29; i >= 0; i-- ){
		temp.integer[ i ] = integer[ i ] + op2.integer[ i ] + carry;

		if ( temp.integer[ i ] > 9 ) {
			temp.integer[ i ] %= 10;
			carry = 1;

		}

		else
			carry = 0;

	}

	return temp;

}

HugeInt HugeInt::operator + ( int op2 )
{
	return *this + HugeInt( op2 );

}

HugeInt HugeInt::operator + ( const char *op2 )
{
	return *this + HugeInt( op2 );

}

HugeInt HugeInt::operator * ( const HugeInt &mul )
{
	HugeInt temp;
	HugeInt tempT;
	HugeInt tempN;
	int carry = 0;
	int n = 0;

	for ( int i = 29; i >= 0; i-- ){

		for ( int t = 0; t <= 29; t++ ){
			tempT.integer[ t ] = 0;
			tempN.integer[ t ] = 0;

		}

		for ( int j = 29; j >= 0; j-- ){
			tempT.integer[ j ] = integer[ j ] * mul.integer[ i ] + carry;

			if ( tempT.integer[ j ] > 9 ){
				carry = tempT.integer[ j ] / 10;
				tempT.integer[ j ] %= 10;				

			}

			else
				carry = 0;

		}

		for ( int y = 29; y >= 0; y-- )
			tempN.integer[ y - n ] = tempT.integer[ y ];

		++n;

		temp = temp + tempN;

	}

	return temp;

}

HugeInt HugeInt::operator * ( int mul )
{
	return *this * HugeInt( mul );

}

ostream &operator << ( ostream &output, const HugeInt &num )
{
	int i;

	for ( i = 0; ( num.integer[ i ] == 0 ) && ( i <= 29 ); i++ );
	if ( i == 30 )
		output << 0;
	else for ( i=0; i <= 29; i++ );
	output << num.integer[ i ];
	return output;

}
