#include<iostream>

using std::endl;
using std::cin;
using std::cout;

typedef char digit_chars_t[10][11][11];
typedef char separator_chars_t[11][4];
typedef char timer_t[11][80];

separator_chars_t separator = {
	"   ",
	"   ",
	"   ",
	"   ",
	" # ",
	"   ",
	" # ",
	"   ",
	"   ",
	"   ",
	"   ",
};

digit_chars_t digits = {
	{
		"##########",
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"##########"
	},
	{
		"         #",
		"        ##",
		"       # #",
		"      #  #",
		"     #   #",
		"         #",
		"         #",
		"         #",
		"         #",
		"         #",
		"         #"
	},
	{
		"##########",
		"         #",
		"         #",
		"         #",
		"         #",
		"##########",
		"#         ",
		"#         ",
		"#         ",
		"#         ",
		"##########"
	},
	{
		"##########",
		"         #",
		"         #",
		"         #",
		"         #",
		"##########",
		"         #",
		"         #",
		"         #",
		"         #",
		"##########"
	},
	{
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"##########",
		"         #",
		"         #",
		"         #",
		"         #",
		"         #"
	},
	{
		"##########",
		"#         ",
		"#         ",
		"#         ",
		"#         ",
		"##########",
		"         #",
		"         #",
		"         #",
		"         #",
		"##########"
	},
	{
		"##########",
		"#         ",
		"#         ",
		"#         ",
		"#         ",
		"##########",
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"##########"
	},
	{
		"##########",
		"         #",
		"         #",
		"         #",
		"         #",
		"         #",
		"         #",
		"         #",
		"         #",
		"         #",
		"         #"
	},
	{
		"##########",
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"##########",
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"##########"
	},
	{
		"##########",
		"#        #",
		"#        #",
		"#        #",
		"#        #",
		"##########",
		"         #",
		"         #",
		"         #",
		"         #",
		"##########"
	}
};

void addASCIISeparator(timer_t timer, int * offsetIndex) {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			timer[i][*offsetIndex + j] = separator[i][j];
		}
	}

	*offsetIndex += 4;
}

void addASCIINumber(timer_t timer, int * offsetIndex, unsigned digit) {
	if (digit >= 10) {
		return;
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			timer[i][*offsetIndex + j] = digits[digit][i][j];
		}
	}

	*offsetIndex += 11;
}

int main() {
	unsigned seconds;
//	cin >> seconds;
	seconds = 8392;

	if (seconds >= 10000) {
		cout << "Invalid input, must be at most a 4 digit number" << endl;
		return -1;
	}

	unsigned minutes = seconds / 60;
	seconds = seconds - minutes * 60;

//	cout << minutes << " " << seconds << endl;

//	for (int i = 0; i < 10; i++) {
//		cout << "printing digit " << i << endl;
//		for (int j = 0; j < 11; j++) {
//			for (int k = 0; k < 10; k++) {
//				cout << digits[i][j][k];
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}

	timer_t timer = {};
	int offsetIndex = 0;

	addASCIINumber(timer, &offsetIndex, 8);
	addASCIISeparator(timer, &offsetIndex);
	addASCIINumber(timer, &offsetIndex, 8);
	addASCIINumber(timer, &offsetIndex, 7);

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 80; j++) {
			cout << timer[i][j];
		}
		cout << endl;
	}

}