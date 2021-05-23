#pragma once
#include <vector>
using namespace std;
class Process {
private:
	std::vector<int> max;
	std::vector<int> need;
	std::vector<int> allocation;
	bool finished = false;
public:
	int pid;
	Process(int id, int a, int b, int c, int d, int _a, int _b, int _c, int _d) {
		pid = id;
		max.push_back(a);
		max.push_back(b);
		max.push_back(c);
		max.push_back(d);
		allocation.push_back(_a);
		allocation.push_back(_b);
		allocation.push_back(_c);
		allocation.push_back(_d);
	}
	void GiveandBack(vector<int> available) {
		if (!finished) {
			need_set();
			process_finish(available);
		}
	}
	void need_set() {
		need.push_back(max[0] - allocation[0]);
		need.push_back(max[1] - allocation[1]);
		need.push_back(max[2] - allocation[2]);
		need.push_back(max[3] - allocation[3]);
	}
	bool check_allocatation(vector<int> available) {
		if (available[0] >= need[0] && available[1] >= need[1] && available[2] >= need[2] && available[3] >= need[3])
			return true;
		return false;
	}
	void process_finish(vector<int> &available) {
		if (check_allocatation(available)) {
			available[0] += this->allocation[0];
			available[1] += this->allocation[1];
			available[2] += this->allocation[2];
			available[3] += this->allocation[3];
			this->allocation[0] = 0;
			this->allocation[1] = 0;
			this->allocation[2] = 0;
			this->allocation[3] = 0;
			finished = true;
		}
	}
	bool is_finished() {
		return finished;
	}
};
