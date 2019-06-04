.SILENT .PHONY: call clean realclean all build test gen
BINS=vm64 vm32
SRCS=coda.c v.c
all: $(BINS)
vm: *.c *.h ; $(CC) -o $@ $(CFLAGS) *.c
world: ; (make v.h ; make v.h) && make test
v.h: h.h ; mv h.h v.h
h.h: v.c ; make gen >h.h ; diff v.h h.h
gen:
	perl -npe 'if(!s/^def\s+F(\w+).*/\1/g){$$_=""}' v.c >x
	perl -npe 's/^(.*)$$/def F\1();/g' x
	echo 'func Funcs[]='
	echo '  {'
	perl -npe 's/^(.*)$$/    F\1,/g' x
	echo '    0};'
	echo 'char*Names[]='
	echo '  {'
	perl -npe 's/^(.*)$$/    "\1",/g' x
	echo '    0};'
	rm x
test: clean $(BINS)
	echo '>> Testing ...'
	./vm64
	./vm32
vm32: *.c *.h ; rm -f vm ; CFLAGS=-m32 make vm && mv vm $@
vm64: *.c *.h ; rm -f vm ; CFLAGS=-m64 make vm && mv vm $@
clean: ; rm -fr ? $(BINS) *~ h.h *.o a.out vm
realclean:;rm -fr v.h;make clean
