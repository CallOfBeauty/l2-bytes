/** L2: Bytes
FIXME: Dimitrios Ntentia
FIXME: username:  ntentiad
Purpose: To learning about bits, bytes, and binary
and to reinforce work with arrays and classes in C++.

Acknowledgements:
Modified from original stub code written by Dr. Jan Pearce
FIXME: I used only the book
*/
#include <string> 
#include <iostream>
#include <random> //needed for Getrandom
using namespace std;

class GetRandom {
	/** Uses <random> from C++11 to return a random integer in range [1..size] */
public:
	GetRandom(int size) {
		random_device rd; // declares a random_device object that need to generate a random number.
		mt19937 gen(rd()); //mt19937 is an efficient pseudo-random number generator using the Mersenne twister algorithm.
		uniform_int_distribution<int> intdist(1, size); //create a uniform distribution object to turn the pseudorandom result into a random digit between 1 and size.
		self_rand_int_ = intdist(gen); //generates the random number.
	}
	int roll() {
		return self_rand_int_;
	}
private:
	int self_rand_int_;
}; // end of GetRandom





class Bytes {
public:
	Bytes() {
	} //default constructor sets all member variables.



	Bytes(bool tempbyte[8]) {
		for (int i = 0; i < bytelen; i++) {
			byte[i] = tempbyte[i];
		}
	}

	void setrandom() {
		/* Dependent upon the Getrandom class above. */

		for (int i = 0; i < bytelen; i++) {
			GetRandom newrandom(2); // returns 1 or 2
			byte[i] = newrandom.roll() - 1;
		}
	}

	void set_byte() { //mutator method sets byte from keyboard

		bool readbit;

		for (int i = 0; i < bytelen; i++) {
			cout << "Please enter bit " << i << ": ";
			cin >> readbit;
			byte[i] = readbit;
		}

		cout << endl;
		return;
	}

	void show_byte() { 

		for (int i = 0; i < bytelen; i++) {
			cout << byte[i];
		}
		return;
	}

	bool isodd() {	//chechs and prints true or false for the parity of the byte array (true  if odd)
		int accum = 0;
		for (int i = 0; i < bytelen; i++) {
			accum = accum + byte[i];
		}
		if (accum % 2 == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	void seteven(int parity) { //sets and prints the parity for the byte array when that is even
		cout << "The byte has an even parity and is the following: ";
		if (parity == 0) {
			byte[7] = parity;
		}
		return;
	}



	void setodd(int parity) { //sets and prints the parity for the byte array when that is even. The parity is the last bit
		cout << "The byte has an even parity and is the following: ";
		if (parity == 1) {
			byte[7] = parity;
			return;
		}
	}

	int returner(int indx) {
		return byte[indx];
	}

	void flipper() {
		for (int i = 0; i < bytelen; i++) {
			if (byte[i] == 1) {
				byte[i] = 0;
			}
			else {
				byte[i] = 1;
			}
		}
	return;
	}

	bool masker() {
		bool readbit;

		for (int i = 0; i < bytelen; i++) {
			cout << "Please enter bit that will be part of the mask byte " << i << ": ";
			cin >> readbit;
			mask[i] = readbit;
		}


		for (int i = 0; i < bytelen; i++) {
			if (mask[i] == 1 && byte[i] == 1) {
				byte[i] = 1;
			}
			else {
				byte[i] = 0;
			}
		}
		cout << "Applying your mask, to the original byte we get: ";
		for (int i = 0; i < bytelen; i++) {
			cout << byte[i];
		}
		return byte;
	}

	friend ostream &operator << (ostream &stream, const Bytes &byte);








private:
	bool byte[8] = { false }; //This initializes all of the bits
	bool mask[8] = { true, true, true, true, true, true, true, true }; 
	const int bytelen = 8;
}; //end of Bytes class


ostream& operator << (ostream& stream, const Bytes& byte) {
	/** this is the definition. */
	for (int i = 0; i < 8; i++) {
		stream << byte.byte[i];
	}
	return stream;
}
int main() {

	bool truebyte[8] = { true, true, true, true, true, true, true, true }; // this style of initalization only works at compile time
	int readchar = 'Y';

	cout << "Welcome to the Bytes class!\n" << endl; //Prints a welcoming message on the screen

	Bytes testbyte;
	Bytes randombyte;
	randombyte.setrandom();
	Bytes defaultbyte(truebyte);  // uses contructor that sets byte using parameter

	testbyte.set_byte();
	cout << "Here is the byte you entered: ";
	testbyte.show_byte();
	cout << endl;

	cout << "Here is a default byte: ";
	defaultbyte.show_byte();
	cout << endl;

	cout << "Here is a random byte: ";
	randombyte.show_byte();
	cout << endl;


	cout << "Your bite has the following parity: ";// Prints out the parity of the code. 0 means even, 1 means odd parity
	cout << testbyte.isodd();
	cout << endl;

	if (testbyte.isodd()==0) {
		testbyte.seteven(testbyte.isodd());
		cout << endl;
	}
	else{
		testbyte.setodd(testbyte.isodd());
		cout << endl;
	}

	cout<<testbyte.returner(2);
	cout << endl;

	testbyte.flipper();

	testbyte.masker();




	



	//FIXME: place code to fully test your Bytes class

	cin >> readchar; //This is to keep screen open in some situations.

	return 0;
}

