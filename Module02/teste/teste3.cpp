#include <iostream>

// A simple fixed-point representation example using 16 bits (8 integer, 8 fractional)
typedef int16_t fixed_point_t;

// Convert a fixed-point value to a floating-point value
float fixedToFloat(fixed_point_t value) {
    return static_cast<float>(value) / (1 << 8); // Shift by the number of fractional bits
}

int main() {
    // Create some fixed-point values
    fixed_point_t value1 = 12345;       // 12345 * 2^-8 = 48.30078125
    fixed_point_t value2 = -9876;      // -9876 * 2^-8 = -38.515625
    fixed_point_t value3 = 32767;      // 32767 * 2^-8 = 127.99609375

    // Convert fixed-point values to floating-point for display
    float float1 = fixedToFloat(value1);
    float float2 = fixedToFloat(value2);
    float float3 = fixedToFloat(value3);

    std::cout << "Fixed-point values:" << std::endl;
    std::cout << "Value 1: " << value1 << " (Float: " << float1 << ")" << std::endl;
    std::cout << "Value 2: " << value2 << " (Float: " << float2 << ")" << std::endl;
    std::cout << "Value 3: " << value3 << " (Float: " << float3 << ")" << std::endl;

    return 0;
}