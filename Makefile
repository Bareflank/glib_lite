DEPS = include/glib.h include/glib/gatomic.h include/glib/ghash.h include/glib/glibconfig.h include/glib/glist.h include/glib/gmacros.h include/glib/gmem.h include/glib/gmisc.h include/glib/gnode.h include/glib/gqueue.h include/glib/gslist.h include/glib/gtypes.h include/glib/gversionmacros.h
OBJ = src/gatomic.o src/ghash.o src/glist.o src/gmem.o src/gmisc.o src/gnode.o src/gqueue.o src/gslist.o

%.o: %.c $(DEPS)
	$(CC) -c -fpic -D__GLIB_H_INSIDE__ -I./ -I./include/ -o $@ $<

libglib_lite.a: $(OBJ)
	$(AR) rcs $@ $^

install:
	mkdir -p $(prefix)/include/glib/
	cp include/glib.h $(prefix)/include/
	cp include/glib/*.h $(prefix)/include/glib/
	cp libglib_lite.a $(prefix)/lib/

clean:
	rm libglib_lite.a
	rm src/*.o
