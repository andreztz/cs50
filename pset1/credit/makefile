all: compile check-local 

compile:
	clang credit.c -lcs50 -lm -o credit  

check:
	check50 cs50/problems/2021/x/credit

check-local:
	check50 --local cs50/problems/2021/x/credit

clean:
	-rm credit

style:
	style50 credit.c
