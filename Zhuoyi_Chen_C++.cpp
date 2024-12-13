#include <iostream>
#include <vector>
#include <cmath>

// Rewrite Matlab Code
void conditional_statements() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    switch (n) {
        case -1:
            std::cout << "negative one\n";
            break;
        case 0:
            std::cout << "zero\n";
            break;
        case 1:
            std::cout << "positive one\n";
            break;
        default:
            std::cout << "other value\n";
            break;
    }
}

// Printing a Vector
void print_vector(std::vector<int> v) {
    std::cout << "[";
    // For loop for each element
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        // Adding comma
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

// While loop
void fibonacci_sequence() {
    // Initialization
    int a = 1, b = 2;
    std::cout << a << ", " << b << ", ";
    // While loop
    while (true) {
        int next = a + b;
        // Do not exceen 4000000
        if (next > 4000000) break;

        std::cout << next << ", ";
        // Recurrence Relation
        a = b; 
        b = next;
    }
}

// Check if prime
bool isprime(int n) {
    if (n <= 1) return false;
    // Examine all the possible factors
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Testing Cases
void test_isprime() {
    std::cout << "isprime(2) = " << isprime(2) << '\n';     
    std::cout << "isprime(10) = " << isprime(10) << '\n';   
    std::cout << "isprime(17) = " << isprime(17) << '\n';   
}

// Factorization 
std::vector<int> factorize(int n) {
    std::vector<int> answer;
    // Module and record the factors
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) answer.push_back(i);
    }
    return answer;
}

// Testing cases
void test_factorize() {
    std::cout << "Factors of 2: ";
    print_vector(factorize(2)) ; 
    std::cout << "Factors of 72: ";
    print_vector(factorize(72)); 
    std::cout << "Factors of 196: ";
    print_vector(factorize(196)); 
}


// Prime factorization function
std::vector<int> prime_factorize(int n) {
    std::vector<int> answer;

    // Separate 2
    while (n % 2 == 0) {
        answer.push_back(2);
        n /= 2;
    }

    // Use Prime factorization (only consider odd number)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            answer.push_back(i);
            n /= i;
        }
    }
    if (n > 2) answer.push_back(n);
    return answer;
}

// More testing Cases

void test_prime_factorize() {
    std::cout << "Prime factors of 2: ";
    print_vector(prime_factorize(2)); 
    std::cout << "Prime factors of 72: ";
    print_vector(prime_factorize(72)); 
    std::cout << "Prime factors of 196: ";
    print_vector(prime_factorize(196)); 
}


// Pascal's Triangle
void print_pascals_triangle(int n) {
    std::vector<std::vector<int> > triangle;

    for (int i = 0; i < n; ++i) {
        std::vector<int> row(i + 1, 1);
        // The recurrence relationship
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);

        // Print the current row
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}

void test_pascals_triangle() {
    int n;
    std::cout << "Enter the number of rows for the Pascal's Triangle: ";
    std::cin >> n;
    print_pascals_triangle(n);
}

// Main function
int main() {
    std::cout << "Testing Conditional Statements:\n";
    conditional_statements();

    std::cout << "\nTesting Fibonacci Sequence:\n";
    fibonacci_sequence();

    std::cout << "\nTesting Prime Check:\n";
    test_isprime();

    std::cout << "\nTesting Factorize:\n";
    test_factorize();

    std::cout << "\nTesting Prime Factorization:\n";
    test_prime_factorize();

    std::cout << "\nTesting Pascal's Triangle:\n";
    test_pascals_triangle();

    return 0;
}
