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

void countingSortByBit(std::vector<unsigned char> &A, int k) {
    int n = A.size();
    std::vector<unsigned char> output(n);
    int count[2] = {0, 0};

    for (int i = 0; i < n; i++) {
        int bit = (A[i] >> k) & 1;
        count[bit]++;
    }

    count[1] += count[0];

    for (int i = n - 1; i >= 0; i--) {
        int bit = (A[i] >> k) & 1;
        output[count[bit] - 1] = A[i];
        count[bit]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

void binaryRadixSort(std::vector<unsigned char> &A) {
    for (int k = 0; k < 8; k++) {
        countingSortByBit(A, k);
    }
}

int main() {
	return 0;
}