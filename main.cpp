#include <iostream>
#include "bank_customer.h"
#include "buyer.h"

enum PrimaryPrompt{LOGIN, REGISTER, EXIT};
enum regprompt{reg_buyer, reg_exit};
enum accountmenu{upgrade_account, exit_to_main_menu, exit_program};

BankCustomer customer1(1, "Alice", 1000.0);
Buyer buyer1(1, customer1.getName(), customer1);

using namespace std;

int main() {
    //create a loop prompt 
    PrimaryPrompt prompt = LOGIN;
    while (prompt != EXIT) {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;
        prompt = static_cast<PrimaryPrompt>(choice - 1);
        switch (prompt) {
            case LOGIN: {
                cout << "Login selected." << endl;
                string inputName;
                int inputId;

                cout << "Enter your ID: ";
                cin >> inputId;
                cout << "Enter your Name: ";
                cin.ignore(); 
                getline(cin, inputName);

                if (inputId == customer1.getId() && inputName == customer1.getName())
                {
                    cout << "Login successful. Welcome, " << inputName << "!" << endl;

                    accountmenu menuPromt = exit_to_main_menu;
                    while (menuPromt != exit_program)
                    {
                        cout << "Select an option: " << endl;
                        cout << "1. Upgrade Account to Seller" << endl;
                        cout << "2. Exit to Main Menu" << endl;
                        cout << "3. Exit Program" << endl;
                        int menu_choice;
                        cin >> menu_choice;
                        menuPromt = static_cast<accountmenu>(menu_choice - 1);
                        switch (menuPromt) {
                            case upgrade_account:
                                cout << "Upgrade Account to Seller selected." << endl;
                                


                                break;
                            case exit_to_main_menu:
                                cout << "Exiting to main menu." << endl;
                                break;
                            case exit_program:
                                cout << "Exiting program." << endl;
                                break;
                            default:
                                cout << "Invalid option." << endl;
                                break;
                        }
                        cout << endl;
                    }
                    

                    cout << "account menu:" << endl;
                    
                    
                }
                else
                {
                    cout << "Login failed. Invalid ID or Name." << endl;
                    prompt = LOGIN;
                    break;
                }
            }
                
                
                /* if Login is selected, based on authority then provide options:
                assume user is logged in as Buyer for now
                1. Chek Account Status (will display if user is Buyer or Seller or both and linked banking account status)
                Will display Buyer, Seller and Banking Account details
                2. Upgrade Account to Seller
                Will prompt user to enter Seller details and create a Seller account linked to Buyer account
                Will reject if a user dont have a banking account linked
                3. Create Banking Account (if not already linked), will be replaced with banking functions
                Must provides: initial deposit amount, Address, Phone number, Email
                Banking functions will provides: Balance checking, Transaction History, Deposit, Withdraw
                4. Browse Store Functionality
                Will display all stores initially
                Need to select a store to browse each store inventory
                Will display all items in the store inventory
                After selecting an item, will display item details and option to add to cart
                After adding to cart, will notify user item is added to cart
                5. Order Functionality
                Will display all items in cart
                Will provide option to remove item from cart
                Will provide option to checkout
                After checkout invoide will be generated (will go to payment functionality)
                6. Payment Functionality
                Will display all listed invoices
                Pick an invoice to pay
                Will display invoice details and total amount
                Will provide option to pay invoice
                Payment is done through confirmation dialogue
                In confirmation dialogue, will display account balance as precursor
                User will need to manually enter invoice id to pay
                After paying balance will be redacted from buyer and added to the responding seller account
                After payment, order status will be changed to paid
                7. Logout (return to main menu)
                Display confirmation dialogue
                If confirmed, return to main menu
                If not, return to Buyer menu
                8. Delete Account (remove both Buyer and Seller account and relevant banking account)
                Display confirmation dialogue
                If confirmed, delete account and return to main menu
                If not, return to Buyer menu
                assume user is logged in as Seller for now
                9. Check Inventory
                10. Add Item to Inventory
                11. Remove Item from Inventory
                12. View Orders (will display all orders placed to this seller
                Only orders with paid status will be listed
                Order details will listing items, quantity, total amount, buyer details, order status (paid, cancelled, completed)
                extra functions
                9. Exit to main Menu
                10. Exit Program
                **/
                break;
            case REGISTER: {
                cout << "Register selected." << endl;
                regprompt reg_prompt = reg_buyer;
                while (reg_prompt != reg_exit) {
                    cout << "Select an option: " << endl;
                    cout << "1. Buyer" << endl;
                    cout << "2. Exit" << endl;
                    int reg_choice;
                    cin >> reg_choice;
                    reg_prompt = static_cast<regprompt>(reg_choice - 1);
                    switch (reg_prompt) {
                        case reg_buyer:
                            {
                                cout << "Buyer selected." << endl;
                                string name, address, phone, email;
                                cout << "Enter your name: ";
                                cin.ignore();
                                getline(cin, name);
                                cout << "Enter your home address: ";
                                getline(cin, address);
                                cout << "Enter your phone number: ";
                                getline(cin, phone);
                                cout << "Enter your email: ";
                                getline(cin, email);

                                BankCustomer customer1(1, name, 0);
                                Buyer buyer1(1, name, customer1);
                                cout << "Buyer account created for " << buyer1.getName() << " with ID " << buyer1.getId() << endl;

                                cout << "Do you want to create a Seller account? (y/n): ";
                                char seller_choice;
                                cin >> seller_choice;
                                if (seller_choice == 'y' || seller_choice == 'Y') {
                                    string store_name, store_address, store_phone, store_email;
                                    cout << "Enter your store name: ";
                                    cin.ignore();
                                    getline(cin, store_name);
                                    cout << "Enter your store address: ";
                                    getline(cin, store_address);
                                    cout << "Enter your store phone number: ";
                                    getline(cin, store_phone);
                                    cout << "Enter your store email: ";
                                    getline(cin, store_email);
                                    


                                    cout << "Seller account created for store " << store_name << endl;

                                    reg_prompt = reg_exit;
                                    break;
                                } 

                                else {
                                    cout << "No Seller account created." << endl;
                                    reg_prompt = reg_exit;
                                    break;
                                }

                            }
                            break;
                        
                        case reg_exit:
                            cout << "Exiting." << endl;
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                    cout << endl;
                }
    
                break;
            }
                /* if register is selected then went throuhh registration process:
                1. Create a new Buyer Account
                Must provides: Name, Home Address, Phone number, Email
                2. Option to create a Seller Account (will be linked to Buyer account)
                Must provides: Store Name, Store Address, Store Phone number, Store Email
                After finished immediately logged in as Buyer/Seller
                */
                break;
            case EXIT:
                cout << "Exiting." << std::endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
        cout << endl;
    }

    //BankCustomer customer1(1, "Alice", 1000.0);
    //Buyer buyer1(1, customer1.getName(), customer1);
    return 1;
}