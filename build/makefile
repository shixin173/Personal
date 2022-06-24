server: common.o log.o tcp_server.o
	gcc -o ../progress/server common.o log.o tcp_server.o

client: common.o log.o tcp_client.o
	gcc -o ../progress/client common.o log.o tcp_client.o

common.o: ../include/*.c
	gcc -c ../include/*.c

log.o: ../app/log/*.c
	gcc -c ../app/log/*.c

tcp_server.o: ../app/server/*.c
	gcc -c ../app/server/*.c

tcp_client.o: ../app/client/*.c
	gcc -c ../app/client/*.c
