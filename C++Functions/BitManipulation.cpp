/***************************************************************
 *  BIT MANIPULATION CHEAT SHEET (C++20)
 *  ------------------------------------------------------------
 *  This file contains all common bit manipulation operations,
 *  algorithms, and tricks — with explanations and examples.
 *  Author: Pratham
 ***************************************************************/

#include <bits/stdc++.h>
using namespace std;

/***************************************************************
 *  SECTION 1 — BASIC BIT OPERATIONS
 ***************************************************************/

// Get i-th bit (0-indexed)
bool getBit(int x, int i)
{
    // Right shift i bits and check last bit
    return (x >> i) & 1;
}

// Set i-th bit to 1
int setBit(int x, int i)
{
    return x | (1 << i);
}

// Clear i-th bit (set to 0)
int clearBit(int x, int i)
{
    return x & ~(1 << i);
}

// Toggle i-th bit (flip)
int toggleBit(int x, int i)
{
    return x ^ (1 << i);
}

/***************************************************************
 *  SECTION 2 — COUNTING BITS
 ***************************************************************/

// Builtin hardware popcount (C++20)
int countBits(unsigned int x)
{
    return __builtin_popcount(x);
}

// Brian Kernighan’s Algorithm — removes lowest set bit each time
int countBitsKernighan(unsigned int x)
{
    int cnt = 0;
    while (x)
    {
        x &= (x - 1); // remove lowest set bit
        cnt++;
    }
    return cnt;
}

/***************************************************************
 *  SECTION 3 — LOWEST/HIGHEST SET BIT
 ***************************************************************/

// Isolate the lowest set bit (e.g., 1011000 → 0001000)
int isolateLowest(int x)
{
    return x & -x;
}

// Remove the lowest set bit
int removeLowest(int x)
{
    return x & (x - 1);
}

/***************************************************************
 *  SECTION 4 — POWER OF TWO CHECKS AND ROUNDING
 ***************************************************************/

// Check if number is power of two
bool isPowerOfTwo(unsigned int x)
{
    return x && !(x & (x - 1));
}

// Round up to next power of two (for 32-bit)
unsigned int nextPowerOfTwo(unsigned int x)
{
    if (x == 0)
        return 1;
    --x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x + 1;
}

// Round down to nearest power of two
unsigned int prevPowerOfTwo(unsigned int x)
{
    if (x == 0)
        return 0;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x - (x >> 1);
}

/***************************************************************
 *  SECTION 5 — FINDING BIT POSITIONS
 ***************************************************************/

// Index of least significant set bit (0-based)
int lsbIndex(unsigned int x)
{
    if (!x)
        return -1;
    int idx = 0;
    while ((x & 1) == 0)
    {
        x >>= 1;
        idx++;
    }
    return idx;
}

// Index of most significant set bit (0-based)
int msbIndex(unsigned int x)
{
    if (!x)
        return -1;
    // Portable count leading zeros for 32-bit unsigned int
    int cnt = 0;
    for (int i = 31; i >= 0; --i)
    {
        if (x & (1u << i))
            break;
        cnt++;
    }
    return 31 - cnt;
}

/***************************************************************
 *  SECTION 6 — BIT REVERSAL AND PARITY
 ***************************************************************/

// Reverse bits of a 32-bit integer
uint32_t reverseBits32(uint32_t x)
{
    x = (x >> 1) & 0x55555555u | (x & 0x55555555u) << 1;
    x = (x >> 2) & 0x33333333u | (x & 0x33333333u) << 2;
    x = (x >> 4) & 0x0F0F0F0Fu | (x & 0x0F0F0F0Fu) << 4;
    x = (x >> 8) & 0x00FF00FFu | (x & 0x00FF00FFu) << 8;
    return (x >> 16) | (x << 16);
}

// Compute parity (0 if even #bits, 1 if odd #bits)
int parity(unsigned int x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x &= 0xF;
    return (0x6996 >> x) & 1;
}

/***************************************************************
 *  SECTION 7 — SIGN AND ABSOLUTE VALUE
 ***************************************************************/

// Swap two numbers using XOR (no temp)
void xorSwap(int &a, int &b)
{
    if (&a == &b)
        return; // same variable protection
    a ^= b;
    b ^= a;
    a ^= b;
}

// Check if two integers have opposite signs
bool oppositeSigns(int a, int b)
{
    return (a ^ b) < 0;
}

// Compute absolute value without branching
int absNoBranch(int x)
{
    int mask = x >> 31; // all 1's if x < 0, else 0
    return (x + mask) ^ mask;
}

/***************************************************************
 *  SECTION 8 — MASK UTILITIES
 ***************************************************************/

// Create a mask with lowest n bits set (e.g., n=5 → 00011111)
unsigned int maskLowN(int n)
{
    if (n <= 0)
        return 0;
    if (n >= 32)
        return ~0u;
    return (1u << n) - 1;
}

/***************************************************************
 *  SECTION 9 — SUBMASK / SUPERSET ITERATION
 ***************************************************************/

// Iterate all non-empty submasks of a bitmask
void iterateSubmasks(int mask)
{
    cout << "Submasks of " << bitset<8>(mask) << ":\n";
    for (int sub = mask; sub; sub = (sub - 1) & mask)
    {
        cout << "  " << bitset<8>(sub) << "\n";
    }
}

// Iterate all supersets of a subset up to universe mask
void iterateSupersets(int subset, int universe)
{
    cout << "Supersets of " << bitset<8>(subset)
         << " within " << bitset<8>(universe) << ":\n";
    for (int sup = subset; sup <= universe; sup = (sup + 1) | subset)
    {
        if ((sup | universe) != universe)
            continue; // skip invalids
        cout << "  " << bitset<8>(sup) << "\n";
        if (sup == universe)
            break;
    }
}

/***************************************************************
 *  SECTION 10 — DEMO
 ***************************************************************/
int main()
{
    int x;
    cin >> x;
    cout << "x = " << x << " (" << bitset<8>(x) << ")\n\n";

    cout << "Get 1st bit: " << getBit(x, 1) << "\n";
    cout << "Set 0th bit: " << bitset<8>(setBit(x, 0)) << "\n";
    cout << "Clear 1st bit: " << bitset<8>(clearBit(x, 1)) << "\n";
    cout << "Toggle 2nd bit: " << bitset<8>(toggleBit(x, 2)) << "\n\n";

    cout << "Count bits: " << countBits(x) << "\n";
    cout << "Isolate lowest set bit: " << bitset<8>(isolateLowest(x)) << "\n";
    cout << "Remove lowest set bit: " << bitset<8>(removeLowest(x)) << "\n";
    cout << "Is power of two? " << isPowerOfTwo(x) << "\n\n";

    cout << "Next power of two: " << nextPowerOfTwo(x) << "\n";
    cout << "Previous power of two: " << prevPowerOfTwo(x) << "\n";
    cout << "LSB index: " << lsbIndex(x) << ", MSB index: " << msbIndex(x) << "\n\n";

    cout << "Reverse bits: " << bitset<8>(reverseBits32(x)) << "\n";
    cout << "Parity (1=odd): " << parity(x) << "\n\n";

    int a = -5, b = 3;
    cout << "Opposite signs? " << oppositeSigns(a, b) << "\n";
    cout << "absNoBranch(-7): " << absNoBranch(-7) << "\n\n";

    iterateSubmasks(0b1011);
    iterateSupersets(0b0011, 0b1111);
}
