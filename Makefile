agenda: tipo.o lista_enc.o main.o
	gcc -o agenda tipo.o lista_enc.o main.o

main.o: main.c
	gcc -c main.c
	
tipo.o: tipo.c tipo.h
	gcc -c tipo.c

lista_enc.o: lista_enc.c lista_enc.h
	gcc -c lista_enc.c

clean:
	rm *.o main