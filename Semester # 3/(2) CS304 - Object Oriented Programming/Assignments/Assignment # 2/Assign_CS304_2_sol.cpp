// Assignment # 2

#include <iostream>
using namespace std;

// Abstract class
class Vehicle
{
protected:
  double baseRate;
  double taxRate;

public:
  Vehicle(double base, double tax) : baseRate(base), taxRate(tax) {}

  virtual double getBaseRate()
  {
    return baseRate;
  }

  virtual double calculateTaxes() = 0; // Pure virtual function
  virtual double calculateTotalCost() = 0;

  virtual ~Vehicle() {} // Virtual destructor
};

// NormalCar class derived from Vehicle
class NormalCar : public Vehicle
{
public:
  // Constructor: sets baseRate and fixed taxRate = 15%
  NormalCar(double base) : Vehicle(base, 0.15) {}

  // Override calculateTaxes
  double calculateTaxes() override
  {
    return taxRate * baseRate;
  }

  // Override calculateTotalCost
  double calculateTotalCost() override
  {
    return calculateTaxes() + baseRate;
  }
};

// LuxuryCar class derived from Vehicle
class LuxuryCar : public Vehicle
{
private:
  double Eduty;

public:
  // Constructor: sets baseRate, taxRate = 20%, Eduty = 30000
  LuxuryCar(double base) : Vehicle(base, 0.20), Eduty(30000) {}

  // Override calculateTaxes
  double calculateTaxes() override
  {
    return (taxRate * baseRate) + Eduty;
  }

  // Override calculateTotalCost
  double calculateTotalCost() override
  {
    return calculateTaxes() + baseRate;
  }
};

int main()
{
  // Polymorphic pointers
  Vehicle *v1 = new NormalCar(500000);  // baseRate = 500000
  Vehicle *v2 = new LuxuryCar(2000000); // baseRate = 2000000

  // Display total costs using polymorphism
  cout << "standard car total cost: " << v1->calculateTotalCost() << endl;
  cout << "Luxury car total cost : " << v2->calculateTotalCost() << endl;

  // Clean up
  delete v1;
  delete v2;

  cout << "\nprogram finished with exit code 0 \nplease press Enter to exit the console." << endl;
  cin.get(); // Wait for Enter
  return 0;
}
