PROJECT = application

HAL = ../libs/hal

MCU = atmega32

F_CPU = 8000000UL

OPT = s


CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size


CFLAG = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -O$(OPT)


SRC = $(PROJECT).c $(HAL)/dio.c 

ELF = bin/$(PROJECT).elf
HEX = bin/$(PROJECT).hex
ASM = bin/$(PROJECT).s
LSS = bin/$(PROJECT).lss


all : $(HEX) $(LSS)

$(ELF) : $(SRC)
	$(CC) $(CFLAG)  $^ -o $@

$(HEX) : $(ELF)
	$(OBJCOPY) -O ihex -R .eeprom $< $@

$(LSS) : $(ELF)
	$(OBJDUMP) -S $< > $@

size : $(ELF)
	$(SIZE) $(ELF)

clean : 
	rm -f  $(ELF) $(HEX) $(LSS)
