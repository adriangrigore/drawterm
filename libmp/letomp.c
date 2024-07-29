#include "os.h"
#include <mp.h>
#include "dat.h"

// convert a little endian byte array (least significant byte first) to an mpint
mpint*
letomp(uchar *s, uint n, mpint *b)
{
	int i=0, m = 0;
	mpdigit x=0;

	if(b == nil)
		b = mpnew(0);

	// dump leading zeros
	while(s[n-1] == 0 && n > 1){
		n--;
	}

	mpbits(b, 8*n);

	// handle zero
	if(n==1 && *s == 0){
		b->top = 0;
		*b->p = 0;
		goto Out;
	}

	for(; n > 0; n--){
		x |= ((mpdigit)(*s++)) << i;
		i += 8;
		if(i == Dbits){
			b->p[m++] = x;
			i = 0;
			x = 0;
		}
	}
	if(i > 0)
		b->p[m++] = x;
	b->top = m;
Out:
	b->sign = 1;
	return b;
}
