SOURCES=src/super.c src/produto.h
CFLAGS=-Wall

all:
	$(CC) $(SOURCES) $(CFLAGS) -o super

clean:
	rm super
