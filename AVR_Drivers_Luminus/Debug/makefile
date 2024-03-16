################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/01_DIO_Driver/subdir.mk
-include APP/subdir.mk
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
AVR_Drivers_Luminus.lss \

FLASH_IMAGE += \
AVR_Drivers_Luminus.hex \

EEPROM_IMAGE += \
AVR_Drivers_Luminus.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: AVR_Drivers_Luminus.elf secondary-outputs

# Tool invocations
AVR_Drivers_Luminus.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_Drivers_Luminus.map -mmcu=atmega32 -o "AVR_Drivers_Luminus.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_Drivers_Luminus.lss: AVR_Drivers_Luminus.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_Drivers_Luminus.elf  >"AVR_Drivers_Luminus.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_Drivers_Luminus.hex: AVR_Drivers_Luminus.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_Drivers_Luminus.elf  "AVR_Drivers_Luminus.hex"
	@echo 'Finished building: $@'
	@echo ' '

AVR_Drivers_Luminus.eep: AVR_Drivers_Luminus.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AVR_Drivers_Luminus.elf  "AVR_Drivers_Luminus.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_Drivers_Luminus.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVR_Drivers_Luminus.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_Drivers_Luminus.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
