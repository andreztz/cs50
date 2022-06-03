from collections import namedtuple
import csv

# import sys
import pytest

from credit import check_credit_card_brand
from credit import check_luhn
from credit import main


# sys.path.insert(0, "../credit")


test_data = []


with open("test_data.csv", "r") as f:
    reader = csv.reader(f)
    headers = next(reader)
    for cc_number, brand in reader:
        test_data.append((int(cc_number), brand))


@pytest.fixture()
def Card():
    return namedtuple("Card", headers)


@pytest.fixture()
def invalid_card_input(Card):
    return Card(1234567890, "INVALID")


@pytest.fixture(params=test_data)
def card_input(Card, request):
    return Card(*request.param)


def test_check_credit_card_brand(card_input):
    expected = card_input.brand
    assert check_credit_card_brand(card_input.cc_number) == expected


def test_check_credit_card_brand_invalid_card_number(invalid_card_input):
    assert check_credit_card_brand(invalid_card_input.cc_number) == "INVALID"


def test_check_luhn(card_input):
    assert check_luhn(card_input.cc_number) is True


def test_check_luhn_invalid_card_number(invalid_card_input):
    assert check_luhn(invalid_card_input.cc_number) is False


def test_main(card_input, capfd, monkeypatch):
    with monkeypatch.context() as m:
        m.setattr("credit.get_int", lambda _: card_input.cc_number)
        main()
        out, _ = capfd.readouterr()
        assert out == f"{card_input.brand}\n"


def test_main_return_ivalid(capfd, monkeypatch, invalid_card_input):
    with monkeypatch.context() as m:
        m.setattr("credit.get_int", lambda _: invalid_card_input.cc_number)
        main()
        out, _ = capfd.readouterr()
        assert out == f"{invalid_card_input.brand}\n\n"
