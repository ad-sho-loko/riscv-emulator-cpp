#include <gtest/gtest.h>
#include "memory.h"

class TestMemory : public ::testing::Test {
};

TEST_F(TestMemory, GetSet8) {
    Memory m = Memory();
    m.set8(0, 0);
    m.set8(1, 1);
    m.set8(2, 2);
    m.set8(3, 3);

    EXPECT_EQ(m.get8(0),  0);
    EXPECT_EQ(m.get8(1),  1);
    EXPECT_EQ(m.get8(2),  2);
    EXPECT_EQ(m.get8(3),  3);
}

TEST_F(TestMemory, GetSet16) {
    Memory m = Memory();

    m.set16(0, 0x1234);
    EXPECT_EQ(m.get8(0),  0x34);
    EXPECT_EQ(m.get8(1),  0x12);
    EXPECT_EQ(m.get16(0),  0x1234);
}

/*
TEST_F(TestMemory, GetSet32) {
    Memory m = Memory();

    m.set32(0, 0x12345678);
    EXPECT_EQ(m.get8(0),  0x78);
    EXPECT_EQ(m.get8(1),  0x56);
    EXPECT_EQ(m.get8(2),  0x34);
    EXPECT_EQ(m.get8(3),  0x12);
    EXPECT_EQ(m.get32(0),  0x12345678);
}
*/

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

