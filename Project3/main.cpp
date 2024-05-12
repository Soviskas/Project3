#include <iostream>
#include <vector>

int main() {
    int r;
    std::cout << "Enter the quantity of dischargers: ";
    std::cin >> r;

    std::vector<std::vector<long long>> dp(r + 1, std::vector<long long>(3, 0));
    dp[1][1] = 2; // два числа з одного розряду: 5 і 9

    for (int i = 2; i <= r; i++) {
        dp[i][1] = dp[i - 1][1] + dp[i - 1][2]; // числа, які закінчуються на одну однакову цифру
        dp[i][2] = dp[i - 1][1]; // числа, які закінчуються на дві однакові цифри
    }

    long long result = dp[r][1] + dp[r][2]; // сума чисел, які закінчуються на одну або дві однакові цифри

    std::cout << "Quantity of numbers from " << r << " discharges: " << result << std::endl;

    return 0;
}
