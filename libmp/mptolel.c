#include "os.h"
#include <mp.h>
#include "dat.h"

void
mptolel(mpint *b, uchar *p, uint n)
{
	mptole(b, p, n, nil);
}
