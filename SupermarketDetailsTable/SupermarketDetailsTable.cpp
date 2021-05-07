//Write a c++ program to store the details of a supermarket item and process it using functions and a two-dimensional array
//1: Make a two-dimensional array to take inputs for the following:
//  item_code, item_name, item_cost_price, item_selling_price, stock, reorder_level
//2: Output the details as a table using a function
//3: Use relevant functions to find the profit and add it as another column called profit
//4: Again reuse the same function to display the details

#include <iostream>
using namespace std;

float input_details(string detail)
{
    float input;
    cout << "What is this item's " << detail << "?\t";
    cin >> input;
    return input;
}

void output_details(string name[3], float details[3][6], int num_details)
{
    int x, y;
    for (x = 0; x < 3; x++) {
        cout << name[x] << "\t\t";
        for (y = 0; y < num_details; y++) {
            cout << details[x][y] << "\t\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    //declaring arrays and variables
    string item_names[3] = { "Bread", "Milk", "Cheese" }, detail_names[5] = { "Code", "Cost Price", "Selling Price", "Stock", "Reorder Level" };
    float item_details[3][6] = { {12345, 1, 3.5, 15, 5, 0}, {56565, 1.5, 5, 64, 12, 0}, {99999, 2.5, 10, 40, 10, 0} };
    int i, j;

    //taking input for 3 items
    for (i = 0; i < 3; i++) {
        cout << "Enter the item's Name:\t";
        cin >> item_names[i];
        for (j = 0; j < 5; j++) {
            item_details[i][j] = input_details(detail_names[j]);
        }
        cout << "\n";
    }

    //output 1
    cout << "ITEM NAME\tITEM CODE\tCOST PRICE\tSELL PRICE\tITEM STOCK\tRE-ORDER LEVEL\n";
    output_details(item_names, item_details, 5);

    cout << "Calculating profit...\n\n";

    //calculating profit
    for (i = 0; i < 3; i++) {
        item_details[i][5] = item_details[i][2] - item_details[i][1];
    }

    //output 2
    cout << "ITEM NAME\tITEM CODE\tCOST PRICE\tSELL PRICE\tITEM STOCK\tRE-ORDER LEVEL\tPROFIT\n";
    output_details(item_names, item_details, 6);
}