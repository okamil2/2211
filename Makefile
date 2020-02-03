C = gcc
RMVF = -f
TST = ciphers
CVSN = -std=c99

$(TST): ciphers.o cipher_main.o
	$(CC) $(CVSN) -o $(TST) ciphers.o cipher_main.o

cipher_main.o: ciphers.h cipher_main.c
	$(CC) $(CVSN) -c cipher_main.c

ciphers.o: ciphers.h ciphers.c
	$(CC) $(CVSN) -c ciphers.c

clean:
	rm $(RMVF) $(TST) *.o core
