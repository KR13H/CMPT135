#include <iostream>
#include <string>

using namespace std;

class Bank_Account
{
protected:
	string account_holder;
	double balance;
public:
	//default-constructors
	Bank_Account();
	//non-default constructors
	Bank_Account(const string& a, const double& b); 
	//copy constructors
	Bank_Account(const Bank_Account& b);
	//Destructor
	~Bank_Account();
	//Assignemnet operator
	Bank_Account& operator=(const Bank_Account&);
	//getters
	string get_account_holder() const;
	double get_balance() const;
	//setters
	void set_account_holder(const string& a);
	void set_balance(const double& b);
	//additional member functions
	void readInfo(istream& in);
	void printInfo(ostream& out) const;
	friend istream& operator>>(istream& in, Bank_Account& b);
	friend ostream& operator<<(ostream& out,const Bank_Account& b);
};
//default-constructors
Bank_Account::Bank_Account(): account_holder("N/A"), balance(0.0)
{
	cout << "Inside Bank_Account default constructor" << endl;
}
//non-default constructors
Bank_Account::Bank_Account(const string& a, const double& b): account_holder(a), balance(b)
{
	cout << "Inside Bank_Account non-default constructor" << endl;
}
//copy constructors
Bank_Account::Bank_Account(const Bank_Account& b)
{
	this->account_holder = b.get_account_holder();
	this->balance = b.get_balance();
	cout << "Inside Bank_Account copy constructor" << endl;
}

//Destructor
Bank_Account::~Bank_Account()
{
	cout << "Inside Bank_Account destructor" << endl;
}
//Assignemnet operator
Bank_Account& Bank_Account::operator=(const Bank_Account& b)
{
	this->account_holder = b.get_account_holder();
	this->balance = b.get_balance();
	return *this;
}
//getters
string Bank_Account::get_account_holder() const
{
	return this->account_holder;
}

double Bank_Account::get_balance() const
{
	return this->balance;
}
//setters
void Bank_Account::set_account_holder(const string& a)
{
	this->account_holder = a;
}
void Bank_Account::set_balance(const double& b)
{
	this->balance = b;
}
//additional member functions
void Bank_Account::readInfo(istream& in)
{
	cout << endl;
	cout << "\tEnter account_holder:"; in >> this->account_holder;
	cout << "\tEnter balance:"; in >> this->balance;
}
void Bank_Account::printInfo(ostream& out) const
{
	out << endl;
	out << "account_holder: " << this->account_holder << endl;
	out << "balance: " << this->balance << endl;
}
istream& operator>>(istream& in, Bank_Account& b)
{
	b.readInfo(in);
	return in;
}
ostream& operator<<(ostream& out,const Bank_Account& b)
{
	b.printInfo(out);
	return out;
}

class Chequing_Accout : public Bank_Account
{
protected:
	int max_num_trans; int num_trans;
public:
	//default-constructors
	Chequing_Accout();
	//non-default constructors
	Chequing_Accout(const string& a, const double& b, const int& t, const int& n); 
	//copy constructors
	Chequing_Accout(Chequing_Accout& c);
	//Destructor
	~Chequing_Accout();
	//Assignemnet operator
	Chequing_Accout& operator=(const Chequing_Accout&);
	//getters
	int get_max_num_trans() const;
	int get_num_trans() const;
	//setters
	void set_max_num_tran(const int& n);
	void set_num_trans(const int& n);
	//Additional member functions
	void deposit(const double& amount);
	void withdraw(const double& amount);
	void advance_month();
	//readinfo
	void readInfo(istream& in);
	//print info
	void printInfo(ostream& out) const;
	//operators for input and output
	friend istream& operator>>(istream& in, Chequing_Accout& c);
	friend ostream& operator<<(ostream& out, const Chequing_Accout& c);
};
//default-constructors
Chequing_Accout::Chequing_Accout(): Bank_Account(), max_num_trans(0), num_trans(0)
{
	cout << "Inside default constructor" << endl;
}

//non-default constructors
Chequing_Accout::Chequing_Accout(const string& a, const double& b, const int& t, const int& n): Bank_Account(a,b), max_num_trans(0), num_trans(0)
{
	cout << "Inside non-default constructor" << endl;
}
//copy constructors
Chequing_Accout::Chequing_Accout(Chequing_Accout& c): Bank_Account(c), max_num_trans(c.max_num_trans), num_trans(c.num_trans)
{
	cout << "Inside copy constructor" << endl;
}
//Destructor
Chequing_Accout::~Chequing_Accout()
{
	cout << "Inside destructor" << endl;
}

//Assignemnet operator
Chequing_Accout& Chequing_Accout::operator=(const Chequing_Accout& c)
{
	this->Bank_Account::operator=(c);
	this->max_num_trans = c.max_num_trans;
	this->num_trans= c.num_trans;
	return *this;
}

//getters
int Chequing_Accout::get_max_num_trans() const
{
	return max_num_trans;
}
int Chequing_Accout::get_num_trans() const
{
	return num_trans;
}
//setters
void Chequing_Accout::set_max_num_tran(const int& n)
{
	max_num_trans = n;
}
void Chequing_Accout::set_num_trans(const int& n)
{
	num_trans = n;
}
//Additional member functions
void Chequing_Accout::deposit(const double& amount)
{
	if (num_trans >= max_num_trans) 
	{
            cout << "Maximum number of transactions reached." << endl;
            return;
    }
        balance += amount;
        num_trans++;
}
void Chequing_Accout::withdraw(const double& amount)
{
	if (num_trans >= max_num_trans) 
	{
		cout << "Maximum number of transactions reached." << endl;
		return;
	}
	if (balance < amount) 
	{
		cout << "Insufficient balance." << endl;
		return;
	}
	balance -= amount;
	num_trans++;
}
void Chequing_Accout::advance_month()
{
	num_trans = 0;
}
//readinfo
void Chequing_Accout::readInfo(istream& in)
{
	this->Bank_Account::readInfo(in);
	cout << "\t Enter the max number of transactions:";
	cin >> this->max_num_trans;
	cout << "\t Enter the num of transactions:";
	cin >> this->num_trans;
}

//print info
void Chequing_Accout::printInfo(ostream& out) const
{
	this->Bank_Account::printInfo(out);
	out << "max number of transactions: " << this->max_num_trans << endl;
	out << "num of transactions: " << this->num_trans << endl;
}
//operators for input and output
istream& operator>>(istream& in, Chequing_Accout& c)
{
	c.readInfo(in);
	return in;
}
ostream& operator<<(ostream& out, const Chequing_Accout& c)
{
	c.printInfo(out);
	return out;
}

class Saving_Account : public Bank_Account
{
protected:
	double interest_rate;
	int num_days;
public:
	//Constructors
	Saving_Account();
	Saving_Account(const string& a, const double& b, const double& i, const int& n);
	//Copy constructors
	Saving_Account(const Saving_Account& s);
	//Assignment operator
	Saving_Account& operator=(const Saving_Account& s);
	//Destructor
	~Saving_Account();
	//getters
	double get_interest_rate() const;
	int get_num_days() const;
	int get_balance();
	//setters
	void set_interest_rate(const double& i);
	void set_num_days(const int&  n);
	//read info and print info
	void readInfo(istream& in);
	void printInfo(ostream& out) const;
	//input and output operators
	friend istream& operator>>(istream& in, Saving_Account& s);
	friend ostream& operator<<(ostream& out, const Saving_Account& s);
};

//Constructors
Saving_Account::Saving_Account(): Bank_Account(), interest_rate(0), num_days(0)
{
	cout << "Inside default constructor" << endl;
}
Saving_Account::Saving_Account(const string& a, const double& b, const double& i, const int& n): Bank_Account(a,b), interest_rate(i), num_days(n)
{
	cout << "Inside non-default constructor" << endl;
}
//Copy constructors
Saving_Account::Saving_Account(const Saving_Account& s): Bank_Account(s), interest_rate(s.interest_rate), num_days(s.num_days)
{
	cout << "Inside copy constructor" << endl;
}
//Assignment operator
Saving_Account& Saving_Account::operator=(const Saving_Account& s)
{
	this->Bank_Account::operator=(s);
	interest_rate = s.interest_rate;
	num_days = s.num_days;
	return *this;
}
//Destructor
Saving_Account::~Saving_Account()
{
	cout << "Inside destructor" << endl;
}
//getters
double Saving_Account::get_interest_rate() const
{
	return interest_rate;
}
int Saving_Account::get_num_days() const
{
	return num_days;
}
int Saving_Account::get_balance()
{
	double interest = this->balance * (this->interest_rate / 100) * (num_days/365);
	return balance + interest;
}
//setters
void Saving_Account::set_interest_rate(const double& i)
{
	interest_rate = i;
}
void Saving_Account::set_num_days(const int&  n)
{
	num_days = n;
}
//read info and print info
void Saving_Account::readInfo(istream& in)
{
	this->Bank_Account::readInfo(in);
	cout << "Please enter the interest rate:";
	cin >> this->interest_rate;
	cout << "Please enter the number of days:";
	cin >> this->num_days;
}
void Saving_Account::printInfo(ostream& out) const
{
	this->Bank_Account::printInfo(out);
	out << "Interest rate: " << this->interest_rate;
	out << "Number of days: " << this->num_days;
}
//input and output operators
istream& operator>>(istream& in, Saving_Account& s)
{
	s.readInfo(in);
	return in;
}
ostream& operator<<(ostream& out, const Saving_Account& s)
{
	s.printInfo(out);
	return out;
}

int main() 
{
    Chequing_Accout* account1 = new Chequing_Accout("John Smith", 1000.0, 0,5);
    account1->deposit(500.0);
    account1->deposit(300.0);
    account1->withdraw(200.0);
    cout << "Account balance: " << account1->get_balance() << endl;
    Chequing_Accout* account2 = new Chequing_Accout("Jane Doe", 2000.0, 0,3);
    account2->deposit(1000.0);
    account2->deposit(500.0);
    account2->withdraw(700.0);
    account2->withdraw(300.0);
    account2->withdraw(100.0);
    account2->deposit(200.0);
    cout << "Account balance: " << account2->get_balance() << endl;
    account2->advance_month();
    account2->withdraw(200.0);
    cout << "Account balance: " << account2->get_balance() << endl;
    Bank_Account* account3 = new Saving_Account("Sarah Johnson", 5000.0, 3.5, 365);
    cout << "Account balance: " << account3->get_balance() << endl;
    delete account1;
    delete account2;
    delete account3;
	system("Pause");
    return 0;
}







