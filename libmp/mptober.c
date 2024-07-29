#include "os.h"
#include <mp.h>
#include "dat.h"

void
mptober(mpint *b, uchar *p, uint n)
{
	int m;

	m = mptobe(b, p, n, nil);
	assert(m >= 0);
	if(m < n){
		n -= m;
		memmove(p+n, p, m);
		memset(p, 0, n);
	}
}
