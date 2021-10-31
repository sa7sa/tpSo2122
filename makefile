all:
	gcc -g -Wall -o cliente cliente.c funcoes.c
	gcc -g -Wall -o balcao balcao.c
	
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