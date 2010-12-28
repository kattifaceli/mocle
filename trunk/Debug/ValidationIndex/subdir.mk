################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ValidationIndex/CRIndex.cpp \
../ValidationIndex/Connectivity.cpp \
../ValidationIndex/Deviation.cpp \
../ValidationIndex/NMIIndex.cpp \
../ValidationIndex/Silhouette.cpp \
../ValidationIndex/VIIndex.cpp 

OBJS += \
./ValidationIndex/CRIndex.o \
./ValidationIndex/Connectivity.o \
./ValidationIndex/Deviation.o \
./ValidationIndex/NMIIndex.o \
./ValidationIndex/Silhouette.o \
./ValidationIndex/VIIndex.o 

CPP_DEPS += \
./ValidationIndex/CRIndex.d \
./ValidationIndex/Connectivity.d \
./ValidationIndex/Deviation.d \
./ValidationIndex/NMIIndex.d \
./ValidationIndex/Silhouette.d \
./ValidationIndex/VIIndex.d 


# Each subdirectory must supply rules for building sources it contributes
ValidationIndex/%.o: ../ValidationIndex/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


