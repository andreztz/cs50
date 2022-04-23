all: compile check-local 

compile:
	clang cash.c -lcs50 -lm -o cash  

check:
	check50 cs50/problems/2021/x/cash/

check-local:
	check50 --local cs50/problems/2021/x/cash

clean:
	-rm cash

style:
	style50 cash.c
