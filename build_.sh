#!/bin/sh

arm-none-eabi-g++ -g -Wall -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -DSTM32F4 -Ilib -I/home/feer/stm32/libopencm3/include -c lib/*.cpp && mv ./*.o obj
arm-none-eabi-g++ -g -Wall -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -DSTM32F4 -Ilib -I/home/feer/stm32/libopencm3/include -Isrc -c src/main.cpp && mv main.o obj
arm-none-eabi-g++ -g -Wall -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard --specs=nosys.specs -DSTM32F4 -L/home/feer/stm32/libopencm3/lib/ obj/*.o obj/stm32f407.ld -o FASTUSBasp.elf -lopencm3_stm32f4 -Tlibopencm3.ld
arm-none-eabi-objcopy -O binary FASTUSBasp.elf FASTUSBasp.bin
