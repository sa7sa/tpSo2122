all:
	gcc -g -Wall -I/usr/include -o cliente cliente.c funcoes.c
	gcc -g -Wall -I/usr/include -o balcao balcao.c funcoes.c

balcao:
	gcc -c balcao.c

cliente:
	gcc -c cliente.c

funcoes:
	gcc -c funcoes.c
	
clean:
	$(RM) balcao balcao.o
	$(RM) cliente cliente.o
	$(RM) funcoes funcoes.o