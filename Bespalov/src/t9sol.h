#include <string>

std::string charintonumber(char r) {
	if (r == 'a') return "2";
	if (r == 'b') return "22";
	if (r == 'c') return "222";

	if (r == 'd') return "3";
	if (r == 'e') return "33";
	if (r == 'f') return "333";

	if (r == 'g') return "4";
	if (r == 'h') return "44";
	if (r == 'i') return "444";

	if (r == 'j') return "5";
	if (r == 'k') return "55";
	if (r == 'l') return "555";

	if (r == 'm') return "6";
	if (r == 'n') return "66";
	if (r == 'o') return "666";

	if (r == 'p') return "7";
	if (r == 'q') return "77";
	if (r == 'r') return "777";
	if (r == 's') return "7777";

	if (r == 't') return "8";
	if (r == 'u') return "88";
	if (r == 'v') return "888";

	if (r == 'w') return "9";
	if (r == 'x') return "99";
	if (r == 'y') return "999";
	if (r == 'z') return "9999";

	if (r == ' ') return "0";
}

std::string t9solve(std::string str) {
	std::string(result);
	std::size_t digitsAndUpperCase = str.find_first_of( "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	if (str.empty()) {
		return "input is empty";
	}
	if (digitsAndUpperCase <= str.size()) {
		return "invalid input";
	}
	result += charintonumber(str[0]);
	for (int i = 1; i < str.size(); ++i) {
		if(charintonumber(str[i])[0] == charintonumber(str[i - 1])[0]) result += " ";
		result += charintonumber(str[i]);
	}
	return result;
}
