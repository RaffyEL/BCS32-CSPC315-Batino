#include <iostream>
#include <cmath>  // for pow()

// Tower of Hanoi implementation
void tower_of_hanoi(int n, const std::string& source, const std::string& destination, const std::string& buffer) {
    if (n == 0) {
        // If there are no packages, no moves are done
        return;
    }

    // Move n-1 packages from source to buffer, using destination as auxiliary
    tower_of_hanoi(n - 1, source, buffer, destination);

    // Print the move of package n
    std::cout << "Move package " << n << " from " << source << " to " << destination << std::endl;

    // Move n-1 packages from buffer to destination, using source as auxiliary
    tower_of_hanoi(n - 1, buffer, destination, source);
}

int main() {
    int N;

    // Input the number of packages (disks) in terms of Tower of Hanoi
    std::cout << "Enter the number of packages: ";
    std::cin >> N;

    // Call the tower of hanoi function
    tower_of_hanoi(N, "source", "destination", "buffer");

    std::cout << std::string(40, '=') << "\n";

    // Calculate and print the total number of moves: 2^N - 1
    std::cout << "\nTotal number of moves for " << N << " packages: " << (pow(2, N) - 1) << std::endl;

    std::cout << "Tower of Hanoi Time Complexity of 'O(2n)'";

    return 0;
}
