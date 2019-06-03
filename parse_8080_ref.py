from bs4 import BeautifulSoup

filename = "8080_ref.html"
with open(filename) as f:
	data = f.read()
soup = BeautifulSoup(data)
table = soup.find("table")

headers = [th.get_text() for th in table.find_all("th")]
assert "Opcode" in headers, "wrong table?"

rows = table.find_all("tr")[1:]
assert len(rows) == 256, "8080 has 256 opcodes"


class Opcode(object):
	def __init__(self, opcode, instruction, size, flags, description):
		self.opcode = int(opcode, 16)
		self.instruction = instruction
		self.var_name = '_'.join(self.instruction.replace(',', ' ').split())
		self.size = int(size) if size else 0
		self.flags = flags
		self.description = description
		self.valid = self.instruction != '-' and self.size > 0

	def is_valid(self):
		return self.valid

opcodes = []
for row in rows:
	opcode = Opcode(*[td.get_text().strip() for td in row.find_all('td')])
	if opcode.is_valid():
		opcodes.append(opcode)

def gen_handler(opcodes, buf):
	buf.write("""
switch(opcode){""")
	for op in opcodes:
		buf.write("""
case {}:
	//{}: {}
	break;
""".format(hex(op.opcode), op.instruction, op.description))

	buf.write("""	
}
	""")

def gen_table(opcodes, buf):
	buf.write("""
#define INST_TBL_SIZE {}\n""".format(256))

	for op in opcodes:
		buf.write("""#define {}					0x{:02X}\n""".format(op.var_name, op.opcode))

	buf.write("""
struct opcode_info_desc{
	uint8_t size;
	char *  desc;
};
""")

	buf.write("""
struct opcode_info_desc opcode_info[INST_TBL_SIZE] = {
""")
	for op in opcodes:
		buf.write("""    {{{size}, (char *)\"{desc}\"}},\n""".format(size=op.size, desc=op.description))

	buf.write("""};""")
with open("i8080_ref.h", 'w') as f:
	gen_table(opcodes, f)