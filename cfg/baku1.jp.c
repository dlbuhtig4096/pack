
#include <baku.h>

pack info = {
    .id = "NUS-NBMJ",
    .rom = 0x00800000,
    .eof = 0x0,
    .fs = {
        RAW(0x00000000, 0x00001000, "boot.bin"),
        RAW(0x00001000, 0x000FF000, "app.bin"),

        FAT(0x00120000, 0x4, "00/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),
            FS_LZX("2.bin"),
            FS_LZX("3.bin"),

        FAT(0x00140000, 0x6, "01/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),
            FS_LZX("2.bin"),
            FS_LZX("3.bin"),
            FS_LZX("4.bin"),
            FS_LZX("5.bin"),

        FAT(0x00160000, 0x6, "02/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),
            FS_LZX("2.bin"),
            FS_LZX("3.bin"),
            FS_LZX("4.bin"),
            FS_LZX("5.bin"),

        FAT(0x00180000, 0xa, "03/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),
            FS_LZX("2.bin"),
            FS_LZX("3.bin"),
            FS_LZX("4.bin"),
            FS_LZX("5.bin"),
            FS_LZX("6.bin"),
            FS_LZX("7.bin"),
            FS_LZX("8.bin"),
            FS_LZX("9.bin"),

        FAT(0x001a0000, 0x6, "04/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),
            FS_LZX("2.bin"),
            FS_LZX("3.bin"),
            FS_LZX("4.bin"),
            FS_LZX("5.bin"),

        FAT(0x001c0000, 0xf, "05/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),
            FS_LZX("2.bin"),
            FS_LZX("3.bin"),
            FS_LZX("4.bin"),
            FS_LZX("5.bin"),
            FS_LZX("6.bin"),
            FS_LZX("7.bin"),
            FS_LZX("8.bin"),
            FS_LZX("9.bin"),
            FS_LZX("a.bin"),
            FS_LZX("b.bin"),
            FS_LZX("c.bin"),
            FS_LZX("d.bin"),
            FS_LZX("e.bin"),

        FAT(0x001e0000, 0xa, "06/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),
            FS_LZX("2.bin"),
            FS_LZX("3.bin"),
            FS_LZX("4.bin"),
            FS_LZX("5.bin"),
            FS_LZX("6.bin"),
            FS_LZX("7.bin"),
            FS_LZX("8.bin"),
            FS_LZX("9.bin"),

        FAT(0x00200000, 0xd, "07/"), // 0x00040000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),
            FS_LZX("2.bin"),
            FS_LZX("3.bin"),
            FS_LZX("4.bin"),
            FS_LZX("5.bin"),
            FS_LZX("6.bin"),
            FS_LZX("7.bin"),
            FS_LZX("8.bin"),
            FS_LZX("9.bin"),
            FS_LZX("a.bin"),
            FS_LZX("b.bin"),
            FS_LZX("c.bin"),

        FAT(0x00240000, 0x6, "08/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),
            FS_LZX("2.bin"),
            FS_LZX("3.bin"),
            FS_LZX("4.bin"),
            FS_LZX("5.bin"),

        FAT(0x00260000, 0x2, "09/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),

        FAT(0x00280000, 0x2, "0a/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),

        FAT(0x002a0000, 0x2, "0b/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),

        FAT(0x002c0000, 0x1, "0c/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),

        FAT(0x002e0000, 0xa, "0d/"), // 0x00020000
            FS_RAW("info"),
            FS_LZX("0.bin"),
            FS_LZX("1.bin"),
            FS_LZX("2.bin"),
            FS_LZX("3.bin"),
            FS_LZX("4.bin"),
            FS_LZX("5.bin"),
            FS_LZX("6.bin"),
            FS_LZX("7.bin"),
            FS_LZX("8.bin"),
            FS_LZX("9.bin"),

        FAT(0x00300000, 0x365, "assets/"), // 0x00500000
            FS_LZX("000.bin"), // Bomb?
            FS_LZX("001.bin"), // Bomb?
            FS_LZX("002.bin"), // Red Bomb?
            FS_LZX("003.bin"), // Red Bomb?
            FS_LZX("004.bin"), // Remote Bomb
            FS_LZX("005.bin"), // Red Remote Bomb
            FS_LZX("006.bin"), // Altair Sphere Merge Bubble?
            FS_LZX("007.bin"), // Blue Explosion?
            FS_LZX("008.bin"), // Spiked Explosion
            FS_LZX("009.bin"), // Spiked Explosion
            FS_LZX("00a.bin"), // Flat Triangle
            FS_LZX("00b.bin"), // Flat Triangle
            FS_LZX("00c.bin"), // ?
            FS_LZX("00d.bin"), // Spiked Explosion
            FS_LZX("00e.bin"), // Spiked Explosion 2
            FS_LZX("00f.bin"), // Sphere
            FS_LZX("010.bin"), // Explosion?
            FS_LZX("011.bin"), // Explosion?
            FS_LZX("012.bin"), // Fire Power up
            FS_LZX("013.bin"), // Bomb Power up
            FS_LZX("014.bin"), // Red Bomb Power up
            FS_LZX("015.bin"), // Remote Bomb Power up
            FS_LZX("016.bin"), // Heart Power up
            FS_LZX("017.bin"), // Skull Power up
            FS_LZX("018.bin"), // Evil Power up 
            FS_LZX("019.bin"), // Gold Card
            FS_LZX("01a.bin"), // Custom Parts ball
            FS_LZX("01b.bin"), // Custom Parts ball
            FS_LZX("01c.bin"), // Custom Parts ball
            FS_LZX("01d.bin"), // Custom Parts ball
            FS_LZX("01e.bin"), // Blue Gem
            FS_LZX("01f.bin"), // Pink Gem
            FS_RAW("020.bin"), // Sound (BGM) / not compressed
            FS_RAW("021.bin"), // Sound (SFX) / not compressed
            FS_LZX("022.bin"), // Shadow?
            FS_LZX("023.bin"), // Unused logo
            FS_LZX("024.bin"), // HUDSON logo (CI8 0x28, 0x2E88)
            FS_LZX("025.bin"), // PRESS START (title screen) (160x128, CI4 0x28)
            FS_LZX("026.bin"), // HUDSON SOFT ©1997 (title screen)
            FS_LZX("027.bin"), // Overworld map Screen
            FS_LZX("028.bin"), // Stage 1-2-3-4 text
            FS_LZX("029.bin"), // Green Garden Overworld Dragon
            FS_LZX("02a.bin"), // World Floor Plane
            FS_LZX("02b.bin"), // Overworld Chain?
            FS_LZX("02c.bin"), // Stage Select Dialog
            FS_LZX("02d.bin"), // Green Garden Overworld Map
            FS_LZX("02e.bin"), // Red Mountain Overworld Map
            FS_LZX("02f.bin"), // White Glacier Overworld Map
            FS_LZX("030.bin"), // Battle menu BG
            FS_LZX("031.bin"), // Single Battle - Team Battle - Options
            FS_LZX("032.bin"), // Multiplayer Stage Select
            FS_LZX("033.bin"), // Battle - Select Player - Select Team - Stage Select
            FS_LZX("034.bin"), // [unknown flash effect?]
            FS_LZX("035.bin"), // OFF/MAN/COM/CUSTOM
            FS_LZX("036.bin"), // World names
            FS_LZX("037.bin"), // World Select/Stage Select text
            FS_LZX("038.bin"), // -VS- text
            FS_LZX("039.bin"), // Menu arrows (?)
            FS_LZX("03a.bin"), // Battle COM level indicator
            FS_LZX("03b.bin"), // Multiplayer Victory Podium
            FS_LZX("03c.bin"), // Multiplayer Victory Lights
            FS_LZX("03d.bin"), // 
            FS_LZX("03e.bin"), // Draw Multiplayer Text
            FS_LZX("03f.bin"), // Times Up Multiplayer Text
            FS_LZX("040.bin"), // Multiplayer Point Coin
            FS_LZX("041.bin"), // Square bracket/reticle?
            FS_LZX("042.bin"), // 
            FS_LZX("043.bin"), // "BOMBERMAN"
            FS_LZX("044.bin"), // Adventure menu (save/erase icons, crystals, difficulty heads)
            FS_LZX("045.bin"), // Console w/ cartridge; gamepad w/ cart
            FS_LZX("046.bin"), // 
            FS_RAW("047.bin"), // Fonts; Not compressed. English and Japanese alphabets (bubble letters)
            FS_RAW("048.bin"), // Fonts; Not compressed. English and Japanese alphabets (thin text)
            FS_LZX("049.bin"), // ?
            FS_LZX("04a.bin"), // P1
            FS_LZX("04b.bin"), // P2
            FS_LZX("04c.bin"), // P3
            FS_LZX("04d.bin"), // P4
            FS_LZX("04e.bin"), // Question mark
            FS_LZX("04f.bin"), // 
            FS_LZX("050.bin"), // Gold Bomber Head
            FS_LZX("051.bin"), // Sunglasses Head
            FS_LZX("052.bin"), // Cat Suit Head
            FS_LZX("053.bin"), // Dragon Suit Head
            FS_LZX("054.bin"), // Girl Outfit Head
            FS_LZX("055.bin"), // Iron Suit Head
            FS_LZX("056.bin"), // Knight Suit Head
            FS_LZX("057.bin"), // Karate Outfit Head
            FS_LZX("058.bin"), // Chicken Head
            FS_LZX("059.bin"), // Samurai Head
            FS_LZX("05a.bin"), // Gold Bomber Body
            FS_LZX("05b.bin"), // Duck Float Body
            FS_LZX("05c.bin"), // Cat Suit Body
            FS_LZX("05d.bin"), // Dragon Suit Body
            FS_LZX("05e.bin"), // Girl Outfit Body
            FS_LZX("05f.bin"), // Iron Suit Body
            FS_LZX("060.bin"), // Knight Suit Body
            FS_LZX("061.bin"), // Karate Outfit Body
            FS_LZX("062.bin"), // Horse Saddle Body
            FS_LZX("063.bin"), // Samurai Body
            FS_LZX("064.bin"), // Gold Bomber Arms
            FS_LZX("065.bin"), // Drill Arms
            FS_LZX("066.bin"), // Cat Suit Arms
            FS_LZX("067.bin"), // Dragon Suit Arms
            FS_LZX("068.bin"), // Slash Claws Arms
            FS_LZX("069.bin"), // Iron Suit Arms
            FS_LZX("06a.bin"), // Knight Suit Arm1
            FS_LZX("06b.bin"), // Boxing Gloves Arm
            FS_LZX("06c.bin"), // Chicken Wings Arms
            FS_LZX("06d.bin"), // Samurai Outfit Arms
            FS_LZX("06e.bin"), // Gold Bomber Arms2
            FS_LZX("06f.bin"), // Drill Arms2
            FS_LZX("070.bin"), // Cat Suit Arms2
            FS_LZX("071.bin"), // Dragon Suit Arms2
            FS_LZX("072.bin"), // Slash Claws Arms2
            FS_LZX("073.bin"), // Iron Suit Arms2
            FS_LZX("074.bin"), // Knight Suit Arms2
            FS_LZX("075.bin"), // Boxing Glove Arms2
            FS_LZX("076.bin"), // Chicken Wings Arms2
            FS_LZX("077.bin"), // Samurai Outfit Arms2
            FS_LZX("078.bin"), // Gold Bomber Legs
            FS_LZX("079.bin"), // Duck Feet Legs
            FS_LZX("07a.bin"), // Cat Suit Legs
            FS_LZX("07b.bin"), // Dragon Suit Legs
            FS_LZX("07c.bin"), // Girl Outfit Legs
            FS_LZX("07d.bin"), // Iron Suit Legs
            FS_LZX("07e.bin"), // Knight Suit Legs
            FS_LZX("07f.bin"), // Karate Outfit Legs
            FS_LZX("080.bin"), // Bunny Socks Legs
            FS_LZX("081.bin"), // High Heels Legs
            FS_LZX("082.bin"), // Gold Bomber Legs2
            FS_LZX("083.bin"), // Duck Feet Legs2
            FS_LZX("084.bin"), // Cat Suit Legs2
            FS_LZX("085.bin"), // Dragon Suit Legs2
            FS_LZX("086.bin"), // Girl Outfit Legs2
            FS_LZX("087.bin"), // Iron Suit Legs2
            FS_LZX("088.bin"), // Knight Suit Legs2
            FS_LZX("089.bin"), // Karate Outfit Legs2
            FS_LZX("08a.bin"), // Bunny Socks Legs2
            FS_LZX("08b.bin"), // High Heels Legs2
            FS_LZX("08c.bin"), // Item Crate (box)?
            FS_LZX("08d.bin"), // Item Crate (box)?
            FS_LZX("08e.bin"), // Tall Item Crate (box)?
            FS_LZX("08f.bin"), // Green Garden Stage 1 Stone Geometry
            FS_LZX("090.bin"), // Green Garden Stage 1 Column
            FS_LZX("091.bin"), // Green Garden Stage Bomb Stone Cube?
            FS_LZX("092.bin"), // Green Garden Stage 3 Column?
            FS_LZX("093.bin"), // Green Garden Stage 1 Pots
            FS_LZX("094.bin"), // Green Garden Stage 3 Bomb Lift
            FS_LZX("095.bin"), // Green Garden Stage 3 Floating Tile
            FS_LZX("096.bin"), // Flat Square
            FS_LZX("097.bin"), // Blue Resort Stage 1 Tree
            FS_LZX("098.bin"), // Blue Resort Cannonball Sprite?
            FS_LZX("099.bin"), // Blue Resort Stage 1/3 Crates
            FS_LZX("09a.bin"), // Blue Resort Stage 1/3 Bomb Drains
            FS_LZX("09b.bin"), // Blue Resort Stage 1Flower pot?
            FS_LZX("09c.bin"), // Blue Resort Stage 1 Bomb Wall
            FS_LZX("09d.bin"), // Red Mountain Level Geometry
            FS_LZX("09e.bin"), // Red Mountain Level Geometry
            FS_LZX("09f.bin"), // Red Mountain Stage 3 Machine
            FS_LZX("0a0.bin"), // Red Mountain Stage 1 Metal Door
            FS_LZX("0a1.bin"), // Red Mountain Stage 3 Tall Barrel
            FS_LZX("0a2.bin"), // Red Mountain Stage 3 Barrel
            FS_LZX("0a3.bin"), // Red Mountain Stage 3 Mine Cart
            FS_LZX("0a4.bin"), // Red Mountain Stage 3 Traffic Light
            FS_LZX("0a5.bin"), // Black Fortress Stage 1 Pillar
            FS_LZX("0a6.bin"), // Black Fortress Stage 1 Box
            FS_LZX("0a7.bin"), // Black Fortress Stage 1 Lampposts
            FS_LZX("0a8.bin"), // Black Fortress Stage 1 Lampposts
            FS_LZX("0a9.bin"), // Black Fortress Stage 1 Lampposts
            FS_LZX("0aa.bin"), // Black Fortress Stage 1 Lampposts
            FS_LZX("0ab.bin"), // Black Fortress Stage 1 Small Vehicle
            FS_LZX("0ac.bin"), // Black Fortress Stage 1 Long Vehicle
            FS_LZX("0ad.bin"), // Black Fortress Stage 1 End Enemy Cannon
            FS_LZX("0ae.bin"), // Black Fortress Stage 1 End Enemy Cannon Shot?
            FS_LZX("0af.bin"), // Black Fortress Stage 1 End Enemy Mid
            FS_LZX("0b0.bin"), // Black Fortress Stage 1 Lampposts
            FS_LZX("0b1.bin"), // Black Fortress Stage 1 Turret Enemy
            FS_LZX("0b2.bin"), // Black Fortress Stage 3 Platform On
            FS_LZX("0b3.bin"), // Black Fortress Stage 1 Walkway
            FS_LZX("0b4.bin"), // Black Fortress Stage 1 Lampposts
            FS_LZX("0b5.bin"), // Unused Missle Trooper Variant?
            FS_LZX("0b6.bin"), // Black Fortress pointy thing? Overworld?
            FS_LZX("0b7.bin"), // Black Fortress Crystal/Gem?
            FS_LZX("0b8.bin"), // 
            FS_LZX("0b9.bin"), // 
            FS_LZX("0ba.bin"), // Black Fortress Stage 3 Undo Icon
            FS_LZX("0bb.bin"), // Black Fortress Stage 1 Walkway
            FS_LZX("0bc.bin"), // Black Fortress Stage 1 End Enemy Platform
            FS_LZX("0bd.bin"), // Rectangle Green and yellow, thunder? Tube?
            FS_LZX("0be.bin"), // Black Fortress Stage 3 Green Platform Room 1
            FS_LZX("0bf.bin"), // Black Fortress Stage 3 Switch 1
            FS_LZX("0c0.bin"), // Black Fortress Stage 3 Switch 2
            FS_LZX("0c1.bin"), // Black Fortress Stage 3 Switch 3
            FS_LZX("0c2.bin"), // Black Fortress Stage 3 Locking Door
            FS_LZX("0c3.bin"), // Black Fortress Stage 1 Lampposts
            FS_LZX("0c4.bin"), // Black Fortress Stage 3 Switch 4
            FS_LZX("0c5.bin"), // Black Fortress Stage 3 Floor Panel
            FS_LZX("0c6.bin"), // Black Fortress Stage 3 Floor Panel
            FS_LZX("0c7.bin"), // Black Fortress Stage 3 Room Walls?
            FS_LZX("0c8.bin"), // Black Fortress Stage 1/3 Locking Doors?
            FS_LZX("0c9.bin"), // Space Pirates Emblem
            FS_LZX("0ca.bin"), // Black Fortress Stage 3 Platform Off
            FS_LZX("0cb.bin"), // Black Fortress Stage 1 Turret Lockon Red
            FS_LZX("0cc.bin"), // Black Fortress Stage 1 Turret Lockon Green
            FS_LZX("0cd.bin"), // Pillar?
            FS_LZX("0ce.bin"), // Vertical Pillar
            FS_LZX("0cf.bin"), // Rainbow Palace Stage 1 Pillar 1
            FS_LZX("0d0.bin"), // Rainbow Palace Stage 1 Pillar 2
            FS_LZX("0d1.bin"), // Rainbow Palace Stage 1 Block
            FS_LZX("0d2.bin"), // Overworld Rainbow Palace Base?
            FS_LZX("0d3.bin"), // 
            FS_LZX("0d4.bin"), // Stone Block?
            FS_LZX("0d5.bin"), // Stone Block?
            FS_LZX("0d6.bin"), // 
            FS_LZX("0d7.bin"), // Red Mountain Stage 1/3 Level Geometry?
            FS_LZX("0d8.bin"), // Stone Block. used?
            FS_LZX("0d9.bin"), // Red Mountain Stage 3 Slant Barrel?
            FS_LZX("0da.bin"), // White Glacier Stage 3 Bomb Icicle
            FS_LZX("0db.bin"), // Crate?
            FS_RAW("0dc.bin"), // Not compressed.
            FS_RAW("0dd.bin"), // Not compressed.
            FS_LZX("0de.bin"), // Red Soldier/Trooper Enemy
            FS_LZX("0df.bin"), // Red Soldier/Trooper Enemy
            FS_LZX("0e0.bin"), // Blue Soldier/Trooper Enemy
            FS_LZX("0e1.bin"), // Green Trooper
            FS_LZX("0e2.bin"), // Green Garden Stage 3 Flare Bird?
            FS_LZX("0e3.bin"), // Green Garden Stage 1 Enemy Totem Head
            FS_LZX("0e4.bin"), // Green Garden Stage 1 Enemy Mash
            FS_LZX("0e5.bin"), // White Glacier Snow Flake
            FS_LZX("0e6.bin"), // Blue Resort Stage 1 Guard Enemy
            FS_LZX("0e7.bin"), // Blue Resort Fish Enemy
            FS_LZX("0e8.bin"), // Blue Resort Fish Enemy swimming
            FS_LZX("0e9.bin"), // Blue Resort Jelly fish
            FS_LZX("0ea.bin"), // Green Garden Stage 3 Annoying Bird
            FS_LZX("0eb.bin"), // Red Mountain Stage 1 Fire Spike
            FS_LZX("0ec.bin"), // Red Mountain Stage 1 Pick Enemy
            FS_LZX("0ed.bin"), // Red Mountain Stage 1 Stalker Bat
            FS_LZX("0ee.bin"), // Red Mountain Stage 1/3 Spin Spilke
            FS_LZX("0ef.bin"), // Black Fortress Stage 3 Purple Soldier/Trooper
            FS_LZX("0f0.bin"), // White Glacier Stage 1/3 Snowman
            FS_LZX("0f1.bin"), // White Glacier Stage 1 Snow Rabbit
            FS_LZX("0f2.bin"), // Green Garden Stage 1 Mash Enemy
            FS_LZX("0f3.bin"), // White Glacier Stage 3 Freezy Enemy
            FS_LZX("0f4.bin"), // White Glacier Snow Flake
            FS_LZX("0f5.bin"), // Snake Jar Enemy?
            FS_LZX("0f6.bin"), // Black Fortress Stage 3 Cannon Mech
            FS_LZX("0f7.bin"), // ?
            FS_LZX("0f8.bin"), // Black Fortress Stage 1 Ufo Enemy
            FS_LZX("0f9.bin"), // Black Fortress Stage 1/3 Dive Mech
            FS_LZX("0fa.bin"), // Green Enemy Head with Glasses
            FS_LZX("0fb.bin"), // Rainbow Palace Stage 1/3 Heart King Enemy
            FS_LZX("0fc.bin"), // Rainbow Palace Stage 1/3 Spade Knight Enemy
            FS_LZX("0fd.bin"), // Rainbow Palace Stage 1/3 Diamond Soldier  Enemy
            FS_LZX("0fe.bin"), // Rainbow Palace Stage 1/3 Club Fighter Enemy
            FS_LZX("0ff.bin"), // Rainbow Palace Stage 1/3 Eleki Enemy
            FS_LZX("100.bin"), // same as 246?
            FS_LZX("101.bin"), // Black Fortress Hazard Enemy?
            FS_LZX("102.bin"), // Blue Resort Guard Bullet
            FS_LZX("103.bin"), // Energy Orb?
            FS_LZX("104.bin"), // -
            FS_LZX("105.bin"), // Blue Resort Stage 4 Bubble?
            FS_LZX("106.bin"), // Black Fortress Stage 2 Boss Missile
            FS_LZX("107.bin"), // Purple/pink Hexagon?
            FS_LZX("108.bin"), // Rectangle Spade image Rgba32
            FS_LZX("109.bin"), // Thunderbolt hexagon?
            FS_LZX("10a.bin"), // Red Mountain Fires Sprite?
            FS_RAW("10b.bin"), // Not compressed.
            FS_LZX("10c.bin"), // Flat Triangle
            FS_LZX("10d.bin"), // Sun-like spark?
            FS_LZX("10e.bin"), // Flat Triangle
            FS_LZX("10f.bin"), // Big sparkle animation?
            FS_LZX("110.bin"), // Flat Triangle
            FS_LZX("111.bin"), // Big spark animation?
            FS_LZX("112.bin"), // Flat Triangle
            FS_LZX("113.bin"), // Sparkles?
            FS_LZX("114.bin"), // Flat Triangle
            FS_LZX("115.bin"), // Big yellow spark?
            FS_LZX("116.bin"), // Stunned star effect
            FS_LZX("117.bin"), // Flat Triangle
            FS_LZX("118.bin"), // Flat Triangle
            FS_LZX("119.bin"), // Fire puff animation
            FS_LZX("11a.bin"), // Energy thing?
            FS_LZX("11b.bin"), // Fire/lava? And big white/yellow flash
            FS_LZX("11c.bin"), // Flat Triangle
            FS_LZX("11d.bin"), // Flat Triangle
            FS_LZX("11e.bin"), // -
            FS_LZX("11f.bin"), // Flat Triangle
            FS_LZX("120.bin"), // Flat Triangle
            FS_LZX("121.bin"), // Explosion animation
            FS_LZX("122.bin"), // Red Mountain Fireball sprite?
            FS_LZX("123.bin"), // Flat Triangle
            FS_LZX("124.bin"), // 
            FS_LZX("125.bin"), // Flat Triangle
            FS_LZX("126.bin"), // Smoke puff animation?
            FS_LZX("127.bin"), // Flat Triangle
            FS_LZX("128.bin"), // Black smoke puff animation?
            FS_LZX("129.bin"), // Red Mountain Fireball sprite?
            FS_LZX("12a.bin"), // Energy thing?
            FS_LZX("12b.bin"), // Stunned Effect
            FS_LZX("12c.bin"), // White Glacier Snow Particle?
            FS_LZX("12d.bin"), // White Glacier Snow Particle?
            FS_LZX("12e.bin"), // White Glacier Snow Particle?
            FS_LZX("12f.bin"), // Flat Triangle
            FS_LZX("130.bin"), // Battle Game HUD heads
            FS_LZX("131.bin"), // 
            FS_LZX("132.bin"), // Test Room
            FS_LZX("133.bin"), // 
            FS_LZX("134.bin"), // Test Room
            FS_LZX("135.bin"), // 
            FS_LZX("136.bin"), // Test Room
            FS_LZX("137.bin"), // 
            FS_LZX("138.bin"), // Test Room
            FS_LZX("139.bin"), // -
            FS_LZX("13a.bin"), // Blue Resort Stage 1 Starting Room
            FS_LZX("13b.bin"), // Blue Resort Stage 1 second room
            FS_LZX("13c.bin"), // Blue Resort Stage 1 Middle Platform Room
            FS_LZX("13d.bin"), // Blue Resort Stage 1/3 Top Room?
            FS_LZX("13e.bin"), // Blue Resort Stage 3 Starting Room
            FS_LZX("13f.bin"), // Blue Resort Stage 3 Exit Room
            FS_LZX("140.bin"), // 
            FS_LZX("141.bin"), // 
            FS_LZX("142.bin"), // 
            FS_LZX("143.bin"), // 
            FS_LZX("144.bin"), // 
            FS_LZX("145.bin"), // 
            FS_LZX("146.bin"), // Space Pirates Emblem
            FS_LZX("147.bin"), // Red Mountain Iron Wall Texture?
            FS_LZX("148.bin"), // Blue Resort Roof Texture
            FS_LZX("149.bin"), // Blue Resort Switch
            FS_LZX("14a.bin"), // Blue Resort Dam?
            FS_LZX("14b.bin"), // Blue Resort Waterfall?
            FS_LZX("14c.bin"), // Blue Resort Water FloorTile
            FS_LZX("14d.bin"), // Blue Resort Water FloorTile
            FS_LZX("14e.bin"), // Blue Resort Water Edge
            FS_LZX("14f.bin"), // Blue Resort Water Ripple
            FS_LZX("150.bin"), // Water Plane?
            FS_LZX("151.bin"), // Water Plane?
            FS_LZX("152.bin"), // Blue Resort Stage 3 Exit Waterfall
            FS_LZX("153.bin"), // Water Planes?
            FS_LZX("154.bin"), // 
            FS_LZX("155.bin"), // 
            FS_LZX("156.bin"), // 
            FS_LZX("157.bin"), // 
            FS_LZX("158.bin"), // 
            FS_LZX("159.bin"), // 
            FS_LZX("15a.bin"), // 
            FS_LZX("15b.bin"), // 
            FS_LZX("15c.bin"), // Blue Resort Stage 1/3 Bridge?
            FS_LZX("15d.bin"), // Blue Resort Stage 1/3 Bridge?
            FS_LZX("15e.bin"), // Blue Resort Stage 1/3 Bridge?
            FS_LZX("15f.bin"), // Blue Resort Stage 1 Exit Bridge?
            FS_LZX("160.bin"), // Blue Resort Stage 1 Window Tile
            FS_LZX("161.bin"), // Blue Resort Stage 1/3 Cannons
            FS_LZX("162.bin"), // Blue Resort Stage 3 Moving Waterway
            FS_LZX("163.bin"), // Blue Resort Stage 3 Fountain Statue Exit
            FS_LZX("164.bin"), // Blue Resort Stage 1/3 Waterfall?
            FS_LZX("165.bin"), // Blue Resort Stage 1/3 Waterfall?
            FS_LZX("166.bin"), // Blue Resort Stage 3 Moving Level Geometry
            FS_LZX("167.bin"), // Blue Resort Stage 1/3 Waterfall?
            FS_LZX("168.bin"), // -
            FS_LZX("169.bin"), // Cut out floor water?
            FS_LZX("16a.bin"), // Cut out floor water?
            FS_LZX("16b.bin"), // Cut out floor water?
            FS_LZX("16c.bin"), // Cut out floor water?
            FS_LZX("16d.bin"), // Cut out floor water?
            FS_LZX("16e.bin"), // Cut out floor water?
            FS_LZX("16f.bin"), // Blue Resort Stage 2
            FS_LZX("170.bin"), // 
            FS_LZX("171.bin"), // 
            FS_LZX("172.bin"), // Blue Resort Stage 4 Raft Pieces?
            FS_LZX("173.bin"), // Blue Resort Stage 4 Walls?
            FS_LZX("174.bin"), // Blue Resort Stage 4 Water Plane
            FS_LZX("175.bin"), // Blue Resort Stage 4 Tsunami?
            FS_LZX("176.bin"), // -
            FS_LZX("177.bin"), // Blue Resort Stage 4 Boss Tentacle
            FS_LZX("178.bin"), // Blue Resort Stage 4 Boss Tentacle
            FS_LZX("179.bin"), // Blue Resort Stage 4 Boss
            FS_LZX("17a.bin"), // 
            FS_LZX("17b.bin"), // 
            FS_LZX("17c.bin"), // Blue Resort Stage 4 WallFlame?
            FS_LZX("17d.bin"), // [Dark purple ball? CI8 0x40; 0x8C0]
            FS_LZX("17e.bin"), // ?
            FS_LZX("17f.bin"), // [Dark purple ball? CI8 0x40; 0x8C0]
            FS_LZX("180.bin"), // Blue Resort Stage 4 Boss Antenna
            FS_LZX("181.bin"), // -
            FS_LZX("182.bin"), // Blue Resort Stage 4 Bubble?
            FS_LZX("183.bin"), // Blue Resort Stage 4 Boss Water Splash
            FS_LZX("184.bin"), // Blue Resort Stage 4 Boss Raft Attack
            FS_LZX("185.bin"), // Red Mountain Stage 1 Starting Room
            FS_LZX("186.bin"), // Red Mountain Stage 4 Lava Plane?
            FS_LZX("187.bin"), // Red Mountain Stage 1 Room?
            FS_LZX("188.bin"), // Red Mountain Stage 1/3 Lava Plane?
            FS_LZX("189.bin"), // Red Mountain Stage 1 Room?
            FS_LZX("18a.bin"), // Red Mountain Stage 1/3 Lava Plane?
            FS_LZX("18b.bin"), // Red Mountain Stage 1 Room?
            FS_LZX("18c.bin"), // Red Mountain Stage 1/3 Lava Plane?
            FS_LZX("18d.bin"), // Red Mountain Stage 1 Room?
            FS_LZX("18e.bin"), // Red Mountain Stage 1/3 Lava Plane?
            FS_LZX("18f.bin"), // Red Mountain Stage 1 Secret Room
            FS_LZX("190.bin"), // 
            FS_LZX("191.bin"), // 
            FS_LZX("192.bin"), // 
            FS_LZX("193.bin"), // 
            FS_LZX("194.bin"), // 
            FS_LZX("195.bin"), // 
            FS_LZX("196.bin"), // 
            FS_LZX("197.bin"), // 
            FS_LZX("198.bin"), // Red Mountain Little Room collision
            FS_LZX("199.bin"), // Red Mountain Stage 3 First Room
            FS_LZX("19a.bin"), // Red Mountain Stage 1/3 Lava Plane?
            FS_LZX("19b.bin"), // Red Mountain Stage 3 Second Room
            FS_LZX("19c.bin"), // Red Mountain Stage 1/3 Lava Plane?
            FS_LZX("19d.bin"), // Red Mountain Stage 3 Third Room
            FS_LZX("19e.bin"), // Red Mountain Stage 1/3 Lava Plane?
            FS_LZX("19f.bin"), // Red Mountain Lava Column?
            FS_LZX("1a0.bin"), // Red Mountain Stage 3 Fourth Room
            FS_LZX("1a1.bin"), // Red Mountain Lava Plane
            FS_LZX("1a2.bin"), // Red Mountain Stage 3 Exit Room
            FS_LZX("1a3.bin"), // Red Mountain Lava Plane
            FS_LZX("1a4.bin"), // Red Mountain Stage 3 Room?
            FS_LZX("1a5.bin"), // Red Mountain 3 First Room collision
            FS_LZX("1a6.bin"), // Red Mountain 3 Second Room collision
            FS_LZX("1a7.bin"), // Red Mountain 3 Third Room collision
            FS_LZX("1a8.bin"), // Red Mountain 3 Fourth Room collision
            FS_LZX("1a9.bin"), // Red Mountain 3 Exit Room collision
            FS_LZX("1aa.bin"), // Red Mountain Stage 2 Mid Boss Room
            FS_LZX("1ab.bin"), // Red Mountain Stage 2 Mid Boss Room collision
            FS_LZX("1ac.bin"), // Red Mountain Stage1 Short Boulder Bridge
            FS_LZX("1ad.bin"), // Red Mountain Stage1 Tall Boulder Bridge
            FS_LZX("1ae.bin"), // Red Mountain Stage 1 Ending Obstacle
            FS_LZX("1af.bin"), // Red Mountain Stage 1 Exit Support Column
            FS_LZX("1b0.bin"), // Red Mountain Stage 3 Switch On
            FS_LZX("1b1.bin"), // Red Mountain Stage 3 Spikes?
            FS_LZX("1b2.bin"), // Red Mountain Stage 3 Spike Switch On
            FS_LZX("1b3.bin"), // Red Mountain Stage 3 Switch Off
            FS_LZX("1b4.bin"), // Red Mountain Stage 3 Spike Switch Off
            FS_LZX("1b5.bin"), // Evil Power up 
            FS_LZX("1b6.bin"), // Red Mountain Stage 3 Boulder Sprite
            FS_LZX("1b7.bin"), // Red Mountain Stage 1/3 Fireball
            FS_LZX("1b8.bin"), // Red Mountain Stage 3 Lifted Railway Exit
            FS_LZX("1b9.bin"), // Red Mountain Stage 3 Railway Lift Exit
            FS_LZX("1ba.bin"), // Red Mountain Stage 3 Railway Destroyed Lift Exit
            FS_LZX("1bb.bin"), // Red Mountain Stage 3 Trolley Enemy
            FS_LZX("1bc.bin"), // Two Planes Crossed?
            FS_LZX("1bd.bin"), // -
            FS_LZX("1be.bin"), // Red Mountain Stage 1/3 Fireball
            FS_LZX("1bf.bin"), // Red Mountain Stage 1 End Switch
            FS_LZX("1c0.bin"), // Red Mountain Stage 1 End Switch
            FS_LZX("1c1.bin"), // Red Mountain Stage? Level Geometry
            FS_LZX("1c2.bin"), // Red Mountain Stage? Level Geometry
            FS_LZX("1c3.bin"), // Red mountain Stage 2 Boss Door
            FS_LZX("1c4.bin"), // Red Mountain Stage 4 Boss Base
            FS_LZX("1c5.bin"), // Red Mountain Stage 4 Boss Eyes
            FS_LZX("1c6.bin"), // Red Mountain Stage 4 Boss Hat
            FS_LZX("1c7.bin"), // Red Mountain Stage 4 Boss Arms
            FS_LZX("1c8.bin"), // Red Mountain Stage 4 Boss Hand Right
            FS_LZX("1c9.bin"), // Red Mountain Stage 4 Boss Hand Left
            FS_LZX("1ca.bin"), // Red Mountain Stage 4 Boss Body
            FS_LZX("1cb.bin"), // Beam Attack? (Triangle Pillar)
            FS_LZX("1cc.bin"), // Flat Square
            FS_LZX("1cd.bin"), // Damage Sprite
            FS_LZX("1ce.bin"), // Boss Explosions Black Fortress?
            FS_LZX("1cf.bin"), // Flat Square
            FS_LZX("1d0.bin"), // [Some kind of electric effect?]
            FS_LZX("1d1.bin"), // Red Mountain Stage 4 Room
            FS_LZX("1d2.bin"), // -
            FS_LZX("1d3.bin"), // Black Fortress Stage 1 Room Ceiling Walkway?
            FS_LZX("1d4.bin"), // Black Fortress Stage 1 Room Highway?
            FS_LZX("1d5.bin"), // Black Fortress Stage 1 Tunnel Entrance
            FS_LZX("1d6.bin"), // Black Fortress Stage 1?
            FS_LZX("1d7.bin"), // Black Fortress Stage 1 Room Ceiling Walway?
            FS_LZX("1d8.bin"), // Black Fortress Stage 1 Tunnel room?
            FS_LZX("1d9.bin"), // 
            FS_LZX("1da.bin"), // 
            FS_LZX("1db.bin"), // 
            FS_LZX("1dc.bin"), // Black Fortress Stage 1 Room Ceiling Walkway?
            FS_LZX("1dd.bin"), // 
            FS_LZX("1de.bin"), // Black Fortress Stage 1 Last Walkway Room
            FS_LZX("1df.bin"), // 
            FS_LZX("1e0.bin"), // Black Fortress Stage 1 Exit Room
            FS_LZX("1e1.bin"), // -
            FS_LZX("1e2.bin"), // -
            FS_LZX("1e3.bin"), // -
            FS_LZX("1e4.bin"), // -
            FS_LZX("1e5.bin"), // -
            FS_LZX("1e6.bin"), // -
            FS_LZX("1e7.bin"), // -
            FS_LZX("1e8.bin"), // -
            FS_LZX("1e9.bin"), // Black Fortress Stage 3 Starting Room
            FS_LZX("1ea.bin"), // 
            FS_LZX("1eb.bin"), // Black Fortress Stage 3 2nd Room?
            FS_LZX("1ec.bin"), // 
            FS_LZX("1ed.bin"), // Black Fortress Stage 3 3rd Room?
            FS_LZX("1ee.bin"), // 
            FS_LZX("1ef.bin"), // Black Fortress Stage 3 Exit Room
            FS_LZX("1f0.bin"), // Black Fortress Stage 3 Platforms?
            FS_LZX("1f1.bin"), // Black Fortress Stage 3 Room?
            FS_LZX("1f2.bin"), // Black Fortress A6 Arrows Text
            FS_LZX("1f3.bin"), // -
            FS_LZX("1f4.bin"), // -
            FS_LZX("1f5.bin"), // -
            FS_LZX("1f6.bin"), // -
            FS_LZX("1f7.bin"), // -
            FS_LZX("1f8.bin"), // -
            FS_LZX("1f9.bin"), // -
            FS_LZX("1fa.bin"), // Black Fortress Stage 4 Boss Room
            FS_LZX("1fb.bin"), // -
            FS_LZX("1fc.bin"), // Space Pirate Emblem
            FS_LZX("1fd.bin"), // ?
            FS_LZX("1fe.bin"), // Flat Square
            FS_LZX("1ff.bin"), // Yellow glowing circle
            FS_LZX("200.bin"), // Black Fortress Stage 4 Cutscene Platform
            FS_LZX("201.bin"), // Multiplayer Map Rock Garden
            FS_LZX("202.bin"), // Multiplayer Map Up and Down Bottom
            FS_LZX("203.bin"), // Multiplayer Map Up and Down Top
            FS_LZX("204.bin"), // Multiplayer Water Plane?
            FS_LZX("205.bin"), // Multiplayer Map Up and Down Preview?
            FS_LZX("206.bin"), // Multiplayer Map Pyramid
            FS_LZX("207.bin"), // Multiplayer Map Greedy Trap
            FS_LZX("208.bin"), // Multiplayer Map Greedy Trap
            FS_LZX("209.bin"), // Greedy Trap Wall Hazard Left
            FS_LZX("20a.bin"), // Greedy Trap Wall Hazard Right
            FS_LZX("20b.bin"), // Multiplayer Water Plane?
            FS_LZX("20c.bin"), // Multiplayer Map unused multiplayer map
            FS_LZX("20d.bin"), // Multiplayer Map Top Rules Bottom
            FS_LZX("20e.bin"), // Top Rules Wall Hazard Left
            FS_LZX("20f.bin"), // Top Rules Wall Hazard Right
            FS_LZX("210.bin"), // Multiplayer Map Top Rules Top
            FS_LZX("211.bin"), // Multiplayer Map Field of Grass
            FS_LZX("212.bin"), // Multiplayer Map In the Gutter
            FS_LZX("213.bin"), // In the Gutter Wall Hazard Right
            FS_LZX("214.bin"), // In the Gutter Wall Hazard Left
            FS_LZX("215.bin"), // Multiplayer Water Plane?
            FS_LZX("216.bin"), // Multiplayer Map Sea Sick
            FS_LZX("217.bin"), // Multiplayer Map Blizzard Batte
            FS_LZX("218.bin"), // Multiplayer Map Lost at Sea
            FS_LZX("219.bin"), // -
            FS_LZX("21a.bin"), // -
            FS_LZX("21b.bin"), // -
            FS_LZX("21c.bin"), // -
            FS_LZX("21d.bin"), // -
            FS_LZX("21e.bin"), // -
            FS_LZX("21f.bin"), // -
            FS_LZX("220.bin"), // -
            FS_LZX("221.bin"), // -
            FS_LZX("222.bin"), // -
            FS_LZX("223.bin"), // White Glacier Stage 1 Starting Room
            FS_LZX("224.bin"), // White Glacier Stage 1 2nd Room Bridges and fences
            FS_LZX("225.bin"), // White Glacier Stage 1 2nd Room
            FS_LZX("226.bin"), // White Glacier Stage 1 Exit Room
            FS_LZX("227.bin"), // White Glacier Stage 1 Exit Room Bridges and fences
            FS_LZX("228.bin"), // White Glacier Stage 1 2nd Room Bridges and fences
            FS_LZX("229.bin"), // White Glacier Stage 1 2nd Room Bridges and fences
            FS_LZX("22a.bin"), // White Glacier Stage 1 2nd Room Bridges and fences
            FS_LZX("22b.bin"), // White Glacier Stage 3 Platform?
            FS_LZX("22c.bin"), // White Glacier Stage 3 Elevator
            FS_LZX("22d.bin"), // White Glacier Stage 2 Ice?
            FS_LZX("22e.bin"), // White Glacier Stage 3 Exit?
            FS_LZX("22f.bin"), // White Glacier Stage 3 Platform?
            FS_LZX("230.bin"), // White Glacier Stage 2 Ice?
            FS_LZX("231.bin"), // White Glacier Stage 3 Room door
            FS_LZX("232.bin"), // White Glacier Stage 3 Platform?
            FS_LZX("233.bin"), // White Glacier Stage 3 Next Stage (Stage 4)
            FS_LZX("234.bin"), // White Glacier Stage 3 Ramp room
            FS_LZX("235.bin"), // White Glacier Stage 3 Elevator
            FS_LZX("236.bin"), // White Glacier Stage 2 Room
            FS_LZX("237.bin"), // -
            FS_LZX("238.bin"), // -
            FS_LZX("239.bin"), // -
            FS_LZX("23a.bin"), // -
            FS_LZX("23b.bin"), // -
            FS_LZX("23c.bin"), // -
            FS_LZX("23d.bin"), // -
            FS_LZX("23e.bin"), // -
            FS_LZX("23f.bin"), // -
            FS_LZX("240.bin"), // -
            FS_LZX("241.bin"), // -
            FS_LZX("242.bin"), // Green Garden Stage 1 Starting room
            FS_LZX("243.bin"), // Green Garden Stage 1 2nd Room
            FS_LZX("244.bin"), // Green Garden Stage 1 Hidden Room 1
            FS_LZX("245.bin"), // Green Garden Stage 1 Hidden Room 2
            FS_LZX("246.bin"), // Green Garden Stage 1 Hidden Room 3
            FS_LZX("247.bin"), // Green Garden Stage 3 Starting Room
            FS_LZX("248.bin"), // Green Garden Stage 3 2nd room
            FS_LZX("249.bin"), // Green Garden Stage 3 hidden room?
            FS_LZX("24a.bin"), // Green Garden Stage 3 Exit Room
            FS_LZX("24b.bin"), // Green Garden Stage 2 Room
            FS_LZX("24c.bin"), // Green Garden Stage 1 Starting Room collision
            FS_LZX("24d.bin"), // Green Garden Stage 1 2nd Room collision
            FS_LZX("24e.bin"), // Green Garden Stage 1 Hidden Room 1 collision
            FS_LZX("24f.bin"), // Green Garden Stage 1 Hidden Room 2 collision
            FS_LZX("250.bin"), // Green Garden Stage 1 Hidden Room 3 collision
            FS_LZX("251.bin"), // Green Garden Stage 3 Starting Room collision
            FS_LZX("252.bin"), // Green Garden Stage 3 2nd Room collision
            FS_LZX("253.bin"), // Green Garden Stage 3 hidden room collision
            FS_LZX("254.bin"), // Green Garden Stage 3 Exit Room collision
            FS_LZX("255.bin"), // Green Garden Stage 2 Room collision
            FS_LZX("256.bin"), // Multiplayer Map unused multiplayer map
            FS_LZX("257.bin"), // -
            FS_LZX("258.bin"), // Snowflake particle?
            FS_LZX("259.bin"), // White Glacier Stage 1 Snowboard Combatant
            FS_LZX("25a.bin"), // Bomb Icon? Logo?
            FS_LZX("25b.bin"), // ?
            FS_LZX("25c.bin"), // White Glacier Stage 1 Tree Snow
            FS_LZX("25d.bin"), // White Glacier Stage 3 Icicle
            FS_LZX("25e.bin"), // Bomb Icon? Logo?
            FS_LZX("25f.bin"), // White Glacier Stage 1 Snowboard Cabin
            FS_LZX("260.bin"), // White Glacier Stage 1 House Roof
            FS_LZX("261.bin"), // White Glacier Stage 1 Ski Lift Exit
            FS_LZX("262.bin"), // White Glacier Stage 1 Ski Lift Seat Exit
            FS_LZX("263.bin"), // Flat Triangle
            FS_LZX("264.bin"), // White Glacier Stage 1 Tree
            FS_LZX("265.bin"), // Sphere
            FS_LZX("266.bin"), // Bomb Icon? Logo?
            FS_LZX("267.bin"), // Bomb Icon? Logo?
            FS_LZX("268.bin"), // White Glacier Stage 4 Overworld
            FS_LZX("269.bin"), // White Glacier Stage 1 Avalanche?
            FS_LZX("26a.bin"), // White Glacier Stage 1 Avalanche warning sign
            FS_LZX("26b.bin"), // ?
            FS_LZX("26c.bin"), // Rectangle Cube
            FS_LZX("26d.bin"), // White Glacier Stage 1 Flowers
            FS_LZX("26e.bin"), // White Glacier Stage 1 Flowers
            FS_LZX("26f.bin"), // Flat Triangle
            FS_LZX("270.bin"), // Flat Triangle
            FS_LZX("271.bin"), // Flat Triangle
            FS_LZX("272.bin"), // Flat Triangle
            FS_LZX("273.bin"), // Flat Triangle
            FS_LZX("274.bin"), // Flat Triangle
            FS_LZX("275.bin"), // (TXT) Frozen sign
            FS_LZX("276.bin"), // (TXT) Avalanche warning sign
            FS_LZX("277.bin"), // (TXT) Sirius lies about his siblings
            FS_LZX("278.bin"), // (TXT) Sirius explains the ice slope
            FS_LZX("279.bin"), // 
            FS_LZX("27a.bin"), // 
            FS_LZX("27b.bin"), // 
            FS_LZX("27c.bin"), // White Glacier Stage 4 Floor Square
            FS_LZX("27d.bin"), // White Glacier Stage 4 Floor Triangle
            FS_LZX("27e.bin"), // White Glacier Stage 4 Room
            FS_LZX("27f.bin"), // White Glacier Stage 4 Boss
            FS_LZX("280.bin"), // 
            FS_LZX("281.bin"), // White Glacier Stage 4 Boss Jaw
            FS_LZX("282.bin"), // White Glacier Stage 4 Mini Spiders
            FS_LZX("283.bin"), // 
            FS_LZX("284.bin"), // Flat Triangle
            FS_LZX("285.bin"), // Green Garden Stage 4 Boss Wing?
            FS_LZX("286.bin"), // Green Garden Stage 4 Boss Wing?
            FS_LZX("287.bin"), // Green Garden Stage 4 Boss Wing?
            FS_LZX("288.bin"), // Green Garden Stage 4 Boss Wing?
            FS_LZX("289.bin"), // 
            FS_LZX("28a.bin"), // 
            FS_LZX("28b.bin"), // 
            FS_LZX("28c.bin"), // 
            FS_LZX("28d.bin"), // 
            FS_LZX("28e.bin"), // (TXT) Sirius discusses the goddess statue
            FS_LZX("28f.bin"), // (TXT) Sirius after waterway is repaired
            FS_LZX("290.bin"), // (TXT) Sirius discusses the Maskers
            FS_LZX("291.bin"), // (TXT) Sirius replacement bot
            FS_LZX("292.bin"), // Green Garden Stage 4 Room
            FS_LZX("293.bin"), // Green Garden Stage 4 Room Bridge
            FS_LZX("294.bin"), // Green Garden Stage 4 Room Bridge
            FS_LZX("295.bin"), // 
            FS_LZX("296.bin"), // Green Garden Stage 4 clouds
            FS_LZX("297.bin"), // Green Garden Stage 4 Boss Body
            FS_LZX("298.bin"), // Green Garden Stage 4 Boss wing
            FS_LZX("299.bin"), // Green Garden Stage 4 Boss wing
            FS_LZX("29a.bin"), // Blue texture?
            FS_LZX("29b.bin"), // Blue texture?
            FS_LZX("29c.bin"), // Green Garden Stage 4 Boss Head
            FS_LZX("29d.bin"), // Green Garden Stage 4 Boss tummy?
            FS_LZX("29e.bin"), // Green Garden Stage 4 Boss Tail 1?
            FS_LZX("29f.bin"), // Green Garden Stage 4 Boss Tail 2?
            FS_LZX("2a0.bin"), // Green Garden Stage 4 Boss Tail 3?
            FS_LZX("2a1.bin"), // Green Garden Stage 4 Boss Tail End
            FS_LZX("2a2.bin"), // 
            FS_LZX("2a3.bin"), // Flat Triangle
            FS_LZX("2a4.bin"), // Green Garden Stage 1 green exit orb
            FS_LZX("2a5.bin"), // Green Garden Stage 1,3 Gem
            FS_LZX("2a6.bin"), // Green Garden Stage 1,3 Gem
            FS_LZX("2a7.bin"), // Blue Resort Stage 1 Flowers Pot?
            FS_LZX("2a8.bin"), // Green Garden Stage 1,3 Dragon Head Door
            FS_LZX("2a9.bin"), // Green Garden Stage 1 Dragon door scales
            FS_LZX("2aa.bin"), // Green Garden Stage 1 Mesh Roof
            FS_LZX("2ab.bin"), // Green Garden Stage 1 Thin Column
            FS_LZX("2ac.bin"), // Green Garden Stage 3 Lift Platform
            FS_LZX("2ad.bin"), // Green Garden Stage 1 Blue Column
            FS_LZX("2ae.bin"), // Green Garden Stage 1 Collapsing Column?
            FS_LZX("2af.bin"), // 
            FS_LZX("2b0.bin"), // Green Garden Stage 1 Collapsing Bridge Square
            FS_LZX("2b1.bin"), // Green Garden Stage 1 Orb Mount?
            FS_LZX("2b2.bin"), // Green Garden Annoying Bird Stage 3
            FS_LZX("2b3.bin"), // Green Garden Stage 1 Waterfall Room 2
            FS_LZX("2b4.bin"), // Green Garden Stage 1 Waterfall Room 1
            FS_LZX("2b5.bin"), // Green Garden Stage 1 Hidden Room Water?
            FS_LZX("2b6.bin"), // Green Garden Stage 1 Hidden Room Water?
            FS_LZX("2b7.bin"), // Green Garden Stage 1 Waterfall Hidden Room
            FS_LZX("2b8.bin"), // Green Garden Stage 3 Water Plane Room 1?
            FS_LZX("2b9.bin"), // Green Garden Stage 3 Water Plane Room 2
            FS_LZX("2ba.bin"), // Green Garden Stage ? Water Plane
            FS_LZX("2bb.bin"), // Green Garden Stage 1 Collapsing Bridge
            FS_LZX("2bc.bin"), // Black Fortress Stage 2 Boss Room
            FS_LZX("2bd.bin"), // 
            FS_LZX("2be.bin"), // Black Fortress Stage 2 Boss Body
            FS_LZX("2bf.bin"), // Damaged metal?
            FS_LZX("2c0.bin"), // Damaged metal? (mirror)
            FS_LZX("2c1.bin"), // Black Fortress Stage 2 Boss Body Front Clip
            FS_LZX("2c2.bin"), // Black Fortress Stage 2 Boss Arms/Guns
            FS_LZX("2c3.bin"), // Black Fortress Stage 2 Boss Guns
            FS_LZX("2c4.bin"), // Black Fortress Stage 2 weapon?
            FS_LZX("2c5.bin"), // Black Fortress Stage 2 Boss Arms/Guns
            FS_LZX("2c6.bin"), // Black Fortress Stage 2 Boss Drone
            FS_LZX("2c7.bin"), // Black Fortress Stage 2 Boss Effect Field
            FS_LZX("2c8.bin"), // Black Fortress Stage 2 Boss Effect Field
            FS_LZX("2c9.bin"), // Flat Square
            FS_LZX("2ca.bin"), // White glowing circle?
            FS_LZX("2cb.bin"), // Black Fortress Stage 2 Boss Missile1
            FS_LZX("2cc.bin"), // Blue Pyramid Attack?
            FS_LZX("2cd.bin"), // Blue/white wing? Sprite?
            FS_LZX("2ce.bin"), // Mirror of 716
            FS_LZX("2cf.bin"), // Triangle Pillar
            FS_LZX("2d0.bin"), // Sprite Explosion/Flat Square?
            FS_LZX("2d1.bin"), // Yellow Pyramid Attack?
            FS_LZX("2d2.bin"), // Sprite Explosion/Flat Square?
            FS_LZX("2d3.bin"), // Sprite Blue Energy
            FS_LZX("2d4.bin"), // Explosion?
            FS_LZX("2d5.bin"), // Black Fortress Stage 2 Drone Explosion 1
            FS_LZX("2d6.bin"), // Black Fortress Stage 2 Drone Explosion 2
            FS_LZX("2d7.bin"), // Black Fortress Stage 2 Boss Hidden Room
            FS_LZX("2d8.bin"), // Black Fortress Stage 2 Boss Door?
            FS_LZX("2d9.bin"), // Rainbow Palace Stage 1 Starting Room
            FS_LZX("2da.bin"), // Rainbow Palace Stage 3 Outside Room
            FS_LZX("2db.bin"), // Rainbow Palace Stage 3 Starting Room
            FS_LZX("2dc.bin"), // Rainbow Palace Stage 3 Starting Room?
            FS_LZX("2dd.bin"), // Rainbow Palace Stage 4 Room
            FS_LZX("2de.bin"), // Rainbow Palace Stage 4 Grid Floor
            FS_LZX("2df.bin"), // 
            FS_LZX("2e0.bin"), // 
            FS_LZX("2e1.bin"), // 
            FS_LZX("2e2.bin"), // 
            FS_LZX("2e3.bin"), // 
            FS_LZX("2e4.bin"), // 
            FS_LZX("2e5.bin"), // Rainbow Palace sky
            FS_LZX("2e6.bin"), // Rainbow Palace platforms
            FS_LZX("2e7.bin"), // Rainbow Palace Stage 2 Room
            FS_LZX("2e8.bin"), // Blue planet and moon
            FS_LZX("2e9.bin"), // Rainbow Palace Stage 2 Boss Mask Projectile
            FS_LZX("2ea.bin"), // Rainbow Palace Stage 2 Boss Head
            FS_LZX("2eb.bin"), // Rainbow Palace Stage 2 Boss Tassles
            FS_LZX("2ec.bin"), // 
            FS_LZX("2ed.bin"), // Rainbow Palace Stage 2 Boss Torso
            FS_LZX("2ee.bin"), // Rainbow Palace Stage 2 Boss Shoulder Pads
            FS_LZX("2ef.bin"), // Rainbow Palace Stage 2 Boss Shoe 1
            FS_LZX("2f0.bin"), // Rainbow Palace Stage 2 Boss Mask Projectile
            FS_LZX("2f1.bin"), // Rainbow Palace Stage 2 Boss Attack Shadow?
            FS_LZX("2f2.bin"), // Rainbow Palace Stage 2 Boss Weaken Shadow
            FS_LZX("2f3.bin"), // Rainbow Palace Stage 2 Boss Cape 1
            FS_LZX("2f4.bin"), // Rainbow Palace Stage 2 Boss Cape 2
            FS_LZX("2f5.bin"), // Rainbow Palace Stage 2 Boss Cape 3
            FS_LZX("2f6.bin"), // Rainbow Palace Stage 2 Boss Cape 4
            FS_LZX("2f7.bin"), // 
            FS_LZX("2f8.bin"), // 
            FS_LZX("2f9.bin"), // Rainbow Palace Stage 2 Boss Card 1
            FS_LZX("2fa.bin"), // Rainbow Palace Stage 2 Boss Card 2
            FS_LZX("2fb.bin"), // Rainbow Palace Stage 2 Boss Card 3
            FS_LZX("2fc.bin"), // Rainbow Palace Stage 2 Boss Card 4
            FS_LZX("2fd.bin"), // Rainbow Palace Stage 2 Boss Card 5
            FS_LZX("2fe.bin"), // Rainbow Palace Stage 2 Boss Card 6
            FS_LZX("2ff.bin"), // Rainbow Palace Stage 2 Boss Card 7
            FS_LZX("300.bin"), // Rainbow Palace Stage 2 Boss Card 8
            FS_LZX("301.bin"), // Rainbow Palace Stage 2 Boss Hand
            FS_LZX("302.bin"), // Rainbow Palace Stage 2 Explosion
            FS_LZX("303.bin"), // Rainbow Palace Stage 2 Internal Explosion
            FS_LZX("304.bin"), // Rainbow Palace Stage 2 Flame Dragon Tail Sprite
            FS_LZX("305.bin"), // Rainbow Palace Stage 2 Flame Dragon Head Attack
            FS_LZX("306.bin"), // Rainbow Palace Stage 2 Star Attack
            FS_LZX("307.bin"), // Yellow Orb? Flat Triangle
            FS_LZX("308.bin"), // Rainbow Palace Stage 2 Boss Shoe 2
            FS_LZX("309.bin"), // Rainbow Palace Stage 2 Boss Fist Attack 1
            FS_LZX("30a.bin"), // Rainbow Palace Stage 2 Boss Fist Attack 2
            FS_LZX("30b.bin"), // Rainbow Palace Stage 2 Boss Fist Attack Shadow
            FS_LZX("30c.bin"), // Rainbow Palace Stage 2 Boss Scythe Attack Call
            FS_LZX("30d.bin"), // Flat Triangle
            FS_LZX("30e.bin"), // Flat Trapezium
            FS_LZX("30f.bin"), // Flat Trapezium
            FS_LZX("310.bin"), // Flat Trapezium
            FS_LZX("311.bin"), // Flat Trapezium
            FS_LZX("312.bin"), // 16t Anvil
            FS_LZX("313.bin"), // Flat Triangle Power up, Two Orbs and link
            FS_LZX("314.bin"), // Blade?
            FS_LZX("315.bin"), // Flat Triangle
            FS_LZX("316.bin"), // Rainbow Palace Stage 1 Purple Floating Block
            FS_LZX("317.bin"), // Rainbow Palace Stage 3 Starting Door
            FS_LZX("318.bin"), // Stainglass window used?
            FS_LZX("319.bin"), // Rainbow Palace Stage 3 Light?
            FS_LZX("31a.bin"), // RGBA 32 x 32 Light Texture?
            FS_LZX("31b.bin"), // Rainbow Palace Stage 3 Stainglass Window
            FS_LZX("31c.bin"), // Rainbow Palace Stage 1 exit Archway
            FS_LZX("31d.bin"), // Rainbow Palace Stage 1 Floor Block
            FS_LZX("31e.bin"), // Rainbow Palace Stage 1 Rainbow?
            FS_LZX("31f.bin"), // RGBA 32 x 32 Rainbow Texture?
            FS_LZX("320.bin"), // Artemis
            FS_LZX("321.bin"), // Orion
            FS_LZX("322.bin"), // Regulus
            FS_LZX("323.bin"), // Sirius no wings
            FS_LZX("324.bin"), // Altair
            FS_LZX("325.bin"), // Altair Final Form
            FS_LZX("326.bin"), // Altair Final Form
            FS_LZX("327.bin"), // Vega
            FS_LZX("328.bin"), // Sirius wings
            FS_LZX("329.bin"), // Blue Resort Cutscene Bird
            FS_LZX("32a.bin"), // Artemis Attack
            FS_LZX("32b.bin"), // Blue Attack
            FS_LZX("32c.bin"), // Burn effect?
            FS_LZX("32d.bin"), // 
            FS_LZX("32e.bin"), // 
            FS_LZX("32f.bin"), // Black Fortress Stage 4 Boss Final Form Knockback attack
            FS_LZX("330.bin"), // (TXT) Sirius rival encountered
            FS_LZX("331.bin"), // (TXT) Sirius rival defeated
            FS_LZX("332.bin"), // (TXT) Sirius rival bot encountered
            FS_LZX("333.bin"), // (TXT) Sirius rival bot defeated
            FS_LZX("334.bin"), // (TXT) Regulus defeated
            FS_LZX("335.bin"), // (TXT) Sirius kills Altair
            FS_LZX("336.bin"), // (TXT) Sirius betrayal
            FS_LZX("337.bin"), // (TXT) Sirius Youuuuu
            FS_LZX("338.bin"), // (TXT) Regulus to the rescue
            FS_LZX("339.bin"), // 
            FS_LZX("33a.bin"), // Cutscene Hill Viewpoint
            FS_LZX("33b.bin"), // Village BG from cliff
            FS_LZX("33c.bin"), // End Cutscene Critter?
            FS_LZX("33d.bin"), // End Cutscene Critter?
            FS_LZX("33e.bin"), // End Cutscene Bird
            FS_LZX("33f.bin"), // HUDSON logo
            FS_LZX("340.bin"), // Planet Bomber
            FS_LZX("341.bin"), // Flat Triangle
            FS_LZX("342.bin"), // Intro Cutscene Machine
            FS_LZX("343.bin"), // Intro Cut Scene Town
            FS_LZX("344.bin"), // Intro Cut Scene Clouds?
            FS_LZX("345.bin"), // Intro Cut Scene Windmill Fan
            FS_LZX("346.bin"), // Omni Cube
            FS_LZX("347.bin"), // Planet Bomber
            FS_LZX("348.bin"), // Planet Bomber
            FS_LZX("349.bin"), // Planet Bomber
            FS_LZX("34a.bin"), // Planet Bomber
            FS_LZX("34b.bin"), // (TXT) Artemis and Altair intro exchange
            FS_LZX("34c.bin"), // (TXT) Sirius intro anchor explanation
            FS_LZX("34d.bin"), // Space Pirates Base Shadow Intro Cutscene
            FS_LZX("34e.bin"), // HUD heart
            FS_LZX("34f.bin"), // Green Garden Stage 1 Totem Head
            FS_LZX("350.bin"), // Mantaray?
            FS_LZX("351.bin"), // Mantaray Shadow?
            FS_LZX("352.bin"), // Water around white edge and blue square?
            FS_LZX("353.bin"), // Bomberman 64 logo bomb
            FS_LZX("354.bin"), // Bomberman 64 logo "BAKU"
            FS_LZX("355.bin"), // Bomberman 64 logo "BOMBER"
            FS_LZX("356.bin"), // Bomberman 64 logo "MAN"
            FS_LZX("357.bin"), // 
            FS_LZX("358.bin"), // (TXT) Sirius tutorial basics
            FS_LZX("359.bin"), // (TXT) Sirius tutorial lift and throw
            FS_LZX("35a.bin"), // (TXT) Sirius tutorial Bomb Kick
            FS_LZX("35b.bin"), // (TXT) Sirius tutorial Pumped Bomb
            FS_LZX("35c.bin"), // (TXT) Sirius tutorial Bomb Jump
            FS_LZX("35d.bin"), // (TXT) Sirius tutorial power-ups
            FS_LZX("35e.bin"), // 
            FS_LZX("35f.bin"), // (TXT) Sirius bad ending speech
            FS_LZX("360.bin"), // (TXT) Regulus true ending speech
            FS_LZX("361.bin"), // (TXT) Sirius Altair's incompetence
            FS_LZX("362.bin"), // (TXT) Sirius tutorial Bomb Lift
            FS_LZX("363.bin"), // (TXT) Sirius dialogue about dust
            FS_LZX("364.bin"), // (TXT) Sirius tutorial lift and throw
            FS_LZX("365.bin"), // Intro Grid Floor? 16 x 16
            // FS_LZX("366.bin"), // Opening splash screen black
            // FS_LZX("367.bin"), // 64 (title screen) (0x28, 0x16D8)
            // FS_LZX("368.bin"), //
    }
};
