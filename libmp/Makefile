ROOT=..
include ../Make.config
# N.B.  This is used only for secstore.  It needn't be fast.

LIB=libmp.a

OFILES=\
	betomp.$O\
	crt.$O\
	letomp.$O\
	mpadd.$O\
	mpaux.$O\
	mpcmp.$O\
	mpsel.$O\
	mpfactorial.$O\
	mpdigdiv.$O\
	mpdiv.$O\
	mpeuclid.$O\
	mpexp.$O\
	mpextendedgcd.$O\
	mpfmt.$O\
	mpinvert.$O\
	mpleft.$O\
	mpmod.$O\
	mpmodop.$O\
	mpmul.$O\
	mprand.$O\
	mpnrand.$O\
	mpright.$O\
	mpsub.$O\
	mptobe.$O\
	mptober.$O\
	mptoi.$O\
	mptole.$O\
	mptolel.$O\
	mptoui.$O\
	mptouv.$O\
	mptov.$O\
	mpvecadd.$O\
	mpveccmp.$O\
	mpvectscmp.$O\
	mpvecdigmuladd.$O\
	mpvecsub.$O\
	strtomp.$O\
	mpfield.$O\
	cnfield.$O\
	gmfield.$O\

default: $(LIB)
$(LIB): $(OFILES)
	$(AR) r $(LIB) $(OFILES)
	$(RANLIB) $(LIB)

%.$O: %.c
	$(CC) $(CFLAGS) $*.c

