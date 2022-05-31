compile: clean speller

speller:
	clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -c -o speller.o speller.c
	clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -c -o dictionary.o dictionary.c
	clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -o speller speller.o dictionary.o -lm

check:
	check50 cs50/problems/2021/x/speller


check-local:
	check50 --local cs50/problems/2021/x/speller


clean:
	-rm speller


style:
	style50 dictionary.c


test:
	./speller texts/cat.txt

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./speller texts/cat.txt 


