#ifndef _I8080_HPP_
#define _I8080_HPP_
#endif

/*
Register Pair	Registers Referenced
B 				B and C (0 and 1)
D 				D and E (2 and 3)
H 				H and L (4 and 5)
PSW				See below

Register pair PSW (Program Status Word) refers to register A (7) and a special byte which reflects the current status of the machine flags. This byte is described in detail in Chapter 2.
*/
#define REG_B	0x0
#define	REG_C	0x1
#define REG_D	0x2
#define REG_E	0x3
#define REG_H	0x4
#define REG_L	0x5
#define REG_M	0x6
#define REG_A	0x7
#define NUM_REGS 8

class i8080_state {
public:
	i8080_state()
	:regs{0}
	{}
	// Flags
	bool carry;
	bool aux_carry;
	bool sign;
	bool zero;
	bool parity;

	// Registers
	uint8_t regs[NUM_REGS];

	// Special Registers
	uint16_t PC;
	uint16_t SP;

};

// #define FLAG_CARRY		0x01
// #define FLAG_AUX_CARRY	0x02
// #define FLAG_SIGN		0x04
// #define FLAG_ZERO		0x08
// #define FLAG_PARITY		0x10

void affect_carry_flag(uint8_t a_value, uint8_t b_value, i8080_state& state);
void affect_aux_carry_flag(uint8_t a_value, uint8_t b_value, i8080_state& state);
void affect_sign_flag(uint8_t value, i8080_state& state);
void affect_zero_flag(uint8_t value, i8080_state& state);
void affect_parity_flag(uint8_t value, i8080_state& state);
int run();