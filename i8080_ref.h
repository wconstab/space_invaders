#ifndef _I8080_REF_HPP_
#define _I8080_REF_HPP_

#define INST_TBL_SIZE 256
#define NOP					0x00
#define LXI_B_D16					0x01
#define STAX_B					0x02
#define INX_B					0x03
#define INR_B					0x04
#define DCR_B					0x05
#define MVI_B_D8					0x06
#define RLC					0x07
#define DAD_B					0x09
#define LDAX_B					0x0A
#define DCX_B					0x0B
#define INR_C					0x0C
#define DCR_C					0x0D
#define MVI_C_D8					0x0E
#define RRC					0x0F
#define LXI_D_D16					0x11
#define STAX_D					0x12
#define INX_D					0x13
#define INR_D					0x14
#define DCR_D					0x15
#define MVI_D_D8					0x16
#define RAL					0x17
#define DAD_D					0x19
#define LDAX_D					0x1A
#define DCX_D					0x1B
#define INR_E					0x1C
#define DCR_E					0x1D
#define MVI_E_D8					0x1E
#define RAR					0x1F
#define LXI_H_D16					0x21
#define SHLD_adr					0x22
#define INX_H					0x23
#define INR_H					0x24
#define DCR_H					0x25
#define MVI_H_D8					0x26
#define DAA					0x27
#define DAD_H					0x29
#define LHLD_adr					0x2A
#define DCX_H					0x2B
#define INR_L					0x2C
#define DCR_L					0x2D
#define MVI_L_D8					0x2E
#define CMA					0x2F
#define LXI_SP_D16					0x31
#define STA_adr					0x32
#define INX_SP					0x33
#define INR_M					0x34
#define DCR_M					0x35
#define MVI_M_D8					0x36
#define STC					0x37
#define DAD_SP					0x39
#define LDA_adr					0x3A
#define DCX_SP					0x3B
#define INR_A					0x3C
#define DCR_A					0x3D
#define MVI_A_D8					0x3E
#define CMC					0x3F
#define MOV_B_B					0x40
#define MOV_B_C					0x41
#define MOV_B_D					0x42
#define MOV_B_E					0x43
#define MOV_B_H					0x44
#define MOV_B_L					0x45
#define MOV_B_M					0x46
#define MOV_B_A					0x47
#define MOV_C_B					0x48
#define MOV_C_C					0x49
#define MOV_C_D					0x4A
#define MOV_C_E					0x4B
#define MOV_C_H					0x4C
#define MOV_C_L					0x4D
#define MOV_C_M					0x4E
#define MOV_C_A					0x4F
#define MOV_D_B					0x50
#define MOV_D_C					0x51
#define MOV_D_D					0x52
#define MOV_D_E					0x53
#define MOV_D_H					0x54
#define MOV_D_L					0x55
#define MOV_D_M					0x56
#define MOV_D_A					0x57
#define MOV_E_B					0x58
#define MOV_E_C					0x59
#define MOV_E_D					0x5A
#define MOV_E_E					0x5B
#define MOV_E_H					0x5C
#define MOV_E_L					0x5D
#define MOV_E_M					0x5E
#define MOV_E_A					0x5F
#define MOV_H_B					0x60
#define MOV_H_C					0x61
#define MOV_H_D					0x62
#define MOV_H_E					0x63
#define MOV_H_H					0x64
#define MOV_H_L					0x65
#define MOV_H_M					0x66
#define MOV_H_A					0x67
#define MOV_L_B					0x68
#define MOV_L_C					0x69
#define MOV_L_D					0x6A
#define MOV_L_E					0x6B
#define MOV_L_H					0x6C
#define MOV_L_L					0x6D
#define MOV_L_M					0x6E
#define MOV_L_A					0x6F
#define MOV_M_B					0x70
#define MOV_M_C					0x71
#define MOV_M_D					0x72
#define MOV_M_E					0x73
#define MOV_M_H					0x74
#define MOV_M_L					0x75
#define HLT					0x76
#define MOV_M_A					0x77
#define MOV_A_B					0x78
#define MOV_A_C					0x79
#define MOV_A_D					0x7A
#define MOV_A_E					0x7B
#define MOV_A_H					0x7C
#define MOV_A_L					0x7D
#define MOV_A_M					0x7E
#define MOV_A_A					0x7F
#define ADD_B					0x80
#define ADD_C					0x81
#define ADD_D					0x82
#define ADD_E					0x83
#define ADD_H					0x84
#define ADD_L					0x85
#define ADD_M					0x86
#define ADD_A					0x87
#define ADC_B					0x88
#define ADC_C					0x89
#define ADC_D					0x8A
#define ADC_E					0x8B
#define ADC_H					0x8C
#define ADC_L					0x8D
#define ADC_M					0x8E
#define ADC_A					0x8F
#define SUB_B					0x90
#define SUB_C					0x91
#define SUB_D					0x92
#define SUB_E					0x93
#define SUB_H					0x94
#define SUB_L					0x95
#define SUB_M					0x96
#define SUB_A					0x97
#define SBB_B					0x98
#define SBB_C					0x99
#define SBB_D					0x9A
#define SBB_E					0x9B
#define SBB_H					0x9C
#define SBB_L					0x9D
#define SBB_M					0x9E
#define SBB_A					0x9F
#define ANA_B					0xA0
#define ANA_C					0xA1
#define ANA_D					0xA2
#define ANA_E					0xA3
#define ANA_H					0xA4
#define ANA_L					0xA5
#define ANA_M					0xA6
#define ANA_A					0xA7
#define XRA_B					0xA8
#define XRA_C					0xA9
#define XRA_D					0xAA
#define XRA_E					0xAB
#define XRA_H					0xAC
#define XRA_L					0xAD
#define XRA_M					0xAE
#define XRA_A					0xAF
#define ORA_B					0xB0
#define ORA_C					0xB1
#define ORA_D					0xB2
#define ORA_E					0xB3
#define ORA_H					0xB4
#define ORA_L					0xB5
#define ORA_M					0xB6
#define ORA_A					0xB7
#define CMP_B					0xB8
#define CMP_C					0xB9
#define CMP_D					0xBA
#define CMP_E					0xBB
#define CMP_H					0xBC
#define CMP_L					0xBD
#define CMP_M					0xBE
#define CMP_A					0xBF
#define RNZ					0xC0
#define POP_B					0xC1
#define JNZ_adr					0xC2
#define JMP_adr					0xC3
#define CNZ_adr					0xC4
#define PUSH_B					0xC5
#define ADI_D8					0xC6
#define RST_0					0xC7
#define RZ					0xC8
#define RET					0xC9
#define JZ_adr					0xCA
#define CZ_adr					0xCC
#define CALL_adr					0xCD
#define ACI_D8					0xCE
#define RST_1					0xCF
#define RNC					0xD0
#define POP_D					0xD1
#define JNC_adr					0xD2
#define OUT_D8					0xD3
#define CNC_adr					0xD4
#define PUSH_D					0xD5
#define SUI_D8					0xD6
#define RST_2					0xD7
#define RC					0xD8
#define JC_adr					0xDA
#define IN_D8					0xDB
#define CC_adr					0xDC
#define SBI_D8					0xDE
#define RST_3					0xDF
#define RPO					0xE0
#define POP_H					0xE1
#define JPO_adr					0xE2
#define XTHL					0xE3
#define CPO_adr					0xE4
#define PUSH_H					0xE5
#define ANI_D8					0xE6
#define RST_4					0xE7
#define RPE					0xE8
#define PCHL					0xE9
#define JPE_adr					0xEA
#define XCHG					0xEB
#define CPE_adr					0xEC
#define XRI_D8					0xEE
#define RST_5					0xEF
#define RP					0xF0
#define POP_PSW					0xF1
#define JP_adr					0xF2
#define DI					0xF3
#define CP_adr					0xF4
#define PUSH_PSW					0xF5
#define ORI_D8					0xF6
#define RST_6					0xF7
#define RM					0xF8
#define SPHL					0xF9
#define JM_adr					0xFA
#define EI					0xFB
#define CM_adr					0xFC
#define CPI_D8					0xFE
#define RST_7					0xFF

struct opcode_info_desc{
	uint8_t size;
	char *  desc;
};

struct opcode_info_desc opcode_info[INST_TBL_SIZE] = {
    {1, (char *)""},
    {3, (char *)"B <- byte 3, C <- byte 2"},
    {1, (char *)"(BC) <- A"},
    {1, (char *)"BC <- BC+1"},
    {1, (char *)"B <- B+1"},
    {1, (char *)"B <- B-1"},
    {2, (char *)"B <- byte 2"},
    {1, (char *)"A = A << 1; bit 0 = prev bit 7; CY = prev bit 7"},
    {1, (char *)"HL = HL + BC"},
    {1, (char *)"A <- (BC)"},
    {1, (char *)"BC = BC-1"},
    {1, (char *)"C <- C+1"},
    {1, (char *)"C <-C-1"},
    {2, (char *)"C <- byte 2"},
    {1, (char *)"A = A >> 1; bit 7 = prev bit 0; CY = prev bit 0"},
    {3, (char *)"D <- byte 3, E <- byte 2"},
    {1, (char *)"(DE) <- A"},
    {1, (char *)"DE <- DE + 1"},
    {1, (char *)"D <- D+1"},
    {1, (char *)"D <- D-1"},
    {2, (char *)"D <- byte 2"},
    {1, (char *)"A = A << 1; bit 0 = prev CY; CY = prev bit 7"},
    {1, (char *)"HL = HL + DE"},
    {1, (char *)"A <- (DE)"},
    {1, (char *)"DE = DE-1"},
    {1, (char *)"E <-E+1"},
    {1, (char *)"E <- E-1"},
    {2, (char *)"E <- byte 2"},
    {1, (char *)"A = A >> 1; bit 7 = prev bit 7; CY = prev bit 0"},
    {3, (char *)"H <- byte 3, L <- byte 2"},
    {3, (char *)"(adr) <-L; (adr+1)<-H"},
    {1, (char *)"HL <- HL + 1"},
    {1, (char *)"H <- H+1"},
    {1, (char *)"H <- H-1"},
    {2, (char *)"H <- byte 2"},
    {1, (char *)"special"},
    {1, (char *)"HL = HL + HI"},
    {3, (char *)"L <- (adr); H<-(adr+1)"},
    {1, (char *)"HL = HL-1"},
    {1, (char *)"L <- L+1"},
    {1, (char *)"L <- L-1"},
    {2, (char *)"L <- byte 2"},
    {1, (char *)"A <- !A"},
    {3, (char *)"SP.hi <- byte 3, SP.lo <- byte 2"},
    {3, (char *)"(adr) <- A"},
    {1, (char *)"SP = SP + 1"},
    {1, (char *)"(HL) <- (HL)+1"},
    {1, (char *)"(HL) <- (HL)-1"},
    {2, (char *)"(HL) <- byte 2"},
    {1, (char *)"CY = 1"},
    {1, (char *)"HL = HL + SP"},
    {3, (char *)"A <- (adr)"},
    {1, (char *)"SP = SP-1"},
    {1, (char *)"A <- A+1"},
    {1, (char *)"A <- A-1"},
    {2, (char *)"A <- byte 2"},
    {1, (char *)"CY=!CY"},
    {1, (char *)"B <- B"},
    {1, (char *)"B <- C"},
    {1, (char *)"B <- D"},
    {1, (char *)"B <- E"},
    {1, (char *)"B <- H"},
    {1, (char *)"B <- L"},
    {1, (char *)"B <- (HL)"},
    {1, (char *)"B <- A"},
    {1, (char *)"C <- B"},
    {1, (char *)"C <- C"},
    {1, (char *)"C <- D"},
    {1, (char *)"C <- E"},
    {1, (char *)"C <- H"},
    {1, (char *)"C <- L"},
    {1, (char *)"C <- (HL)"},
    {1, (char *)"C <- A"},
    {1, (char *)"D <- B"},
    {1, (char *)"D <- C"},
    {1, (char *)"D <- D"},
    {1, (char *)"D <- E"},
    {1, (char *)"D <- H"},
    {1, (char *)"D <- L"},
    {1, (char *)"D <- (HL)"},
    {1, (char *)"D <- A"},
    {1, (char *)"E <- B"},
    {1, (char *)"E <- C"},
    {1, (char *)"E <- D"},
    {1, (char *)"E <- E"},
    {1, (char *)"E <- H"},
    {1, (char *)"E <- L"},
    {1, (char *)"E <- (HL)"},
    {1, (char *)"E <- A"},
    {1, (char *)"H <- B"},
    {1, (char *)"H <- C"},
    {1, (char *)"H <- D"},
    {1, (char *)"H <- E"},
    {1, (char *)"H <- H"},
    {1, (char *)"H <- L"},
    {1, (char *)"H <- (HL)"},
    {1, (char *)"H <- A"},
    {1, (char *)"L <- B"},
    {1, (char *)"L <- C"},
    {1, (char *)"L <- D"},
    {1, (char *)"L <- E"},
    {1, (char *)"L <- H"},
    {1, (char *)"L <- L"},
    {1, (char *)"L <- (HL)"},
    {1, (char *)"L <- A"},
    {1, (char *)"(HL) <- B"},
    {1, (char *)"(HL) <- C"},
    {1, (char *)"(HL) <- D"},
    {1, (char *)"(HL) <- E"},
    {1, (char *)"(HL) <- H"},
    {1, (char *)"(HL) <- L"},
    {1, (char *)"special"},
    {1, (char *)"(HL) <- A"},
    {1, (char *)"A <- B"},
    {1, (char *)"A <- C"},
    {1, (char *)"A <- D"},
    {1, (char *)"A <- E"},
    {1, (char *)"A <- H"},
    {1, (char *)"A <- L"},
    {1, (char *)"A <- (HL)"},
    {1, (char *)"A <- A"},
    {1, (char *)"A <- A + B"},
    {1, (char *)"A <- A + C"},
    {1, (char *)"A <- A + D"},
    {1, (char *)"A <- A + E"},
    {1, (char *)"A <- A + H"},
    {1, (char *)"A <- A + L"},
    {1, (char *)"A <- A + (HL)"},
    {1, (char *)"A <- A + A"},
    {1, (char *)"A <- A + B + CY"},
    {1, (char *)"A <- A + C + CY"},
    {1, (char *)"A <- A + D + CY"},
    {1, (char *)"A <- A + E + CY"},
    {1, (char *)"A <- A + H + CY"},
    {1, (char *)"A <- A + L + CY"},
    {1, (char *)"A <- A + (HL) + CY"},
    {1, (char *)"A <- A + A + CY"},
    {1, (char *)"A <- A - B"},
    {1, (char *)"A <- A - C"},
    {1, (char *)"A <- A + D"},
    {1, (char *)"A <- A - E"},
    {1, (char *)"A <- A + H"},
    {1, (char *)"A <- A - L"},
    {1, (char *)"A <- A + (HL)"},
    {1, (char *)"A <- A - A"},
    {1, (char *)"A <- A - B - CY"},
    {1, (char *)"A <- A - C - CY"},
    {1, (char *)"A <- A - D - CY"},
    {1, (char *)"A <- A - E - CY"},
    {1, (char *)"A <- A - H - CY"},
    {1, (char *)"A <- A - L - CY"},
    {1, (char *)"A <- A - (HL) - CY"},
    {1, (char *)"A <- A - A - CY"},
    {1, (char *)"A <- A & B"},
    {1, (char *)"A <- A & C"},
    {1, (char *)"A <- A & D"},
    {1, (char *)"A <- A & E"},
    {1, (char *)"A <- A & H"},
    {1, (char *)"A <- A & L"},
    {1, (char *)"A <- A & (HL)"},
    {1, (char *)"A <- A & A"},
    {1, (char *)"A <- A ^ B"},
    {1, (char *)"A <- A ^ C"},
    {1, (char *)"A <- A ^ D"},
    {1, (char *)"A <- A ^ E"},
    {1, (char *)"A <- A ^ H"},
    {1, (char *)"A <- A ^ L"},
    {1, (char *)"A <- A ^ (HL)"},
    {1, (char *)"A <- A ^ A"},
    {1, (char *)"A <- A | B"},
    {1, (char *)"A <- A | C"},
    {1, (char *)"A <- A | D"},
    {1, (char *)"A <- A | E"},
    {1, (char *)"A <- A | H"},
    {1, (char *)"A <- A | L"},
    {1, (char *)"A <- A | (HL)"},
    {1, (char *)"A <- A | A"},
    {1, (char *)"A - B"},
    {1, (char *)"A - C"},
    {1, (char *)"A - D"},
    {1, (char *)"A - E"},
    {1, (char *)"A - H"},
    {1, (char *)"A - L"},
    {1, (char *)"A - (HL)"},
    {1, (char *)"A - A"},
    {1, (char *)"if NZ, RET"},
    {1, (char *)"C <- (sp); B <- (sp+1); sp <- sp+2"},
    {3, (char *)"if NZ, PC <- adr"},
    {3, (char *)"PC <= adr"},
    {3, (char *)"if NZ, CALL adr"},
    {1, (char *)"(sp-2)<-C; (sp-1)<-B; sp <- sp - 2"},
    {2, (char *)"A <- A + byte"},
    {1, (char *)"CALL $0"},
    {1, (char *)"if Z, RET"},
    {1, (char *)"PC.lo <- (sp); PC.hi<-(sp+1); SP <- SP+2"},
    {3, (char *)"if Z, PC <- adr"},
    {3, (char *)"if Z, CALL adr"},
    {3, (char *)"(SP-1)<-PC.hi;(SP-2)<-PC.lo;SP<-SP-2;PC=adr"},
    {2, (char *)"A <- A + data + CY"},
    {1, (char *)"CALL $8"},
    {1, (char *)"if NCY, RET"},
    {1, (char *)"E <- (sp); D <- (sp+1); sp <- sp+2"},
    {3, (char *)"if NCY, PC<-adr"},
    {2, (char *)"special"},
    {3, (char *)"if NCY, CALL adr"},
    {1, (char *)"(sp-2)<-E; (sp-1)<-D; sp <- sp - 2"},
    {2, (char *)"A <- A - data"},
    {1, (char *)"CALL $10"},
    {1, (char *)"if CY, RET"},
    {3, (char *)"if CY, PC<-adr"},
    {2, (char *)"special"},
    {3, (char *)"if CY, CALL adr"},
    {2, (char *)"A <- A - data - CY"},
    {1, (char *)"CALL $18"},
    {1, (char *)"if PO, RET"},
    {1, (char *)"L <- (sp); H <- (sp+1); sp <- sp+2"},
    {3, (char *)"if PO, PC <- adr"},
    {1, (char *)"L <-> (SP); H <-> (SP+1)"},
    {3, (char *)"if PO, CALL adr"},
    {1, (char *)"(sp-2)<-L; (sp-1)<-H; sp <- sp - 2"},
    {2, (char *)"A <- A & data"},
    {1, (char *)"CALL $20"},
    {1, (char *)"if PE, RET"},
    {1, (char *)"PC.hi <- H; PC.lo <- L"},
    {3, (char *)"if PE, PC <- adr"},
    {1, (char *)"H <-> D; L <-> E"},
    {3, (char *)"if PE, CALL adr"},
    {2, (char *)"A <- A ^ data"},
    {1, (char *)"CALL $28"},
    {1, (char *)"if P, RET"},
    {1, (char *)"flags <- (sp); A <- (sp+1); sp <- sp+2"},
    {3, (char *)"if P=1 PC <- adr"},
    {1, (char *)"special"},
    {3, (char *)"if P, PC <- adr"},
    {1, (char *)"(sp-2)<-flags; (sp-1)<-A; sp <- sp - 2"},
    {2, (char *)"A <- A | data"},
    {1, (char *)"CALL $30"},
    {1, (char *)"if M, RET"},
    {1, (char *)"SP=HL"},
    {3, (char *)"if M, PC <- adr"},
    {1, (char *)"special"},
    {3, (char *)"if M, CALL adr"},
    {2, (char *)"A - data"},
    {1, (char *)"CALL $38"},
};

#endif
