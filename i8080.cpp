#include <iostream>
#include <memory>
#include <cstring>
#include <stdio.h>

#include "i8080.hpp"
#include "i8080_ref.h"

using namespace std;



void affect_carry_flag(uint8_t a_value, uint8_t b_value, i8080_state& state){
	uint16_t test = a_value + b_value;
	state.carry = test & 0x100;
}

void affect_aux_carry_flag(uint8_t a_value, uint8_t b_value, i8080_state& state){
	uint16_t test = (a_value & 0xf) + (b_value & 0xf);
	state.aux_carry = test & 0x10;
}

void affect_sign_flag(uint8_t value, i8080_state& state){
    state.sign = value & 0x80;
}

void affect_zero_flag(uint8_t value, i8080_state& state){
    state.zero = value == 0;
}

void affect_parity_flag(uint8_t value, i8080_state& state){
	int accum = 0;
	for(int i = 0; i < 8; i++){
		accum += (value >> i) & 1;
	}
	state.parity = !(accum % 2);
}

int run()
{
	i8080_state state;
	size_t MEM_SIZE = 0xffff;
	auto memory = make_unique<uint8_t[]>(MEM_SIZE);
	bool enable = true;
	int rc = 0;
	uint8_t advance = 0;

	// Initialize
	uint16_t code = 0x1000;
	#define PROG_SIZE 4
	uint8_t program[PROG_SIZE] = {INR_B, INR_B, INR_B, HLT};
	memcpy(memory.get()+code, program, PROG_SIZE);
	state.PC = code;

	uint8_t opcode;
   	uint8_t reg_id;
	uint8_t old_value;
	uint8_t new_value;
	uint8_t flags;

	// Run
    while(enable)
    {
    	opcode = memory[state.PC];
    	printf("opcode %x\n", opcode);

    	switch(opcode){

    	// Increment Register	
		case INR_B:
		case INR_C:
		case INR_D:
		case INR_E:
		case INR_H:
		case INR_L:
		case INR_M:
		case INR_A:
    		reg_id = (opcode & 0x38) >> 3;

    		old_value = state.regs[reg_id];
    		new_value = old_value + 1;
    		state.regs[reg_id] = new_value;

    		affect_zero_flag(new_value, state);
    		affect_sign_flag(new_value, state);
    		affect_parity_flag(new_value, state);
    		affect_aux_carry_flag(old_value, 1, state);

    		printf("INR: reg %d = %x\n", reg_id, state.regs[reg_id]);
    		break;

    	case HLT:
    		enable = false;
    		break;

    	default:
    		enable = false;
    		rc = -1;
    		break;
    	}

    	state.PC += opcode_info[opcode].size;
    	printf("PC %x\n", state.PC);
    }

    return rc;
}

int old(uint8_t opcode)
{
	switch(opcode){
	case 0x0:
		//NOP: 
		break;

	case 0x1:
		//LXI B,D16: B <- byte 3, C <- byte 2
		break;

	case 0x2:
		//STAX B: (BC) <- A
		break;

	case 0x3:
		//INX B: BC <- BC+1
		break;

	case 0x4:
		//INR B: B <- B+1
		break;

	case 0x5:
		//DCR B: B <- B-1
		break;

	case 0x6:
		//MVI B, D8: B <- byte 2
		break;

	case 0x7:
		//RLC: A = A << 1; bit 0 = prev bit 7; CY = prev bit 7
		break;

	case 0x9:
		//DAD B: HL = HL + BC
		break;

	case 0xa:
		//LDAX B: A <- (BC)
		break;

	case 0xb:
		//DCX B: BC = BC-1
		break;

	case 0xc:
		//INR C: C <- C+1
		break;

	case 0xd:
		//DCR C: C <-C-1
		break;

	case 0xe:
		//MVI C,D8: C <- byte 2
		break;

	case 0xf:
		//RRC: A = A >> 1; bit 7 = prev bit 0; CY = prev bit 0
		break;

	case 0x11:
		//LXI D,D16: D <- byte 3, E <- byte 2
		break;

	case 0x12:
		//STAX D: (DE) <- A
		break;

	case 0x13:
		//INX D: DE <- DE + 1
		break;

	case 0x14:
		//INR D: D <- D+1
		break;

	case 0x15:
		//DCR D: D <- D-1
		break;

	case 0x16:
		//MVI D, D8: D <- byte 2
		break;

	case 0x17:
		//RAL: A = A << 1; bit 0 = prev CY; CY = prev bit 7
		break;

	case 0x19:
		//DAD D: HL = HL + DE
		break;

	case 0x1a:
		//LDAX D: A <- (DE)
		break;

	case 0x1b:
		//DCX D: DE = DE-1
		break;

	case 0x1c:
		//INR E: E <-E+1
		break;

	case 0x1d:
		//DCR E: E <- E-1
		break;

	case 0x1e:
		//MVI E,D8: E <- byte 2
		break;

	case 0x1f:
		//RAR: A = A >> 1; bit 7 = prev bit 7; CY = prev bit 0
		break;

	case 0x21:
		//LXI H,D16: H <- byte 3, L <- byte 2
		break;

	case 0x22:
		//SHLD adr: (adr) <-L; (adr+1)<-H
		break;

	case 0x23:
		//INX H: HL <- HL + 1
		break;

	case 0x24:
		//INR H: H <- H+1
		break;

	case 0x25:
		//DCR H: H <- H-1
		break;

	case 0x26:
		//MVI H,D8: H <- byte 2
		break;

	case 0x27:
		//DAA: special
		break;

	case 0x29:
		//DAD H: HL = HL + HI
		break;

	case 0x2a:
		//LHLD adr: L <- (adr); H<-(adr+1)
		break;

	case 0x2b:
		//DCX H: HL = HL-1
		break;

	case 0x2c:
		//INR L: L <- L+1
		break;

	case 0x2d:
		//DCR L: L <- L-1
		break;

	case 0x2e:
		//MVI L, D8: L <- byte 2
		break;

	case 0x2f:
		//CMA: A <- !A
		break;

	case 0x31:
		//LXI SP, D16: SP.hi <- byte 3, SP.lo <- byte 2
		break;

	case 0x32:
		//STA adr: (adr) <- A
		break;

	case 0x33:
		//INX SP: SP = SP + 1
		break;

	case 0x34:
		//INR M: (HL) <- (HL)+1
		break;

	case 0x35:
		//DCR M: (HL) <- (HL)-1
		break;

	case 0x36:
		//MVI M,D8: (HL) <- byte 2
		break;

	case 0x37:
		//STC: CY = 1
		break;

	case 0x39:
		//DAD SP: HL = HL + SP
		break;

	case 0x3a:
		//LDA adr: A <- (adr)
		break;

	case 0x3b:
		//DCX SP: SP = SP-1
		break;

	case 0x3c:
		//INR A: A <- A+1
		break;

	case 0x3d:
		//DCR A: A <- A-1
		break;

	case 0x3e:
		//MVI A,D8: A <- byte 2
		break;

	case 0x3f:
		//CMC: CY=!CY
		break;

	case 0x40:
		//MOV B,B: B <- B
		break;

	case 0x41:
		//MOV B,C: B <- C
		break;

	case 0x42:
		//MOV B,D: B <- D
		break;

	case 0x43:
		//MOV B,E: B <- E
		break;

	case 0x44:
		//MOV B,H: B <- H
		break;

	case 0x45:
		//MOV B,L: B <- L
		break;

	case 0x46:
		//MOV B,M: B <- (HL)
		break;

	case 0x47:
		//MOV B,A: B <- A
		break;

	case 0x48:
		//MOV C,B: C <- B
		break;

	case 0x49:
		//MOV C,C: C <- C
		break;

	case 0x4a:
		//MOV C,D: C <- D
		break;

	case 0x4b:
		//MOV C,E: C <- E
		break;

	case 0x4c:
		//MOV C,H: C <- H
		break;

	case 0x4d:
		//MOV C,L: C <- L
		break;

	case 0x4e:
		//MOV C,M: C <- (HL)
		break;

	case 0x4f:
		//MOV C,A: C <- A
		break;

	case 0x50:
		//MOV D,B: D <- B
		break;

	case 0x51:
		//MOV D,C: D <- C
		break;

	case 0x52:
		//MOV D,D: D <- D
		break;

	case 0x53:
		//MOV D,E: D <- E
		break;

	case 0x54:
		//MOV D,H: D <- H
		break;

	case 0x55:
		//MOV D,L: D <- L
		break;

	case 0x56:
		//MOV D,M: D <- (HL)
		break;

	case 0x57:
		//MOV D,A: D <- A
		break;

	case 0x58:
		//MOV E,B: E <- B
		break;

	case 0x59:
		//MOV E,C: E <- C
		break;

	case 0x5a:
		//MOV E,D: E <- D
		break;

	case 0x5b:
		//MOV E,E: E <- E
		break;

	case 0x5c:
		//MOV E,H: E <- H
		break;

	case 0x5d:
		//MOV E,L: E <- L
		break;

	case 0x5e:
		//MOV E,M: E <- (HL)
		break;

	case 0x5f:
		//MOV E,A: E <- A
		break;

	case 0x60:
		//MOV H,B: H <- B
		break;

	case 0x61:
		//MOV H,C: H <- C
		break;

	case 0x62:
		//MOV H,D: H <- D
		break;

	case 0x63:
		//MOV H,E: H <- E
		break;

	case 0x64:
		//MOV H,H: H <- H
		break;

	case 0x65:
		//MOV H,L: H <- L
		break;

	case 0x66:
		//MOV H,M: H <- (HL)
		break;

	case 0x67:
		//MOV H,A: H <- A
		break;

	case 0x68:
		//MOV L,B: L <- B
		break;

	case 0x69:
		//MOV L,C: L <- C
		break;

	case 0x6a:
		//MOV L,D: L <- D
		break;

	case 0x6b:
		//MOV L,E: L <- E
		break;

	case 0x6c:
		//MOV L,H: L <- H
		break;

	case 0x6d:
		//MOV L,L: L <- L
		break;

	case 0x6e:
		//MOV L,M: L <- (HL)
		break;

	case 0x6f:
		//MOV L,A: L <- A
		break;

	case 0x70:
		//MOV M,B: (HL) <- B
		break;

	case 0x71:
		//MOV M,C: (HL) <- C
		break;

	case 0x72:
		//MOV M,D: (HL) <- D
		break;

	case 0x73:
		//MOV M,E: (HL) <- E
		break;

	case 0x74:
		//MOV M,H: (HL) <- H
		break;

	case 0x75:
		//MOV M,L: (HL) <- L
		break;

	case 0x76:
		//HLT: special
		break;

	case 0x77:
		//MOV M,A: (HL) <- A
		break;

	case 0x78:
		//MOV A,B: A <- B
		break;

	case 0x79:
		//MOV A,C: A <- C
		break;

	case 0x7a:
		//MOV A,D: A <- D
		break;

	case 0x7b:
		//MOV A,E: A <- E
		break;

	case 0x7c:
		//MOV A,H: A <- H
		break;

	case 0x7d:
		//MOV A,L: A <- L
		break;

	case 0x7e:
		//MOV A,M: A <- (HL)
		break;

	case 0x7f:
		//MOV A,A: A <- A
		break;

	case 0x80:
		//ADD B: A <- A + B
		break;

	case 0x81:
		//ADD C: A <- A + C
		break;

	case 0x82:
		//ADD D: A <- A + D
		break;

	case 0x83:
		//ADD E: A <- A + E
		break;

	case 0x84:
		//ADD H: A <- A + H
		break;

	case 0x85:
		//ADD L: A <- A + L
		break;

	case 0x86:
		//ADD M: A <- A + (HL)
		break;

	case 0x87:
		//ADD A: A <- A + A
		break;

	case 0x88:
		//ADC B: A <- A + B + CY
		break;

	case 0x89:
		//ADC C: A <- A + C + CY
		break;

	case 0x8a:
		//ADC D: A <- A + D + CY
		break;

	case 0x8b:
		//ADC E: A <- A + E + CY
		break;

	case 0x8c:
		//ADC H: A <- A + H + CY
		break;

	case 0x8d:
		//ADC L: A <- A + L + CY
		break;

	case 0x8e:
		//ADC M: A <- A + (HL) + CY
		break;

	case 0x8f:
		//ADC A: A <- A + A + CY
		break;

	case 0x90:
		//SUB B: A <- A - B
		break;

	case 0x91:
		//SUB C: A <- A - C
		break;

	case 0x92:
		//SUB D: A <- A + D
		break;

	case 0x93:
		//SUB E: A <- A - E
		break;

	case 0x94:
		//SUB H: A <- A + H
		break;

	case 0x95:
		//SUB L: A <- A - L
		break;

	case 0x96:
		//SUB M: A <- A + (HL)
		break;

	case 0x97:
		//SUB A: A <- A - A
		break;

	case 0x98:
		//SBB B: A <- A - B - CY
		break;

	case 0x99:
		//SBB C: A <- A - C - CY
		break;

	case 0x9a:
		//SBB D: A <- A - D - CY
		break;

	case 0x9b:
		//SBB E: A <- A - E - CY
		break;

	case 0x9c:
		//SBB H: A <- A - H - CY
		break;

	case 0x9d:
		//SBB L: A <- A - L - CY
		break;

	case 0x9e:
		//SBB M: A <- A - (HL) - CY
		break;

	case 0x9f:
		//SBB A: A <- A - A - CY
		break;

	case 0xa0:
		//ANA B: A <- A & B
		break;

	case 0xa1:
		//ANA C: A <- A & C
		break;

	case 0xa2:
		//ANA D: A <- A & D
		break;

	case 0xa3:
		//ANA E: A <- A & E
		break;

	case 0xa4:
		//ANA H: A <- A & H
		break;

	case 0xa5:
		//ANA L: A <- A & L
		break;

	case 0xa6:
		//ANA M: A <- A & (HL)
		break;

	case 0xa7:
		//ANA A: A <- A & A
		break;

	case 0xa8:
		//XRA B: A <- A ^ B
		break;

	case 0xa9:
		//XRA C: A <- A ^ C
		break;

	case 0xaa:
		//XRA D: A <- A ^ D
		break;

	case 0xab:
		//XRA E: A <- A ^ E
		break;

	case 0xac:
		//XRA H: A <- A ^ H
		break;

	case 0xad:
		//XRA L: A <- A ^ L
		break;

	case 0xae:
		//XRA M: A <- A ^ (HL)
		break;

	case 0xaf:
		//XRA A: A <- A ^ A
		break;

	case 0xb0:
		//ORA B: A <- A | B
		break;

	case 0xb1:
		//ORA C: A <- A | C
		break;

	case 0xb2:
		//ORA D: A <- A | D
		break;

	case 0xb3:
		//ORA E: A <- A | E
		break;

	case 0xb4:
		//ORA H: A <- A | H
		break;

	case 0xb5:
		//ORA L: A <- A | L
		break;

	case 0xb6:
		//ORA M: A <- A | (HL)
		break;

	case 0xb7:
		//ORA A: A <- A | A
		break;

	case 0xb8:
		//CMP B: A - B
		break;

	case 0xb9:
		//CMP C: A - C
		break;

	case 0xba:
		//CMP D: A - D
		break;

	case 0xbb:
		//CMP E: A - E
		break;

	case 0xbc:
		//CMP H: A - H
		break;

	case 0xbd:
		//CMP L: A - L
		break;

	case 0xbe:
		//CMP M: A - (HL)
		break;

	case 0xbf:
		//CMP A: A - A
		break;

	case 0xc0:
		//RNZ: if NZ, RET
		break;

	case 0xc1:
		//POP B: C <- (sp); B <- (sp+1); sp <- sp+2
		break;

	case 0xc2:
		//JNZ adr: if NZ, PC <- adr
		break;

	case 0xc3:
		//JMP adr: PC <= adr
		break;

	case 0xc4:
		//CNZ adr: if NZ, CALL adr
		break;

	case 0xc5:
		//PUSH B: (sp-2)<-C; (sp-1)<-B; sp <- sp - 2
		break;

	case 0xc6:
		//ADI D8: A <- A + byte
		break;

	case 0xc7:
		//RST 0: CALL $0
		break;

	case 0xc8:
		//RZ: if Z, RET
		break;

	case 0xc9:
		//RET: PC.lo <- (sp); PC.hi<-(sp+1); SP <- SP+2
		break;

	case 0xca:
		//JZ adr: if Z, PC <- adr
		break;

	case 0xcc:
		//CZ adr: if Z, CALL adr
		break;

	case 0xcd:
		//CALL adr: (SP-1)<-PC.hi;(SP-2)<-PC.lo;SP<-SP-2;PC=adr
		break;

	case 0xce:
		//ACI D8: A <- A + data + CY
		break;

	case 0xcf:
		//RST 1: CALL $8
		break;

	case 0xd0:
		//RNC: if NCY, RET
		break;

	case 0xd1:
		//POP D: E <- (sp); D <- (sp+1); sp <- sp+2
		break;

	case 0xd2:
		//JNC adr: if NCY, PC<-adr
		break;

	case 0xd3:
		//OUT D8: special
		break;

	case 0xd4:
		//CNC adr: if NCY, CALL adr
		break;

	case 0xd5:
		//PUSH D: (sp-2)<-E; (sp-1)<-D; sp <- sp - 2
		break;

	case 0xd6:
		//SUI D8: A <- A - data
		break;

	case 0xd7:
		//RST 2: CALL $10
		break;

	case 0xd8:
		//RC: if CY, RET
		break;

	case 0xda:
		//JC adr: if CY, PC<-adr
		break;

	case 0xdb:
		//IN D8: special
		break;

	case 0xdc:
		//CC adr: if CY, CALL adr
		break;

	case 0xde:
		//SBI D8: A <- A - data - CY
		break;

	case 0xdf:
		//RST 3: CALL $18
		break;

	case 0xe0:
		//RPO: if PO, RET
		break;

	case 0xe1:
		//POP H: L <- (sp); H <- (sp+1); sp <- sp+2
		break;

	case 0xe2:
		//JPO adr: if PO, PC <- adr
		break;

	case 0xe3:
		//XTHL: L <-> (SP); H <-> (SP+1)
		break;

	case 0xe4:
		//CPO adr: if PO, CALL adr
		break;

	case 0xe5:
		//PUSH H: (sp-2)<-L; (sp-1)<-H; sp <- sp - 2
		break;

	case 0xe6:
		//ANI D8: A <- A & data
		break;

	case 0xe7:
		//RST 4: CALL $20
		break;

	case 0xe8:
		//RPE: if PE, RET
		break;

	case 0xe9:
		//PCHL: PC.hi <- H; PC.lo <- L
		break;

	case 0xea:
		//JPE adr: if PE, PC <- adr
		break;

	case 0xeb:
		//XCHG: H <-> D; L <-> E
		break;

	case 0xec:
		//CPE adr: if PE, CALL adr
		break;

	case 0xee:
		//XRI D8: A <- A ^ data
		break;

	case 0xef:
		//RST 5: CALL $28
		break;

	case 0xf0:
		//RP: if P, RET
		break;

	case 0xf1:
		//POP PSW: flags <- (sp); A <- (sp+1); sp <- sp+2
		break;

	case 0xf2:
		//JP adr: if P=1 PC <- adr
		break;

	case 0xf3:
		//DI: special
		break;

	case 0xf4:
		//CP adr: if P, PC <- adr
		break;

	case 0xf5:
		//PUSH PSW: (sp-2)<-flags; (sp-1)<-A; sp <- sp - 2
		break;

	case 0xf6:
		//ORI D8: A <- A | data
		break;

	case 0xf7:
		//RST 6: CALL $30
		break;

	case 0xf8:
		//RM: if M, RET
		break;

	case 0xf9:
		//SPHL: SP=HL
		break;

	case 0xfa:
		//JM adr: if M, PC <- adr
		break;

	case 0xfb:
		//EI: special
		break;

	case 0xfc:
		//CM adr: if M, CALL adr
		break;

	case 0xfe:
		//CPI D8: A - data
		break;

	case 0xff:
		//RST 7: CALL $38
		break;
		
	}
	return 0;
}