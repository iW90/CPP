# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <utility>
# include <sstream>
# include <stdexcept>
# include <algorithm>
# include <ctime>
# include <cmath>
# include <iomanip>
# include <utility>

int get_next_partition(int previous, int current) {
    return current + 2 * previous;
}

int main() {
    int previous = 2;
    int current = 2;
    int next;
//    while(current < 1369) {
  for (int i = 0; i < 15; i++) {
        next = get_next_partition(previous, current);
        std::cout << next << std::endl;
        previous = current;
        current = next;
    }

}