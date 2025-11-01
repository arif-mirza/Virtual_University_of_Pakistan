// Assignment # 2

#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class LibraryMember
{
protected:
  int memberId;
  string memberName;
  double membershipFee;

public:
  LibraryMember(int id, string name) : memberId(id), memberName(name), membershipFee(0.0) {}

  virtual void calculateMembershipFee() = 0;
  virtual void displayDetails() const = 0;

  virtual ~LibraryMember() {}
};

// Student Member Class
class StudentMember : public LibraryMember
{
private:
  double baseFee;
  double discount;

public:
  StudentMember(int id, string name, double baseFee, double discount)
      : LibraryMember(id, name), baseFee(baseFee), discount(discount) {}

  void calculateMembershipFee() override
  {
    membershipFee = baseFee - discount;
  }

  void displayDetails() const override
  {
    cout << "\n=== Student Member ===\n";
    cout << "ID: " << memberId << endl;
    cout << "Name: " << memberName << endl;
    cout << "Base Fee: " << baseFee << endl;
    cout << "Discount: " << discount << endl;
    cout << "Membership Fee: " << membershipFee << endl;
  }

  ~StudentMember() {}
};

// Faculty Member Class
class FacultyMember : public LibraryMember
{
private:
  double baseFee;
  double facilityFee;

public:
  FacultyMember(int id, string name, double baseFee, double facilityFee)
      : LibraryMember(id, name), baseFee(baseFee), facilityFee(facilityFee) {}

  void calculateMembershipFee() override
  {
    membershipFee = baseFee + facilityFee;
  }

  void displayDetails() const override
  {
    cout << "\n=== Faculty Member ===\n";
    cout << "ID: " << memberId << endl;
    cout << "Name: " << memberName << endl;
    cout << "Base Fee: " << baseFee << endl;
    cout << "Facility Fee: " << facilityFee << endl;
    cout << "Membership Fee: " << membershipFee << endl;
  }

  ~FacultyMember() {}
};

int main()
{
  cout << "===== Membership Detail =====\n";

  // Base class pointer array
  LibraryMember *members[2];

  // Dynamic object creation
  members[0] = new StudentMember(101, "Ahmad Mustafa", 5000, 1000);
  members[1] = new FacultyMember(201, "Azam khan", 7000, 2000);

  // Call functions using polymorphism
  for (int i = 0; i < 2; i++)
  {
    members[i]->calculateMembershipFee();
    members[i]->displayDetails();
  }

  // Free memory
  for (int i = 0; i < 2; i++)
  {
    delete members[i];
  }

  return 0;
}
