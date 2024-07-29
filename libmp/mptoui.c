#include "os.h"
#include <mp.h>
#include "dat.h"

/*
 *  this code assumes that mpdigit is at least as
 *  big as an int.
 */

mpint*
uitomp(uint i, mpint *b)
{
	if(b == nil){
		b = mpnew(0);
		setmalloctag(b, getcallerpc(&i));
	}

	if (b->flags & MPtimesafe) 
		b->flags &= ~MPnorm;
	else
		b->flags |= MPnorm;

	if(i != 0)
		b->top = 1;
	else
		b->top = 0;
	*b->p = i;
	b->sign = 1;
	return b;
}

uint
mptoui(mpint *b)
{
	uint x;

	x = *b->p;
	if(b->sign < 0)
		x = 0;
	else if(b->top > 1 || (sizeof(mpdigit) > sizeof(uint) && x > MAXUINT))
		x =  MAXUINT;
	return x;
}
