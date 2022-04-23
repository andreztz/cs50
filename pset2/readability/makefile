all: compile check-local 

compile:
	clang readability.c -lcs50 -lm -o readability  

check:
	check50 cs50/problems/2021/x/readability

check-local:
	check50 --local cs50/problems/2021/x/readability

clean:
	-rm readability

style:
	style50 readability.c
