SOURCES=src/super.c src/produto.h src/produto.h src/produto.c src/data.h src/data.c\
		src/estoque.c src/estoque.h src/carrinho.c src/carrinho.h src/utils.h src/utils.c

CFLAGS=-Wall

all:
	$(CC) $(SOURCES) $(CFLAGS) -o super

clean:
	rm super
