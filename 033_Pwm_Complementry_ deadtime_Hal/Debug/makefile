################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := 033_Pwm_Complementry_ deadtime_Hal
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
033_Pwm_Complementry_\ deadtime_Hal.elf \

MAP_FILES += \
033_Pwm_Complementry_\ deadtime_Hal.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
033_Pwm_Complementry_\ deadtime_Hal.list \

OBJCOPY_HEX += \
033_Pwm_Complementry_\ deadtime_Hal.hex \


# All Target
all: main-build

# Main-build Target
main-build: 033_Pwm_Complementry_\ deadtime_Hal.elf secondary-outputs

# Tool invocations
033_Pwm_Complementry_\ deadtime_Hal.elf 033_Pwm_Complementry_\ deadtime_Hal.map: $(OBJS) $(USER_OBJS) C:\Users\omrvr\STM32CubeIDE\workspace_1.15.0\033_Pwm_Complementry_\ deadtime_Hal\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "033_Pwm_Complementry_ deadtime_Hal.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\omrvr\STM32CubeIDE\workspace_1.15.0\033_Pwm_Complementry_ deadtime_Hal\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="033_Pwm_Complementry_ deadtime_Hal.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

033_Pwm_Complementry_\ deadtime_Hal.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "033_Pwm_Complementry_ deadtime_Hal.list"
	@echo 'Finished building: $@'
	@echo ' '

033_Pwm_Complementry_\ deadtime_Hal.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "033_Pwm_Complementry_ deadtime_Hal.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) 033_Pwm_Complementry_\ deadtime_Hal.elf 033_Pwm_Complementry_\ deadtime_Hal.hex 033_Pwm_Complementry_\ deadtime_Hal.list 033_Pwm_Complementry_\ deadtime_Hal.map 033_Pwm_Complementry_\\ deadtime_Hal.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
