///
/// @file: RunLengthEncoding.hpp
/// @description: Run-length encoding is a lossless compression method that works best for data with long sequences
///     of the same value, so-called 'runs'. The sequence is compressed to the value being repeated and its count
/// TAGS:
///     domain/compression
///     prop/lossless
///

#ifndef RUN_LENGTH_ENCODING
#define RUN_LENGTH_ENCODING

#include <vector>
#include <iostream>

template<typename T>
concept Comparable = requires(T a, T b) {
    { a == b } -> std::convertible_to<bool>;
};

template<typename T>
concept Printable = requires(T t) {
    { std::cout << t } -> std::same_as<std::ostream&>;
};

namespace RunLengthEncoding {
    template<Comparable T>
    struct EncodingUnit {
        T value;
        size_t count;

        EncodingUnit(T value, size_t count): value{value}, count{count} {}
    };

    template<Comparable T>
    std::vector<EncodingUnit<T>> encode(const std::vector<T>& input) {
        std::vector<EncodingUnit<T>> encoded;

        size_t run_length = 0;
        for (size_t i = 0; i < input.size(); i++) {
            if (i == input.size() - 1) [[unlikely]] {
                encoded.emplace_back(input[i], ++run_length);
                break;
            }

            if (input[i] == input[i + 1]) {
                run_length++;
                continue;
            }

            encoded.emplace_back(input[i], ++run_length);
            run_length = 0;
        }

        return encoded;
    }

    template<Comparable T>
    std::vector<T> decode(const std::vector<EncodingUnit<T>>& encoded) {
        std::vector<T> output;

        for (const EncodingUnit<T>& unit : encoded) {
            std::vector<T> temp(unit.count, unit.value);
            output.insert(output.end(), temp.begin(), temp.end());
        }

        return output;
    }

    template<Comparable T>
    void printEncoding(const std::vector<EncodingUnit<T>>& encoded) requires Printable<T> {
        std::cout << "{";

        for (size_t i = 0; i < encoded.size(); i++) {
            auto [value, count] = encoded[i];
            std::cout << "(" << value << ": " << count << ")";
            if (i < encoded.size() - 1) [[likely]] {
                std::cout << ", ";
            }
        }

        std::cout << "}" << std::endl;
    }

}; //namespace RunLengthEncoding


#endif //RUN_LENGTH_ENCODING
