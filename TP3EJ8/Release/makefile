################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
TP3EJ8.lss \

FLASH_IMAGE += \
TP3EJ8.hex \

EEPROM_IMAGE += \
TP3EJ8.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: TP3EJ8.elf secondary-outputs

# Tool invocations
TP3EJ8.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TP3EJ8.map -mmcu=atmega128 -o "TP3EJ8.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TP3EJ8.lss: TP3EJ8.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TP3EJ8.elf  >"TP3EJ8.lss"
	@echo 'Finished building: $@'
	@echo ' '

TP3EJ8.hex: TP3EJ8.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TP3EJ8.elf  "TP3EJ8.hex"
	@echo 'Finished building: $@'
	@echo ' '

TP3EJ8.eep: TP3EJ8.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex TP3EJ8.elf  "TP3EJ8.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TP3EJ8.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 TP3EJ8.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TP3EJ8.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
