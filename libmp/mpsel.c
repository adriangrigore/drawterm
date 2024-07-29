#include "os.h"
#include <mp.h>
#include "dat.h"

// res = s != 0 ? b1 : b2
void
mpsel(int s, mpint *b1, mpint *b2, mpint *res)
{
	mpassign(s ? b1 : b2, res);
}
