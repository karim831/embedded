PROJECT = application

HAL = ../libs/hal

MCU = atmega32

OPT = s

F_CPU = 8000000UL




# FLAGS

CFLAG = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -O$(OPT)

# GNU TOOLS

GCC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
Size = avr-size

# FILES

SRC = $(PROJECT).c $(HAL)/dio.c
ELF = ./bin/$(PROJECT).elf
HEX = ./bin/$(PROJECT).hex
LSS = ./bin/$(PROJECT).lss

# TARGETS

all : $(HEX) $(ELF) $(LSS)

$(ELF) : $(SRC)
	$(GCC) $(CFLAG) $^ -o $@

$(HEX) : $(ELF)
	$(OBJCOPY) -O ihex -R .eeprom $< $@

$(LSS) : $(ELF)
	$(OBJDUMP) -S $< > $@

size : $(ELF)
	$(SIZE) $(ELF)

clean :
	rm -f $(ELF) $(HEX) $(LSS)





