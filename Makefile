# 
# zim-utils Makefile
#
###############################################################################

CC=g++
CFLAGS=-lzim

SRCDIR=src
BUILDDIR=build

###############################################################################

make: $(SRCDIR)/dump_titles.o
	mkdir -p $(BUILDDIR)
	$(CC) -o $(BUILDDIR)/dump_titles $(SRCDIR)/dump_titles.o $(CFLAGS)

.PHONY: clean

clean:
	rm -rf $(BUILDDIR) $(SRCDIR)/*.o

