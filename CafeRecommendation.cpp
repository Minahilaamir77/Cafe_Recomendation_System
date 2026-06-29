#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// function to display menu nicely
void showMenu(string items[], int prices[], bool isVeg[], bool isSpicy[], int size)
{
    cout << "\n==================== AI CAFE MENU ====================\n";
    cout << left << setw(5) << "ID"
         << setw(22) << "Item"
         << setw(10) << "Price"
         << setw(12) << "Type"
         << setw(12) << "Spice" << endl;
    cout << "------------------------------------------------------\n";

    for (int i = 0; i < size; i++)
    {
        cout << left << setw(5) << (i + 1)
             << setw(22) << items[i]
             << setw(10) << prices[i]
             << setw(12) << (isVeg[i] ? "Veg" : "Non-Veg")
             << setw(12) << (isSpicy[i] ? "Spicy" : "Non-Spicy")
             << endl;
    }

    cout << "======================================================\n";
}

int main()
{
    const int SIZE = 10;

    // menu data
    string items[SIZE] =
    {
        "French Fries", "Veg Sandwich", "Spicy Veg Roll", "Pasta Alfredo",
        "Chicken Burger", "Spicy Chicken Wrap", "Beef Burger",
        "Hot Wings", "Mint Lemonade", "Cold Coffee"
    };

    int prices[SIZE] =
    {120, 180, 220, 300, 280, 320, 350, 260, 140, 200};

    bool isVeg[SIZE] =
    {1,1,1,1,0,0,0,0,1,1};

    bool isSpicy[SIZE] =
    {0,0,1,0,0,1,0,1,0,0};

    cout << "Welcome to AI Cafe!\n";
    showMenu(items, prices, isVeg, isSpicy, SIZE);

    // ------------------ BUDGET INPUT (safe input handling) ------------------

    int budget;

    cout << "\nEnter your budget (PKR): ";

    while (!(cin >> budget))  // prevents crash if user types letter
    {
        cout << "Invalid input. Please enter numbers only: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    if (budget < 0)
    {
        cout << "Budget cannot be negative. Setting to 0.\n";
        budget = 0;
    }

    // ------------------ PREFERENCES ------------------

    int vegChoice;
    int spicyChoice;

    cout << "Veg? (1 = Veg, 0 = Non-Veg): ";
    while (!(cin >> vegChoice) || (vegChoice != 0 && vegChoice != 1))
    {
        cout << "Enter only 1 or 0: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Spicy? (1 = Spicy, 0 = Non-Spicy): ";
    while (!(cin >> spicyChoice) || (spicyChoice != 0 && spicyChoice != 1))
    {
        cout << "Enter only 1 or 0: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // ------------------ SIMPLE AI SUGGESTION ------------------

    cout << "\nAI Recommendations within your budget:\n";

    bool found = false;

    for (int i = 0; i < SIZE; i++)
    {
        if (prices[i] <= budget &&
            isVeg[i] == vegChoice &&
            isSpicy[i] == spicyChoice)
        {
            cout << "ID " << (i + 1)
                 << " - " << items[i]
                 << " (PKR " << prices[i] << ")\n";
            found = true;
        }
    }

    if (!found)
        cout << "No exact match found.\n";

    // ------------------ ORDER SECTION ------------------

    int orderId[50];
    int orderQty[50];
    int orderCount = 0;

    cout << "\nPlace your order (Enter 0 to stop)\n";

    while (true)
    {
        if (orderCount >= 50)
        {
            cout << "Maximum 50 items allowed.\n";
            break;
        }

        int id;
        cout << "Enter Item ID: ";

        while (!(cin >> id))
        {
            cout << "Enter numbers only: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (id == 0)
            break;

        if (id < 1 || id > SIZE)
        {
            cout << "Invalid ID.\n";
            continue;
        }

        int qty;
        cout << "Enter Quantity: ";

        while (!(cin >> qty))
        {
            cout << "Enter numbers only: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (qty <= 0)
        {
            cout << "Quantity must be at least 1.\n";
            continue;
        }

        orderId[orderCount] = id - 1;
        orderQty[orderCount] = qty;
        orderCount++;

        cout << "Added: " << items[id - 1] << " x " << qty << endl;
    }

    if (orderCount == 0)
    {
        cout << "No order placed.\n";
        return 0;
    }

    // ------------------ BILL CALCULATION ------------------

    double subtotal = 0;

    for (int i = 0; i < orderCount; i++)
        subtotal += prices[orderId[i]] * orderQty[i];

    int payMethod;

    cout << "\nSelect Payment Method:\n";
    cout << "1 = Cash (16% GST)\n";
    cout << "2 = Card (5% GST)\n";

    while (!(cin >> payMethod) || (payMethod != 1 && payMethod != 2))
    {
        cout << "Enter only 1 or 2: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    double gstRate = (payMethod == 1) ? 0.16 : 0.05;
    double gstAmount = subtotal * gstRate;
    double total = subtotal + gstAmount;

    // ------------------ PRINT BILL ------------------

    cout << "\n===================== AI CAFE BILL =====================\n";

    cout << left << setw(22) << "Item"
         << setw(10) << "Price"
         << setw(10) << "Qty"
         << setw(12) << "Line Total" << endl;

    cout << "--------------------------------------------------------\n";

    for (int i = 0; i < orderCount; i++)
    {
        int idx = orderId[i];
        double lineTotal = prices[idx] * orderQty[i];

        cout << left << setw(22) << items[idx]
             << setw(10) << prices[idx]
             << setw(10) << orderQty[i]
             << setw(12) << fixed << setprecision(2) << lineTotal
             << endl;
    }

    cout << "--------------------------------------------------------\n";

    cout << left << setw(30) << "Subtotal:"
         << fixed << setprecision(2) << subtotal << endl;

    cout << left << setw(30)
         << (gstRate == 0.16 ? "GST (16%):" : "GST (5%):")
         << gstAmount << endl;

    cout << left << setw(30) << "Total Payable:"
         << total << endl;

    // ------------------ BUDGET EXCEED MESSAGE ------------------

    if (total > budget)
    {
        cout << left << setw(30) << "Your Budget:"
             << budget << endl;

        cout << left << setw(30) << "Amount Exceeded By:"
             << (total - budget) << endl;
    }

    cout << "========================================================\n";
    cout << "Order Completed. Thank you for visiting AI Cafe!\n";

    return 0;
}
