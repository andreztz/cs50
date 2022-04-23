all: compile check-local 

compile:
	clang scrabble.c -lcs50 -lm -o scrabble  

check:
	check50 cs50/labs/2021/x/scrabble

check-local:
	check50 --local cs50/labs/2021/x/scrabble

clean:
	-rm scrabble

style:
	style50 scrabble.c
