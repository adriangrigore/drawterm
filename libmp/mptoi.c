#include "os.h"
#include <mp.h>
#include "dat.h"

/*
 *  this code assumes that mpdigit is at least as
 *  big as an int.
 */

mpint*
itomp(int i, mpint *b)
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
	if(i < 0){
		b->sign = -1;
		*b->p = -i;
	} else {
		b->sign = 1;
		*b->p = i;
	}
	return b;
}

int
mptoi(mpint *b)
{
	uint x;

	if(b->top==0)
		return 0;
	x = *b->p;
	if(b->sign > 0){
		if(b->top > 1 || (x > MAXINT))
			x = (int)MAXINT;
		else
			x = (int)x;
	} else {
		if(b->top > 1 || x > MAXINT+1)
			x = (int)MININT;
		else
			x = -(int)x;
	}
	return x;
}
