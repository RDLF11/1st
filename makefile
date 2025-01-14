main: cells.o collect.o linked_list.o main.o quit.o

cells.o:
	gcc -Wall -Wextra -Wpedantic -c -g src/cells.c
collect.o:
	gcc -Wall -Wextra -Wpedantic -c -g src/collect.c
linked_list.o:
	gcc -Wall -Wextra -Wpedantic -c -g src/linked_list.c
main.o:
	gcc -Wall -Wextra -Wpedantic -c -g src/main.c
quit.o:
	gcc -Wall -Wextra -Wpedantic -c -g src/quit.c

implement-wifi-collector: cp /.main wifi-collector \
				rm main

clean:
	rm main \
	*.o

//TODO: save .o files to temp obj folder, compile from that folder and then delete it
//TODO: change output name to wifi-collector