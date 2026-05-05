#include<iostream>
#include<chrono>
#include<thread>
#include<string>
#include<bitset>
#include<vector>
#include<algorithm>
#include<random>
// Parity Corruption Detection Test.
// (C) nekomekoraiyuu 2026
/*
 		dont mind my mess IT JUST
		WORKS OK
 */
using namespace std;
// Global Variables
vector <string> inTransmission;
string received;
vector <int> corrupted;
// 0 is Even Mode and 1 is Odd Mode
unsigned char PARITY_MODE = 0;
// Initialize random device
random_device dev1;
mt19937 gen(dev1());
uniform_int_distribution<>out_a(0,7);
uniform_int_distribution<>out_b(0,1);
// Function Prototypes
void transmit(string s) {
	string b;
	cout << "<<Transmitting..." << endl;
	cout << "?]]]To transmit: " << s << "\n----" << endl;
	cout << "Character" << '\t' << "Dec" << '\t' << "Ascii" << endl;
	for (const char &c : s) {
		b = bitset<7>(c).to_string();
		this_thread::sleep_for(chrono::milliseconds(100));
		cout << c  << '\t' << static_cast<int>(c) << '\t' << bitset<7>(c) << endl;
		// Now check if its even or odd parity
		if (!(count(b.begin(),b.end(),'1') % 2)) {
			b = to_string(PARITY_MODE) + b;
		}
		else {
			b = to_string((!PARITY_MODE)) + b;
		}
		inTransmission.push_back(b);
		}
}

void receive() {
	cout << "Receiving...." << endl;
	int index = 0;
	unsigned char c;
	for (const auto &i : inTransmission) {
		c = stoi(i.substr(1,7),nullptr,2);
		received += c;
		cout << "[[Index " << index << endl;
		this_thread::sleep_for(chrono::milliseconds(200));
		// Check if is corrupted
		if (count(i.begin(),i.end(),'1')%2 == PARITY_MODE) {
			cout << "-->Index bit OK" << endl;
		}
		else
			cout << "-->Index bit is CORRUPT" << endl;
		cout << "Received: - CHAR - BIT - DEC :" << '\t' << c << '\t' << i << '\t' << static_cast<int>(c) << endl;
		index += 1;
	}
}
void corrupt() {
	auto &t = inTransmission;
	int rand, rand2;
	unsigned char bit;
	uniform_int_distribution<>out_t(0,t.size()-1);
	while (corrupted.size() != t.size()) {
	rand = out_t(gen);
	auto c_res = find(corrupted.begin(),corrupted.end(), rand);
	if (c_res == corrupted.end()) {
			corrupted.push_back(rand);
			rand2 = out_a(gen);
			bit = u_char(out_b(gen)) + '0';
			cout << '\n' << "[!!!] Corrupting index " << rand << " At subindex " << rand2 << " with Corrupt bit: " << bit << endl; 
			t.at(rand).at(rand2) = bit;
			break;
			}
	}
	
}
int main() {
	unsigned char input;
	// Strings go here
	string 
		s_default("wandahoi!"), //Modify this if you want to try something else
		p_header("Parity Error Detection Simulation - <CPP>"),
	       p_prompt("select simulation mode:\n[0] Even Parity\n[1]Odd Parity"),
	p_err_input("Invalid input!"),
	p_start("-- Transmitted"),
	p_err("-- CORRUPTION"),
	p_end("-- Received");
	// INIT
	cout << p_header << endl << p_prompt << endl;
	cin >> input;
	if (input != '0' && input != '1') {
		cout << p_err_input << endl;
		return 1;
	}
	PARITY_MODE = input - '0';
	transmit(s_default);
	// Show Transmitted bits
	cout << p_start << '\n';
	for (const auto &i : inTransmission)
		cout << i << " ";
	// CORRUPT THE TRANSMISSION BITS
	for (const auto &i : inTransmission)
		corrupt();
	// Post corruption
	cout << p_err << endl;
	for (const auto &i : inTransmission)
		cout << i << " ";
	cout << endl;
	receive();
	cout << p_end << endl;
	cout << received << endl;
}
