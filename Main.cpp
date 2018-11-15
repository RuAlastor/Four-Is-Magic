

#include <iostream>
#include <string>


namespace Numbers {
	
	std::string smalls[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"
	"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

	std::string decades[] = { " ", " ", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	std::string hundred = " hundred";

	std::string thousandPowers[] = { " ", " ", " thousand", " million", " billion", " trillion", " quadrillion", "quintillion" };

}

long int test[] = { 1, 4, 11, 13, 75, 100, 337, 10024, 1604, 2147483647 };

std::string fourIsMagic(long int&);
std::string say(long int);

int main() {

	for (int i = 0; i < 10; i++) {
		std::cout << fourIsMagic(test[i]) << '\n';
	}

	system("pause");
	return 0;
}

std::string fourIsMagic(long int& _arabicNumber) {
	long int arabicNumber = _arabicNumber;
	if (arabicNumber == 4) {
		return "Four is magic!\n";
	}
	std::string completeAnswer = say(arabicNumber);
	arabicNumber = completeAnswer.length();
	std::string tempAnswer = "";
	while (arabicNumber != 4) {
		tempAnswer = say(arabicNumber);
		arabicNumber = tempAnswer.length();
		completeAnswer += " is " + tempAnswer + ", " + tempAnswer;
	}
	completeAnswer += " is four, four is magic!\n";
	return completeAnswer;
}

std::string say(long int _arabicNumber) {
	std::string answer = "";
	if (_arabicNumber < 20) {
		answer += Numbers::smalls[_arabicNumber];
	}
	else if (_arabicNumber < 100) {
		answer += Numbers::decades[_arabicNumber / 10];
		if (_arabicNumber % 10 != 0) {
			answer += "-" + Numbers::smalls[_arabicNumber % 10];
		}
	}
	else if (_arabicNumber < 1000) {
		answer += Numbers::smalls[_arabicNumber / 100] + Numbers::hundred;
		if (_arabicNumber % 100 != 0) {
			answer += " " + say(_arabicNumber % 100);
		}
	}
	else {
		long int helperMod;
		std::string helperStr1 = "";
		std::string helperStr2 = "";
		for (int power = 0; _arabicNumber > 0; power++) {
			helperMod = _arabicNumber % 1000;
			_arabicNumber = _arabicNumber / 1000;
			if (helperMod != 0) {
				helperStr1 = say(helperMod) + Numbers::thousandPowers[power];
				if (helperStr2 != "") {
					helperStr1 += " " + helperStr2;
				}
				helperStr2 = helperStr1;
			}
		}
		answer += helperStr2;
	}


	return answer;
}