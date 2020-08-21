#include <iostream>
#include <limits>
#include <chrono>
#include <string>
#include "Expression.h"
#include "parser.h"


void measure_time() {
    auto start = std::chrono::high_resolution_clock::now();

    /*
     *
     * put the code here !!!
     *
     * */
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count() << " microseconds" << std::endl;
}

int main() {
    std::cout.precision(std::numeric_limits<double>::max_digits10);

    /*
     * mistake 8 - 2 = 6 then 6 * 3 = 18
     * run to see the exact answer
    */

    std::string exp("8-2*3");

    std::cout << evaluate_string(exp) << std::endl;


}

