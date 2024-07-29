#include "os.h"
#include <mp.h>
#include "dat.h"

void
mpmod(mpint *b, mpint *m, mpint *remainder)
{
	int sign;
	mpint *ms; // handle m == remainder and b < 0

	sign = b->sign;
	ms = sign < 0 && m == remainder ? mpcopy(m) : m;
	if((m->flags & MPfield) == 0
|| ((Mfield*)m)->reduce((Mfield*)m, b, remainder) != 0)
		mpdiv(b, m, nil, remainder);
	if(sign < 0){
		mpmagsub(ms, remainder, remainder);
		if(ms != m) mpfree(ms);
	}
}
