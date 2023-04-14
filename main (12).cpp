#include "valid.h"
#include <iomanip>
#include <iostream>
using namespace std;

// Function prototypes
void printMenu();
void printWelcome();
void printGoodbye();
int getChoice();
void printAdultTicket();
void printChildrenTicket();
int getTickets(string ticketType);
int getAdultTicket();
int getChildrenTicket();
string getCustName();
float calcTotal(float adultTicket, float childrenTicket);
void printTotalPrice(float totalPrice);

const int ADD_TICKET = 1;
const int PRINT_TOTAL = 2;
const int CHECKOUT = 3;
const int ADULT_TICKET = 5.00;
const int CHILDREN_TICKET = 3.00;

int main() {
  // Declare all variables at the top of main() and initialize them.
  string custName = "";
  float adultTicket = 0.00;
  float totalAdultTicket = 0.00;
  float childrenTicket = 0.00;
  float totalChildrenTicket = 0.00;
  float totalPrice = 0.00;
  int choice = 0;
  int quantity = 0;
  string adultTickets = "Enter number of adult tickets: ";
  string childrenTickets = "Enter number of children tickets: ";

  
  printWelcome();

  
  while (choice != CHECKOUT) {
    printMenu();
    choice = getChoice();
    if (choice == ADD_TICKET) {
      custName = getCustName();
      adultTicket = getTickets("adult");
      childrenTicket = getTickets("children");
      totalAdultTicket = totalAdultTicket + adultTicket;
      totalChildrenTicket = totalChildrenTicket + childrenTicket;
    } else if (choice == PRINT_TOTAL) {
      totalPrice = calcTotal(totalAdultTicket, totalChildrenTicket);
      printTotalPrice(totalPrice);
    }
  }

  
  // Check to see if user purhased anything
  if (totalPrice > 0)
    printTotalPrice(totalPrice);
  else
    cout << "\nNo tickets purchased!" << endl;

  printGoodbye();
  return 0;
}


// print menu
void printMenu() {
  cout << "\n1. Buy tickets" << endl;
  cout << "2. Print total" << endl;
  cout << "3. Checkout" << endl;
}


// prints welcome message
void printWelcome() {
  cout << "Welcome to the swimming pool!\n" << endl;
  cout << "The adult ticket price is " << ADULT_TICKET << ".00" << endl;
  cout << "The children ticket price is " << CHILDREN_TICKET << ".00" << endl;
  cout << "\nEnter 1, 2, or 3 from the menu of choices." << endl;
}


// prints goodbye message
void printGoodbye() { cout << "\nThank you!" << endl; }


// Calculates the total price of the tickets.
float calcTotal(float adultTicket, float childrenTicket) {
  float totalPrice = 0.00;
  totalPrice = adultTicket * ADULT_TICKET + childrenTicket * CHILDREN_TICKET;
  return totalPrice;
}


// Print an output statement telling the user the total price.
void printTotalPrice(float totalPrice) {
  cout << fixed << setprecision(2) << "That will be $" << totalPrice << endl;
}


// prompts for and returns a valid choice
int getChoice() {
  int choice = 0;
  choice = getFloat("\nEnter choice: ");
  while (choice < 1 || choice > 3) {
    cout << "Invalid choice." << endl;
    choice = getFloat("\nEnter choice: ");
  }
  return choice;
}


// Asks for a valid customer name
string getCustName() {
  string custName = "";
  cout << "\nEnter customer name: ";
  getline(cin, custName);
  while (custName == "") {
    cout << "Must enter name." << endl;
    cout << "\nEnter customer name: ";
    getline(cin, custName);
  }
  return custName;
}


// Print an output statement for the user to enter the number of tickets.
int getTickets(string ticketType) {
  int ticket = 0;
  ticket = getInteger("Enter number of " + ticketType + " tickets: ");
  while (ticket < 0) {
    cout << "Must be 0 or more." << endl;
    ticket = getInteger("Enter number of " + ticketType + " tickets: ");
  }
  return ticket;
}
