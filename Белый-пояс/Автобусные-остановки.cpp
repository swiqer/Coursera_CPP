#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void BusesForStop(const string& stop, vector<map<string, vector<string>>>& buses) {
	int i = 0;
	for (const auto& bus : buses) {
		for (const auto& stations : bus) {
			for (const auto& find : stations.second) {
				if (find == stop) {
					i = 1;
					cout << stations.first << " ";
				}
			}
		}
	}
	if (i != 1) cout << "No stop" << endl;
	else cout << endl;
}

void Help(const string& stop, vector<map<string, vector<string>>>& buses, const string& busNumber) {
	int i = 0;
	for (const auto& bus : buses) {
		for (const auto& stations : bus) {
			for (const auto& find : stations.second) {
				if (find == stop && stations.first != busNumber) {
					i = 1;
					cout << stations.first << " ";
				}
			}
		}
	}
	if (i != 1) cout << "no interchange" << endl;
	else cout << endl;
}


void StopForBus(const string& busNumber, vector<map<string, vector<string>>>& buses) {
	int i = 0;
	for (const auto& bus : buses) {
		for (const auto& inBus : bus) {
			if (busNumber == inBus.first) {
				i = 1;
				for (const auto& name : inBus.second) {
					cout << "Stop " << name << ": ";
					Help(name, buses, busNumber);
				}
			}
		}
	}
	if (i != 1) cout << "No bus" << endl;
}

void AllBuses(vector<map<string, vector<string>>>& buses) {
	int i = 0;
	vector<string> sortedOutPut;
	for (const auto& bus : buses) {
		for (const auto& inBus : bus) {
			sortedOutPut.push_back(inBus.first);
		}
	}
	sort(sortedOutPut.begin(), sortedOutPut.end());
	while (i < sortedOutPut.size()) {
		for (const auto& bus : buses) {
			for (const auto& inBuss : bus) {
				if (inBuss.first == sortedOutPut[i]) {
					cout << "Bus " << sortedOutPut[i] << ": ";
					for (const auto& x : inBuss.second) cout << x << " ";
					cout << endl;
				}
			}
		}
		i++;
	}
}

int main(){
	int rounds;
	cin >> rounds;

	string command;
	string bus;
	int stopCount;
	string station;
	map<string, vector<string>> save;
	vector<map<string, vector<string>>> buses;

	while (rounds--) {
		cin >> command;
		if (command == "NEW_BUS") {
			cin >> bus >> stopCount;
			while (stopCount--) {
				cin >> station;
				save[bus].push_back(station);
			}
			buses.push_back(save);
			save.clear();

		}
		else if (command == "BUSES_FOR_STOP") {
			cin >> station;
			BusesForStop(station, buses);
		}
		else if (command == "STOPS_FOR_BUS") {
			cin >> bus;
			StopForBus(bus, buses);
		}
		else if (command == "ALL_BUSES") {
			if (buses.size() == 0) cout << "No buses" << endl;
			else {
				AllBuses(buses);
			}
		}
	}
	return 0;
}
