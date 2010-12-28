################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ClusteringAlgorithms.cpp \
../DataSet.cpp \
../Euclidean.cpp \
../Exception.cpp \
../InformationTheory.cpp \
../NnList.cpp \
../Partition.cpp \
../Pearson.cpp \
../RelationSDN.cpp \
../SettingsAlgorithm.cpp \
../Similarity.cpp \
../SimilarityMatrix.cpp \
../ValidationIndex.cpp \
../main.cpp 

OBJS += \
./ClusteringAlgorithms.o \
./DataSet.o \
./Euclidean.o \
./Exception.o \
./InformationTheory.o \
./NnList.o \
./Partition.o \
./Pearson.o \
./RelationSDN.o \
./SettingsAlgorithm.o \
./Similarity.o \
./SimilarityMatrix.o \
./ValidationIndex.o \
./main.o 

CPP_DEPS += \
./ClusteringAlgorithms.d \
./DataSet.d \
./Euclidean.d \
./Exception.d \
./InformationTheory.d \
./NnList.d \
./Partition.d \
./Pearson.d \
./RelationSDN.d \
./SettingsAlgorithm.d \
./Similarity.d \
./SimilarityMatrix.d \
./ValidationIndex.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


