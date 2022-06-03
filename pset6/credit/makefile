check-local:
	check50 --local cs50/problems/2021/x/sentimental/credit

check:
	check50 cs50/problems/2021/x/sentimental/credit

style:
	style50 credit.py

test:
	pytest --cov=credit -v -s

test-report:
	pytest --cov=credit --cov-report=html -v -s
	python -m http.server --directory htmlcov

flake8:
	flake8 . --exclude .venv

black:
	black --line-length 79 .
