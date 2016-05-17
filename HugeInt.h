#ifndef HUGEINTH
#define HUGEINT_H

#include <iostream>

using std::ostream;

class HugeInt {
	friend ostream &operator << ( ostream &, const HugeInt & );

	public:
	HugeInt( long = 0 );
	HugeInt( const char * );

	HugeInt operator + ( const HugeInt & );
	HugeInt operator + ( int );
	HugeInt operator + ( const char * );

	HugeInt operator * ( int );
	HugeInt operator * ( const HugeInt & );

	private:
	short integer[ 30 ];

};

#endif
