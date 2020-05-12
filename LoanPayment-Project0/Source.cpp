#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
	cout << "Program: To determine the monthly payment to payoff loan" << endl;
	cout << "Ajay Nair" << endl;

	while (1) {

		double PV;
		int n, i;
		double a;
		double r;
		double P;
		double principal, interest = 0;
		ofstream outFile;
		outFile.open("D:\\schedule.txt");	// open output file
		if (!outFile.is_open())
		{
			cin.clear();
			cout << "Error Unable to open file";
			cin.ignore(100, '\n');
			getchar();
			return 1;
		}

		cout << "Enter Principle amount borrowed: ";
		cin >> PV;
		if (PV < 150000) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Pricipal loan amount should be greater than 150000" << endl;
			continue;
		}
		cout << "Enter Annual Percentage rate:    ";
		cin >> a;
		if (a < 5) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Annual Percentage cannot be less than 5%" << endl;
			continue;
		}
		cout << "Enter Term in number of months:   ";
		cin >> n;
		if (n < 180) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Term cannot be less than 180 months" << endl;
			continue;
		}

		r = a / 1200;
		P = r * (PV) / (1 - (pow(1 + r, -n)));
		//P = P1 / P2;
		cout << "Monthly Payment amount= " << P << endl;

		outFile << "Paymt No" << setw(25) << "Principal" << setw(25) << "Interest" << setw(25) << "Balance" << endl;
		outFile << "--------" << setw(25) << "---------" << setw(25) << "--------" << setw(25) << "-------" << endl;
		outFile << "0" << setw(25) << "0" << setw(25) << "0" << setw(25) << PV << endl;

		for (i = 0; i < n; i++)
		{
			interest = PV * r;
			principal = P - interest;
			PV = PV - principal;
			outFile << fixed;
			outFile << setprecision(2);
			outFile << i + 1 << setw(30) << principal << setw(25) << interest << setw(25) << PV << endl;
			cout << fixed;
			cout << setprecision(2);
			cout << i + 1 << setw(30) << principal << setw(25) << interest << setw(25) << PV << endl;
		}
		outFile.close();
		cout << "Hit enter to calculate schedule for the next principal amount" << endl;
		getchar();
		cin.get();

	}


}


