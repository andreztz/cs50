all: compile check-local 

compile:
	clang substitution.c -lcs50 -lm -o substitution  

check:
	check50 cs50/problems/2021/x/substitution

check-local:
	check50 --local cs50/problems/2021/x/substitution

clean:
	-rm substitution

style:
	style50 substitution.c
