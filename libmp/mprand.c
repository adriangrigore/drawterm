#include "os.h"
#include <mp.h>
#include <libsec.h>
#include "dat.h"

mpint*
mprand(int bits, void (*gen)(uchar*, int), mpint *b)
{
	int n, m;
	mpdigit mask;
	uchar *p;

	n = DIGITS(bits);
	if(b == nil){
		b = mpnew(bits);
		setmalloctag(b, getcallerpc(&bits));
	}else
		mpbits(b, bits);

	p = malloc(n*Dbytes);
	if(p == nil)
		sysfatal("mprand: %r");
	(*gen)(p, n*Dbytes);
	betomp(p, n*Dbytes, b);
	free(p);

	// make sure we don't give too many bits
	m = bits%Dbits;
	n--;
	if(m > 0){
		mask = 1;
		mask <<= m;
		mask--;
		b->p[n] &= mask;
	}

	for(; n >= 0 && !(b->flags && MPtimesafe); n--)
		if(b->p[n] != 0)
			break;

	if (b->flags & MPtimesafe) 
		b->flags &= ~MPnorm;
	else
		b->flags |= MPnorm;

	b->top = n+1;
	b->sign = 1;
	return b;
}
