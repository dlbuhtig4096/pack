gcc -s -m64 -O3 -fno-stack-protector -fno-exceptions -fno-stack-check -fomit-frame-pointer -ffunction-sections -Wl,--gc-sections -Wl,--stack,0x02000000 -I include -I src src/pack1.c -Wl,-Map,bin/pack1.map -o bin/pack1.exe