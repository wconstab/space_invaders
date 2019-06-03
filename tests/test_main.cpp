#include "gtest/gtest.h"
#include "i8080.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


// inline void affect_carry_flag(uint8_t a_value, uint8_t b_value, i8080_state& state);
// inline void affect_aux_carry_flag(uint8_t a_value, uint8_t b_value, i8080_state& state);
// inline void affect_sign_flag(uint8_t value, i8080_state& state);
// inline void affect_zero_flag(uint8_t value, i8080_state& state);
// inline void affect_parity_flag(uint8_t value, i8080_state& state);
TEST(i8080, FlagCarry) {
	i8080_state state;

	affect_carry_flag(0xff, 0, state);
	ASSERT_FALSE(state.carry);

	affect_carry_flag(0xff, 1, state);
	ASSERT_TRUE(state.carry);

	affect_carry_flag(0b10101111, 0b01010000, state);
	ASSERT_FALSE(state.carry);
}

TEST(i8080, FlagAuxCarry) {
	i8080_state state;

	affect_aux_carry_flag(0xf, 0, state);
	ASSERT_FALSE(state.aux_carry);

	affect_carry_flag(0xf, 1, state);
	ASSERT_TRUE(state.aux_carry);

	affect_carry_flag(0b1011, 0b0001, state);
	ASSERT_FALSE(state.aux_carry);

	affect_carry_flag(0b1011, 0b0100, state);
	ASSERT_FALSE(state.aux_carry);

	affect_carry_flag(0b1011, 0b0101, state);
	ASSERT_TRUE(state.aux_carry);
}

TEST(i8080, FlagZero) {
	i8080_state state;

	affect_zero_flag(0, state);
	ASSERT_TRUE(state.zero);

	affect_zero_flag(1, state);
	ASSERT_FALSE(state.zero);
}

TEST(i8080, FlagParity) {
	i8080_state state;

	// true for even parity
	affect_parity_flag(0b101, state);
	ASSERT_TRUE(state.parity);
	affect_parity_flag(0xff, state);
	ASSERT_TRUE(state.parity);

	affect_parity_flag(1, state);
	ASSERT_FALSE(state.parity);
	affect_parity_flag(0x7f, state);
	ASSERT_FALSE(state.parity);
}

TEST(i8080, FlagSign) {
	i8080_state state;

	// true for even parity
	affect_sign_flag(0x1, state);
	ASSERT_FALSE(state.sign);
	affect_sign_flag(0xff, state);
	ASSERT_TRUE(state.sign);
}