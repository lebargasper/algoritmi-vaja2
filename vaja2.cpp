#include <fstream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<unsigned char> &vec, const char s[]) {
    ifstream input(s);
	int st;

	if (!input.is_open()) {
		return false;
	}

	while (input >> st) {
        if (st < 0 || st > 255) return false;
        vec.push_back(static_cast<unsigned char>(st));
    }
	input.close();
	return true;
}

int main() {
	return 0;
}