from dataclasses import dataclass
import re
import sys

from cs50 import get_int


@dataclass
class regex_in:
    """
    https://stackoverflow.com/questions/70680363/structural-pattern-matching-using-regex
    """

    string: str

    def __eq__(self, other: str | re.Pattern):
        if isinstance(other, str):
            other = re.compile(other)
        assert isinstance(other, re.Pattern)
        return other.fullmatch(self.string) is not None


def check_credit_card_brand(cc_number):
    match regex_in(str(cc_number)[:2]):
        case r"3[4|7]":
            return "AMEX"
        case r"5[1-5]":
            return "MASTERCARD"
        case r"4[0-9]":
            return "VISA"
        case _:
            return "INVALID"


def sum_digits(number):
    if number > 9:
        return number % 10 + 1
    return number


def check_luhn(cc_number):
    number = cc_number
    remainder = 0
    even_pos_sum = 0
    odd_pos_sum = 0
    idx = 1

    while number != 0:
        remainder = number % 10
        if idx % 2 == 0:
            even_pos_sum += sum_digits(remainder * 2)
        else:
            odd_pos_sum += remainder

        number = number // 10
        idx += 1

    if (even_pos_sum + odd_pos_sum) % 10 == 0:
        return True
    else:
        return False


def main():
    cc_number = get_int("CC number: ")
    cc_number_is_valid = check_luhn(cc_number)
    brand = check_credit_card_brand(cc_number)

    if cc_number_is_valid:
        print(f"{brand}")
    else:
        print(f"{brand}\n")
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
