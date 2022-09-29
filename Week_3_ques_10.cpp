#include <iostream>
using namespace std;

class Weight 
{
private:
	int pound, ounce;
public:
	//Constructors
	Weight();
	Weight(const int& p, const int& o);

	//setters
	void setPound(const int& p);
	void setOunce(const int& o);

	//getters
	int getPound() const;
	int getOunce() const;

	//operators
	//w + w
	Weight operator+(const Weight& w) const; 
	//++w
	Weight& operator++();
	//W++
	Weight operator++(int DUMMY);

	//input streaming operator
	friend istream& operator>>(istream& in, Weight& w);
	friend ostream& operator<<(ostream& out, const Weight& w);
};

//Constructors
Weight::Weight(): pound(0), ounce(0) {}
Weight::Weight(const int& p, const int& o){
		pound = (p < 0) ? 0 : p;
		ounce = (o < 0 || o > 15) ? 0 : o;
	}

//setters
void Weight::setPound(const int& p){pound = p;}
void Weight::setOunce(const int& o){ounce = o;}

//getters
int Weight::getPound() const{return pound;}
int Weight::getOunce() const{return ounce;}

//operators
//w + w
Weight Weight::operator+(const Weight& w) const{
	int p1 = this-> pound;
	int o1 = this-> ounce;
	int p2 = w.pound;
	int o2 = w.ounce;
	Weight ans(p1+p2, o1+o2);
	return ans;}
//doube pre-increment is fine but post is not fine
//++ ++ w
//Pre-increment 
Weight& Weight::operator++(){
	Weight temp(1,1);
	*this = *this + temp;
	return *this;}

//double post-increment is not fine 
//i.e. w++ ++ is wrong
//Post increment
Weight Weight::operator++(int DUMMY){
	Weight temp = *this;
	Weight add(1,1);
	*this = *this + add;
	return temp;}

//input streaming operator
istream& operator>>(istream& in, Weight& w){
	cout << endl;
	cout << "\tPlease enter the weight in pounds: ";
	in >> w.pound;
	cout << "\tPlease enter the weight in ounces: ";
	in >> w.ounce;
	return in;}
ostream& operator<<(ostream& out, const Weight& w){
	out << w.pound << " Pounds and " << w.ounce << " Ounces";
	return out;}

int main()
{
	Weight w1, w2(13,3), w3(15,15);
	cout << "w1: " << w1 << endl;
	cout << "w2: " << w2 << endl;
	w1 = w2 + w3;
	cout << "w1: " << w1 << endl;
	++ ++w1;
	cout << "w1: " << w1 << endl;
	Weight w4;
	cout << "Please enter the values for w4: ";
	cin >> w4;
	cout << "w4: " << w4 << endl;

	system("Pause");
	return 0;
}

