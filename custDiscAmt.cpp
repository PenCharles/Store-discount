#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
using namespace std;

	//Author: James Saylor
	//Description : This program determines the discount based on the customers
	//status with the store

//constants
const int MIN_PURCH_RATE1 = 50;
const int MIN_PURCH_RATE2 = 100;
const int MIN_PURCH_RATE3 = 200;
const double GEN_CLUB_CUST1 = 0.03;
const double GEN_CUST1 = 0.05;
const double GEN_CUST2 = 0.08;
const double GEN_CUST3 = 0.16;
const double CLUB_CUST1 = 0.07;
const double CLUB_CUST2 = 0.12;
const double CLUB_CUST3 = 0.20;
const double CARD_HOLDER = 0.20;
const double GOLD_HOLDER = 0.25;
const double SALES_TAX = 0.075;
const string GEN_PUB = "General Public";
const string REWARDS_MEM = "Rewards Member";
const string CREDIT_MEM = "Card Holder";
const string GOLD_MEM = "Gold Card Holder";

//functions
double DiscountRate(char type, double num)
{
	char cardType;
	double rate;
	
	//determine discount
	if(type == 'C')
	{
		cout << endl << endl << "Credit card type (S for standard, G for gold): ";
		cin >> cardType;
		cardType = static_cast<char>(toupper(cardType));
		
		if(cardType == 'G')
		{
			rate = GOLD_HOLDER;
		}
		else
		{
			rate = CARD_HOLDER;
		}
	}
	else
	{
		if(num < MIN_PURCH_RATE1)
		{
			if(type == 'P' || type == 'R')
			{
				rate = GEN_CLUB_CUST1;
			}
		}
		else if(num >= MIN_PURCH_RATE1 && num < MIN_PURCH_RATE2)
		{
			if(type == 'P')
			{
				rate = GEN_CUST1;
			}
			else
			{
				rate = CLUB_CUST1;
			}
		}
		else if(num >= MIN_PURCH_RATE2 && num < MIN_PURCH_RATE3)
		{
			if(type == 'P')
			{
				rate = GEN_CUST2;
			}
			else
			{
				rate = CLUB_CUST2;
			}
		}
		else
		{
			if(type == 'P')
			{
				rate = GEN_CUST3;
			}
			else
			{
				rate = CLUB_CUST3;
			}
		}
	}
	
	return rate;
}

int main ()
{
//variables
char custType;
string customerCategory;
double totalAmount;
double discount;
double discountedAmount;
double subTotal;
double taxes;
double totalBill;
	
	//input
	cout << "Department Store Sale Bill Calculator" << endl << endl;
	cout << "Customer Type Choices:" << endl;
	cout << "    P - general public" << endl;
	cout << "    R - rewards club member" << endl;
	cout << "    C - credit card holder" << endl << endl;
	cout << "Enter customer type: ";
	cin >> custType;
	custType = static_cast<char>(toupper(custType));
	cout << endl << endl << "Enter total amount of purchase: ";
	cin >> totalAmount;
	discount = DiscountRate(custType, totalAmount);
	
	//math
	discountedAmount = totalAmount * discount;
	subTotal = totalAmount - discountedAmount;
	taxes = subTotal * SALES_TAX;
	totalBill = subTotal + taxes;
	
	//determine customer category
	if(custType == 'P')
		customerCategory = GEN_PUB;
	else if(custType == 'R')
		customerCategory = REWARDS_MEM;
	else if (custType == 'C' && discount == CARD_HOLDER)
		customerCategory = CREDIT_MEM;
	else
		customerCategory = GOLD_MEM;
	
	//output
	cout << endl << endl << "Department Store Bill" << endl << endl;
	cout << "  Customer Category:" << setw(20) << customerCategory << endl;
	cout << "  Discount Rate:" << setw(23) << discount * 100 << "%" << endl << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "  Total Purchase Amount:" << setw(7) << "$" << setw(9) << totalAmount << endl;
	cout << "  Less Discounted Amount:" << setw(6) << "$" << setw(9) << discountedAmount;
	cout << endl << setw(40) << "----------" << endl;
	cout << "  Subtotal after discount:" << setw(5) << "$" << setw(9) << subTotal;
	cout << endl << "  Plus Sales Tax (7.5%)" << setw(8) << "$" << setw(9) << taxes;
	cout << endl << setw(40) << "----------" << endl;
	cout << "  Total Bill:" << setw(18) << "$" << setw(9) << totalBill;
	
  	cout << endl << endl;
 	return 0;
}

