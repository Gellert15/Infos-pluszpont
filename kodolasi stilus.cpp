#include <algorithm>
#include <iostream>
#include <vector>

// Használjuk a szabványos std::pair-t, ami már tartalmazza a rendezési logikát.
using IntPair = std::pair<int, int>;

void ProcessAndDisplay(std::vector<IntPair>& data) {
  // A std::sort a pair első eleme szerint rendez, majd a második szerint.
  std::sort(data.begin(), data.end());

  std::cout << "===\nOutput:\n---\n";

  for (const auto& [first, second] : data) {
    if (first % 2 == 0) {
      std::cout << (second % 2 == 0 ? first * second : first + second) << "\n";
    } else {
      std::cout << (second % 2 == 0 ? first - second : first) << "\n";
    }
  }
}

int main() {
  std::vector<IntPair> pairs = {{5, 1}, {2, 4}, {3, 7}, {1, 6}, {4, 5}};

  ProcessAndDisplay(pairs);

  return 0;
}
