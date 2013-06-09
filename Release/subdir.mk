################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../complex.c \
../console.c \
../holesky.c \
../main.c \
../matrix.c 

OBJS += \
./complex.o \
./console.o \
./holesky.o \
./main.o \
./matrix.o 

C_DEPS += \
./complex.d \
./console.d \
./holesky.d \
./main.d \
./matrix.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


