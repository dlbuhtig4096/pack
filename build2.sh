gcc -s -m64 -O3 -fno-stack-protector -fno-exceptions -fno-stack-check -fomit-frame-pointer -ffunction-sections -Wl,--gc-sections -Wl,--stack,0x02000000 -I include -I src src/pack2.c -Wl,-Map,bin/pack2.map -o bin/pack2.exe