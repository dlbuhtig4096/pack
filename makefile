
# 工具
CC ?= gcc
CP ?= objcopy

# 路徑
BIN := bin
CFG := cfg
INC := inc
SRC := src
ELF ?= .exe

%/:
	mkdir -p $@

$(BIN)/%.o: $(CFG)/%.c $(CFG)/baku.h $(INC)/pack.h $(INC)/env.h
	$(CC) -c -I $(CFG) -fno-ident -I $(INC) $< -o $@

$(BIN)/%.bin: $(BIN)/%.o
	$(CP) -O binary $< $@

$(BIN)/%$(ELF): $(SRC)/%.c $(INC)/pack.h $(INC)/env.h
	$(CC) -s -m64 -O3 -fno-stack-protector -fno-exceptions -fno-stack-check -fomit-frame-pointer -ffunction-sections -Wl,--gc-sections -Wl,--stack,0x02000000 -I $(INC) -I $(SRC) $< -Wl,-Map,$(subst $(ELF),.map,$@) -o $@

all: $(BIN)/ $(BIN)/pack$(ELF) $(BIN)/baku1.jp.bin $(BIN)/baku1.us.bin  $(BIN)/baku2.jp.bin $(BIN)/baku2.us.bin
