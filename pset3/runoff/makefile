all: compile check-local 

compile:
	clang runoff.c -lcs50 -lm -o runoff  

check:
	check50 cs50/problems/2021/x/runoff

check-local:
	check50 --local cs50/problems/2021/x/runoff

clean:
	-rm runoff

style:
	style50 runoff.c
