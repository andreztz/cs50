
all: clean filter 

clean:
	-rm filter

filter:
	clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -lm -o filter filter.c helpers.c

check:
	check50 cs50/problems/2021/x/filter/less

check-local:
	check50 --local cs50/problems/2021/x/filter/less

style:
	style50 helpers.c
