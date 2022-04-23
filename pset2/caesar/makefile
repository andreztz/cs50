all: compile check-local 

compile:
	clang caesar.c -lcs50 -lm -o caesar  

check:
	check50 cs50/problems/2021/x/caesar

check-local:
	check50 --local cs50/problems/2021/x/caesar

clean:
	-rm caesar

style:
	style50 caesar.c
