all: compile check-local 

compile:
	clang plurality.c -lcs50 -lm -o plurality  

check:
	check50 cs50/problems/2021/x/plurality

check-local:
	check50 --local cs50/problems/2021/x/plurality

clean:
	-rm plurality

style:
	style50 plurality.c
