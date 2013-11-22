SOURCES=src/super.c src/produto.h src/produto.h src/produto.c src/data.h src/data.c
CFLAGS=-Wall

all:
	$(CC) $(SOURCES) $(CFLAGS) -o super

clean:
	rm super
