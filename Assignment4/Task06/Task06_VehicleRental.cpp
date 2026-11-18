
#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Vehicle {
protected:
    string registration;
    double dailyRate;
    bool rented;

public:
    Vehicle(string r, double rate)
        : registration(r), dailyRate(rate), rented(false) {}

    virtual ~Vehicle() = default;

    virtual double rentalCharge(int days) const = 0;

    virtual void display() const {
        cout << "Registration: " << registration << endl;
        cout << "Daily Rate: " << dailyRate << endl;
        cout << "Status: " << (rented ? "Rented" : "Available") << endl;
    }

    void rent() {
        rented = true;
    }

    void returnVehicle() {
        rented = false;
    }
};

// Bicycle
class Bicycle : public Vehicle {
public:
    Bicycle(string r, double rate)
        : Vehicle(r, rate) {}

    double rentalCharge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "\n--- Bicycle ---" << endl;
        Vehicle::display();
    }
};

// Abstract motor vehicle
class MotorVehicle : public Vehicle {
protected:
    double fuelLevel;
    string serviceDueDate;

public:
    MotorVehicle(string r, double rate,
                 double fuel, string date)
        : Vehicle(r, rate),
          fuelLevel(fuel), serviceDueDate(date) {}

    void displayMotorDetails() const {
        cout << "Fuel/Charge Level: " << fuelLevel << endl;
        cout << "Service Due Date: " << serviceDueDate << endl;
    }
};

// Two Wheeler
class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string r, double rate,
               double fuel, string date)
        : MotorVehicle(r, rate, fuel, date) {}

    double rentalCharge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "\n--- Two Wheeler ---" << endl;
        Vehicle::display();
        displayMotorDetails();
    }
};

// Car
class Car : public MotorVehicle {
protected:
    int seatingCapacity;

public:
    Car(string r, double rate, double fuel,
        string date, int seats)
        : MotorVehicle(r, rate, fuel, date),
          seatingCapacity(seats) {}

    double rentalCharge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "\n--- Car ---" << endl;
        Vehicle::display();
        displayMotorDetails();
        cout << "Seating Capacity: " << seatingCapacity << endl;
    }
};

// Electric Car
class ElectricCar : public Car {
private:
    double batteryCapacity;
    double kwhUsedPerDay;
    double pricePerKwh;

public:
    ElectricCar(string r, double rate, double charge,
                string date, int seats,
                double battery, double usage, double price)
        : Car(r, rate, charge, date, seats),
          batteryCapacity(battery),
          kwhUsedPerDay(usage),
          pricePerKwh(price) {}

    double rentalCharge(int days) const override {
        return dailyRate * days +
               kwhUsedPerDay * days * pricePerKwh;
    }

    void display() const override {
        cout << "\n--- Electric Car ---" << endl;
        Vehicle::display();
        displayMotorDetails();
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

// New vehicle type added without modifying existing classes
class ElectricBus : public MotorVehicle {
private:
    int seatingCapacity;
    double kwhUsedPerDay;
    double pricePerKwh;

public:
    ElectricBus(string r, double rate, double charge,
                string date, int seats,
                double usage, double price)
        : MotorVehicle(r, rate, charge, date),
          seatingCapacity(seats),
          kwhUsedPerDay(usage),
          pricePerKwh(price) {}

    double rentalCharge(int days) const override {
        return dailyRate * days +
               kwhUsedPerDay * days * pricePerKwh;
    }

    void display() const override {
        cout << "\n--- Electric Bus ---" << endl;
        Vehicle::display();
        displayMotorDetails();
        cout << "Seating Capacity: " << seatingCapacity << endl;
    }
};

int main() {
    Bicycle bicycle("B101", 100);
    TwoWheeler bike("T201", 250, 5, "2026-12-15");
    Car car("C301", 1500, 40, "2026-12-20", 5);
    ElectricCar electricCar(
        "E401", 1800, 90, "2026-12-25",
        5, 60, 12, 8
    );
    ElectricBus bus(
        "EB501", 4000, 80, "2027-01-10",
        40, 50, 8
    );

    Vehicle* fleet[] = {
        &bicycle, &bike, &car, &electricCar, &bus
    };

    cout << "===== UNIVERSITY VEHICLE RENTAL SYSTEM =====" << endl;

    for (Vehicle* v : fleet) {
        v->display();
        cout << "Rental for 2 days: Rs. "
             << v->rentalCharge(2) << endl;
    }

    cout << "\n===== RENTAL OPERATIONS =====" << endl;

    car.rent();
    cout << "Car rented successfully." << endl;
    car.display();

    car.returnVehicle();
    cout << "\nCar returned successfully." << endl;
    car.display();

    cout << "\n===== LATE RETURN CHARGE =====" << endl;

    int lateDays = 2;
    double lateFeePerDay = 200;

    cout << "Late days: " << lateDays << endl;
    cout << "Late fee: Rs. "
         << lateDays * lateFeePerDay << endl;

    return 0;
}
