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

void Izpis_Stevil(const vector<unsigned char> &polje) {
    ofstream output("out.txt");

	if (!output.is_open()) return;

    for (size_t i = 0; i < polje.size(); i++) {
        output << static_cast<int>(polje[i]) << ' ';
    }

    output.close();
}

int main() {
	return 0;
}