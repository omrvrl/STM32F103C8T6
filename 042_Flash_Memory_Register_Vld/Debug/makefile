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


BUILD_ARTIFACT_NAME := 042_Flash_Memory_Register_Vld
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
042_Flash_Memory_Register_Vld.elf \

MAP_FILES += \
042_Flash_Memory_Register_Vld.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
042_Flash_Memory_Register_Vld.list \

OBJCOPY_HEX += \
042_Flash_Memory_Register_Vld.hex \


# All Target
all: main-build

# Main-build Target
main-build: 042_Flash_Memory_Register_Vld.elf secondary-outputs

# Tool invocations
042_Flash_Memory_Register_Vld.elf 042_Flash_Memory_Register_Vld.map: $(OBJS) $(USER_OBJS) C:\Users\omrvr\STM32CubeIDE\workspace_1.15.0\042_Flash_Memory_Register_Vld\STM32F100RBTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "042_Flash_Memory_Register_Vld.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\omrvr\STM32CubeIDE\workspace_1.15.0\042_Flash_Memory_Register_Vld\STM32F100RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="042_Flash_Memory_Register_Vld.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

042_Flash_Memory_Register_Vld.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "042_Flash_Memory_Register_Vld.list"
	@echo 'Finished building: $@'
	@echo ' '

042_Flash_Memory_Register_Vld.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "042_Flash_Memory_Register_Vld.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) 042_Flash_Memory_Register_Vld.elf 042_Flash_Memory_Register_Vld.hex 042_Flash_Memory_Register_Vld.list 042_Flash_Memory_Register_Vld.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
