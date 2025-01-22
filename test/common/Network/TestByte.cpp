#include <criterion/criterion.h>
#include "TestByte.hpp"

Test(byte_constructors, test_byte_constructor_empty)
{
    Network::Byte emptyByte;
    cr_assert_eq(emptyByte.getSize(), 0);
}

Test(byte_constructors, test_byte_constructor_with_vector)
{
    std::vector<uint8_t> bytes = {1, 2, 3, 4};
    Network::Byte byteWithVector(bytes);
    cr_assert_eq(byteWithVector.getSize(), bytes.size());
}

// Test(byte_constructors, test_byte_constructor_with_size)
// {
//     Byte byteWithSize(10);
//     cr_assert_eq(byteWithSize.getSize(), 10);
// }

Test(byte_operators, test_byte_operator_plus)
{
    Network::Byte byte1;
    Network::Byte byte2;
    Network::Byte byte3 = byte1 + byte2;
    cr_assert_eq(byte3.getSize(), byte1.getSize() + byte2.getSize());
}

Test(byte_operators, test_byte_operator_left_shift)
{
    Network::Byte byte1;
    std::string str = "Hello, World!";
    byte1 << str;
    std::string readStr;
    byte1 >> readStr;
    cr_assert_str_eq(str.c_str(), readStr.c_str());
}
