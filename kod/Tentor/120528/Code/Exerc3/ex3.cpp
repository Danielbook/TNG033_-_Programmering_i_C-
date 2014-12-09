#include <iostream>
#include <iomanip>

using namespace std;

/********************************
* Class Customer definition     *
*********************************/

class Customer {
    public:

        Customer(int id, int lim) : ID (id), credit_limit(lim)
        { debt = 0; } ;

        int get_ID() const
        {
            return ID;
        }

        bool update_debt(double d);

        virtual double to_pay() const
        {
            return debt;
        };

        int get_credit_limit() const
        {
            return credit_limit;
        };

        friend ostream& operator<<(ostream& os, const Customer& c);

    protected:

        int ID;
        const int credit_limit;
        double debt;

     virtual void display(ostream& os) const;
};


/*****************************************************
* Class Customer member functions implementation     *
******************************************************/

bool Customer::update_debt(double d)
{
    if (d + debt > credit_limit)
        return false;

    debt += d;
    return true;
}

void Customer::display(ostream& os) const
{
    os << "Invoice for customer: " << ID << endl;
    os << "======================================" << endl;

    os << "Amount to pay: "
        << fixed << setprecision(2) << debt << " sek" << endl;

    os << "======================================" << endl;


}

ostream& operator<<(ostream& os, const Customer& c)
{
    c.display(os);

    return os;
}


/*********************************
* Class Good_Customer definition *
**********************************/


class Good_Customer : public Customer {
    public:

        Good_Customer(int id, int lim, double disc)
         : Customer(id, lim), discount(disc)
        {
            if (discount > max_discount)
                max_discount = discount;
        };

        double to_pay() const
        {
            if (debt)
                return (debt - discount);

             return 0;

        };

        void set_discount(double d)
        {
            if (d > 0)
            {
                discount = d;
                if (d > max_discount)
                    max_discount = d;
            }
        }

        static double get_max_discount()
        {
            return max_discount;
        }


    protected:
        double discount;

    static double max_discount;


    virtual void display(ostream& os) const;
};



/********************************************************
* Class Good_Customer member functions implementation   *
*********************************************************/

double Good_Customer::max_discount = 0;

void Good_Customer::display(ostream& os) const
{
    os << "Invoice for customer: " << ID << endl;
    os << "======================================" << endl;

    os << "Debt: "
        << fixed << setprecision(2) << debt << " sek" << endl;

    os << "Discount offered: "
        << fixed << setprecision(2) << discount << " sek" << endl;

    os << "Amount to pay: "
        << fixed << setprecision(2) << to_pay() << " sek" << endl;

    os << "======================================" << endl;
}



/*********************************
* Class Bad_Customer definition  *
**********************************/


class Bad_Customer : public Customer {
    public:

        Bad_Customer(int id, int lim, double ir)
         : Customer(id, lim), interest_rate(ir)
        {
            if (interest_rate > max_rate)
                max_rate = interest_rate;
        };

        double to_pay() const
        {
            if (debt)
                return (debt + debt*interest_rate/100.0);

             return 0;

        };

        void set_interest_rate(int ir)
        {
            if (ir > 0)
            {
                interest_rate = ir;
                if (ir > max_rate)
                    max_rate = ir;
            }



        }

        static int get_max_rate()
        {
            return max_rate;
        }


    protected:
        int interest_rate;

    static int max_rate;

    virtual void display(ostream& os) const;
};



/********************************************************
* Class Bad_Customer member functions implementation    *
*********************************************************/

int Bad_Customer::max_rate = 0;

void Bad_Customer::display(ostream& os) const
{
    os << "Invoice for customer: " << ID << endl;
    os << "======================================" << endl;

    os << "Debt: "
        << fixed << setprecision(2) << debt << " sek" << endl;

    os << "Interest rate: "
        << fixed << setprecision(2) << interest_rate << "%" << endl;

    os << "Interest to pay: "
        << fixed << setprecision(2)
        << debt*interest_rate/100.0 << endl;

    os << "Amount to pay: "
        << fixed << setprecision(2) << to_pay() << " sek" << endl;

    os << "======================================" << endl;
}


/**************************************
* Main function                       *
***************************************/


int main()
{
    const int MAX = 6;

    Customer C1(1, 200);
    Good_Customer C2(2,200,10);
    Bad_Customer C3(3,100,5);

    Customer* DB[MAX];
    int howMany = 3;

    DB[0] = &C1;
    DB[1] = &C2;
    DB[2] = &C3;

    for(int i = 0; i < 3; i++)
        cout << "Customer " << DB[i]->get_ID()
             << " has credit limit "
             << DB[i]->get_credit_limit() << endl << endl;

    if (!C1.update_debt(51))
        cout << "update customer " << C1.get_ID()
             << " debt not possible!!"  << endl;

    if (!C2.update_debt(52))
        cout << "update customer " << C2.get_ID()
             << " debt not possible!!"  << endl;

    if (!C3.update_debt(53))
        cout << "update customer " << C3.get_ID()
             << " debt not possible!!"  << endl;


    for(int i = 0; i < howMany; i++)
        cout << "Customer " << DB[i]->get_ID()
             << " should pay " << DB[i]->to_pay() << endl << endl;

    if (!C3.update_debt(200))
        cout << "Update customer " << C3.get_ID()
             << " debt not possible!!"  << endl << endl;

    const Good_Customer C4(4,400,20);
    const Bad_Customer C5(5,80,10);

    cout << "Customer " << C4.get_ID()
         << " has credit limit "
         << C4.get_credit_limit()
         << " and should pay " << C4.to_pay() << endl;;

    cout << "Customer " << C5.get_ID()
         << " has credit limit "
         << C5.get_credit_limit()
         << " and should pay " << C4.to_pay() << endl << endl;

    C2.set_discount(50);
    C3.set_interest_rate(15);

    cout << endl << "INVOICES" << endl << endl;
    for(int i = 0; i < 3; i++)
        cout << *DB[i] << endl << endl;

    cout << "Max discount offered to a customer: "
         << Good_Customer::get_max_discount() << endl;

    cout << "Max interest rate: "
         << Bad_Customer::get_max_rate() << endl;


    return 0;
}
