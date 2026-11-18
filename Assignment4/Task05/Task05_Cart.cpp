
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Cart {
private:
    string items[10];
    double prices[10];
    int n;
    double discount;

public:
    Cart() : n(0), discount(0) {}

    // Return current object using this pointer
    Cart& add(const string& item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }
        return *this;
    }

    Cart& setDiscount(double d) {
        this->discount = d;
        return *this;
    }

    double total() const {
        double sum = 0;

        for (int i = 0; i < n; i++) {
            sum += prices[i];
        }

        return sum - (sum * discount / 100);
    }

    void display() const {
        cout << "\n--- Shopping Cart ---" << endl;

        for (int i = 0; i < n; i++) {
            cout << items[i] << ": " << prices[i] << endl;
        }

        cout << "Discount: " << discount << "%" << endl;
        cout << fixed << setprecision(2);
        cout << "Final Total: " << total() << endl;
    }
};

int main() {
    Cart c;

    Cart* ptr = &c;

    ptr->add("Book", 60)
        .add("Bag", 120)
        .add("Shoes", 180)
        .setDiscount(10);

    ptr->display();

    cout << "\nAccess using reference:" << endl;

    Cart& ref = c;
    cout << "Total using reference: "
         << ref.total() << endl;

    return 0;
}
