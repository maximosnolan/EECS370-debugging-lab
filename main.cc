#include <iostream>
#include <functional>
#include <vector>
#include <optional>
#include <numeric>
#include <string>

namespace example {
// add two numbers together! 
    [[nodiscard]] static inline auto add(int32_t & arg0, int32_t & arg1) -> int32_t {
        return arg0 + arg1; 
    }

//convert a vector of strings into a singular string seperated by spaces only IF all strings passed in are non empty
    [[nodiscard]] static inline auto accumulate(std::vector<std::string> & vec) -> std::optional<std::string> {
        for (const auto & v : vec) {
            if (v == "") return std::nullopt;
        }

    //define lambda expression for the accumulation
        auto add_space_fold = [](const std::string a, const  std::string b) {
            return std::move(a) + " " + std::move(b);
        };
        std::string blank = "";
        std::optional<std::string> returnValue = {std::accumulate(vec.begin(), vec.end(), blank,  add_space_fold)};
        //See what the return value is! 

        return returnValue;
    }

}

[[nodiscard]] auto main(int16_t argc, char ** argv) -> int {
    //debugger step 1! 
    printf("1: Hello world!\n");
    int32_t capturedReturnValue = 4;
    //make sure you can see captured return value

    //declare two values:
    int32_t arg0 = 5, arg1 = 7; 
    capturedReturnValue = example::add(arg0, arg1);
    printf("2: add return: %d", capturedReturnValue);

    //sometimes you might jump into a function that makes no sense (our starter code or a library function)
    std::vector<std::string> vec= {"Hello", "World", "This","Is","How","You","Can","Use","Modern","C++","Effectivly"};

    auto value = example::accumulate(vec);
    if (value.has_value()) {
        std::cout << "Here is the value we got! " << *value << "\n";
    }
    std::cout << "Notice how sometimes it's best to not jump into code we didn't write, we can just step over those functions :) \n";


}