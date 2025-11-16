#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <string>
#include <cctype>
using namespace std;

//code test in github test

class InputValidationException : public std::runtime_error {
public:
    InputValidationException(const std::string& msg) : std::runtime_error(msg) {}
};

void ClearInput() {
    if (cin.fail()) {
        cerr << "--- INPUT ERROR ---: Please enter a number, not text or symbols.\n";
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double CalculateY(double x, int n) {
    double y = 0.0;

    if (x < 1.0) {
        double product_result = 1.0;

        for (int i = 1; i <= n; ++i) {
            double numerator = 2.0 * pow(x, 2) - x * (double)i;
            product_result *= (numerator / (double)i);
        }
        y = product_result + 7.0 * x;
    }
    else {
        double fractional_term = (6.0 - x) / (x + 1.0);
        double nested_sum = 0.0;

        if (n >= 5) {
            for (int j = 2; j <= (n - 2); ++j) {
                double inner_product = 1.0;

                for (int i = 0; i <= n; ++i) {
                    double term = x - 7.0 * (double)i * (double)j + 9.0 * (double)j * x;
                    inner_product *= term;
                }

                nested_sum += inner_product;
            }
        }

        y = fractional_term + nested_sum;
    }
    return y;
}

//main function

int main() {
    int choice = 0;
    int n = 0;
    double a = 0.0, b = 0.0, step = 0.0;
    double single_x = 0.0;

    cout << "\n-----------------------------------------\n";
    cout << "      Basics of Software Engineering\n";
    cout << "      Laboratory Work 2\n";
    cout << "      Coding Domain\n";
    cout << "-----------------------------------------\n";
    cout << "Welcome to domain 25.\n";

    cout << "Input any key to open Main Menu\n";
    cout << ">> ";

    cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        cout << "\n=========================================\n";
        cout << "            Main Menu\n";
        cout << "=========================================\n";
        cout << "1. Calculate for one x.\n";
        cout << "2. Calculate for a range of x.\n";
        cout << "3. Exit program.\n";
        cout << ">> Enter your choice (1-3): ";

        cin >> choice;

        if (cin.fail()) {
            ClearInput();
            choice = 0;
            continue;
        }
        ClearInput();

        switch (choice) {
        case 1: {
            cout << "\n--- Option 1: Single X Calculation ---\n";
            bool success = false;

            do {
                try {
                    cout << "Enter integer n (must be > 4): ";
                    if (!(cin >> n)) {
                        throw InputValidationException("n must be a whole number, not text or symbols.");
                    }

                    char next_char;
                    cin.get(next_char);
                    if (next_char != '\n' && !isspace(next_char)) {
                        throw InputValidationException("n must be a whole number (integer), not a decimal.");
                    }
                    if (n <= 4) {
                        throw InputValidationException("n must be greater than 4.");
                    }
                    success = true;
                }
                catch (const InputValidationException& e) {
                    cerr << "--- LOGIC/INPUT ERROR ---: " << e.what() << endl;
                    ClearInput();
                    success = false;
                }
            } while (!success);

            success = false;
            do {
                try {
                    cout << "Enter real number x: ";
                    if (!(cin >> single_x)) {
                        throw InputValidationException("x must be a real number, not text or symbols.");
                    }
                    ClearInput();
                    success = true;
                }
                catch (const InputValidationException& e) {
                    cerr << "--- LOGIC/INPUT ERROR ---: " << e.what() << endl;
                    ClearInput();
                    success = false;
                }
            } while (!success);

            double y = CalculateY(single_x, n);

            cout << fixed << setprecision(6);
            cout << "\n--- Calculation Result ---\n";
            cout << "For n = " << n << " and x = " << single_x << endl;
            cout << "Y = " << y << endl;
            
            break;
        }

        case 2: {
            cout << "\n--- Option 2: Range Calculation ---\n";
            bool success;

            do {
                success = true;
                try {
                    cout << "Enter integer n (must be > 4): ";
                    if (!(cin >> n)) {
                        throw InputValidationException("n must be a whole number, not text or symbols.");
                    }

                    char next_char;
                    cin.get(next_char);
                    if (next_char != '\n' && !isspace(next_char)) {
                        throw InputValidationException("n must be a whole number (integer), not a decimal.");
                    }

                    if (n <= 4) {
                        throw InputValidationException("n must be greater than 4.");
                    }
                }
                catch (const InputValidationException& e) {
                    cerr << "--- LOGIC/INPUT ERROR ---: " << e.what() << endl;
                    ClearInput();
                    success = false;
                }
            } while (!success);

            do {
                success = true;
                try {
                    cout << "Enter starting range value (a): ";
                    if (!(cin >> a)) { throw InputValidationException("a must be a real number, not a text or a symbols."); }
                    ClearInput();
                }
                catch (const InputValidationException& e) {
                    cerr << "--- LOGIC/INPUT ERROR ---: " << e.what() << endl;
                    ClearInput();
                    success = false;
                }
			} while (!success);

            do {
                success = true;
                try {
                    cout << "Enter ending range value (b): ";
                    if (!(cin >> b)) { throw InputValidationException("b must be a real number, not a text or a symbols."); }
                    ClearInput();
                    if (b <= a) {
                        throw InputValidationException("Ending value b must be bigger than startinf value a.");
                    }
                }
                catch (const InputValidationException& e) {
                    cerr << "--- LOGIC/INPUT ERROR ---: " << e.what() << endl;
                    ClearInput();
                    success = false;
                }
			} while (!success);

            do {
                success = true;
                try {
                    cout << "Enter step size (must be > 0): ";
                    if (!(cin >> step)) { throw InputValidationException("Step size must be a real number, not text or symbols."); }
                    ClearInput();
                    if (step <= 0.0) {
                        throw InputValidationException("Step size must be positive.");
                    }
                }
                catch (const InputValidationException& e) {
                    cerr << "--- LOGIC/INPUT ERROR ---: " << e.what() << endl;
                    ClearInput();
                    success = false;
                    }
                } while (!success);
				

                cout << "\nCalculation Results (n = " << n << ")\n";
                cout << fixed << setprecision(6);
                cout << "------------------------------------------\n";
                cout << setw(5) << "k" << setw(15) << "x" << setw(20) << "Y(x)" << endl;
                cout << "------------------------------------------\n";

                int k = 1;
                const double epsilon = 1e-9;

                for (double current_x = a; current_x <= b + epsilon; current_x += step) {
                    double y_range = CalculateY(current_x, n);

                    cout << setw(5) << k << setw(15) << current_x << setw(20) << y_range << endl;
                    k++;
                }
                cout << "------------------------------------------\n";
                cout << "Range calculation complete.\n";
                break;
            }

        case 3:
            cout << "Exiting program... \n";
            cout << "Goodbye!\n";
            break;

        default:
            cerr << "Invalid menu option. Please select 1, 2, or 3.\n";
            break;
        }
    } while (choice != 3);
    return 0;
}