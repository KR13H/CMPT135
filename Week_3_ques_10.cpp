#include <iostream>

class Weight {
    private:
        int pounds;
        int ounces;

    public:
        // Constructors
        Weight() {
            pounds = 0;
            ounces = 0;
        }

        Weight(int p, int o) {
            pounds = p + o / 16;
            ounces = o % 16;
            if (ounces < 0) {
                pounds--;
                ounces += 16;
            }
        }

        // Getters
        int getPounds() {
            return pounds;
        }

        int getOunces() {
            return ounces;
        }

        // Setters
        void setPounds(int p) {
            pounds = p;
        }

        void setOunces(int o) {
            ounces = o % 16;
            if (o < 0) {
                pounds = pounds + o / 16 - 1;
                ounces = 16 + o % 16;
            } else {
                pounds = pounds + o / 16;
                ounces = o % 16;
            }
        }
};

int main() 
{
    Weight w1;
    Weight w2(5, 20);

    std::cout << "Weight 1: " << w1.getPounds() << " pounds " << w1.getOunces() << " ounces" << std::endl;
    std::cout << "Weight 2: " << w2.getPounds() << " pounds " << w2.getOunces() << " ounces" << std::endl;

    w1.setPounds(6);
    w1.setOunces(20);
    std::cout << "Weight 1: " << w1.getPounds() << " pounds " << w1.getOunces() << " ounces" << std::endl;

    system("Pause");
    return 0;
}
