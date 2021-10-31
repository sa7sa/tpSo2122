all:
	gcc -g -Wall -o cliente cliente.c
	gcc -g -Wall -o balcao balcao.c

servidor:
	gcc -c balcao.c

cliente:
	gcc -c cliente.c

clean:
	$(RM) balcao balcao.o
	$(RM) cliente cliente.o