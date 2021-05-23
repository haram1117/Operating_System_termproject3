#include <iostream>
#include <vector>
#include "bankers.h"

using namespace std;

void available_set(vector<int> &v, int a, int b, int c, int d) {
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
}

bool isSafeState(vector<Process> &SafeSequence, vector<int> &available, Process P0, Process P1, Process P2, Process P3, Process P4) {
	vector<Process> process_v;
	process_v.push_back(P0);
	process_v.push_back(P1);
	process_v.push_back(P2);
	process_v.push_back(P3);
	process_v.push_back(P4);
	int i = 0;
	int count = 0;
	while (!(P0.is_finished() && P1.is_finished() && P2.is_finished() && P3.is_finished() && P4.is_finished())) {
		if (i == 5)
			i = 0;
		if (count >= 20)
			return false;
		process_v[i].GiveandBack(available);
		if (process_v[i].is_finished()) {
			SafeSequence.push_back(process_v[i]);
		}
		i++;
		count++;
	}
	if (P0.is_finished() && P1.is_finished() && P2.is_finished() && P3.is_finished() && P4.is_finished())
		return true;
}

int main() {
	vector<int> available_v;
	vector<Process> SafeSequence;
	available_set(available_v, 3, 2, 1, 1);
	Process P0(0, 6, 0, 1, 2, 4, 0, 0, 1);
	Process P1(1, 1, 7, 5, 0, 1, 1, 0, 0);
	Process P2(2, 2, 3, 5, 6, 1, 2, 5, 4);
	Process P3(3, 1, 6, 5, 3, 0, 6, 3, 3);
	Process P4(4, 1, 6, 5, 6, 0, 2, 1, 2);


	if (isSafeState(SafeSequence, available_v, P0, P1, P2, P3, P4)) {
		cout << "Safe State" << "\n";
		for (int i = 0; i < SafeSequence.size(); i++) {
			cout << "P" << SafeSequence[i].pid << "\t";
		}
	}
	else
		cout << "Unsafe State" << "\n";


}
