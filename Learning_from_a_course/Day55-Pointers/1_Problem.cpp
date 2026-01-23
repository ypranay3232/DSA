#include <iostream>
#include <vector>
using namespace std;

void findTwoSumBruteForce(int* arr, int size, int target) {
    // Outer pointer starts at the beginning of the array
    for (int* p1 = arr; p1 < arr + size - 1; ++p1) {
        
        // Inner pointer starts at the element immediately after p1
        for (int* p2 = p1 + 1; p2 < arr + size; ++p2) {
            
            // Dereference pointers (*) to get the actual values stored at those addresses
            if (*p1 + *p2 == target) {
                // Calculate original indices using pointer subtraction (pointer - base_address)
                std::cout << "Indices found: [" << (p1 - arr) << ", " << (p2 - arr) << "]" <<endl;
                std::cout << "Values: " << *p1 << " + " << *p2 << " = " << target <<endl;
                return;
            }
        }
    }
    std::cout << "No solution found." << std::endl;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    // Pass the array name (which decays into a pointer to its first element)
    findTwoSumBruteForce(nums, size, target);

    return 0;
}
