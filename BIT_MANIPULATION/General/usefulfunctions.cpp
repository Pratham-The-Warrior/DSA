// int main()
// {
//     unsigned int n = 12; // Binary: 00001100

//     cout << "Original n: " << n
//          << " (Binary: " << bitset<8>(n) << ")\n\n";

//*     // 1. Power of Two Functions
//     cout << "bit_floor (Largest power of 2 <= n): " << bit_floor(n) << "\n";
//     cout << "bit_ceil  (Smallest power of 2 >= n): " << bit_ceil(n) << "\n";
//     cout << "bit_width (Bits needed to represent n): " << bit_width(n) << "\n";
//     cout << "has_single_bit (Is power of 2?): " << boolalpha << has_single_bit(n) << "\n\n";

//*     // 2. Counting Functions
//     cout << "popcount (Number of 1s): " << popcount(n) << "\n";
//     cout << "countl_zero (Leading zeros): " << countl_zero(n) << "\n";
//     cout << "countr_zero (Trailing zeros): " << countr_zero(n) << "\n";
//     cout << "countl_one (Leading ones): " << countl_one(n) << "\n";
//     cout << "countr_one (Trailing ones): " << countr_one(n) << "\n\n";

//*     // 3. Rotation Functions
//     unsigned char x = 0b10000001;
//     cout << "Original x: " << bitset<8>(x) << "\n";
//     cout << "rotl (Rotate left by 1):  " << bitset<8>(rotl(x, 1)) << "\n";
//     cout << "rotr (Rotate right by 1): " << bitset<8>(rotr(x, 1)) << "\n";

//     return 0;
// }
