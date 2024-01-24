
#include <baku.h>

pack info = {
    .id = "NUS-NBVJ",
    .rom = 0x01000000,
    .eof = 0x0,
    .fs = {
        RAW(0x00000000, 0x00001000, "boot.bin"),
        RAW(0x00001000, 0x000FF000, "app.bin"),

        FAT(0x00100000, 0x1, "actor/"), // 0x00020000
            FS_RAW("info"),
            FS_LZY("main.bin"),

        FAT(0x00120000, 0x1, "item/"), // 0x00010000
            FS_RAW("info"),
            FS_LZY("main.bin"),

        FAT(0x00130000, 0x1, "coll/"), // 0x00010000
            FS_RAW("info"),
            FS_LZY("main.bin"),

        FAT(0x00140000, 0x1, "mobj/"), // 0x00020000
            FS_RAW("info"),
            FS_LZY("main.bin"),

        FAT(0x00160000, 0x7, "blast/"), // 0x00020000
            FS_RAW("info"),
            FS_LZY("flame.bin"),
            FS_LZY("ice.bin"),
            FS_LZY("wind.bin"),
            FS_LZY("ground.bin"),
            FS_LZY("elec.bin"),
            FS_LZY("light.bin"),
            FS_LZY("dark.bin"),

        FAT(0x00180000, 0x9, "enemy/"), // 0x00060000
            FS_RAW("info"),
            FS_LZY("world1.bin"),
            FS_LZY("world2.bin"),
            FS_LZY("world3.bin"),
            FS_LZY("world4.bin"),
            FS_LZY("world5.bin"),
            FS_LZY("world6.bin"),
            FS_LZY("world7.bin"),
            FS_LZY("world8.bin"),
            FS_LZY("battle.bin"),

        FAT(0x001E0000, 0x3, "boss/"), // 0x00040000
            FS_RAW("info"),
            FS_LZY("demon.bin"), // 魔神
            FS_LZY("devil.bin"), // 渾沌的魔神
            FS_LZY("angel.bin"), // 聖邪的天使

        FAT(0x00220000, 0x6, "menu/"), // 0x00020000
            FS_RAW("info"),
            FS_LZY("card.bin"), // 記憶卡刪除畫面
            FS_LZY("title.bin"), // 標題畫面
            FS_LZY("file.bin"), // 檔案選擇
            FS_LZY("battle.bin"), // 對戰選擇
            FS_LZY("custom.bin"), // 組合畫面
            FS_LZY("stage.bin"), // 選關畫面

        FAT(0x00240000, 0x2, "demo/"), // 0x00010000
            FS_RAW("info"),
            FS_LZY("story.bin"), // 一般動畫
            FS_LZY("guide.bin"), // 教學動畫

        FAT(0x00250000, 0x8, "stage/"), // 0x00030000
            FS_RAW("info"),
            FS_LZY("world1.bin"),
            FS_LZY("world2.bin"),
            FS_LZY("world3.bin"),
            FS_LZY("world4.bin"),
            FS_LZY("world5.bin"),
            FS_LZY("world6.bin"),
            FS_LZY("world7.bin"),
            FS_LZY("world8.bin"),

        RAW(0x00280000, 0x00010000, "symbol.bin"), // 0x00020000

        FAT(0x002A0000, 0xc3c, "assets/"), // 0x00D60000
            FS_RAW("000.bin"), // Music data. (Already loaded.)
            FS_RAW("001.bin"), // Sound effect data. (Already loaded.)
            FS_RAW("002.bin"), // Text data? (Already loaded.)
            FS_YAY("003.bin"), // [Early development bomb?] (Unused.)
            FS_YAY("004.bin"), // [Early development fire blast?] (Unused.)
            FS_YAY("005.bin"), // [Bluish 1 block?] (Unused.)
            FS_YAY("006.bin"), // [Greenish 2 block?] (Unused.)
            FS_YAY("007.bin"), // Shadow.
            FS_YAY("008.bin"), // [3 bubble?] (Unused.)
            FS_YAY("009.bin"), // [Slightly lower gear enemy (animated)?] (Unused.)
            FS_YAY("00a.bin"), // [Mechanical lift (with darker coloring)?] (Unused.)
            FS_YAY("00b.bin"), // [Early development Fire Up graphic?] (Unused.)
            FS_LZX("00c.bin"), // Test map two model's hitbox.
            FS_YAY("00d.bin"), // Test map two model.
            FS_LZX("00e.bin"), // Test map one model's hitbox. (Unused.)
            FS_YAY("00f.bin"), // Test map one model. (Unused.)
            FS_LZX("010.bin"), // Normal model's hitbox.
            FS_YAY("011.bin"), // Normal model.
            FS_LZX("012.bin"), // Park model's hitbox.
            FS_YAY("013.bin"), // Park model (animated).
            FS_LZX("014.bin"), // Tropical Island model's hitbox.
            FS_YAY("015.bin"), // Tropical Island model.
            FS_LZX("016.bin"), // Miniature City model's hitbox.
            FS_YAY("017.bin"), // Miniature City model.
            FS_LZX("018.bin"), // Underground Mine model's hitbox.
            FS_YAY("019.bin"), // Underground Mine model.
            FS_LZX("01a.bin"), // Desert Shrine model's hitbox.
            FS_YAY("01b.bin"), // Desert Shrine model (animated).
            FS_LZX("01c.bin"), // Altar model's hitbox.
            FS_YAY("01d.bin"), // Altar model.
            FS_LZX("01e.bin"), // Rope Bridge model's hitbox.
            FS_YAY("01f.bin"), // Rope Bridge model.
            FS_LZX("020.bin"), // Castle Garden model's hitbox.
            FS_YAY("021.bin"), // Castle Garden model (animated).
            FS_LZX("022.bin"), // Unused Park model's hitbox.
            FS_YAY("023.bin"), // Unused Park model.
            FS_LZX("024.bin"), // Cloud Castle model's hitbox.
            FS_YAY("025.bin"), // Cloud Castle model.
            FS_LZX("026.bin"), // River model's hitbox.
            FS_YAY("027.bin"), // River model (animated).
            FS_LZX("028.bin"), // Royal Palace model's hitbox.
            FS_YAY("029.bin"), // Royal Palace model.
            FS_LZX("02a.bin"), // Casino model's hitbox.
            FS_YAY("02b.bin"), // Casino model.
            FS_LZX("02c.bin"), // Underground Maze model's hitbox.
            FS_YAY("02d.bin"), // Underground Maze model.
            FS_LZX("02e.bin"), // Underground River model's hitbox.
            FS_YAY("02f.bin"), // Underground River model (animated).
            FS_LZX("030.bin"), // Ivory Halls model's hitbox.
            FS_YAY("031.bin"), // Ivory Halls model.
            FS_LZX("032.bin"), // Crystal Palace model's hitbox.
            FS_YAY("033.bin"), // Crystal Palace model (animated).
            FS_LZX("034.bin"), // Hanging Gardens model's hitbox.
            FS_YAY("035.bin"), // Hanging Gardens model.
            FS_LZX("036.bin"), // Plains model's hitbox.
            FS_YAY("037.bin"), // Plains model.
            FS_LZX("038.bin"), // Floating Halls model's hitbox.
            FS_YAY("039.bin"), // Floating Halls model.
            FS_LZX("03a.bin"), // Unused Park model's hitbox.
            FS_YAY("03b.bin"), // Unused Park model.
            FS_LZX("03c.bin"), // Ranch model's hitbox.
            FS_YAY("03d.bin"), // Ranch model.
            FS_LZX("03e.bin"), // Unused Park model's hitbox.
            FS_YAY("03f.bin"), // Unused Park model.
            FS_LZX("040.bin"), // Unused flooring model's hitbox?
            FS_YAY("041.bin"), // Unused flooring model.
            FS_LZX("042.bin"), // Simple hitbox A.
            FS_YAY("043.bin"), // [A tiny block?]
            FS_LZX("044.bin"), // Simple hitbox B.
            FS_YAY("045.bin"), // [A tiny block?]
            FS_LZX("046.bin"), // Simple hitbox C.
            FS_YAY("047.bin"), // [A tiny block?]
            FS_LZX("048.bin"), // Entry Point model's hitbox.
            FS_YAY("049.bin"), // Neverland, Entry Point(?) model.
            FS_LZX("04a.bin"), // Bonus Room model's hitbox.
            FS_YAY("04b.bin"), // Neverland, Bonus Room(?) model.
            FS_LZX("04c.bin"), // Through the Line of Fire model's hitbox.
            FS_YAY("04d.bin"), // Neverland, Through the Line of Fire(?) model.
            FS_LZX("04e.bin"), // Intersection model's hitbox.
            FS_YAY("04f.bin"), // Neverland, Intersection(?) model.
            FS_LZX("050.bin"), // Conveyor Belts model's hitbox.
            FS_YAY("051.bin"), // Neverland, Conveyor Belts(?) model (animated).
            FS_LZX("052.bin"), // Potholes model's hitbox.
            FS_YAY("053.bin"), // Neverland, Potholes(?) model.
            FS_LZX("054.bin"), // Carrier Works model's hitbox.
            FS_YAY("055.bin"), // Neverland, Carrier Works(?) model.
            FS_LZX("056.bin"), // Switch Room model's hitbox.
            FS_YAY("057.bin"), // Neverland, Switch Room(?) model.
            FS_LZX("058.bin"), // Bridge Room model's hitbox.
            FS_YAY("059.bin"), // Neverland, Bridge Room(?) model (animated).
            FS_LZX("05a.bin"), // Cage Room model's hitbox.
            FS_YAY("05b.bin"), // Neverland, Cage Room(?) model.
            FS_LZX("05c.bin"), // Safe Point model's hitbox.
            FS_YAY("05d.bin"), // Neverland, Safe Point model.
            FS_LZX("05e.bin"), // Underground Corridor model's hitbox.
            FS_YAY("05f.bin"), // Neverland, Underground Corridor model.
            FS_LZX("060.bin"), // Warehousing model's hitbox.
            FS_YAY("061.bin"), // Neverland, Warehousing model.
            FS_LZX("062.bin"), // Furnace model's hitbox.
            FS_YAY("063.bin"), // Neverland, Furnace(?) model.
            FS_LZX("064.bin"), // First Passageway model's hitbox.
            FS_YAY("065.bin"), // Neverland, First Passageway(?) model (animated).
            FS_LZX("066.bin"), // Second Passageway model's hitbox.
            FS_YAY("067.bin"), // Neverland, Second Passageway(?) model (animated).
            FS_LZX("068.bin"), // Landing Point model's hitbox.
            FS_YAY("069.bin"), // Neverland, Landing Point model (animated).
            FS_LZX("06a.bin"), // Third Passageway model's hitbox.
            FS_YAY("06b.bin"), // Neverland, Third Passageway(?) model (animated).
            FS_LZX("06c.bin"), // Gravity Generator Room model's hitbox.
            FS_YAY("06d.bin"), // Neverland, Gravity Generator Room model.
            FS_LZX("06e.bin"), // Secret Room model's hitbox.
            FS_YAY("06f.bin"), // Neverland, Secret Room model.
            FS_LZX("070.bin"), // Around the Moat model's hitbox.
            FS_YAY("071.bin"), // Aquanet, Around the Moat(?) model (animated).
            FS_LZX("072.bin"), // First Room model's hitbox.
            FS_YAY("073.bin"), // Aquanet, First Room(?) model.
            FS_LZX("074.bin"), // Second Room model's hitbox.
            FS_YAY("075.bin"), // Aquanet, Second Room(?) model.
            FS_LZX("076.bin"), // Third Room model's hitbox.
            FS_YAY("077.bin"), // Aquanet, Third Room(?) model.
            FS_LZX("078.bin"), // Swimming Pool Spa model's hitbox.
            FS_YAY("079.bin"), // Aquanet, Swimming Pool Spa(?) model.
            FS_LZX("07a.bin"), // Behind the Moat model's hitbox.
            FS_YAY("07b.bin"), // Aquanet, Behind the Moat(?) model (animated).
            FS_LZX("07c.bin"), // Beyond the Moat model's hitbox.
            FS_YAY("07d.bin"), // Aquanet, Beyond the Moat(?) model (animated).
            FS_LZX("07e.bin"), // Elevator Hub model's hitbox.
            FS_YAY("07f.bin"), // Aquanet, Elevator Hub(?) model.
            FS_LZX("080.bin"), // Hidden Balcony model's hitbox.
            FS_YAY("081.bin"), // Aquanet, Hidden Balcony(?) model.
            FS_LZX("082.bin"), // Water Channels model's hitbox.
            FS_YAY("083.bin"), // Aquanet, Water Channels(?) model.
            FS_LZX("084.bin"), // Fountain Room model's hitbox.
            FS_YAY("085.bin"), // Aquanet, Fountain Room(?) model.
            FS_LZX("086.bin"), // Secret Room model's hitbox.
            FS_YAY("087.bin"), // Aquanet, Secret Room model.
            FS_LZX("088.bin"), // Elevator Stopping Point model's hitbox.
            FS_YAY("089.bin"), // Aquanet, Elevator Stopping Point model.
            FS_LZX("08a.bin"), // Behemos' Lair model's hitbox.
            FS_YAY("08b.bin"), // Aquanet, Behemos' Lair model.
            FS_LZX("08c.bin"), // To the Tower model's hitbox.
            FS_YAY("08d.bin"), // Aquanet, To the Tower(?) model (animated).
            FS_LZX("08e.bin"), // Tower 1F model's hitbox.
            FS_YAY("08f.bin"), // Aquanet, Tower 1F model (animated).
            FS_LZX("090.bin"), // Tower 2F model's hitbox.
            FS_YAY("091.bin"), // Aquanet, Tower 2F model (animated).
            FS_LZX("092.bin"), // Tower 3F model's hitbox.
            FS_YAY("093.bin"), // Aquanet, Tower 3F model.
            FS_LZX("094.bin"), // Gravity Generator Room model's hitbox.
            FS_YAY("095.bin"), // Aquanet, Gravity Generator Room model.
            FS_LZX("096.bin"), // Prison model's hitbox.
            FS_YAY("097.bin"), // Alcatraz, Prison(?) model.
            FS_LZX("098.bin"), // Sewer Entrance model's hitbox.
            FS_YAY("099.bin"), // Alcatraz, Sewer Entrance model (animated).
            FS_LZX("09a.bin"), // Twisted Sewers model's hitbox.
            FS_YAY("09b.bin"), // Alcatraz, Twisted Sewers model (animated).
            FS_LZX("09c.bin"), // Security Room A model's hitbox.
            FS_YAY("09d.bin"), // Alcatraz, Security Room A(?) model.
            FS_LZX("09e.bin"), // Security Room B model's hitbox.
            FS_YAY("09f.bin"), // Alcatraz, Security Room B(?) model.
            FS_LZX("0a0.bin"), // Sewage Disposal model's hitbox.
            FS_YAY("0a1.bin"), // Alcatraz, Sewage Disposal(?) model.
            FS_LZX("0a2.bin"), // Through the Pipe model's hitbox.
            FS_YAY("0a3.bin"), // Alcatraz, Through the Pipe(?) model.
            FS_LZX("0a4.bin"), // Prison Bridge model's hitbox.
            FS_YAY("0a5.bin"), // Alcatraz, Prison Bridge(?) model.
            FS_LZX("0a6.bin"), // Pipe Room A model's hitbox.
            FS_YAY("0a7.bin"), // Alcatraz, Pipe Room A model.
            FS_LZX("0a8.bin"), // Pipe Room B model's hitbox.
            FS_YAY("0a9.bin"), // Alcatraz, Pipe Room B model.
            FS_LZX("0aa.bin"), // Final Defense Unit model's hitbox.
            FS_YAY("0ab.bin"), // Alcatraz, Final Defense Unit(?) model.
            FS_LZX("0ac.bin"), // Gravity Generator Room model's hitbox.
            FS_YAY("0ad.bin"), // Alcatraz, Gravity Generator Room model.
            FS_LZX("0ae.bin"), // Secret Room model's hitbox.
            FS_YAY("0af.bin"), // Alcatraz, Secret Room model.
            FS_LZX("0b0.bin"), // Cell Room model's hitbox.
            FS_YAY("0b1.bin"), // Alcatraz, Cell Room model.
            FS_LZX("0b2.bin"), // BHB Army Ship Storeroom model's hitbox.
            FS_YAY("0b3.bin"), // BHB Army Ship Storeroom model.
            FS_LZX("0b4.bin"), // First Intersection model's hitbox.
            FS_YAY("0b5.bin"), // Horizon, First Intersection(?) model.
            FS_LZX("0b6.bin"), // Eastern Tower model's hitbox.
            FS_YAY("0b7.bin"), // Horizon, Eastern Tower(?) model.
            FS_LZX("0b8.bin"), // Push-Block Trial model's hitbox.
            FS_YAY("0b9.bin"), // Horizon, Push-Block Trial(?) model.
            FS_LZX("0ba.bin"), // Leading Road model's hitbox.
            FS_YAY("0bb.bin"), // Horizon, Leading Road(?) model.
            FS_LZX("0bc.bin"), // First Trial model's hitbox.
            FS_YAY("0bd.bin"), // Horizon, First Trial(?) model.
            FS_LZX("0be.bin"), // Second Trial model's hitbox.
            FS_YAY("0bf.bin"), // Horizon, Second Trial(?) model.
            FS_LZX("0c0.bin"), // Resting Point model's hitbox.
            FS_YAY("0c1.bin"), // Horizon, Resting Point model.
            FS_LZX("0c2.bin"), // Floating Temple model's hitbox.
            FS_YAY("0c3.bin"), // Horizon, Floating Temple(?) model.
            FS_LZX("0c4.bin"), // Twin Bridges model's hitbox.
            FS_YAY("0c5.bin"), // Horizon, Twin Bridges(?) model.
            FS_LZX("0c6.bin"), // Final Deposit model's hitbox.
            FS_YAY("0c7.bin"), // Horizon, Final Deposit(?) model.
            FS_LZX("0c8.bin"), // Last Route model's hitbox.
            FS_YAY("0c9.bin"), // Horizon, Last Route(?) model.
            FS_LZX("0ca.bin"), // Fourth Trial model's hitbox.
            FS_YAY("0cb.bin"), // Horizon, Fourth Trial(?) model.
            FS_LZX("0cc.bin"), // Secret Room model's hitbox.
            FS_YAY("0cd.bin"), // Horizon, Secret Room model.
            FS_LZX("0ce.bin"), // Third Trial model's hitbox.
            FS_YAY("0cf.bin"), // Horizon, Third Trial(?) model.
            FS_LZX("0d0.bin"), // Last Trial model's hitbox.
            FS_YAY("0d1.bin"), // Horizon, Last Trial(?) model.
            FS_LZX("0d2.bin"), // Gravity Generator Room model's hitbox.
            FS_YAY("0d3.bin"), // Horizon, Gravity Generator Room model.
            FS_LZX("0d4.bin"), // Wide torch's 2D animation.
            FS_LZX("0d5.bin"), // Parking Lot model's hitbox.
            FS_YAY("0d6.bin"), // Starlight, Parking Lot model (animated).
            FS_LZX("0d7.bin"), // Closed Road model's hitbox.
            FS_YAY("0d8.bin"), // Starlight, Closed Road(?) model.
            FS_LZX("0d9.bin"), // Fountain Square model's hitbox.
            FS_YAY("0da.bin"), // Starlight, Fountain Square(?) model (animated).
            FS_LZX("0db.bin"), // Small Inlet model's hitbox.
            FS_YAY("0dc.bin"), // Starlight, Small Inlet(?) model (animated).
            FS_LZX("0dd.bin"), // Alleyway model's hitbox.
            FS_YAY("0de.bin"), // Starlight, Alleyway(?) model.
            FS_LZX("0df.bin"), // Casino Entrance model's hitbox.
            FS_YAY("0e0.bin"), // Starlight, Casino Entrance model (animated).
            FS_LZX("0e1.bin"), // Casino Lobby model's hitbox.
            FS_YAY("0e2.bin"), // Starlight, Casino Lobby(?) model (animated).
            FS_LZX("0e3.bin"), // Betting Room model's hitbox.
            FS_YAY("0e4.bin"), // Starlight, Betting Room(?) model (animated).
            FS_LZX("0e5.bin"), // Slots Room model's hitbox.
            FS_YAY("0e6.bin"), // Starlight, Slots Room model.
            FS_LZX("0e7.bin"), // Waiting Room model's hitbox.
            FS_YAY("0e8.bin"), // Starlight, Waiting Room(?) model.
            FS_LZX("0e9.bin"), // Stage Room model's hitbox.
            FS_YAY("0ea.bin"), // Starlight, Stage Room model.
            FS_LZX("0eb.bin"), // Lookout Point model's hitbox.
            FS_YAY("0ec.bin"), // Starlight, Lookout Point(?) model.
            FS_LZX("0ed.bin"), // Wheel of Fortune model's hitbox.
            FS_YAY("0ee.bin"), // Starlight, Wheel of Fortune model.
            FS_LZX("0ef.bin"), // Gravity Generator Room model's hitbox.
            FS_YAY("0f0.bin"), // Starlight, Gravity Generator Room model.
            FS_LZX("0f1.bin"), // Secret Room model's hitbox.
            FS_YAY("0f2.bin"), // Starlight, Secret Room model.
            FS_LZX("0f3.bin"), // Casino-stripes display's animation.
            FS_LZX("0f4.bin"), // Play Casino display lit. (Unused.)
            FS_LZX("0f5.bin"), // Flower-squares display's animation.
            FS_LZX("0f6.bin"), // Diagonal dots display's animation.
            FS_LZX("0f7.bin"), // Casino welcome sign display's animation. (Normally unused.)
            FS_LZX("0f8.bin"), // Dotted-sevens display's animation.
            FS_LZX("0f9.bin"), // Slot tile's animation.
            FS_LZX("0fa.bin"), // Casino-stripes display lit. (Unused.)
            FS_LZX("0fb.bin"), // Stage light lit. (Normally unused.)
            FS_LZX("0fc.bin"), // Entrance model's hitbox.
            FS_YAY("0fd.bin"), // Epikyur, Entrance model.
            FS_LZX("0fe.bin"), // Center Fountain model's hitbox.
            FS_YAY("0ff.bin"), // Epikyur, Center Fountain model (animated).
            FS_LZX("100.bin"), // Tattered Bridge model's hitbox.
            FS_YAY("101.bin"), // Epikyur, Tattered Bridge(?) model (animated).
            FS_LZX("102.bin"), // Misaligned Bridge model's hitbox.
            FS_YAY("103.bin"), // Epikyur, Misaligned Bridge model (animated).
            FS_LZX("104.bin"), // Yard model's hitbox.
            FS_YAY("105.bin"), // Epikyur, Yard model (animated).
            FS_LZX("106.bin"), // Lobby model's hitbox.
            FS_YAY("107.bin"), // Epikyur, Lobby model.
            FS_LZX("108.bin"), // Spike Traps model's hitbox.
            FS_YAY("109.bin"), // Epikyur, Spike Traps model.
            FS_LZX("10a.bin"), // Mirror Room model's hitbox.
            FS_YAY("10b.bin"), // Epikyur, Mirror Room model.
            FS_LZX("10c.bin"), // Spike Pit model's hitbox.
            FS_YAY("10d.bin"), // Epikyur, Spike Pit model.
            FS_LZX("10e.bin"), // Storeroom model's hitbox.
            FS_YAY("10f.bin"), // Epikyur, Storeroom(?) model.
            FS_LZX("110.bin"), // Prehistoric Puzzle model's hitbox.
            FS_YAY("111.bin"), // Epikyur, Prehistoric Puzzle(?) model.
            FS_LZX("112.bin"), // Military Puzzle model's hitbox.
            FS_YAY("113.bin"), // Epikyur, Military Puzzle(?) model.
            FS_LZX("114.bin"), // Showcase Room model's hitbox.
            FS_YAY("115.bin"), // Epikyur, Showcase Room model.
            FS_LZX("116.bin"), // Castle of Time (First Room) model's hitbox.
            FS_YAY("117.bin"), // Epikyur, Castle of Time (First Room) model.
            FS_LZX("118.bin"), // Castle of Time (Second Room) model's hitbox.
            FS_YAY("119.bin"), // Epikyur, Castle of Time (Second Room) model.
            FS_LZX("11a.bin"), // Coaster Body 1 model's hitbox.
            FS_YAY("11b.bin"), // Epikyur, Coaster Body 1 model (animated).
            FS_LZX("11c.bin"), // Coaster Start model's hitbox.
            FS_YAY("11d.bin"), // Epikyur, Coaster Start model.
            FS_LZX("11e.bin"), // Coaster Body 2 model's hitbox.
            FS_YAY("11f.bin"), // Epikyur, Coaster Body 2 model (animated).
            FS_LZX("120.bin"), // Coaster Finish model's hitbox.
            FS_YAY("121.bin"), // Epikyur, Coaster Finish model.
            FS_LZX("122.bin"), // Gravity Generator Room model's hitbox.
            FS_YAY("123.bin"), // Epikyur, Gravity Generator Room model (animated).
            FS_LZX("124.bin"), // Secret Room model's hitbox.
            FS_YAY("125.bin"), // Epikyur, Secret Room model.
            FS_LZX("126.bin"), // Starting Point model's hitbox.
            FS_YAY("127.bin"), // Thantos, Starting Point(?) model.
            FS_LZX("128.bin"), // Streets model's hitbox.
            FS_YAY("129.bin"), // Thantos, Streets(?) model.
            FS_LZX("12a.bin"), // Up the Ladder model's hitbox.
            FS_YAY("12b.bin"), // Thantos, Up the Ladder(?) model.
            FS_LZX("12c.bin"), // Wrecked Lot model's hitbox.
            FS_YAY("12d.bin"), // Thantos, Wrecked Lot model.
            FS_LZX("12e.bin"), // Battery Ambush model's hitbox.
            FS_YAY("12f.bin"), // Thantos, Battery Ambush(?) model.
            FS_LZX("130.bin"), // Battle for the Battery model's hitbox.
            FS_YAY("131.bin"), // Thantos, Battle for the Battery(?) model (animated).
            FS_LZX("132.bin"), // Compactor model's hitbox.
            FS_YAY("133.bin"), // Thantos, Compactor(?) model.
            FS_LZX("134.bin"), // Subway Entrance model's hitbox.
            FS_YAY("135.bin"), // Thantos, Subway Entrance model.
            FS_LZX("136.bin"), // Aboard the Subway model's hitbox.
            FS_YAY("137.bin"), // Thantos, Aboard the Subway model.
            FS_LZX("138.bin"), // Subway Destination model's hitbox.
            FS_YAY("139.bin"), // Thantos, Subway Destination(?) model.
            FS_LZX("13a.bin"), // Supposed Dead End model's hitbox.
            FS_YAY("13b.bin"), // Thantos, Supposed Dead End(?) model.
            FS_LZX("13c.bin"), // The Crevice model's hitbox.
            FS_YAY("13d.bin"), // Thantos, the Crevice(?) model.
            FS_LZX("13e.bin"), // Voltage Storage Unit model's hitbox.
            FS_YAY("13f.bin"), // Thantos, Voltage Storage Unit(?) model.
            FS_LZX("140.bin"), // Secret Room model's hitbox.
            FS_YAY("141.bin"), // Thantos, Secret Room model.
            FS_LZX("142.bin"), // Hangout model's hitbox.
            FS_YAY("143.bin"), // Thantos, Hangout(?) model.
            FS_LZX("144.bin"), // Back Alley model's hitbox.
            FS_YAY("145.bin"), // Thantos, Back Alley(?) model.
            FS_LZX("146.bin"), // Hidden Territory model's hitbox.
            FS_YAY("147.bin"), // Thantos, Hidden Territory(?) model.
            FS_LZX("148.bin"), // Gravity Generator Room model's hitbox.
            FS_YAY("149.bin"), // Thantos, Gravity Generator Room model.
            FS_LZX("14a.bin"), // Top of the Tower model's hitbox.
            FS_YAY("14b.bin"), // Thantos, Top of the Tower(?) model.
            FS_LZX("14c.bin"), // Runway model's hitbox.
            FS_YAY("14d.bin"), // Warship Noah, Runway model (animated).
            FS_LZX("14e.bin"), // Sliding Floors (West) model's hitbox.
            FS_YAY("14f.bin"), // Warship Noah, Sliding Floors (West) model (animated).
            FS_LZX("150.bin"), // Sliding Floors (East) model's hitbox.
            FS_YAY("151.bin"), // Warship Noah, Sliding Floors (East) model (animated).
            FS_LZX("152.bin"), // Security Barrier Control Room model's hitbox.
            FS_YAY("153.bin"), // Warship Noah, Security Barrier Control Room(?) model.
            FS_LZX("154.bin"), // Card Key Room model's hitbox.
            FS_YAY("155.bin"), // Warship Noah, Card Key Room model (animated).
            FS_LZX("156.bin"), // Storage Area model's hitbox.
            FS_YAY("157.bin"), // Warship Noah, Storage Area(?) model.
            FS_LZX("158.bin"), // Bridge Lift model's hitbox.
            FS_YAY("159.bin"), // Warship Noah, Bridge Lift(?) model.
            FS_LZX("15a.bin"), // Western Defensive Unit model's hitbox.
            FS_YAY("15b.bin"), // Warship Noah, Western Defensive Unit(?) model (animated).
            FS_LZX("15c.bin"), // Engine Room model's hitbox.
            FS_YAY("15d.bin"), // Warship Noah, Engine Room model (animated).
            FS_LZX("15e.bin"), // Eastern Defensive Unit model's hitbox.
            FS_YAY("15f.bin"), // Warship Noah, Eastern Defensive Unit(?) model (animated).
            FS_LZX("160.bin"), // Unfinished room's hitbox.
            FS_YAY("161.bin"), // Unfinished room. (Unused.)
            FS_LZX("162.bin"), // Engine Defense Mechanism Control Room model's hitbox.
            FS_YAY("163.bin"), // Warship Noah, Engine Defense Mechanism Control Room(?) model (animated).
            FS_LZX("164.bin"), // Generator Room model's hitbox.
            FS_YAY("165.bin"), // Warship Noah, Generator Room(?) model (animated).
            FS_LZX("166.bin"), // Main Reactor model's hitbox.
            FS_YAY("167.bin"), // Warship Noah, Main Reactor model.
            FS_LZX("168.bin"), // Power Shaft Room model's hitbox.
            FS_YAY("169.bin"), // Warship Noah, Power Shaft Room model.
            FS_LZX("16a.bin"), // Below Headquarters model's hitbox.
            FS_YAY("16b.bin"), // Warship Noah, Below Headquarters(?) model (animated).
            FS_LZX("16c.bin"), // Central Command Room model's hitbox.
            FS_YAY("16d.bin"), // Warship Noah, Central Command Room model (animated).
            FS_LZX("16e.bin"), // The Top model's hitbox.
            FS_YAY("16f.bin"), // Warship Noah, the Top model (animated).
            FS_LZX("170.bin"), // Secret Room model's hitbox.
            FS_YAY("171.bin"), // Warship Noah, Secret Room model. (Normally unused.)
            FS_LZX("172.bin"), // Tutorial Area model's hitbox.
            FS_YAY("173.bin"), // Tutorial Area model.
            FS_LZX("174.bin"), // The Heart model's hitbox.
            FS_YAY("175.bin"), // Warship Noah, the Heart model.
            FS_LZX("176.bin"), // Unused Bowl Room A model's hitbox?
            FS_YAY("177.bin"), // Warship Noah, Unused Bowl Room A model.
            FS_LZX("178.bin"), // Unused Bowl Room B model's hitbox?
            FS_YAY("179.bin"), // Warship Noah, Unused Bowl Room B model.
            FS_LZX("17a.bin"), // Unused Bowl Room C model's hitbox?
            FS_YAY("17b.bin"), // Warship Noah, Unused Bowl Room C model.
            FS_LZX("17c.bin"), // Wide torch flame 2D effect placeholder? (Unused.)
            FS_LZX("17d.bin"), // Wide torch flame 2D effect placeholder? (Unused.)
            FS_YAY("17e.bin"), // Bomberman character.
            FS_YAY("17f.bin"), // Bomberman placeholder animation? (Unused.)
            FS_YAY("180.bin"), // Standing.
            FS_YAY("181.bin"), // Running.
            FS_YAY("182.bin"), // Picking up from the ground.
            FS_YAY("183.bin"), // Throwing.
            FS_YAY("184.bin"), // Running, carrying.
            FS_YAY("185.bin"), // Bomberman placeholder animation? (Unused.)
            FS_YAY("186.bin"), // Kicking.
            FS_YAY("187.bin"), // Deflected. (Normally unused.)
            FS_YAY("188.bin"), // Knocked out, head spinning around. 
            FS_YAY("189.bin"), // Tapping right foot.
            FS_YAY("18a.bin"), // Bomberman placeholder animation? (Unused.)
            FS_YAY("18b.bin"), // Bomberman placeholder animation? (Unused.)
            FS_YAY("18c.bin"), // Climbing.
            FS_YAY("18d.bin"), // Climbing up.
            FS_YAY("18e.bin"), // Stomping the ground.
            FS_YAY("18f.bin"), // Bomberman placeholder animation? (Unused.)
            FS_YAY("190.bin"), // Taking a blow.
            FS_YAY("191.bin"), // Arms and legs spread out.
            FS_YAY("192.bin"), // Bomberman placeholder animation? (Unused.)
            FS_YAY("193.bin"), // Kneeling forward.
            FS_YAY("194.bin"), // Jumping for joy.
            FS_YAY("195.bin"), // Shrugging.
            FS_YAY("196.bin"), // Tapping right foot impatiently.
            FS_YAY("197.bin"), // Standing in a trance.
            FS_YAY("198.bin"), // Knocked down.
            FS_YAY("199.bin"), // Walking, head pulled back a bit.
            FS_YAY("19a.bin"), // Jumps twice, spinning with enthusiasm, and raises left arm.
            FS_YAY("19b.bin"), // Nods head up/down.
            FS_YAY("19c.bin"), // Head and arms shake violently.
            FS_YAY("19d.bin"), // Stumbles backwards.
            FS_YAY("19e.bin"), // Leaning forward.
            FS_YAY("19f.bin"), // Ducks for cover.
            FS_YAY("1a0.bin"), // Lifts left arm, staring at something.
            FS_YAY("1a1.bin"), // Rubbing right cheek.
            FS_YAY("1a2.bin"), // Jumps up from the ground and shakes head.
            FS_YAY("1a3.bin"), // Jumps up and raises right arm.
            FS_YAY("1a4.bin"), // Takes a quick bow.
            FS_YAY("1a5.bin"), // Turns head from left to right, looking around.
            FS_YAY("1a6.bin"), // Walking.
            FS_YAY("1a7.bin"), // Holding with two hands, walking.
            FS_YAY("1a8.bin"), // Legs spread out, holding with two hands.
            FS_YAY("1a9.bin"), // Stomping the ground, holding with two hands.
            FS_YAY("1aa.bin"), // Kicking, holding with two hands.
            FS_YAY("1ab.bin"), // Pushing with both hands.
            FS_YAY("1ac.bin"), // Putting down.
            FS_YAY("1ad.bin"), // Arms out, trying to talk
            FS_YAY("1ae.bin"), // Walking, arms held low. (Unused.)
            FS_YAY("1af.bin"), // Running, arms held low. (Unused.)
            FS_YAY("1b0.bin"), // Drops down on back.
            FS_YAY("1b1.bin"), // Flips backwards, flops facedown.
            FS_YAY("1b2.bin"), // Arms and legs flail.
            FS_YAY("1b3.bin"), // [A tiny block?]
            FS_YAY("1b4.bin"), // [A tiny block?]
            FS_YAY("1b5.bin"), // [A tiny block?]
            FS_YAY("1b6.bin"), // [A tiny block?]
            FS_YAY("1b7.bin"), // [A tiny block?]
            FS_YAY("1b8.bin"), // [A tiny block?]
            FS_YAY("1b9.bin"), // [A tiny block?]
            FS_YAY("1ba.bin"), // [A tiny block?]
            FS_YAY("1bb.bin"), // [A tiny block?]
            FS_YAY("1bc.bin"), // [A tiny block?]
            FS_YAY("1bd.bin"), // [A tiny block?]
            FS_YAY("1be.bin"), // [A tiny block?]
            FS_YAY("1bf.bin"), // [A tiny block?]
            FS_YAY("1c0.bin"), // [A tiny block?]
            FS_YAY("1c1.bin"), // [A tiny block?]
            FS_YAY("1c2.bin"), // [A tiny block?]
            FS_YAY("1c3.bin"), // [A tiny block?]
            FS_YAY("1c4.bin"), // [A tiny block?]
            FS_YAY("1c5.bin"), // [A tiny block?]
            FS_YAY("1c6.bin"), // [A tiny block?]
            FS_YAY("1c7.bin"), // [A tiny block?]
            FS_YAY("1c8.bin"), // [A tiny block?]
            FS_YAY("1c9.bin"), // [A tiny block?]
            FS_YAY("1ca.bin"), // [A tiny block?]
            FS_LZX("1cb.bin"), // Soul Eater's red wings.
            FS_LZX("1cc.bin"), // Soul Eater's red ears & feet.
            FS_LZX("1cd.bin"), // Soul Eater's red body.
            FS_LZX("1ce.bin"), // Gray square lift's hitbox.
            FS_LZX("1cf.bin"), // Pylon's flickering texture.
            FS_LZX("1d0.bin"), // Red carpet staircase's hitbox.
            FS_LZX("1d1.bin"), // Stone platform's hitbox.
            FS_YAY("1d2.bin"), // Freeze ring.
            FS_YAY("1d3.bin"), // Frozen ground.
            FS_YAY("1d4.bin"), // Freeze cloud.
            FS_YAY("1d5.bin"), // Icy blow.
            FS_YAY("1d6.bin"), // Large ice crystal.
            FS_YAY("1d7.bin"), // Large ice crystal circle.
            FS_YAY("1d8.bin"), // Lava puddle (needs to be animated).
            FS_YAY("1d9.bin"), // Fiery blow.
            FS_YAY("1da.bin"), // Fire bullet rings(?).
            FS_YAY("1db.bin"), // Fire pillar (needs to be animated).
            FS_LZX("1dc.bin"), // Fire pillar's 2D animation.
            FS_YAY("1dd.bin"), // Fire bullet.
            FS_YAY("1de.bin"), // Deteriorating fire bullet.
            FS_YAY("1df.bin"), // Magma sphere (needs to be animated).
            FS_LZX("1e0.bin"), // Magma sphere's flowing 2D animation.
            FS_YAY("1e1.bin"), // Gravity sphere (needs to be animated).
            FS_YAY("1e2.bin"), // Black sphere (needs to be animated).
            FS_YAY("1e3.bin"), // Swirling wind (animated).
            FS_YAY("1e4.bin"), // Largest magma sphere's growth animation.
            FS_YAY("1e5.bin"), // Medium magma sphere's growth animation.
            FS_YAY("1e6.bin"), // Dust particle circle. (Unused.)
            FS_YAY("1e7.bin"), // Small dust particles. (Unused.)
            FS_YAY("1e8.bin"), // Alt small dust particles. (Unused.)
            FS_YAY("1e9.bin"), // Detonated Gravity Bomb.
            FS_YAY("1ea.bin"), // Descending lightning blast (animated).
            FS_YAY("1eb.bin"), // Pre-detonation lightning streaks.
            FS_YAY("1ec.bin"), // Alt pre-detonation lightning streaks.
            FS_YAY("1ed.bin"), // Air bubble.
            FS_YAY("1ee.bin"), // Blue lightning bolt.
            FS_YAY("1ef.bin"), // Small, electric orb.
            FS_YAY("1f0.bin"), // Electrifying sphere.
            FS_YAY("1f1.bin"), // Round lightning blast.
            FS_YAY("1f2.bin"), // Surrounding electricity (animated, but missing second animation).
            FS_LZX("1f3.bin"), // Twisting electricity's animation (also works with leftover sparks).
            FS_YAY("1f4.bin"), // Air ring.
            FS_YAY("1f5.bin"), // Thin air ring.
            FS_YAY("1f6.bin"), // Scattering feathers (backside). (Unused.)
            FS_YAY("1f7.bin"), // Scattering feathers (frontside). (Unused.)
            FS_YAY("1f8.bin"), // Cyclones (animated).
            FS_YAY("1f9.bin"), // Scattering air particles (animated).
            FS_YAY("1fa.bin"), // Internal light blast (animated).
            FS_YAY("1fb.bin"), // Yellow light ring.
            FS_YAY("1fc.bin"), // Light sphere.
            FS_YAY("1fd.bin"), // Ray of light (needs to be animated).
            FS_YAY("1fe.bin"), // Round white light.
            FS_YAY("1ff.bin"), // Light sphere finishing (animated).
            FS_YAY("200.bin"), // Opened-up Light Bomb (animated).
            FS_YAY("201.bin"), // Pre-detonation flashlights (animated).
            FS_YAY("202.bin"), // Fire blast (needs to be animated).
            FS_LZX("203.bin"), // Fire blast's 2D animation.
            FS_YAY("204.bin"), // Ring of fire (needs to be animated).
            FS_LZX("205.bin"), // Ring of fire's 2D animation.
            FS_YAY("206.bin"), // Bright fire blast (needs to be animated).
            FS_LZX("207.bin"), // Bright fire blast's 2D animation.
            FS_YAY("208.bin"), // Cloud ring (animated).
            FS_YAY("209.bin"), // Swirling suction (animated).
            FS_YAY("20a.bin"), // Ring of compression (needs to be animated).
            FS_YAY("20b.bin"), // Dark blue lightning (animated). (Unused.)
            FS_LZX("20c.bin"), // Ring of compression's 2D animation.
            FS_LZX("20d.bin"), // Flame bar 2D animation. (Unused.)
            FS_YAY("20e.bin"), // Rotating electricity (animated).
            FS_YAY("20f.bin"), // Blast of light (animated).
            FS_YAY("210.bin"), // Circle of light (animated).
            FS_YAY("211.bin"), // Big fire blast (animated).
            FS_YAY("212.bin"), // Big fire ring's (needs to be animated).
            FS_LZX("213.bin"), // Big fire ring's 2D animation.
            FS_YAY("214.bin"), // Double lightning (needs to be animated).
            FS_LZX("215.bin"), // Double lightning 2D animation.
            FS_YAY("216.bin"), // White, shrinking sphere (animated).
            FS_YAY("217.bin"), // Yellow beam of light (animated).
            FS_YAY("218.bin"), // Flickering light sphere (animated).
            FS_YAY("219.bin"), // Leftover sparks (animated, but needs effect).
            FS_YAY("21a.bin"), // Outshining ray of light's animation.
            FS_YAY("21b.bin"), // Growing magma sphere (partially animated; needs further effect).
            FS_YAY("21c.bin"), // Lava puddle's largest growth animation.
            FS_YAY("21d.bin"), // Lava puddle's regular growth animation.
            FS_YAY("21e.bin"), // Pillar of fire's scaling animation.
            FS_YAY("21f.bin"), // Rotating ray of light's animation.
            FS_LZX("220.bin"), // Cracked tile texture. (Unused.)
            FS_LZX("221.bin"), // Dark tile texture. (Unused.)
            FS_LZX("222.bin"), // Dark cracked tile texture. (Unused.)
            FS_LZX("223.bin"), // Button's metallic texture (requires BHB button for effect; animated).
            FS_LZX("224.bin"), // Button's stone texture (requires BHB button for effect).
            FS_LZX("225.bin"), // Button's fancy texture (requires old, square button for effect).
            FS_LZX("226.bin"), // Button's color texture (requires BHB button for effect; animated).
            FS_YAY("227.bin"), // Radio(?) device (animated).
            FS_YAY("228.bin"), // Green King atop castle (animated). (Normally unused.)
            FS_YAY("229.bin"), // Large torch (needs to be animated).
            FS_LZX("22a.bin"), // Pipelines' hitbox.
            FS_YAY("22b.bin"), // Pipelines (clean).
            FS_YAY("22c.bin"), // Pipelines (damaged).
            FS_YAY("22d.bin"), // Pull switch (animated).
            FS_YAY("22e.bin"), // BHB button (animated).
            FS_LZX("22f.bin"), // Gravity Generator's darkened light bulbs (requires Gravity Generator for effect).
            FS_YAY("230.bin"), // Generator barrier (animated).
            FS_YAY("231.bin"), // Dummy crane (Unused.)
            FS_YAY("232.bin"), // Crane base.
            FS_YAY("233.bin"), // Crane.
            FS_YAY("234.bin"), // Steel crate segment (one half). (Normally unused.)
            FS_YAY("235.bin"), // Steel crate segment (other half). (Normally unused.)
            FS_YAY("236.bin"), // Steel crate(?).
            FS_YAY("237.bin"), // Mechanical lift.
            FS_YAY("238.bin"), // Twisting mechanism (animated).
            FS_YAY("239.bin"), // Garage door (animated).
            FS_YAY("23a.bin"), // Colorful, glass door (animated).
            FS_YAY("23b.bin"), // Piped pillar 9. (Normally unused.)
            FS_YAY("23c.bin"), // Large, grated platform.
            FS_LZX("23d.bin"), // Large, grated platform's hitbox.
            FS_YAY("23e.bin"), // Old, square button (animated).
            FS_LZX("23f.bin"), // BHB button's green color. (Unused.)
            FS_YAY("240.bin"), // Flamethrower gun base.
            FS_YAY("241.bin"), // Flamethrower gun.
            FS_YAY("242.bin"), // Lava flare (animated).
            FS_YAY("243.bin"), // Small tile.
            FS_LZX("244.bin"), // Green, metal door texture (requires colorful, glass door for effect).
            FS_LZX("245.bin"), // Serpent double doors texture (requires rusty double doors for effect).
            FS_YAY("246.bin"), // Riveted metal plates.
            FS_YAY("247.bin"), // Heated, triangular block.
            FS_LZX("248.bin"), // Unknown hitbox. (Unused.)
            FS_YAY("249.bin"), // Encased cylinder(?).
            FS_YAY("24a.bin"), // Coal crate.
            FS_YAY("24b.bin"), // Small display(?).
            FS_YAY("24c.bin"), // Incinerator (clean).
            FS_YAY("24d.bin"), // Incinerator (damaged).
            FS_YAY("24e.bin"), // Incinerator (heavily damaged).
            FS_YAY("24f.bin"), // Incinerator (shattering).
            FS_YAY("250.bin"), // Green crate (clean).
            FS_YAY("251.bin"), // Green crate (damaged).
            FS_YAY("252.bin"), // Green crate (heavily damaged).
            FS_YAY("253.bin"), // Green crate (shattering).
            FS_YAY("254.bin"), // Mechanical bridge (animated).
            FS_YAY("255.bin"), // Small pot.
            FS_YAY("256.bin"), // Shell pile.
            FS_YAY("257.bin"), // Crystal block.
            FS_YAY("258.bin"), // Serpent statue (clean).
            FS_YAY("259.bin"), // Serpent statue (damaged).
            FS_YAY("25a.bin"), // Serpent statue (shattering).
            FS_LZX("25b.bin"), // Serpent statue's hitbox.
            FS_YAY("25c.bin"), // Broken stone pillar.
            FS_YAY("25d.bin"), // White stone block.
            FS_YAY("25e.bin"), // Pearl block.
            FS_YAY("25f.bin"), // Shattering tile (animated). (Unused.)
            FS_LZX("260.bin"), // Stone double doors (requires rusty double doors for effect).
            FS_LZX("261.bin"), // Factory double doors (requires rusty double doors for effect).
            FS_YAY("262.bin"), // Serpent pillar (clean).
            FS_YAY("263.bin"), // Serpent pillar (damaged).
            FS_YAY("264.bin"), // Serpent pillar (shattering).
            FS_YAY("265.bin"), // Tall stone pillar (animated).
            FS_YAY("266.bin"), // Water pool (third room of Aquanet, animated).
            FS_LZX("267.bin"), // Water pool's hitbox.
            FS_YAY("268.bin"), // Convex serpent door (animated).
            FS_LZX("269.bin"), // Convex serpent door's hitbox.
            FS_YAY("26a.bin"), // Icy barrier.
            FS_YAY("26b.bin"), // Sea monster fountain (clean).
            FS_YAY("26c.bin"), // Sea monster fountain (damaged).
            FS_YAY("26d.bin"), // Sea monster fountain (shattering).
            FS_YAY("26e.bin"), // Rusty double doors (animated).
            FS_YAY("26f.bin"), // Watergate (animated).
            FS_YAY("270.bin"), // Water elevator (animated).
            FS_YAY("271.bin"), // Sea monster statue (clean).
            FS_YAY("272.bin"), // Sea monster statue (damaged).
            FS_YAY("273.bin"), // Sea monster statue (shattering).
            FS_YAY("274.bin"), // Mouth switch (animated).
            FS_LZX("275.bin"), // Mouth switch's hitbox.
            FS_YAY("276.bin"), // Large fountain (animated).
            FS_YAY("277.bin"), // Drop-down staircase (animated).
            FS_LZX("278.bin"), // Drop-down staircase's hitbox.
            FS_YAY("279.bin"), // Moving platform (Aquanet, Tower 3F).
            FS_YAY("27a.bin"), // Water cannon.
            FS_YAY("27b.bin"), // Shooting water stream (animated).
            FS_YAY("27c.bin"), // Stalactite (fallen).
            FS_YAY("27d.bin"), // Stalactite (shattering).
            FS_YAY("27e.bin"), // Water pool (moat, animated).
            FS_LZX("27f.bin"), // Water pool's hitbox.
            FS_YAY("280.bin"), // Water pool (swimming pool spa, animated).
            FS_LZX("281.bin"), // Water pool's hitbox.
            FS_YAY("282.bin"), // Water pool (elevator room, animated).
            FS_LZX("283.bin"), // Water pool's hitbox.
            FS_YAY("284.bin"), // Metal crate(?).
            FS_YAY("285.bin"), // Brown crate.
            FS_YAY("286.bin"), // Old turbine block thing.
            FS_YAY("287.bin"), // Floor control machine (clean).
            FS_YAY("288.bin"), // Floor control machine (damaged).
            FS_YAY("289.bin"), // Floor control machine (shattering).
            FS_YAY("28a.bin"), // Brown chest(?).
            FS_YAY("28b.bin"), // Riveted barrel. (Normally unused.)
            FS_YAY("28c.bin"), // Rusty triangular block.
            FS_LZX("28d.bin"), // Alt cracked tile texture. (Unused.)
            FS_LZX("28e.bin"), // Unknown cracked stone wall texture. (Unused.)
            FS_LZX("28f.bin"), // Tile texture. (Unused.)
            FS_YAY("290.bin"), // Rusty girder (clean).
            FS_YAY("291.bin"), // Rusty girder (damaged).
            FS_YAY("292.bin"), // Damaged stone block.
            FS_YAY("293.bin"), // Filthy piped pillar.
            FS_YAY("294.bin"), // Circuit breaker machine (clean).
            FS_YAY("295.bin"), // Circuit breaker machine (damaged).
            FS_YAY("296.bin"), // Circuit breaker machine (shattering).
            FS_LZX("297.bin"), // Button's red color (requires BHB button for effect).
            FS_LZX("298.bin"), // Sewage filter's hitbox.
            FS_YAY("299.bin"), // White bars (clean).
            FS_YAY("29a.bin"), // White bars (damaged).
            FS_YAY("29b.bin"), // White bars (shattering).
            FS_YAY("29c.bin"), // Pig (animated). (Unused animation.)
            FS_YAY("29d.bin"), // Coconut block.
            FS_YAY("29e.bin"), // Tropical water. (Normally unused.)
            FS_YAY("29f.bin"), // Miniature apartment building.
            FS_YAY("2a0.bin"), // Miniature office building.
            FS_YAY("2a1.bin"), // Miniature skyscraper (clean).
            FS_YAY("2a2.bin"), // Miniature skyscraper (damaged).
            FS_YAY("2a3.bin"), // Miniature overpass.
            FS_YAY("2a4.bin"), // Small boulder.
            FS_YAY("2a5.bin"), // Mouse (animated). (Unused animation.)
            FS_YAY("2a6.bin"), // Large boulder.
            FS_YAY("2a7.bin"), // Chicken (animated). (Unused animation.)
            FS_YAY("2a8.bin"), // Fish (animated). (Unused animation.)
            FS_YAY("2a9.bin"), // Crusher wall.
            FS_YAY("2aa.bin"), // Missile.
            FS_YAY("2ab.bin"), // Ancient statue (green stand).
            FS_YAY("2ac.bin"), // Ancient statue (red stand).
            FS_YAY("2ad.bin"), // Brown pillar.
            FS_YAY("2ae.bin"), // Cracked brown pillar.
            FS_YAY("2af.bin"), // Snake statue block.
            FS_YAY("2b0.bin"), // Small torch (needs to be animated).
            FS_LZX("2b1.bin"), // Small torch block's 2D animation.
            FS_YAY("2b2.bin"), // Brown stone block.
            FS_YAY("2b3.bin"), // Giant torch (clean; needs to be animated). (Normally unused.)
            FS_LZX("2b4.bin"), // Giant torch's 2D animation (also works with large torch).
            FS_YAY("2b5.bin"), // Giant torch (damaged). (Normally unused.)
            FS_YAY("2b6.bin"), // Giant torch (badly damaged). (Normally unused.)
            FS_YAY("2b7.bin"), // Giant torch (shattering). (Normally unused.)
            FS_LZX("2b8.bin"), // Unknown damaged stone wall texture. (Unused.)
            FS_YAY("2b9.bin"), // Vertical stone double doors (animated).
            FS_YAY("2ba.bin"), // Vertical stone door (animated).
            FS_YAY("2bb.bin"), // Ancient wall.
            FS_YAY("2bc.bin"), // Jewel pedestal.
            FS_YAY("2bd.bin"), // Red jewel.
            FS_YAY("2be.bin"), // Blue jewel.
            FS_YAY("2bf.bin"), // Fragile tile (clean).
            FS_YAY("2c0.bin"), // Fragile tile (damaged).
            FS_YAY("2c1.bin"), // Fragile tile (shattering).
            FS_LZX("2c2.bin"), // Fragile tile's hitbox.
            FS_YAY("2c3.bin"), // Scorpion door (animated).
            FS_YAY("2c4.bin"), // Ancient door (animated).
            FS_YAY("2c5.bin"), // Floating platform (used to carry last jewel).
            FS_YAY("2c6.bin"), // Green jewel.
            FS_YAY("2c7.bin"), // Scorpion elevator (needs to be animated).
            FS_LZX("2c8.bin"), // Scorpion elevator's fade animation.
            FS_LZX("2c9.bin"), // Scorpion elevator's hitbox.
            FS_LZX("2ca.bin"), // Black hole door texture (requires garage door for effect).
            FS_LZX("2cb.bin"), // Serpent door (vertical) texture (requires garage door for effect).
            FS_YAY("2cc.bin"), // Alt fragile tile (clean).
            FS_YAY("2cd.bin"), // Alt fragile tile (damaged).
            FS_YAY("2ce.bin"), // Alt fragile tile (shattering).
            FS_YAY("2cf.bin"), // Jewel case.
            FS_LZX("2d0.bin"), // Jewel case's left blue jewel.
            FS_LZX("2d1.bin"), // Jewel case's right blue jewel.
            FS_LZX("2d2.bin"), // Jewel case's red jewel.
            FS_YAY("2d3.bin"), // Three-lamp streetlights.
            FS_YAY("2d4.bin"), // Five-lamp streetlights.
            FS_YAY("2d5.bin"), // Trash bin(?).
            FS_YAY("2d6.bin"), // Starlight fountain (animated).
            FS_LZX("2d7.bin"), // Starlight fountain's hitbox.
            FS_YAY("2d8.bin"), // Tall tree.
            FS_YAY("2d9.bin"), // Small planter.
            FS_YAY("2da.bin"), // Slot machine.
            FS_YAY("2db.bin"), // Stack of chips.
            FS_YAY("2dc.bin"), // Red-cushioned door (animated).
            FS_LZX("2dd.bin"), // Unknown dark damaged stone wall texture. (Unused.)
            FS_YAY("2de.bin"), // Roulette table (clean).
            FS_YAY("2df.bin"), // Roulette table (damaged).
            FS_YAY("2e0.bin"), // Roulette table (shattering).
            FS_YAY("2e1.bin"), // Queen of Hearts card (animated).
            FS_YAY("2e2.bin"), // Ace of Spades card (animated).
            FS_YAY("2e3.bin"), // King of Clubs card (animated).
            FS_YAY("2e4.bin"), // Knight of Diamonds card (animated).
            FS_YAY("2e5.bin"), // Small barricade.
            FS_YAY("2e6.bin"), // CLOSED floor sign (clean).
            FS_YAY("2e7.bin"), // CLOSED floor sign (damaged).
            FS_YAY("2e8.bin"), // CLOSED floor sign (shattering).
            FS_YAY("2e9.bin"), // GET OUT signboard.
            FS_YAY("2ea.bin"), // Rotating doors.
            FS_LZX("2eb.bin"), // Rotating doors' hitbox.
            FS_LZX("2ec.bin"), // Dungeon door texture (requires colorful, glass door for effect).
            FS_YAY("2ed.bin"), // Feminine bunny statue.
            FS_YAY("2ee.bin"), // Masculine bunny statue.
            FS_YAY("2ef.bin"), // Burly bunny statue (clean).
            FS_YAY("2f0.bin"), // Burly bunny statue (damaged).
            FS_YAY("2f1.bin"), // Burly bunny statue (badly damaged).
            FS_YAY("2f2.bin"), // Burly bunny statue (shattering).
            FS_YAY("2f3.bin"), // Starlight elevator (animated).
            FS_YAY("2f4.bin"), // Table for two.
            FS_YAY("2f5.bin"), // Limousine (clean).
            FS_YAY("2f6.bin"), // Limousine (damaged).
            FS_YAY("2f7.bin"), // Limousine (shattering).
            FS_YAY("2f8.bin"), // Large disco ball.
            FS_YAY("2f9.bin"), // Card block.
            FS_LZX("2fa.bin"), // Hearts card block texture (requires card block for effect).
            FS_LZX("2fb.bin"), // Spades card block texture (requires card block for effect).
            FS_LZX("2fc.bin"), // Clubs card block texture (requires card block for effect).
            FS_LZX("2fd.bin"), // Diamonds card block texture (requires card block for effect).
            FS_YAY("2fe.bin"), // Epikyur information board.
            FS_YAY("2ff.bin"), // Giant ghost (animated).
            FS_LZX("300.bin"), // Giant ghost's tongue hitbox.
            FS_YAY("301.bin"), // Castle bridge (animated).
            FS_LZX("302.bin"), // Castle bridge's floor hitbox.
            FS_YAY("303.bin"), // Castle clock's minute hand.
            FS_YAY("304.bin"), // Castle clock's short hand.
            FS_YAY("305.bin"), // Popcorn stand (clean).
            FS_YAY("306.bin"), // Popcorn stand (damaged).
            FS_YAY("307.bin"), // Popcorn stand (shattering).
            FS_YAY("308.bin"), // Vending machine (clean).
            FS_YAY("309.bin"), // Vending machine (damaged).
            FS_YAY("30a.bin"), // Vending machine (shattering).
            FS_YAY("30b.bin"), // Rollercoaster cart (animated).
            FS_LZX("30c.bin"), // Rollercoaster cart's hitbox. 
            FS_YAY("30d.bin"), // Creepy tree.
            FS_YAY("30e.bin"), // Fancy gate.
            FS_YAY("30f.bin"), // Dark brown double doors (animated).
            FS_YAY("310.bin"), // Haunted house window.
            FS_LZX("311.bin"), // Haunted house window's broken state.
            FS_YAY("312.bin"), // Red carpet staircase.
            FS_LZX("313.bin"), // Red carpet staircase's missing stairs.
            FS_YAY("314.bin"), // Small brownish door (animated).
            FS_YAY("315.bin"), // Small brownish door with fiery door frame.
            FS_LZX("316.bin"), // Fiery door frame's 2D animation.
            FS_YAY("317.bin"), // Dark fragile tile (clean).
            FS_YAY("318.bin"), // Dark fragile tile (damaged).
            FS_YAY("319.bin"), // Dark fragile tile (shattering).
            FS_YAY("31a.bin"), // Spike trap (animated).
            FS_YAY("31b.bin"), // Shattering glass (animated).
            FS_YAY("31c.bin"), // Chained spike trap.
            FS_YAY("31d.bin"), // Haunted dresser (animated).
            FS_LZX("31e.bin"), // Haunted dresser's blue flame animation.
            FS_LZX("31f.bin"), // Haunted dresser's skull dimming. (Normally unused.)
            FS_LZX("320.bin"), // Haunted dresser's flame gone out. (Normally unused.)
            FS_YAY("321.bin"), // Rectangular floating platform.
            FS_LZX("322.bin"), // Rectangular floating platform's hitbox.
            FS_YAY("323.bin"), // Dinosaur egg.
            FS_YAY("324.bin"), // Dinosaur fossil.
            FS_YAY("325.bin"), // Triceratops (clean).
            FS_YAY("326.bin"), // Triceratops (damaged).
            FS_YAY("327.bin"), // Triceratops (shattering).
            FS_YAY("328.bin"), // T-rex skeleton body (clean).
            FS_YAY("329.bin"), // T-rex skeleton body (damaged).
            FS_YAY("32a.bin"), // T-rex skeleton body (shattering).
            FS_YAY("32b.bin"), // T-rex skull.
            FS_YAY("32c.bin"), // Hanging aircraft.
            FS_YAY("32d.bin"), // Rocket display (clean).
            FS_YAY("32e.bin"), // Rocket display (damaged).
            FS_YAY("32f.bin"), // Rocket display (shattering).
            FS_YAY("330.bin"), // Tank display.
            FS_YAY("331.bin"), // Glass display case.
            FS_YAY("332.bin"), // Battery.
            FS_YAY("333.bin"), // Baelfael statue.
            FS_YAY("334.bin"), // Behemos statue.
            FS_YAY("335.bin"), // Ashtarth statue.
            FS_YAY("336.bin"), // Zhael statue.
            FS_YAY("337.bin"), // Molok statue.
            FS_YAY("338.bin"), // Bulzeeb statue.
            FS_YAY("339.bin"), // Zoniha statue.
            FS_YAY("33a.bin"), // Frozen fountain.
            FS_YAY("33b.bin"), // Castle doors (animated).
            FS_YAY("33c.bin"), // Haunted House Pass card (animated).
            FS_YAY("33d.bin"), // Museum Pass card (animated).
            FS_YAY("33e.bin"), // Pile of tires.
            FS_YAY("33f.bin"), // Air compressor(?).
            FS_YAY("340.bin"), // Phone booth.
            FS_LZX("341.bin"), // Phone booth's hitbox.
            FS_YAY("342.bin"), // Garbage dumpster.
            FS_YAY("343.bin"), // Trashed motorcycle (clean).
            FS_YAY("344.bin"), // Trashed motorcycle (damaged).
            FS_YAY("345.bin"), // Trashed motorcycle (shattering).
            FS_LZX("346.bin"), // Trashed motorcycle's hitbox.
            FS_YAY("347.bin"), // Brown oil barrel.
            FS_YAY("348.bin"), // Fire hydrant.
            FS_YAY("349.bin"), // Stop sign.
            FS_YAY("34a.bin"), // Old streetlight.
            FS_YAY("34b.bin"), // Cracked wall (untended).
            FS_YAY("34c.bin"), // Cracked wall (opening).
            FS_YAY("34d.bin"), // Cracked wall (shattering).
            FS_YAY("34e.bin"), // Trash compactor.
            FS_YAY("34f.bin"), // Manhole.
            FS_YAY("350.bin"), // Bent lamppost (animated).
            FS_LZX("351.bin"), // Bent lamppost's initial hitbox.
            FS_LZX("352.bin"), // Bent lamppost's bridge hitbox.
            FS_YAY("353.bin"), // Gravity wall barrier being crushed (animated; also works with the other).
            FS_YAY("354.bin"), // Gravity wall barrier.
            FS_LZX("355.bin"), // Gravity wall barrier's empty center. (Unused.)
            FS_YAY("356.bin"), // Chain-link tower (animated). (Normally unused.)
            FS_YAY("357.bin"), // Hanging chain-link. (Normally unused.)
            FS_YAY("358.bin"), // Small hi-tech floor panel (animated). (Normally unused.)
            FS_YAY("359.bin"), // Card Key machine (animated).
            FS_LZX("35a.bin"), // Card Key machine's western slot activated.
            FS_LZX("35b.bin"), // Card Key machine's southern slot activated.
            FS_LZX("35c.bin"), // Card Key machine's hitbox.
            FS_YAY("35d.bin"), // Card Key card (animated).
            FS_YAY("35e.bin"), // Hi-tech bridge.
            FS_LZX("35f.bin"), // Hi-tech bridge's hitbox.
            FS_YAY("360.bin"), // Futuristic lift (animated).
            FS_LZX("361.bin"), // Futuristic lift's hitbox.
            FS_YAY("362.bin"), // Electric barrier transmitter (animated).
            FS_YAY("363.bin"), // Electric barrier transmitter pad(?).
            FS_YAY("364.bin"), // Large hi-tech floor panel (animated). (Unused animation.)
            FS_YAY("365.bin"), // Electric switch (needs to be animated).
            FS_LZX("366.bin"), // Electric switch's animation.
            FS_YAY("367.bin"), // Security mechanism control panel thing (clean; animated).
            FS_YAY("368.bin"), // Security mechanism control panel thing (damaged).
            FS_YAY("369.bin"), // Security mechanism control panel thing (shattering).
            FS_YAY("36a.bin"), // Giant door (animated).
            FS_LZX("36b.bin"), // Giant door's blue lights.
            FS_LZX("36c.bin"), // Serpent door (horizontal) texture (requires colorful, glass door for effect).
            FS_YAY("36d.bin"), // Green & white barricade.
            FS_YAY("36e.bin"), // Gray rectangular lift.
            FS_YAY("36f.bin"), // Control panel.
            FS_LZX("370.bin"), // Control panel's activation.
            FS_YAY("371.bin"), // Generator (clean; animated).
            FS_YAY("372.bin"), // Generator (damaged; animated).
            FS_YAY("373.bin"), // Generator (shattering).
            FS_YAY("374.bin"), // Futuristic ladder (animated).
            FS_LZX("375.bin"), // Futuristic ladder's hitbox.
            FS_YAY("376.bin"), // Engine guard (clean; animated).
            FS_YAY("377.bin"), // Engine guard (shattering).
            FS_YAY("378.bin"), // Power shaft beam rotating clockwise (animated).
            FS_YAY("379.bin"), // Power shaft beam rotating counterclockwise (animated).
            FS_YAY("37a.bin"), // Central Command Room elevator (animated).
            FS_LZX("37b.bin"), // Red flashing light's blue color. (Unused.)
            FS_YAY("37c.bin"), // Celestial Stone platform (animated when lit).
            FS_LZX("37d.bin"), // Celestial Stone platform's shining light.
            FS_YAY("37e.bin"), // Futuristic double doors (animated).
            FS_YAY("37f.bin"), // Vertical, futuristic door (animated).
            FS_YAY("380.bin"), // Short blue crate.
            FS_YAY("381.bin"), // Tall blue crate.
            FS_YAY("382.bin"), // Triangular metallic block. (Normally unused.)
            FS_YAY("383.bin"), // Loose stone pillar mechanism (untended).
            FS_YAY("384.bin"), // Loose stone pillar mechanism (loosened).
            FS_YAY("385.bin"), // Loose stone pillar mechanism (fallen).
            FS_YAY("386.bin"), // Steel bar (clean).
            FS_YAY("387.bin"), // Steel bar (damaged).
            FS_YAY("388.bin"), // Purple pillar.
            FS_YAY("389.bin"), // Guardian Armor block (animated).
            FS_YAY("38a.bin"), // Gray square lift.
            FS_YAY("38b.bin"), // Pylon floor cover (animated).
            FS_YAY("38c.bin"), // Moving platform (Thantos Generator Room).
            FS_YAY("38d.bin"), // Red elevator cage (animated).
            FS_YAY("38e.bin"), // Horizontal electricity (needs to be animated).
            FS_LZX("38f.bin"), // Horizontal electricity's animation.
            FS_YAY("390.bin"), // Subway door (animated).
            FS_YAY("391.bin"), // Subway trunk door (animated).
            FS_LZX("392.bin"), // Subway trunk door's hitbox.
            FS_YAY("393.bin"), // Open/closing floor trap (animated).
            FS_YAY("394.bin"), // Slaty pavement (needs to be animated).
            FS_LZX("395.bin"), // Slaty pavement's disappearing animation.
            FS_YAY("396.bin"), // BHB pushable block.
            FS_YAY("397.bin"), // Phantom.
            FS_YAY("398.bin"), // Pylon (animated, but needs effect).
            FS_YAY("399.bin"), // Drop-down ladder (animated).
            FS_YAY("39a.bin"), // Protected pylon (animated).
            FS_LZX("39b.bin"), // Protected pylon's flickering barrier.
            FS_LZX("39c.bin"), // Protected pylon's red flashing barrier.
            FS_LZX("39d.bin"), // Protected pylon's frozen barrier.
            FS_YAY("39e.bin"), // Car.
            FS_YAY("39f.bin"), // Brown cage (clean).
            FS_YAY("3a0.bin"), // Brown cage (damaged).
            FS_YAY("3a1.bin"), // Brown cage (shattering).
            FS_YAY("3a2.bin"), // Stalagmite.
            FS_LZX("3a3.bin"), // Tropical water's hitbox. (Normally unused.)
            FS_YAY("3a4.bin"), // Sewage water pouring out (animated).
            FS_YAY("3a5.bin"), // Water pouring out (animated).
            FS_LZX("3a6.bin"), // Drop-down ladder's hitbox.
            FS_YAY("3a7.bin"), // Dirty water pool (animated).
            FS_LZX("3a8.bin"), // Dirty water pool's hitbox.
            FS_YAY("3a9.bin"), // Rusty pipe.
            FS_YAY("3aa.bin"), // Water/ice shot (animated).
            FS_YAY("3ab.bin"), // Twister/hurricane (animated).
            FS_YAY("3ac.bin"), // Hamster (animated).
            FS_YAY("3ad.bin"), // BHB Army ship (animated).
            FS_LZX("3ae.bin"), // BHB Army ship original paint color (requires BHB Army ship or space shuttle).
            FS_LZX("3af.bin"), // BHB Army ship's pink paint job (requires BHB Army ship or space shuttle).
            FS_LZX("3b0.bin"), // BHB Army ship's tailpipe turned on (requires BHB Army ship or space shuttle).
            FS_LZX("3b1.bin"), // BHB Army ship's tailpipe turned off (requires BHB Army ship or space shuttle).
            FS_LZX("3b2.bin"), // BHB Army ship's black hole design (requires BHB Army ship or space shuttle).
            FS_LZX("3b3.bin"), // BHB Army ship's Pommy design (requires BHB Army ship or space shuttle).
            FS_YAY("3b4.bin"), // Bright lights.
            FS_LZX("3b5.bin"), // Rusty pipe's hitbox.
            FS_YAY("3b6.bin"), // Ice platform.
            FS_YAY("3b7.bin"), // Fire Stone.
            FS_YAY("3b8.bin"), // Ice Stone.
            FS_YAY("3b9.bin"), // Wind Stone.
            FS_YAY("3ba.bin"), // Earth Stone.
            FS_YAY("3bb.bin"), // Lightning Stone.
            FS_YAY("3bc.bin"), // Light Stone.
            FS_YAY("3bd.bin"), // Shadow Stone.
            FS_YAY("3be.bin"), // Celestial Stone.
            FS_YAY("3bf.bin"), // BHB control panel block.
            FS_YAY("3c0.bin"), // Question mark.
            FS_YAY("3c1.bin"), // Gravity floor barrier.
            FS_YAY("3c2.bin"), // Jail cell door (clean).
            FS_YAY("3c3.bin"), // Jail cell door (shattering).
            FS_LZX("3c4.bin"), // Slaty pavement's reappearing animation.
            FS_YAY("3c5.bin"), // Electric wall barrier corner (needs to be animated). (Normally unused.)
            FS_LZX("3c6.bin"), // Electric wall barrier corner's 2D animation. (Normally unused.)
            FS_YAY("3c7.bin"), // Old sewage meter(?).
            FS_LZX("3c8.bin"), // Old sewage meter(?)'s animation.
            FS_YAY("3c9.bin"), // Electric wall barrier (needs to be animated).
            FS_LZX("3ca.bin"), // Electric wall barrier's 2D animation.
            FS_YAY("3cb.bin"), // Green cage (normal).
            FS_YAY("3cc.bin"), // Green cage (shattering).
            FS_YAY("3cd.bin"), // Gravity Generator (clean; animated).
            FS_YAY("3ce.bin"), // Gravity Generator (damaged; animated).
            FS_YAY("3cf.bin"), // Gravity Generator (shattering).
            FS_YAY("3d0.bin"), // Gravity being released (animated).
            FS_YAY("3d1.bin"), // Glass shield (animated).
            FS_LZX("3d2.bin"), // Glass shield's hitbox.
            FS_YAY("3d3.bin"), // Car doors (standing).
            FS_YAY("3d4.bin"), // Car doors (blown out).
            FS_YAY("3d5.bin"), // Sewage filter (standing; animated).
            FS_YAY("3d6.bin"), // Sewage filter (shattering).
            FS_YAY("3d7.bin"), // Stone platform.
            FS_YAY("3d8.bin"), // Thermal energy.
            FS_LZX("3d9.bin"), // Thermal energy's hitbox.
            FS_YAY("3da.bin"), // Grated platform piece (animated).
            FS_YAY("3db.bin"), // Warning HUD screen (animated).
            FS_LZX("3dc.bin"), // Warning HUD screen grid's 2D animation.
            FS_LZX("3dd.bin"), // Space shuttle interior model's hitbox.
            FS_YAY("3de.bin"), // Space shuttle exterior model.
            FS_YAY("3df.bin"), // Tailpipe flash (animated).
            FS_YAY("3e0.bin"), // Black hole suction.
            FS_YAY("3e1.bin"), // Black hole layer one.
            FS_YAY("3e2.bin"), // Black hole layer two.
            FS_YAY("3e3.bin"), // Black hole layer three.
            FS_YAY("3e4.bin"), // Space shuttle interior model.
            FS_YAY("3e5.bin"), // Space rock.
            FS_YAY("3e6.bin"), // Starry backdrop.
            FS_YAY("3e7.bin"), // Guardian Helmet custom part.
            FS_YAY("3e8.bin"), // Guardian Vest custom part.
            FS_YAY("3e9.bin"), // Guardian Sleeves custom part.
            FS_YAY("3ea.bin"), // Guardian Boots custom part.
            FS_YAY("3eb.bin"), // Full Helmet custom part.
            FS_YAY("3ec.bin"), // Warrior's Armor custom part.
            FS_YAY("3ed.bin"), // Gauntlet custom part.
            FS_YAY("3ee.bin"), // Armored Boots custom part.
            FS_YAY("3ef.bin"), // Plate custom part.
            FS_YAY("3f0.bin"), // Frog Suit custom part.
            FS_YAY("3f1.bin"), // Webbed Gloves custom part.
            FS_YAY("3f2.bin"), // Frog Feet custom part.
            FS_YAY("3f3.bin"), // Helmet custom part.
            FS_YAY("3f4.bin"), // Biker Suit custom part.
            FS_YAY("3f5.bin"), // Leather Gloves custom part.
            FS_YAY("3f6.bin"), // Leather Boots custom part.
            FS_YAY("3f7.bin"), // Pointed Hat custom part.
            FS_YAY("3f8.bin"), // Clown Suit custom part.
            FS_YAY("3f9.bin"), // White Gloves custom part.
            FS_YAY("3fa.bin"), // Clown Shoes custom part.
            FS_YAY("3fb.bin"), // Robot Head custom part.
            FS_YAY("3fc.bin"), // Robot Suit custom part.
            FS_YAY("3fd.bin"), // Robot Arm custom part.
            FS_YAY("3fe.bin"), // Robot Boots custom part.
            FS_YAY("3ff.bin"), // Cat Ears custom part.
            FS_YAY("400.bin"), // Cat Suit custom part.
            FS_YAY("401.bin"), // Cat Gloves custom part.
            FS_YAY("402.bin"), // Cat Slippers custom part.
            FS_YAY("403.bin"), // Mohawk custom part.
            FS_YAY("404.bin"), // Leather Jacket custom part.
            FS_YAY("405.bin"), // Brass Knuckles custom part.
            FS_YAY("406.bin"), // Boots custom part.
            FS_YAY("407.bin"), // Cowboy Hat custom part.
            FS_YAY("408.bin"), // Cowboy Vest custom part.
            FS_YAY("409.bin"), // Cowboy Gloves custom part.
            FS_YAY("40a.bin"), // Cowboy Boots custom part.
            FS_YAY("40b.bin"), // Topknot custom part.
            FS_YAY("40c.bin"), // Kimono custom part.
            FS_YAY("40d.bin"), // Sword custom part.
            FS_YAY("40e.bin"), // Sandals custom part.
            FS_YAY("40f.bin"), // Beret custom part.
            FS_YAY("410.bin"), // Artist's Smock custom part.
            FS_YAY("411.bin"), // Paint Set custom part.
            FS_YAY("412.bin"), // Slippers custom part.
            FS_YAY("413.bin"), // Beard custom part.
            FS_YAY("414.bin"), // Tank Body custom part.
            FS_YAY("415.bin"), // Fan custom part.
            FS_YAY("416.bin"), // Bigfoot Shoes custom part.
            FS_YAY("417.bin"), // Headgear custom part.
            FS_YAY("418.bin"), // Elephant Suit custom part.
            FS_YAY("419.bin"), // Gloves custom part.
            FS_YAY("41a.bin"), // Kung Fu Shoes custom part.
            FS_YAY("41b.bin"), // Gold Helmet custom part.
            FS_YAY("41c.bin"), // Gold Suit custom part.
            FS_YAY("41d.bin"), // Gold Gloves custom part.
            FS_YAY("41e.bin"), // Gold Boots custom part.
            FS_YAY("41f.bin"), // Ribbon custom part.
            FS_YAY("420.bin"), // Pink Dress custom part.
            FS_YAY("421.bin"), // Slash Claws custom part.
            FS_YAY("422.bin"), // High Heels custom part.
            FS_YAY("423.bin"), // Bald Head custom part.
            FS_YAY("424.bin"), // Apron custom part.
            FS_YAY("425.bin"), // Hand Puppets custom part.
            FS_YAY("426.bin"), // Pommy Slippers custom part.
            FS_YAY("427.bin"), // Rabbit Ears custom part.
            FS_YAY("428.bin"), // Duck Suit custom part.
            FS_YAY("429.bin"), // Drill custom part.
            FS_YAY("42a.bin"), // Sneakers custom part.
            FS_YAY("42b.bin"), // Propeller enemy running. (Normally unused.)
            FS_YAY("42c.bin"), // Gear enemy running. (Normally unused.)
            FS_YAY("42d.bin"), // Fire Ball enemy.
            FS_YAY("42e.bin"), // BHB Soldier walking.
            FS_YAY("42f.bin"), // BHB Soldier swinging hammer.
            FS_YAY("430.bin"), // BHB Soldier darting.
            FS_YAY("431.bin"), // BHB Soldier knocked out.
            FS_YAY("432.bin"), // BHB Soldier flailing arms and legs.
            FS_YAY("433.bin"), // BHB Soldier taking a blow.
            FS_YAY("434.bin"), // Flame Titan walking.
            FS_YAY("435.bin"), // Flame Titan breathing fire.
            FS_YAY("436.bin"), // Flame Titan vomiting.
            FS_YAY("437.bin"), // Flame Titan knocked out. (Normally unused.)
            FS_YAY("438.bin"), // Hunt Dog idling.
            FS_YAY("439.bin"), // Hunt Dog biting.
            FS_YAY("43a.bin"), // Hunt Dog wagging its tail then biting.
            FS_YAY("43b.bin"), // Hunt Dog squelching into position. (Normally unused.)
            FS_YAY("43c.bin"), // Hunt Dog taking a blow.
            FS_YAY("43d.bin"), // Hunt Dog squelching. (Normally unused.)
            FS_YAY("43e.bin"), // Hunt Dog in pain.
            FS_LZX("43f.bin"), // Flame Titan's flashing fire.
            FS_LZX("440.bin"), // Flame Titan's boiling belly.
            FS_LZX("441.bin"), // Hunt Dog's flickering tail light.
            FS_YAY("442.bin"), // Giant Crab walking.
            FS_YAY("443.bin"), // Giant Crab jumping.
            FS_YAY("444.bin"), // Giant Crab blowing.
            FS_YAY("445.bin"), // Giant Crab flipping over.
            FS_YAY("446.bin"), // Giant Crab knocked out.
            FS_YAY("447.bin"), // Giant Crab getting back up. (Normally unused.)
            FS_YAY("448.bin"), // Giant Crab taking a blow.
            FS_YAY("449.bin"), // Giant Crab trembling.
            FS_YAY("44a.bin"), // Triton walking.
            FS_YAY("44b.bin"), // Triton swinging trident.
            FS_YAY("44c.bin"), // Triton knocked out.
            FS_YAY("44d.bin"), // Triton taking a blow.
            FS_YAY("44e.bin"), // Triton twitching with head down.
            FS_YAY("44f.bin"), // Froggy's top half hopping up.
            FS_YAY("450.bin"), // Froggy's bottom half hopping up.
            FS_YAY("451.bin"), // Froggy's top half lunging backward.
            FS_YAY("452.bin"), // Froggy's bottom half lunging backward, then launching tongue.
            FS_YAY("453.bin"), // Froggy's top half flinching.
            FS_YAY("454.bin"), // Froggy's bottom half flinching.
            FS_YAY("455.bin"), // Froggy's top half leaning back.
            FS_YAY("456.bin"), // Froggy's bottom half leaning back.
            FS_YAY("457.bin"), // Blowfish walking.
            FS_YAY("458.bin"), // Blowfish puffing up.
            FS_YAY("459.bin"), // Blowfish puffed up halfway. (Normally unused.)
            FS_YAY("45a.bin"), // Blowfish puffing up further.
            FS_YAY("45b.bin"), // Blowfish puffed up all the way. (Normally unused.)
            FS_YAY("45c.bin"), // Blowfish deflating slowly. (Normally unused.)
            FS_YAY("45d.bin"), // Blowfish inflating upward. (Normally unused.)
            FS_YAY("45e.bin"), // Blowfish inflated. (Normally unused.)
            FS_LZX("45f.bin"), // Blowfish's glaring eyes.
            FS_LZX("460.bin"), // Blowfish's agitated face. (Unused.)
            FS_YAY("461.bin"), // Seal waddling.
            FS_YAY("462.bin"), // Seal lowering head and lifting.
            FS_YAY("463.bin"), // Seal flicking forward.
            FS_YAY("464.bin"), // Seal taking a blow.
            FS_LZX("465.bin"), // Seal's burnt body.
            FS_YAY("466.bin"), // Seal knocked out.
            FS_LZX("467.bin"), // Seal's rolled eyeballs.
            FS_YAY("468.bin"), // Seal leaning body forward. (Normally unused.)
            FS_YAY("469.bin"), // Seal twitching. (Normally unused.)
            FS_LZX("46a.bin"), // Seal burnt up and crying. (Unused.)
            FS_YAY("46b.bin"), // Seal waving nose up and down. (Normally unused.)
            FS_YAY("46c.bin"), // Grab Pot idling.
            FS_LZX("46d.bin"), // Grab Pot's solid casing.
            FS_LZX("46e.bin"), // Grab Pot's open eyes.
            FS_LZX("46f.bin"), // Grab Pot's cracked casing.
            FS_LZX("470.bin"), // Grab Pot's shut eyes.
            FS_LZX("471.bin"), // Grab Pot's eyes closing.
            FS_YAY("472.bin"), // Sea Urchin puffing up. (Normally unused.)
            FS_YAY("473.bin"), // Sea Urchin breathing.
            FS_YAY("474.bin"), // Mad Rat walking.
            FS_YAY("475.bin"), // Mad Rat biting.
            FS_YAY("476.bin"), // Mat Rat falling over onto back. (Normally unused.)
            FS_YAY("477.bin"), // Mad Rat turning over onto legs. (Normally unused.)
            FS_YAY("478.bin"), // Mad Rat knocked out.
            FS_YAY("479.bin"), // Mad Rat taking a blow.
            FS_YAY("47a.bin"), // Mad Rat wiggling. (Unused.)
            FS_YAY("47b.bin"), // Blaggy flying.
            FS_YAY("47c.bin"), // Blaggy biting. (Normally unused.)
            FS_YAY("47d.bin"), // Blaggy knocked out.
            FS_YAY("47e.bin"), // Blaggy taking a blow.
            FS_YAY("47f.bin"), // BH-TYPE01 walking.
            FS_YAY("480.bin"), // BH-TYPE01 attacking blades.
            FS_YAY("481.bin"), // BH-TYPE01 taking a blow.
            FS_YAY("482.bin"), // BH-TYPE01 knocked out.
            FS_LZX("483.bin"), // BH-TYPE01's flickering display.
            FS_LZX("484.bin"), // BH-TYPE01's red display.
            FS_YAY("485.bin"), // BH-TYPE02 walking.
            FS_YAY("486.bin"), // BH-TYPE02 swinging blade.
            FS_YAY("487.bin"), // BH-TYPE02 taking a blow.
            FS_YAY("488.bin"), // BHB Army Combatant walking.
            FS_YAY("489.bin"), // BHB Army Combatant charging forward.
            FS_YAY("48a.bin"), // BHB Army Combatant darting.
            FS_YAY("48b.bin"), // BHB Army Combatant knocked out.
            FS_YAY("48c.bin"), // BHB Army Combatant flailing arms and legs.
            FS_YAY("48d.bin"), // BHB Army Combatant jumping up and landing on butt. (Normally unused.)
            FS_YAY("48e.bin"), // BHB Army Combatant taking a blow.
            FS_YAY("48f.bin"), // Cannon body.
            FS_YAY("490.bin"), // Cannon nose.
            FS_YAY("491.bin"), // Black Bull walking.
            FS_YAY("492.bin"), // Black Bull charging forward.
            FS_YAY("493.bin"), // Black Bull knocked out.
            FS_YAY("494.bin"), // Black Bull taking a blow.
            FS_YAY("495.bin"), // Black Bull spreading legs.
            FS_YAY("496.bin"), // Ancestral Spirit nodding.
            FS_YAY("497.bin"), // Ancestral Spirit's cloud blowing.
            FS_YAY("498.bin"), // Ancestral Spirit pulling head back & lunging forward.
            FS_YAY("499.bin"), // Ancestral Spirit's cloud blowing violently.
            FS_YAY("49a.bin"), // Ancestral Spirit knocked out.
            FS_YAY("49b.bin"), // Ancestral Spirit's cloud blowing weakly.
            FS_YAY("49c.bin"), // Ancestral Spirit taking a blow.
            FS_YAY("49d.bin"), // Ancestral Spirit's cloud whipping.
            FS_YAY("49e.bin"), // Harpy walking.
            FS_YAY("49f.bin"), // Harpy preparing wings.
            FS_YAY("4a0.bin"), // Harpy taking a blow.
            FS_YAY("4a1.bin"), // Harpy knocked out.
            FS_YAY("4a2.bin"), // Harpy crouching.
            FS_YAY("4a3.bin"), // Snake slithering.
            FS_YAY("4a4.bin"), // Snake biting.
            FS_YAY("4a5.bin"), // Snake taking a blow.
            FS_YAY("4a6.bin"), // Snake knocked out.
            FS_YAY("4a7.bin"), // Stone Guard walking.
            FS_YAY("4a8.bin"), // Stone Guard attacking.
            FS_YAY("4a9.bin"), // Stone Guard taking a blow.
            FS_YAY("4aa.bin"), // Stone Guard using shield.
            FS_YAY("4ab.bin"), // Stone Guard looking down frustrated. (Normally unused.)
            FS_YAY("4ac.bin"), // Stone Guard standing still.
            FS_YAY("4ad.bin"), // Dummy stone guard. (Unused.)
            FS_YAY("4ae.bin"), // Music Box idling.
            FS_LZX("4af.bin"), // Music Box's flickering lights.
            FS_YAY("4b0.bin"), // Music Box spinning around. (Normally unused.)
            FS_LZX("4b1.bin"), // Music Box's flickering musical note.
            FS_YAY("4b2.bin"), // Music Box taking a blow.
            FS_YAY("4b3.bin"), // Music Box spreading arms. (Normally unused.)
            FS_YAY("4b4.bin"), // T-12000 walking.
            FS_LZX("4b5.bin"), // Stone Guard's top half of body in stone.
            FS_YAY("4b6.bin"), // T-12000 twists body and opens mouth.
            FS_YAY("4b7.bin"), // T-12000 knocked out.
            FS_LZX("4b8.bin"), // Stone Guard's remaining body parts in stone.
            FS_YAY("4b9.bin"), // T-12000 taking a blow.
            FS_YAY("4ba.bin"), // T-12000 spreading arms and legs. (Normally unused.)
            FS_YAY("4bb.bin"), // Playing Card Knight walking.
            FS_YAY("4bc.bin"), // Playing Card Knight delivering a punch.
            FS_YAY("4bd.bin"), // Playing Card Knight taking a blow.
            FS_YAY("4be.bin"), // Playing Card Knight knocked out. (Normally unused.)
            FS_YAY("4bf.bin"), // Playing Card Knight raising arms in the air.
            FS_LZX("4c0.bin"), // Playing Card Knight's red eye.
            FS_LZX("4c1.bin"), // Playing Card Knight's green skin.
            FS_LZX("4c2.bin"), // Playing Card Knight's green club.
            FS_LZX("4c3.bin"), // Playing Card Knight's green eye.
            FS_LZX("4c4.bin"), // Playing Card Knight's red skin.
            FS_LZX("4c5.bin"), // Playing Card Knight's red heart.
            FS_LZX("4c6.bin"), // Playing Card Knight's blue eye.
            FS_LZX("4c7.bin"), // Playing Card Knight's yellow skin.
            FS_LZX("4c8.bin"), // Playing Card Knight's yellow diamond.
            FS_YAY("4c9.bin"), // Magician idling.
            FS_YAY("4ca.bin"), // Magician preparing wand.
            FS_YAY("4cb.bin"), // Magician taking a blow.
            FS_YAY("4cc.bin"), // Magician knocked out.
            FS_YAY("4cd.bin"), // Magician blown back.
            FS_YAY("4ce.bin"), // Spin Chip spinning.
            FS_YAY("4cf.bin"), // Spin Chip taking a blow.
            FS_YAY("4d0.bin"), // Spin Chip knocked out.
            FS_YAY("4d1.bin"), // Bomb the Cat walking.
            FS_YAY("4d2.bin"), // Bomb the Cat delivering a punch.
            FS_YAY("4d3.bin"), // Bomb the Cat running.
            FS_YAY("4d4.bin"), // Bomb the Cat knocked out.
            FS_YAY("4d5.bin"), // Bomb the Cat taking a blow.
            FS_YAY("4d6.bin"), // Bomb the Cat raising left side of body. (Normally unused.)
            FS_LZX("4d7.bin"), // Bomb the Cat's blinking eyes.
            FS_LZX("4d8.bin"), // Bomb the Cat's squinting eyes.
            FS_LZX("4d9.bin"), // Bomb the Cat's closed eyes.
            FS_LZX("4da.bin"), // Bomb the Cat's rolled eyes.
            FS_YAY("4db.bin"), // Ghost idling.
            FS_YAY("4dc.bin"), // Ghost sneaking.
            FS_YAY("4dd.bin"), // Ghost taking a blow.
            FS_YAY("4de.bin"), // Ghost inflating like a balloon. (Normally unused.)
            FS_LZX("4df.bin"), // Ghost's mischievous glare.
            FS_LZX("4e0.bin"), // Ghost's rolling eyes.
            FS_YAY("4e1.bin"), // Child Mare sitting.
            FS_YAY("4e2.bin"), // Child Mare running.
            FS_YAY("4e3.bin"), // Child Mare taking a blow.
            FS_YAY("4e4.bin"), // Child Mare getting up from the ground.
            FS_YAY("4e5.bin"), // Child Mare sitting back down.
            FS_YAY("4e6.bin"), // Child Mare knocked out.
            FS_YAY("4e7.bin"), // Child Mare flinching.
            FS_LZX("4e8.bin"), // Child Mare's freaked out face.
            FS_LZX("4e9.bin"), // Child Mare's upset face.
            FS_YAY("4ea.bin"), // Pteranodon flying.
            FS_YAY("4eb.bin"), // Pteranodon preparing wings.
            FS_YAY("4ec.bin"), // Pteranodon taking a blow.
            FS_YAY("4ed.bin"), // Pteranodon spreading wings.
            FS_LZX("4ee.bin"), // Pteranodon's eyes blinking.
            FS_LZX("4ef.bin"), // Pteranodon's rolled eyes.
            FS_YAY("4f0.bin"), // Bone Tank idling.
            FS_YAY("4f1.bin"), // Bone Tank vomiting.
            FS_YAY("4f2.bin"), // Bone Tank taking aim.
            FS_YAY("4f3.bin"), // Bone Tank taking a blow.
            FS_YAY("4f4.bin"), // Bone Tank twitching. (Normally unused.)
            FS_LZX("4f5.bin"), // Bone Tank's eyes glowing red.
            FS_YAY("4f6.bin"), // Ripper walking.
            FS_YAY("4f7.bin"), // Ripper jabbing knife.
            FS_YAY("4f8.bin"), // Ripper tossing.
            FS_YAY("4f9.bin"), // Ripper knocked out.
            FS_YAY("4fa.bin"), // Ripper taking a blow.
            FS_YAY("4fb.bin"), // Ripper with arms up.
            FS_YAY("4fc.bin"), // Crazy Biker idling.
            FS_YAY("4fd.bin"), // Crazy Biker wheelie driving.
            FS_YAY("4fe.bin"), // Crazy Biker taking a blow.
            FS_YAY("4ff.bin"), // Crazy Biker immediately on one wheel.
            FS_YAY("500.bin"), // Zombie stepping forward.
            FS_YAY("501.bin"), // Zombie munching.
            FS_YAY("502.bin"), // Zombie knocked out.
            FS_YAY("503.bin"), // Zombie falling over.
            FS_YAY("504.bin"), // Zombie getting up from the ground.
            FS_LZX("505.bin"), // Zombie's right pupil missing.
            FS_LZX("506.bin"), // Zombie's left pupil missing.
            FS_YAY("507.bin"), // BHB Soldier walking.
            FS_YAY("508.bin"), // BHB Soldier aiming & firing laser gun.
            FS_YAY("509.bin"), // BHB Soldier kicking.
            FS_YAY("50a.bin"), // BHB Soldier taking a blow.
            FS_YAY("50b.bin"), // BHB Soldier knocked out.
            FS_YAY("50c.bin"), // BHB Soldier flailing arms and legs.
            FS_YAY("50d.bin"), // BH-TYPE03 idling.
            FS_YAY("50e.bin"), // BH-TYPE03 swiping mechanical arms.
            FS_YAY("50f.bin"), // BH-TYPE03 preparing back weapons.
            FS_YAY("510.bin"), // BH-TYPE03 taking a blow.
            FS_YAY("511.bin"), // BH-TYPE03 leaning back. (Normally unused.)
            FS_YAY("512.bin"), // Spiritual Dog crouching.
            FS_YAY("513.bin"), // Spiritual Dog running.
            FS_YAY("514.bin"), // Spiritual Dog jumping.
            FS_YAY("515.bin"), // Spiritual Dog turning head & exhaling.
            FS_YAY("516.bin"), // Spiritual Dog taking a blow.
            FS_YAY("517.bin"), // Spiritual Dog knocked out. (Normally unused.)
            FS_LZX("518.bin"), // Spiritual Dog's red fur.
            FS_LZX("519.bin"), // Spiritual Dog's red body.
            FS_LZX("51a.bin"), // Spiritual Dog's red head.
            FS_YAY("51b.bin"), // Soul Eater idling.
            FS_YAY("51c.bin"), // Soul Eater swinging scythe.
            FS_YAY("51d.bin"), // Soul Eater pulling head back and lunging forward.
            FS_YAY("51e.bin"), // Soul Eater knocked out. (Normally unused.)
            FS_YAY("51f.bin"), // Soul Eater taking a blow.
            FS_LZX("520.bin"), // Soul Eater's eyes glowing. (Unused.)
            FS_YAY("521.bin"), // Road Roller running.
            FS_YAY("522.bin"), // Shadow Beast walking.
            FS_YAY("523.bin"), // Shadow Beast biting.
            FS_YAY("524.bin"), // Shadow Beast taking a blow.
            FS_YAY("525.bin"), // Shadow Beast opening mouth. (Normally unused.)
            FS_LZX("526.bin"), // Shadow Beast's glowing skin.
            FS_LZX("527.bin"), // Shadow Beast's rolled eyes.
            FS_YAY("528.bin"), // BH-TYPE04 idling.
            FS_YAY("529.bin"), // BH-TYPE04 taking a blow.
            FS_YAY("52a.bin"), // BH-TYPE04 picking up & tossing.
            FS_YAY("52b.bin"), // BH-TYPE04 leaning backward. (Normally unused.)
            FS_YAY("52c.bin"), // BH-TYPE04 leaning forward. (Normally unused.)
            FS_LZX("52d.bin"), // BH-TYPE04's flashing lights.
            FS_LZX("52e.bin"), // BH-TYPE04's flickering red eye.
            FS_YAY("52f.bin"), // Grab Pot opening tentacles.
            FS_LZX("530.bin"), // Stone Guard's bottom half of body in stone?
            FS_YAY("531.bin"), // Slot tile (needs to be animated).
            FS_YAY("532.bin"), // Lava puddle's larger growth animation.
            FS_YAY("533.bin"), // [A tiny block?]
            FS_YAY("534.bin"), // [A tiny block?]
            FS_YAY("535.bin"), // [A tiny block?]
            FS_YAY("536.bin"), // [A tiny block?]
            FS_YAY("537.bin"), // [A tiny block?]
            FS_YAY("538.bin"), // [A tiny block?]
            FS_YAY("539.bin"), // [A tiny block?]
            FS_YAY("53a.bin"), // [A tiny block?]
            FS_YAY("53b.bin"), // [A tiny block?]
            FS_YAY("53c.bin"), // [A tiny block?]
            FS_YAY("53d.bin"), // [A tiny block?]
            FS_YAY("53e.bin"), // [A tiny block?]
            FS_YAY("53f.bin"), // [A tiny block?]
            FS_YAY("540.bin"), // [A tiny block?]
            FS_YAY("541.bin"), // [A tiny block?]
            FS_YAY("542.bin"), // Bomber character.
            FS_YAY("543.bin"), // Standing.
            FS_YAY("544.bin"), // Running.
            FS_YAY("545.bin"), // Picking up from ground.
            FS_YAY("546.bin"), // Throwing.
            FS_YAY("547.bin"), // Carrying.
            FS_YAY("548.bin"), // Kicking.
            FS_YAY("549.bin"), // Deflected. (Normally unused.)
            FS_YAY("54a.bin"), // Knocked down.
            FS_YAY("54b.bin"), // Knocked out, head spinning around.
            FS_YAY("54c.bin"), // Climbing.
            FS_YAY("54d.bin"), // Climbing up.
            FS_YAY("54e.bin"), // Stomping the ground.
            FS_YAY("54f.bin"), // Taking a blow.
            FS_YAY("550.bin"), // Arms and legs spreading out.
            FS_YAY("551.bin"), // Jumping up from the ground.
            FS_YAY("552.bin"), // Dropping down on back.
            FS_YAY("553.bin"), // Loses balance, twitches.
            FS_YAY("554.bin"), // Legs spread out, holding with two hands.
            FS_YAY("555.bin"), // Stomping the ground, holding with two hands.
            FS_YAY("556.bin"), // Kicking, holding with two hands.
            FS_YAY("557.bin"), // Jumps for joy.
            FS_YAY("558.bin"), // Running, arms held low. (Unused.)
            FS_YAY("559.bin"), // Throws a low punch.
            FS_YAY("55a.bin"), // Throws a low kick.
            FS_YAY("55b.bin"), // Gathers strength and jumps vigorously.
            FS_LZX("55c.bin"), // Performing Hellfire.
            FS_YAY("55d.bin"), // On his right knee.
            FS_YAY("55e.bin"), // Standing with arms crossed.
            FS_YAY("55f.bin"), // Bracing self.
            FS_YAY("560.bin"), // Baelfael character.
            FS_YAY("561.bin"), // Behemos character.
            FS_YAY("562.bin"), // Ashtarth character.
            FS_YAY("563.bin"), // Zhael character.
            FS_YAY("564.bin"), // Molok character.
            FS_YAY("565.bin"), // Aims with right arm and fires.
            FS_YAY("566.bin"), // Takes two steps, raises right arm, and brings it forward.
            FS_YAY("567.bin"), // Grabs chest in pain.
            FS_YAY("568.bin"), // Swings his right arm swiftly.
            FS_YAY("569.bin"), // On his right knee.
            FS_YAY("56a.bin"), // Standing with arms crossed.
            FS_YAY("56b.bin"), // Dashing.
            FS_YAY("56c.bin"), // Throws arms up and forth.
            FS_YAY("56d.bin"), // Bracing self.
            FS_LZX("56e.bin"), // Performing Rave the Shadow.
            FS_YAY("56f.bin"), // On his right knee.
            FS_YAY("570.bin"), // Standing with arms crossed.
            FS_YAY("571.bin"), // Collapses to the ground.
            FS_YAY("572.bin"), // Pulls body back.
            FS_YAY("573.bin"), // Jumps up and strikes right hand.
            FS_YAY("574.bin"), // Jumps up, spins around, and tosses her left arm forward.
            FS_YAY("575.bin"), // Jumps with arms up, then strikes forcefully.
            FS_YAY("576.bin"), // Bracing self.
            FS_LZX("577.bin"), // Performing Thunderstrike.
            FS_YAY("578.bin"), // On her right knee.
            FS_YAY("579.bin"), // Left arm covers face and head nods slightly.
            FS_YAY("57a.bin"), // Heavyweight walking.
            FS_YAY("57b.bin"), // Heavyweight thrusting forward.
            FS_YAY("57c.bin"), // Heavyweight knocked out. (Normally unused.)
            FS_YAY("57d.bin"), // Heavyweight carrying. (Normally unused.)
            FS_YAY("57e.bin"), // Heavyweight throwing. (Normally unused.)
            FS_YAY("57f.bin"), // Heavyweight grabbing chest in pain.
            FS_YAY("580.bin"), // Heavyweight kicking. (Normally unused.)
            FS_YAY("581.bin"), // Heavyweight spreading arms and legs. (Normally unused.)
            FS_YAY("582.bin"), // Heavyweight pounding the ground.
            FS_YAY("583.bin"), // Heavyweight holds arm up and tosses.
            FS_YAY("584.bin"), // Heavyweight bracing self.
            FS_YAY("585.bin"), // Heavyweight performing Atlas Toss.
            FS_YAY("586.bin"), // Heavyweight uppercuts.
            FS_YAY("587.bin"), // Heavyweight standing with arms crossed.
            FS_YAY("588.bin"), // Heavyweight on his right knee.
            FS_YAY("589.bin"), // Zoniha character.
            FS_YAY("58a.bin"), // Jumps into the air with legs crossed, then tosses arms forward.
            FS_YAY("58b.bin"), // Skips, then pounds the ground.
            FS_YAY("58c.bin"), // Sliding right leg in a kick.
            FS_YAY("58d.bin"), // Jumps and hovers in the air.
            FS_LZX("58e.bin"), // Performing Supernova.
            FS_YAY("58f.bin"), // On her right knee.
            FS_YAY("590.bin"), // Arms at hips and bobbing head up & down.
            FS_YAY("591.bin"), // Bulzeeb character.
            FS_YAY("592.bin"), // Tossing arms forward.
            FS_YAY("593.bin"), // Right arm reaching up high.
            FS_YAY("594.bin"), // Swipes left arm low.
            FS_YAY("595.bin"), // Bracing self.
            FS_LZX("596.bin"), // Performing Dark Illusion.
            FS_YAY("597.bin"), // On his right knee.
            FS_YAY("598.bin"), // Tosses right arm across body.
            FS_YAY("599.bin"), // Rukifellth character (also used for animation).
            FS_YAY("59a.bin"), // Rukifellth's cape while clasping hands (animated).
            FS_YAY("59b.bin"), // Rukifellth bobbing head and shoulders.
            FS_YAY("59c.bin"), // Rukifellth's cape while bobbing (animated).
            FS_YAY("59d.bin"), // Rukifellth standing.
            FS_YAY("59e.bin"), // Rukifellth's cape while standing (animated).
            FS_YAY("59f.bin"), // Rukifellth walking.
            FS_YAY("5a0.bin"), // Rukifellth's cape while walking (animated).
            FS_YAY("5a1.bin"), // Rukifellth pointing finger.
            FS_YAY("5a2.bin"), // Rukifellth's cape while pointing finger (animated).
            FS_YAY("5a3.bin"), // Rukifellth attempting to turn body.
            FS_YAY("5a4.bin"), // Rukifellth's cape while turning body (animated).
            FS_YAY("5a5.bin"), // Rukifellth running. (Unused.)
            FS_YAY("5a6.bin"), // Rukifellth's cape while running (animated). (Unused.)
            FS_YAY("5a7.bin"), // Rukifellth dashing.
            FS_YAY("5a8.bin"), // Rukifellth's cape while dashing (animated).
            FS_YAY("5a9.bin"), // Rukifellth taking a blow.
            FS_YAY("5aa.bin"), // Rukifellth's cape while taking a blow (animated).
            FS_YAY("5ab.bin"), // Rukifellth kicking. (Normally unused.)
            FS_YAY("5ac.bin"), // Rukifellth's cape while kicking (animated). (Normally unused.)
            FS_YAY("5ad.bin"), // Rukifellth pounding both fists down in front.
            FS_YAY("5ae.bin"), // Rukifellth's cape while pounding both fists (animated). 
            FS_YAY("5af.bin"), // Rukifellth attempting to swing sword.
            FS_YAY("5b0.bin"), // Rukifellth's cape while swinging sword (animated).
            FS_YAY("5b1.bin"), // Rukifellth bracing self.
            FS_YAY("5b2.bin"), // Rukifellth's cape while bracing self (animated).
            FS_YAY("5b3.bin"), // Rukifellth falling to his right knee.
            FS_YAY("5b4.bin"), // Rukifellth's cape while falling to knees (animated).
            FS_YAY("5b5.bin"), // Rukifellth in the air with arms up.
            FS_YAY("5b6.bin"), // Rukifellth's cape while in the air (animated).
            FS_YAY("5b7.bin"), // Rukifellth performing Dark Victory.
            FS_YAY("5b8.bin"), // Rukifellth's cape while performing Dark Victory (animated).
            FS_LZX("5b9.bin"), // Rukifellth's sword.
            FS_LZX("5ba.bin"), // Rukifellth giving his red eye.
            FS_LZX("5bb.bin"), // White Bomber's neutral expression.
            FS_LZX("5bc.bin"), // Black Bomber's neutral expression.
            FS_LZX("5bd.bin"), // Red Bomber's neutral expression.
            FS_LZX("5be.bin"), // Blue Bomber's neutral expression.
            FS_LZX("5bf.bin"), // White Bomber's face when deflected/stunned.
            FS_LZX("5c0.bin"), // Black Bomber's face when deflected/stunned.
            FS_LZX("5c1.bin"), // Red Bomber's face when deflected/stunned.
            FS_LZX("5c2.bin"), // Blue Bomber's face when deflected/stunned.
            FS_LZX("5c3.bin"), // White Bomber's face when knocked out.
            FS_LZX("5c4.bin"), // Black Bomber's face when knocked out.
            FS_LZX("5c5.bin"), // Red Bomber's face when knocked out.
            FS_LZX("5c6.bin"), // Blue Bomber's face when knocked out.
            FS_LZX("5c7.bin"), // White Bomber's face while in pain.
            FS_LZX("5c8.bin"), // Black Bomber's face while in pain.
            FS_LZX("5c9.bin"), // Red Bomber's face while in pain.
            FS_LZX("5ca.bin"), // Blue Bomber's face while in pain.
            FS_LZX("5cb.bin"), // White Bomber's face when recovering.
            FS_LZX("5cc.bin"), // Black Bomber's face when recovering.
            FS_LZX("5cd.bin"), // Red Bomber's face when recovering.
            FS_LZX("5ce.bin"), // Blue Bomber's face when recovering.
            FS_LZX("5cf.bin"), // White Bomber's gleeful eyes. (Unused.)
            FS_LZX("5d0.bin"), // Black Bomber's gleeful eyes. (Unused.)
            FS_LZX("5d1.bin"), // Red Bomber's gleeful eyes. (Unused.)
            FS_LZX("5d2.bin"), // Blue Bomber's gleeful eyes. (Unused.)
            FS_LZX("5d3.bin"), // Bomberman's eyes slowly blinking.
            FS_LZX("5d4.bin"), // Bomberman's face when serious.
            FS_LZX("5d5.bin"), // Bomberman' face when jumping for joy.
            FS_LZX("5d6.bin"), // Bomberman's face when shrugging.
            FS_LZX("5d7.bin"), // Bomberman's upset face. (Unused.)
            FS_LZX("5d8.bin"), // Bomberman's face when in love.
            FS_LZX("5d9.bin"), // Bomberman's face when jumping enthusiastically.
            FS_LZX("5da.bin"), // Bomberman's angry face.
            FS_LZX("5db.bin"), // Bomberman's face under pressure.
            FS_LZX("5dc.bin"), // Bomberman's eyes closed.
            FS_LZX("5dd.bin"), // Bomberman's eyes squinting under pleasure.
            FS_LZX("5de.bin"), // Bomberman's face when recovering.
            FS_LZX("5df.bin"), // Bomberman's wink.
            FS_LZX("5e0.bin"), // Bomberman's eyes blinking in a pattern as if while trying to talk.
            FS_LZX("5e1.bin"), // Bomberman's face when in disbelief.
            FS_LZX("5e2.bin"), // Bomberman's eyes wide-open.
            FS_YAY("5e3.bin"), // Rukifellth attempting to swing sword downward.
            FS_YAY("5e4.bin"), // Rukifellth's cape while swinging sword downward.
            FS_LZX("5e5.bin"), // Bomberman's blank expression? (Unused.)
            FS_LZX("5e6.bin"), // Bomberman's blank expression? (Unused.)
            FS_LZX("5e7.bin"), // Bomberman's blank expression? (Unused.)
            FS_LZX("5e8.bin"), // Bomberman's blank expression? (Unused.)
            FS_LZX("5e9.bin"), // Bomberman's blank expression? (Unused.)
            FS_LZX("5ea.bin"), // Bomberman's blank expression? (Unused.)
            FS_YAY("5eb.bin"), // Monkey character.
            FS_YAY("5ec.bin"), // Platypus(?) character.
            FS_YAY("5ed.bin"), // Fox character.
            FS_YAY("5ee.bin"), // Party Girl(?) character.
            FS_YAY("5ef.bin"), // Humanoid Girl character.
            FS_YAY("5f0.bin"), // Panda(?) character.
            FS_YAY("5f1.bin"), // Wolf character.
            FS_YAY("5f2.bin"), // Bunny character.
            FS_YAY("5f3.bin"), // Bull character.
            FS_YAY("5f4.bin"), // Sword Boy character.
            FS_YAY("5f5.bin"), // Young Maid(?) character.
            FS_YAY("5f6.bin"), // Viking(?) character.
            FS_YAY("5f7.bin"), // Reaper character.
            FS_YAY("5f8.bin"), // Witch character.
            FS_YAY("5f9.bin"), // Knight character.
            FS_YAY("5fa.bin"), // Red King character.
            FS_YAY("5fb.bin"), // Green King character.
            FS_YAY("5fc.bin"), // Normal Pommy standing.
            FS_YAY("5fd.bin"), // Normal Pommy running.
            FS_YAY("5fe.bin"), // Normal Pommy knocked out.
            FS_YAY("5ff.bin"), // Normal Pommy attacking.
            FS_YAY("600.bin"), // Normal Pommy crouching.
            FS_YAY("601.bin"), // Normal Pommy tucking in.
            FS_YAY("602.bin"), // Normal Pommy jumping for joy.
            FS_LZX("603.bin"), // Normal Pommy's neutral expression.
            FS_LZX("604.bin"), // Normal Pommy's eyes closed.
            FS_LZX("605.bin"), // Normal Pommy's face while attacking.
            FS_LZX("606.bin"), // Normal Pommy's face while jumping for joy.
            FS_YAY("607.bin"), // Knuckle Pommy standing.
            FS_YAY("608.bin"), // Knuckle Pommy running.
            FS_YAY("609.bin"), // Knuckle Pommy knocked out.
            FS_YAY("60a.bin"), // Knuckle Pommy attacking.
            FS_YAY("60b.bin"), // Knuckle Pommy crouching.
            FS_YAY("60c.bin"), // Knuckle Pommy tucking in.
            FS_YAY("60d.bin"), // Knuckle Pommy jumping for joy.
            FS_LZX("60e.bin"), // Knuckle Pommy's neutral expression.
            FS_LZX("60f.bin"), // Knuckle Pommy's eyes closed.
            FS_LZX("610.bin"), // Knuckle Pommy's face while attacking.
            FS_LZX("611.bin"), // Knuckle Pommy's face while jumping for joy.
            FS_YAY("612.bin"), // Animal Pommy standing.
            FS_YAY("613.bin"), // Animal Pommy running.
            FS_YAY("614.bin"), // Animal Pommy knocked out.
            FS_YAY("615.bin"), // Animal Pommy attacking.
            FS_YAY("616.bin"), // Animal Pommy crouching.
            FS_YAY("617.bin"), // Animal Pommy tucking in.
            FS_YAY("618.bin"), // Animal Pommy jumping for joy.
            FS_LZX("619.bin"), // Animal Pommy's neutral expression.
            FS_LZX("61a.bin"), // Animal Pommy's eyes closed.
            FS_LZX("61b.bin"), // Animal Pommy's face while attacking.
            FS_LZX("61c.bin"), // Animal Pommy's face while jumping for joy.
            FS_YAY("61d.bin"), // Hammer Pommy standing.
            FS_YAY("61e.bin"), // Hammer Pommy running.
            FS_YAY("61f.bin"), // Hammer Pommy knocked out.
            FS_YAY("620.bin"), // Hammer Pommy attacking.
            FS_YAY("621.bin"), // Hammer Pommy crouching.
            FS_YAY("622.bin"), // Hammer Pommy tucking in.
            FS_YAY("623.bin"), // Hammer Pommy jumping for joy.
            FS_LZX("624.bin"), // Hammer Pommy's neutral expression.
            FS_LZX("625.bin"), // Hammer Pommy's eyes closed.
            FS_LZX("626.bin"), // Hammer Pommy's face while attacking.
            FS_LZX("627.bin"), // Hammer Pommy's face while jumping for joy.
            FS_YAY("628.bin"), // Magic Pommy floating.
            FS_YAY("629.bin"), // Magic Pommy flying.
            FS_YAY("62a.bin"), // Magic Pommy knocked out.
            FS_YAY("62b.bin"), // Magic Pommy attacking.
            FS_YAY("62c.bin"), // Magic Pommy crouching.
            FS_YAY("62d.bin"), // Magic Pommy tucking in.
            FS_YAY("62e.bin"), // Magic Pommy jumping for joy.
            FS_LZX("62f.bin"), // Magic Pommy's neutral expression.
            FS_LZX("630.bin"), // Magic Pommy's eyes closed.
            FS_LZX("631.bin"), // Magic Pommy's face while jumping for joy.
            FS_YAY("632.bin"), // Knight Pommy standing.
            FS_YAY("633.bin"), // Knight Pommy running.
            FS_YAY("634.bin"), // Knight Pommy knocked out.
            FS_YAY("635.bin"), // Knight Pommy attacking.
            FS_YAY("636.bin"), // Knight Pommy crouching.
            FS_YAY("637.bin"), // Knight Pommy tucking in.
            FS_YAY("638.bin"), // Knight Pommy jumping for joy.
            FS_YAY("639.bin"), // Claw Pommy standing.
            FS_YAY("63a.bin"), // Claw Pommy running.
            FS_YAY("63b.bin"), // Claw Pommy knocked out.
            FS_YAY("63c.bin"), // Claw Pommy attacking.
            FS_YAY("63d.bin"), // Claw Pommy crouching.
            FS_YAY("63e.bin"), // Claw Pommy tucking in.
            FS_YAY("63f.bin"), // Claw Pommy jumping for joy.
            FS_LZX("640.bin"), // Claw Pommy's neutral expression.
            FS_LZX("641.bin"), // Claw Pommy's eyes closed.
            FS_LZX("642.bin"), // Claw Pommy's face while attacking.
            FS_LZX("643.bin"), // Claw Pommy's face while jumping for joy.
            FS_YAY("644.bin"), // Devil Pommy floating.
            FS_YAY("645.bin"), // Devil Pommy flying.
            FS_YAY("646.bin"), // Devil Pommy knocked out.
            FS_YAY("647.bin"), // Devil Pommy attacking.
            FS_YAY("648.bin"), // Devil Pommy crouching.
            FS_YAY("649.bin"), // Devil Pommy tucking in.
            FS_YAY("64a.bin"), // Devil Pommy jumping for joy.
            FS_LZX("64b.bin"), // Devil Pommy's neutral expression.
            FS_LZX("64c.bin"), // Devil Pommy's eyes closed.
            FS_LZX("64d.bin"), // Devil Pommy's face while attacking.
            FS_LZX("64e.bin"), // Devil Pommy's face while jumping for joy.
            FS_YAY("64f.bin"), // Cat Pommy standing.
            FS_YAY("650.bin"), // Cat Pommy running.
            FS_YAY("651.bin"), // Cat Pommy knocked out.
            FS_YAY("652.bin"), // Cat Pommy attacking.
            FS_YAY("653.bin"), // Cat Pommy crouching.
            FS_YAY("654.bin"), // Cat Pommy tucking in.
            FS_YAY("655.bin"), // Cat Pommy jumping for joy.
            FS_LZX("656.bin"), // Cat Pommy's neutral expression.
            FS_LZX("657.bin"), // Cat Pommy's eyes closed.
            FS_LZX("658.bin"), // Cat Pommy's face while jumping for joy.
            FS_YAY("659.bin"), // Penguin Pommy standing.
            FS_YAY("65a.bin"), // Penguin Pommy running.
            FS_YAY("65b.bin"), // Penguin Pommy knocked out.
            FS_YAY("65c.bin"), // Penguin Pommy attacking.
            FS_YAY("65d.bin"), // Penguin Pommy crouching.
            FS_YAY("65e.bin"), // Penguin Pommy tucking in.
            FS_YAY("65f.bin"), // Penguin Pommy jumping for joy.
            FS_LZX("660.bin"), // Penguin Pommy's neutral expression.
            FS_LZX("661.bin"), // Penguin Pommy's eyes closed.
            FS_LZX("662.bin"), // Penguin Pommy's face while attacking.
            FS_LZX("663.bin"), // Penguin Pommy's face while jumping for joy.
            FS_YAY("664.bin"), // Bird Pommy floating.
            FS_YAY("665.bin"), // Bird Pommy flying.
            FS_YAY("666.bin"), // Bird Pommy knocked out.
            FS_YAY("667.bin"), // Bird Pommy attacking.
            FS_YAY("668.bin"), // Bird Pommy crouching.
            FS_YAY("669.bin"), // Bird Pommy tucking in.
            FS_YAY("66a.bin"), // Bird Pommy jumping for joy.
            FS_LZX("66b.bin"), // Bird Pommy's neutral expression.
            FS_LZX("66c.bin"), // Bird Pommy's eyes closed.
            FS_LZX("66d.bin"), // Bird Pommy's face while attacking.
            FS_LZX("66e.bin"), // Bird Pommy's face while jumping for joy.
            FS_YAY("66f.bin"), // Chicken Pommy standing.
            FS_YAY("670.bin"), // Chicken Pommy running.
            FS_YAY("671.bin"), // Chicken Pommy knocked out.
            FS_YAY("672.bin"), // Chicken Pommy attacking.
            FS_YAY("673.bin"), // Chicken Pommy crouching.
            FS_YAY("674.bin"), // Chicken Pommy tucking in.
            FS_YAY("675.bin"), // Chicken Pommy jumping for joy.
            FS_LZX("676.bin"), // Chicken Pommy's neutral expression.
            FS_LZX("677.bin"), // Chicken Pommy's eyes closed.
            FS_LZX("678.bin"), // Chicken Pommy's face while attacking.
            FS_LZX("679.bin"), // Chicken Pommy's face while jumping for joy.
            FS_YAY("67a.bin"), // Beast Pommy standing.
            FS_YAY("67b.bin"), // Beast Pommy running.
            FS_YAY("67c.bin"), // Beast Pommy knocked out.
            FS_YAY("67d.bin"), // Beast Pommy attacking.
            FS_YAY("67e.bin"), // Beast Pommy crouching.
            FS_YAY("67f.bin"), // Beast Pommy tucking in.
            FS_YAY("680.bin"), // Beast Pommy jumping for joy.
            FS_LZX("681.bin"), // Beast Pommy's neutral expression.
            FS_LZX("682.bin"), // Beast Pommy's eyes closed.
            FS_LZX("683.bin"), // Beast Pommy's face while attacking.
            FS_LZX("684.bin"), // Beast Pommy's face while jumping for joy.
            FS_YAY("685.bin"), // Dragon Pommy floating.
            FS_YAY("686.bin"), // Dragon Pommy flying.
            FS_YAY("687.bin"), // Dragon Pommy knocked out.
            FS_YAY("688.bin"), // Dragon Pommy attacking.
            FS_YAY("689.bin"), // Dragon Pommy crouching.
            FS_YAY("68a.bin"), // Dragon Pommy tucking in.
            FS_YAY("68b.bin"), // Dragon Pommy jumping for joy.
            FS_LZX("68c.bin"), // Dragon Pommy's neutral expression.
            FS_LZX("68d.bin"), // Dragon Pommy's eyes closed.
            FS_LZX("68e.bin"), // Dragon Pommy's face while attacking.
            FS_LZX("68f.bin"), // Dragon Pommy's face while jumping for joy.
            FS_YAY("690.bin"), // Dinosaur Pommy standing.
            FS_YAY("691.bin"), // Dinosaur Pommy running.
            FS_YAY("692.bin"), // Dinosaur Pommy knocked out.
            FS_YAY("693.bin"), // Dinosaur Pommy attacking.
            FS_YAY("694.bin"), // Dinosaur Pommy crouching.
            FS_YAY("695.bin"), // Dinosaur Pommy tucking in.
            FS_YAY("696.bin"), // Dinosaur Pommy jumping for joy.
            FS_LZX("697.bin"), // Dinosaur Pommy's neutral expression.
            FS_LZX("698.bin"), // Dinosaur Pommy's eyes closed.
            FS_LZX("699.bin"), // Dinosaur Pommy's face while attacking.
            FS_LZX("69a.bin"), // Dinosaur Pommy's face while jumping for joy.
            FS_YAY("69b.bin"), // Pixie Pommy floating.
            FS_YAY("69c.bin"), // Pixie Pommy flying.
            FS_YAY("69d.bin"), // Pixie Pommy knocked out.
            FS_YAY("69e.bin"), // Pixie Pommy attacking.
            FS_YAY("69f.bin"), // Pixie Pommy crouching.
            FS_YAY("6a0.bin"), // Pixie Pommy tucking in.
            FS_YAY("6a1.bin"), // Pixie Pommy jumping for joy.
            FS_YAY("6a2.bin"), // Pixie Pommy preparing magic.
            FS_LZX("6a3.bin"), // Pixie Pommy's neutral expression.
            FS_LZX("6a4.bin"), // Pixie Pommy's eyes closed.
            FS_LZX("6a5.bin"), // Pixie Pommy's face while jumping for joy.
            FS_YAY("6a6.bin"), // Shadow Pommy floating.
            FS_YAY("6a7.bin"), // Shadow Pommy flying.
            FS_YAY("6a8.bin"), // Shadow Pommy knocked out.
            FS_YAY("6a9.bin"), // Shadow Pommy attacking.
            FS_YAY("6aa.bin"), // Shadow Pommy crouching.
            FS_YAY("6ab.bin"), // Shadow Pommy tucking in.
            FS_YAY("6ac.bin"), // Shadow Pommy jumping for joy.
            FS_YAY("6ad.bin"), // Shadow Pommy preparing projectile attack.
            FS_LZX("6ae.bin"), // Shadow Pommy's neutral expression.
            FS_LZX("6af.bin"), // Shadow Pommy's eyes closed.
            FS_LZX("6b0.bin"), // Shadow Pommy's face while attacking.
            FS_LZX("6b1.bin"), // Shadow Pommy's face while jumping for joy.
            FS_LZX("6b2.bin"), // Shadow Pommy's face while attacking differently.
            FS_YAY("6b3.bin"), // Pommy egg (animated).
            FS_LZX("6b4.bin"), // Pommy egg's solid texture. 
            FS_YAY("6b5.bin"), // Pommy egg beginning to hatch.
            FS_LZX("6b6.bin"), // Pommy egg's cracking texture.
            FS_YAY("6b7.bin"), // Pommy egg bursting open.
            FS_LZX("6b8.bin"), // Pommy egg's cracked texture.
            FS_YAY("6b9.bin"), // Lilith character.
            FS_YAY("6ba.bin"), // Vibrates and falls over.
            FS_YAY("6bb.bin"), // Prepares for takeoff and flips.
            FS_YAY("6bc.bin"), // Does a front flip. (Unused.)
            FS_YAY("6bd.bin"), // Flips and sticks the landing. (Unused.)
            FS_YAY("6be.bin"), // Gets up sluggishly.
            FS_YAY("6bf.bin"), // Overhand arm toss.
            FS_YAY("6c0.bin"), // Arm swipes to the right.
            FS_YAY("6c1.bin"), // Strikes with right arm.
            FS_YAY("6c2.bin"), // Tucking in.
            FS_LZX("6c3.bin"), // Close combat.
            FS_YAY("6c4.bin"), // Waves hello.
            FS_YAY("6c5.bin"), // On her right knee.
            FS_YAY("6c6.bin"), // On the ground limping.
            FS_LZX("6c7.bin"), // Lilith's face while under attack.
            FS_LZX("6c8.bin"), // Lilith's face relieved of stress.
            FS_LZX("6c9.bin"), // Lilith's face looks strained.
            FS_LZX("6ca.bin"), // Lilith's face while greeting.
            FS_LZX("6cb.bin"), // Lilith's eyes slowly blink twice.
            FS_LZX("6cc.bin"), // Lilith's eyes halfway-closed and blinking.
            FS_YAY("6cd.bin"), // Normal Pommy character.
            FS_YAY("6ce.bin"), // Knuckle Pommy character.
            FS_YAY("6cf.bin"), // Animal Pommy character.
            FS_YAY("6d0.bin"), // Hammer Pommy character.
            FS_YAY("6d1.bin"), // Magic Pommy character.
            FS_YAY("6d2.bin"), // Knight Pommy character.
            FS_YAY("6d3.bin"), // Claw Pommy character.
            FS_YAY("6d4.bin"), // Devil Pommy character.
            FS_YAY("6d5.bin"), // Cat Pommy character.
            FS_YAY("6d6.bin"), // Penguin Pommy character.
            FS_YAY("6d7.bin"), // Bird Pommy character.
            FS_YAY("6d8.bin"), // Chicken Pommy character.
            FS_YAY("6d9.bin"), // Beast Pommy character.
            FS_YAY("6da.bin"), // Dragon Pommy character.
            FS_YAY("6db.bin"), // Dinosaur Pommy character.
            FS_YAY("6dc.bin"), // Pixie Pommy character.
            FS_YAY("6dd.bin"), // Shadow Pommy character.
            FS_YAY("6de.bin"), // Alt Pommy egg. (Unused.)
            FS_YAY("6df.bin"), // Putting down.
            FS_YAY("6e0.bin"), // [A tiny block?]
            FS_YAY("6e1.bin"), // [A tiny block?]
            FS_YAY("6e2.bin"), // [A tiny block?]
            FS_YAY("6e3.bin"), // [A tiny block?]
            FS_YAY("6e4.bin"), // [A tiny block?]
            FS_YAY("6e5.bin"), // [A tiny block?]
            FS_YAY("6e6.bin"), // [A tiny block?]
            FS_YAY("6e7.bin"), // [A tiny block?]
            FS_YAY("6e8.bin"), // [A tiny block?]
            FS_YAY("6e9.bin"), // [A tiny block?]
            FS_YAY("6ea.bin"), // [A tiny block?]
            FS_YAY("6eb.bin"), // [A tiny block?]
            FS_YAY("6ec.bin"), // [A tiny block?]
            FS_YAY("6ed.bin"), // [A tiny block?]
            FS_YAY("6ee.bin"), // [A tiny block?]
            FS_YAY("6ef.bin"), // [A tiny block?]
            FS_YAY("6f0.bin"), // [A tiny block?]
            FS_YAY("6f1.bin"), // [A tiny block?]
            FS_YAY("6f2.bin"), // [A tiny block?]
            FS_YAY("6f3.bin"), // [A tiny block?]
            FS_YAY("6f4.bin"), // [A tiny block?]
            FS_YAY("6f5.bin"), // Fire Bomb.
            FS_YAY("6f6.bin"), // Ice Bomb.
            FS_YAY("6f7.bin"), // Hurricane Bomb.
            FS_YAY("6f8.bin"), // Earth Bomb.
            FS_YAY("6f9.bin"), // Lightning Bomb.
            FS_YAY("6fa.bin"), // Light Bomb.
            FS_YAY("6fb.bin"), // Gravity Bomb.
            FS_LZX("6fc.bin"), // Gravity Bomb's flashing red light.
            FS_YAY("6fd.bin"), // [A tiny block?]
            FS_YAY("6fe.bin"), // [A tiny block?]
            FS_YAY("6ff.bin"), // [A tiny block?]
            FS_YAY("700.bin"), // [A tiny block?]
            FS_YAY("701.bin"), // [A tiny block?]
            FS_YAY("702.bin"), // [A tiny block?]
            FS_YAY("703.bin"), // [A tiny block?]
            FS_YAY("704.bin"), // [A tiny block?]
            FS_YAY("705.bin"), // [A tiny block?]
            FS_YAY("706.bin"), // [A tiny block?]
            FS_YAY("707.bin"), // [A tiny block?]
            FS_YAY("708.bin"), // [A tiny block?]
            FS_YAY("709.bin"), // Fire Up item (animated).
            FS_YAY("70a.bin"), // Bomb Up item (animated).
            FS_YAY("70b.bin"), // Skate item (animated).
            FS_YAY("70c.bin"), // Steel Shoe item (animated).
            FS_YAY("70d.bin"), // Glove item (animated).
            FS_YAY("70e.bin"), // Bomb Kick item (animated).
            FS_YAY("70f.bin"), // Remote Control item (animated).
            FS_YAY("710.bin"), // Heart item (animated).
            FS_YAY("711.bin"), // Invincibility item (animated). (Unused?)
            FS_YAY("712.bin"), // 10g item (animated).
            FS_YAY("713.bin"), // 50g item (animated).
            FS_YAY("714.bin"), // 100g item (animated).
            FS_YAY("715.bin"), // 200g item (animated).
            FS_YAY("716.bin"), // Carrot item (animated).
            FS_YAY("717.bin"), // Cherry item (animated).
            FS_YAY("718.bin"), // Apple item (animated).
            FS_YAY("719.bin"), // Strawberry item (animated).
            FS_YAY("71a.bin"), // Corn item (animated).
            FS_YAY("71b.bin"), // Banana item (animated).
            FS_YAY("71c.bin"), // Grape item (animated).
            FS_YAY("71d.bin"), // Melon item (animated).
            FS_YAY("71e.bin"), // Hot dog (or Yakitori again?) item (animated).
            FS_YAY("71f.bin"), // Yakitori item (animated).
            FS_YAY("720.bin"), // Sausage item (animated).
            FS_YAY("721.bin"), // Chicken item (animated).
            FS_YAY("722.bin"), // Beef item (animated).
            FS_YAY("723.bin"), // Ham item (animated).
            FS_YAY("724.bin"), // Turkey item (animated).
            FS_YAY("725.bin"), // Caveman Meat item (animated).
            FS_YAY("726.bin"), // Candy item (animated).
            FS_YAY("727.bin"), // Lollipop item (animated).
            FS_YAY("728.bin"), // Ice cream item (animated).
            FS_YAY("729.bin"), // Cotton candy(?) item (animated).
            FS_YAY("72a.bin"), // Cake slice item (animated).
            FS_YAY("72b.bin"), // Flan item (animated).
            FS_YAY("72c.bin"), // Sundae item (animated).
            FS_YAY("72d.bin"), // Whole Cake item (animated).
            FS_YAY("72e.bin"), // Key item (animated).
            FS_YAY("72f.bin"), // Skull item (animated). (Unused?)
            FS_YAY("730.bin"), // Evil item (animated). (Unused?)
            FS_YAY("731.bin"), // Custom Part item (animated).
            FS_LZX("732.bin"), // Fire Up graphic.
            FS_LZX("733.bin"), // Bomb Up graphic.
            FS_LZX("734.bin"), // Skate graphic.
            FS_LZX("735.bin"), // Steel Shoe graphic.
            FS_LZX("736.bin"), // Glove graphic.
            FS_LZX("737.bin"), // Bomb Kick graphic.
            FS_LZX("738.bin"), // Remote Control graphic.
            FS_LZX("739.bin"), // Invincibility graphic.
            FS_LZX("73a.bin"), // Heart graphic. (Unused?)
            FS_LZX("73b.bin"), // Skull graphic.
            FS_LZX("73c.bin"), // Evil graphic.
            FS_LZX("73d.bin"), // Custom Head Part graphic.
            FS_LZX("73e.bin"), // Custom Body Part graphic.
            FS_LZX("73f.bin"), // Custom Arm Part graphic.
            FS_LZX("740.bin"), // Custom Leg Part graphic.
            FS_LZX("741.bin"), // Fire Down graphic.
            FS_LZX("742.bin"), // Bomb Down graphic.
            FS_LZX("743.bin"), // Full Fire graphic.
            FS_YAY("744.bin"), // [A tiny block?]
            FS_YAY("745.bin"), // [A tiny block?]
            FS_YAY("746.bin"), // [A tiny block?]
            FS_YAY("747.bin"), // [A tiny block?]
            FS_YAY("748.bin"), // [A tiny block?]
            FS_YAY("749.bin"), // [A tiny block?]
            FS_YAY("74a.bin"), // [A tiny block?]
            FS_YAY("74b.bin"), // [A tiny block?]
            FS_YAY("74c.bin"), // [A tiny block?]
            FS_YAY("74d.bin"), // [A tiny block?]
            FS_YAY("74e.bin"), // [A tiny block?]
            FS_YAY("74f.bin"), // [A tiny block?]
            FS_YAY("750.bin"), // [A tiny block?]
            FS_YAY("751.bin"), // [A tiny block?]
            FS_YAY("752.bin"), // [A tiny block?]
            FS_YAY("753.bin"), // [A tiny block?]
            FS_YAY("754.bin"), // [A tiny block?]
            FS_YAY("755.bin"), // [A tiny block?]
            FS_YAY("756.bin"), // [A tiny block?]
            FS_YAY("757.bin"), // [A tiny block?]
            FS_YAY("758.bin"), // [A tiny block?]
            FS_YAY("759.bin"), // [A tiny block?]
            FS_YAY("75a.bin"), // [A tiny block?]
            FS_YAY("75b.bin"), // [A tiny block?]
            FS_YAY("75c.bin"), // [A tiny block?]
            FS_YAY("75d.bin"), // [A tiny block?]
            FS_YAY("75e.bin"), // [A tiny block?]
            FS_YAY("75f.bin"), // Dizziness stars (animated).
            FS_YAY("760.bin"), // Flame burst (needs to be animated).
            FS_YAY("761.bin"), // Smoke cloud (needs to be animated).
            FS_YAY("762.bin"), // Gray cloud. (Unused.)
            FS_YAY("763.bin"), // Bursting triangles (animated). (Unused.)
            FS_YAY("764.bin"), // Blue sparkle.
            FS_YAY("765.bin"), // Blue, electric bulb (needs to be animated).
            FS_YAY("766.bin"), // Electricity dispersion (needs to be animated).
            FS_YAY("767.bin"), // Sword slash (needs to be animated).
            FS_YAY("768.bin"), // Green energy barrier (needs to be animated). (Unused.)
            FS_YAY("769.bin"), // Iceberg.
            FS_YAY("76a.bin"), // Brown bubble.
            FS_YAY("76b.bin"), // Fire spawn.
            FS_YAY("76c.bin"), // Lava splash.
            FS_YAY("76d.bin"), // Lava bubble.
            FS_YAY("76e.bin"), // Lava bulge.
            FS_YAY("76f.bin"), // Bomb-bonk.
            FS_YAY("770.bin"), // Water splash.
            FS_YAY("771.bin"), // Yellowish circle.
            FS_YAY("772.bin"), // Red light.
            FS_YAY("773.bin"), // Blade slash.
            FS_YAY("774.bin"), // Blown wind.
            FS_YAY("775.bin"), // Ice shattering (animated).
            FS_YAY("776.bin"), // Dark energy (animated).
            FS_YAY("777.bin"), // Summon Horror bird (animated).
            FS_YAY("778.bin"), // Bulzeeb's jetpack flames (animated).
            FS_YAY("779.bin"), // Dark hole (needs to be animated).
            FS_YAY("77a.bin"), // Burnt ground spot.
            FS_YAY("77b.bin"), // Lightning strike (needs to be animated).
            FS_YAY("77c.bin"), // Lightning blow to the ground (needs to be animated).
            FS_YAY("77d.bin"), // Ball of lightning (needs to be animated).
            FS_YAY("77e.bin"), // Baelfael's exhaled fire breath.
            FS_YAY("77f.bin"), // Blaster light.
            FS_YAY("780.bin"), // Faint glow. (Normally unused.)
            FS_YAY("781.bin"), // Shockwave burst.
            FS_YAY("782.bin"), // Blaster splatter (needs to be animated).
            FS_YAY("783.bin"), // Blue laser beam (also for glow's animation). (Normally unused.)
            FS_YAY("784.bin"), // Wind slicing (needs to be animated).
            FS_YAY("785.bin"), // Light burst (needs to be animated).
            FS_YAY("786.bin"), // Unfinished element (needs to be animated)? 
            FS_YAY("787.bin"), // Laser beam.
            FS_YAY("788.bin"), // Water dispersion (needs to be animated).
            FS_YAY("789.bin"), // Water ripple (needs to be animated). (Normally unused.)
            FS_YAY("78a.bin"), // Triple water ripples (needs to be animated).
            FS_YAY("78b.bin"), // Tossed knife (needs to be animated).
            FS_YAY("78c.bin"), // True Justice swipe (animated).
            FS_YAY("78d.bin"), // Sphere of light's air rings (animated).
            FS_YAY("78e.bin"), // Sphere of light (animated).
            FS_YAY("78f.bin"), // [A tiny block?]
            FS_YAY("790.bin"), // [A tiny block?]
            FS_YAY("791.bin"), // Pulsating shield (animated).
            FS_YAY("792.bin"), // Dislodged horn (animated).
            FS_YAY("793.bin"), // Star.
            FS_YAY("794.bin"), // Star bursting (animated).
            FS_YAY("795.bin"), // Yellow sparkle.
            FS_YAY("796.bin"), // Fumes (needs to be animated).
            FS_YAY("797.bin"), // Steam cloud (needs to be animated).
            FS_YAY("798.bin"), // Fiery blast.
            FS_YAY("799.bin"), // Fiery ring.
            FS_YAY("79a.bin"), // White sparkle/glitter.
            FS_YAY("79b.bin"), // Earthy blast (needs to be animated).
            FS_YAY("79c.bin"), // Heavy explosion (needs to be animated).
            FS_YAY("79d.bin"), // [A tiny block?]
            FS_YAY("79e.bin"), // [A tiny block?]
            FS_YAY("79f.bin"), // [A tiny block?]
            FS_YAY("7a0.bin"), // Large sparkle (animated).
            FS_YAY("7a1.bin"), // Warp point (needs to be animated).
            FS_YAY("7a2.bin"), // Various sword slashes (animated).
            FS_YAY("7a3.bin"), // Flame Wave (needs to be animated).
            FS_YAY("7a4.bin"), // Shadowy sphere.
            FS_YAY("7a5.bin"), // Twister (animated).
            FS_YAY("7a6.bin"), // Violent impact (needs to be animated).
            FS_YAY("7a7.bin"), // Gathering light toward the ground (animated).
            FS_YAY("7a8.bin"), // Gathering light (animated).
            FS_YAY("7a9.bin"), // Stony blast (animated). (Normally unused.)
            FS_YAY("7aa.bin"), // Giant lightning strike.
            FS_YAY("7ab.bin"), // Chaos Blade sword.
            FS_YAY("7ac.bin"), // Chaos Blade's purple shine (needs to be animated).
            FS_YAY("7ad.bin"), // Sword slashing (animated).
            FS_YAY("7ae.bin"), // Slashes (animated).
            FS_YAY("7af.bin"), // Vibrant red explosion (animated). (Unused.)
            FS_YAY("7b0.bin"), // Glass shattering (animated).
            FS_YAY("7b1.bin"), // Light burst's surrounding glow.
            FS_YAY("7b2.bin"), // Freeze blast (animated). (Normally unused.)
            FS_YAY("7b3.bin"), // Wind slashes (animated).
            FS_YAY("7b4.bin"), // Yellow confetti (animated).
            FS_YAY("7b5.bin"), // Big bomb's light ring (animated).
            FS_YAY("7b6.bin"), // Black substance (needs to be animated). (Normally unused.)
            FS_YAY("7b7.bin"), // Energy suction (animated). (Nomrally unused.)
            FS_YAY("7b8.bin"), // Energy development (animated). (Normally unused.)
            FS_YAY("7b9.bin"), // Finishing light (animated). (Normally unused.)
            FS_YAY("7ba.bin"), // Dumbbell.
            FS_YAY("7bb.bin"), // Ring of light.
            FS_YAY("7bc.bin"), // Spinning beam of light (animated). (Normally unused.)
            FS_YAY("7bd.bin"), // Yellowish, glowing cube (needs to be animated). (Normally unused.)
            FS_YAY("7be.bin"), // Light development (animated). (Normally unused.)
            FS_YAY("7bf.bin"), // Glowing starlight (animated). (Normally unused.)
            FS_YAY("7c0.bin"), // Brief, circling wind low to the ground (animated).
            FS_YAY("7c1.bin"), // Violent cyclone (animated).
            FS_YAY("7c2.bin"), // Shockwaves.
            FS_LZX("7c3.bin"), // Flame burst's 2D animation.
            FS_LZX("7c4.bin"), // Black smoke cloud's 2D animation.
            FS_LZX("7c5.bin"), // White smoke cloud's 2D animation.
            FS_LZX("7c6.bin"), // Blue, electric bulb's 2D animation.
            FS_LZX("7c7.bin"), // Electricity dispersion's 2D animation.
            FS_LZX("7c8.bin"), // Sword slash's alternating 2D animation. (Unused.)
            FS_LZX("7c9.bin"), // Green energy barrier's dissolving 2D animation. (Unused.)
            FS_LZX("7ca.bin"), // Dark hole's 2D animation.
            FS_LZX("7cb.bin"), // Lightning's 2D animation.
            FS_LZX("7cc.bin"), // Lightning blow's (to the ground) 2D animation.
            FS_LZX("7cd.bin"), // Ball of lightning's 2D animation.
            FS_LZX("7ce.bin"), // Blaster splatter's 2D animation.
            FS_LZX("7cf.bin"), // Blue laser beam's 2D animation. (Normally unused.)
            FS_LZX("7d0.bin"), // Wind slicing's 2D animation.
            FS_LZX("7d1.bin"), // Light burst's 2D animation.
            FS_LZX("7d2.bin"), // Water dispersion's 2D animation.
            FS_LZX("7d3.bin"), // Water ripple's 2D animation. (Normally unused.)
            FS_LZX("7d4.bin"), // Triple ripples' 2D animation.
            FS_LZX("7d5.bin"), // Green knife's flashing 2D animation.
            FS_LZX("7d6.bin"), // Dislodged horn's flickering 2D animation.
            FS_LZX("7d7.bin"), // Steam fumes' 2D animation.
            FS_LZX("7d8.bin"), // Steam cloud's 2D animation.
            FS_LZX("7d9.bin"), // Earthy blast's 2D animation.
            FS_LZX("7da.bin"), // Heavy explosion's 2D animation.
            FS_LZX("7db.bin"), // Shining white light's 2D animation.
            FS_LZX("7dc.bin"), // Shining red light's 2D animation.
            FS_LZX("7dd.bin"), // Shining green light's 2D animation.
            FS_LZX("7de.bin"), // Green warp point's 2D animation.
            FS_LZX("7df.bin"), // Short fumes' 2D animation.
            FS_LZX("7e0.bin"), // Flame Wave's 2D animation.
            FS_LZX("7e1.bin"), // Violent impact's 2D animation.
            FS_LZX("7e2.bin"), // Chaos Blade's shining 2D animation.
            FS_LZX("7e3.bin"), // Blue warp point's 2D animation.
            FS_LZX("7e4.bin"), // Light burst's blackness 2D animation. (Normally unused.)
            FS_LZX("7e5.bin"), // Yellowish, glowing cube's flickering 2D animation. (Normally unused.)
            FS_LZX("7e6.bin"), // Flare knife's flashing 2D animation.
            FS_YAY("7e7.bin"), // [A tiny block?]
            FS_YAY("7e8.bin"), // [A tiny block?]
            FS_YAY("7e9.bin"), // [A tiny block?]
            FS_LZX("7ea.bin"), // Black substance's 2D animation. (Normally unused.)
            FS_YAY("7eb.bin"), // [A tiny block?]
            FS_LZX("7ec.bin"), // Energy development's undulating 2D animation. (Normally unused.)
            FS_LZX("7ed.bin"), // Custom Bomberman text file.
            FS_LZX("7ee.bin"), // Normal text file?
            FS_LZX("7ef.bin"), // Planet select text file.
            FS_LZX("7f0.bin"), // Battle Mode text file.
            FS_LZX("7f1.bin"), // System text file.
            FS_LZX("7f2.bin"), // All text symbols?
            FS_LZX("7f3.bin"), // All text characters?
            FS_LZX("7f4.bin"), // Alcatraz stage settings.
            FS_LZX("7f5.bin"), // Aquanet stage settings.
            FS_LZX("7f6.bin"), // Horizon stage settings.
            FS_LZX("7f7.bin"), // Starlight stage settings.
            FS_LZX("7f8.bin"), // Neverland stage settings.
            FS_LZX("7f9.bin"), // Epikyur stage settings.
            FS_LZX("7fa.bin"), // Thantos stage settings.
            FS_LZX("7fb.bin"), // Warship Noah stage settings.
            FS_LZX("7fc.bin"), // Unused stage settings.
            FS_LZX("7fd.bin"), // Battle Mode stage settings.
            FS_LZX("7fe.bin"), // Alcatraz camera settings.
            FS_LZX("7ff.bin"), // Aquanet camera settings.
            FS_LZX("800.bin"), // Horizon camera settings.
            FS_LZX("801.bin"), // Starlight camera settings.
            FS_LZX("802.bin"), // Neverland camera settings.
            FS_LZX("803.bin"), // Epikyur camera settings.
            FS_LZX("804.bin"), // Thantos camera settings.
            FS_LZX("805.bin"), // Warship Noah camera settings.
            FS_LZX("806.bin"), // Unused camera settings.
            FS_LZX("807.bin"), // Battle Mode camera settings.
            FS_LZX("808.bin"), // Test Map 1 (area code).
            FS_LZX("809.bin"), // Test Map 2 (area code).
            FS_LZX("80a.bin"), // Normal Battle Stage (area code).
            FS_LZX("80b.bin"), // Park Battle Stage (area code).
            FS_LZX("80c.bin"), // Tropical Island Battle Stage (area code).
            FS_LZX("80d.bin"), // Miniature City Battle Stage (area code).
            FS_LZX("80e.bin"), // Abandoned Mine Battle Stage (area code).
            FS_LZX("80f.bin"), // Desert Shrine Battle Stage (area code).
            FS_LZX("810.bin"), // Altar Battle Stage (area code).
            FS_LZX("811.bin"), // Rope Bridge Battle Stage (area code).
            FS_LZX("812.bin"), // Castle Garden Battle Stage (area code).
            FS_LZX("813.bin"), // Unfinished area code. (Unused.)
            FS_LZX("814.bin"), // Cloud Castle Battle Stage (area code).
            FS_LZX("815.bin"), // River Battle Stage (area code).
            FS_LZX("816.bin"), // Royal Palace Battle Stage (area code).
            FS_LZX("817.bin"), // Casino Battle Stage (area code).
            FS_LZX("818.bin"), // Underground Maze Battle Stage (area code).
            FS_LZX("819.bin"), // Underground River Battle Stage (area code).
            FS_LZX("81a.bin"), // Ivory Halls Battle Stage (area code).
            FS_LZX("81b.bin"), // Crystal Palace Battle Stage (area code).
            FS_LZX("81c.bin"), // Hanging Gardens Battle Stage (area code).
            FS_LZX("81d.bin"), // Plains Battle Stage (area code).
            FS_LZX("81e.bin"), // Floating Halls Battle Stage (area code).
            FS_LZX("81f.bin"), // Unfinished area code.
            FS_LZX("820.bin"), // Ranch Battle Stage (area code).
            FS_LZX("821.bin"), // Ranch Battle Stage (area code).
            FS_LZX("822.bin"), // Neverland, Entry Point (area code).
            FS_LZX("823.bin"), // Neverland, Bonus Room (area code).
            FS_LZX("824.bin"), // Neverland, Through the Line of Fire (area code).
            FS_LZX("825.bin"), // Neverland, Intersection (area code).
            FS_LZX("826.bin"), // Neverland, Conveyor Belts (area code).
            FS_LZX("827.bin"), // Neverland, Potholes (area code).
            FS_LZX("828.bin"), // Neverland, Carrier Works (area code).
            FS_LZX("829.bin"), // Neverland, Switch Room (area code).
            FS_LZX("82a.bin"), // Neverland, Bridge Room (area code).
            FS_LZX("82b.bin"), // Neverland, Cage Room (area code).
            FS_LZX("82c.bin"), // Neverland, Safe Point (area code).
            FS_LZX("82d.bin"), // Neverland, Underground Corridor (area code).
            FS_LZX("82e.bin"), // Neverland, Warehousing (area code).
            FS_LZX("82f.bin"), // Neverland, Furnace (area code).
            FS_LZX("830.bin"), // Neverland, First Passageway (area code).
            FS_LZX("831.bin"), // Neverland, Second Passageway (area code).
            FS_LZX("832.bin"), // Neverland, Landing Point (area code).
            FS_LZX("833.bin"), // Neverland, Third Passageway (area code).
            FS_LZX("834.bin"), // Neverland, Gravity Generator Room (area code).
            FS_LZX("835.bin"), // Aquanet, Around the Moat (Starting Point) (area code).
            FS_LZX("836.bin"), // Aquanet, First Room (area code).
            FS_LZX("837.bin"), // Aquanet, Second Room (area code).
            FS_LZX("838.bin"), // Aquanet, Third Room (area code).
            FS_LZX("839.bin"), // Aquanet, Swimming Pool Spa (area code).
            FS_LZX("83a.bin"), // Aquanet, Behind the Moat (area code).
            FS_LZX("83b.bin"), // Aquanet, Beyond the Moat (area code).
            FS_LZX("83c.bin"), // Aquanet, Elevator Hub (area code).
            FS_LZX("83d.bin"), // Aquanet, Hidden Balcony (area code).
            FS_LZX("83e.bin"), // Aquanet, Water Channels (area code).
            FS_LZX("83f.bin"), // Aquanet, Fountain Room (area code).
            FS_LZX("840.bin"), // Aquanet, Secret Room 3 (area code).
            FS_LZX("841.bin"), // Aquanet, Elevator Stopping Point (area code).
            FS_LZX("842.bin"), // Aquanet, Behemos' Lair (area code).
            FS_LZX("843.bin"), // Aquanet, To the Tower (area code).
            FS_LZX("844.bin"), // Aquanet, Tower 1F (area code).
            FS_LZX("845.bin"), // Aquanet, Tower 2F (area code).
            FS_LZX("846.bin"), // Aquanet, Tower 3F (area code).
            FS_LZX("847.bin"), // Aquanet, Gravity Generator Room (area code).
            FS_LZX("848.bin"), // Alcatraz, Prison (area code).
            FS_LZX("849.bin"), // Alcatraz, Sewer Entrance (area code).
            FS_LZX("84a.bin"), // Alcatraz, Twisted Sewers (area code).
            FS_LZX("84b.bin"), // Alcatraz, Security Room A (area code).
            FS_LZX("84c.bin"), // Alcatraz, Security Room B (area code).
            FS_LZX("84d.bin"), // Alcatraz, Sewage Disposal (area code).
            FS_LZX("84e.bin"), // Alcatraz, Through the Pipe (area code).
            FS_LZX("84f.bin"), // Alcatraz, Prison Bridge (area code).
            FS_LZX("850.bin"), // Alcatraz, Pipe Room A (area code).
            FS_LZX("851.bin"), // Alcatraz, Pipe Room B (area code).
            FS_LZX("852.bin"), // Alcatraz, Final Defense Unit (area code).
            FS_LZX("853.bin"), // Alcatraz, Gravity Generator Room (area code).
            FS_LZX("854.bin"), // Horizon, First Intersection (area code).
            FS_LZX("855.bin"), // Horizon, Eastern Tower (area code).
            FS_LZX("856.bin"), // Horizon, Push-Block Trial (area code).
            FS_LZX("857.bin"), // Horizon, Leading Road (area code).
            FS_LZX("858.bin"), // Horizon, First Trial (area code).
            FS_LZX("859.bin"), // Horizon, Second Trial (area code).
            FS_LZX("85a.bin"), // Horizon, Resting Point (area code).
            FS_LZX("85b.bin"), // Horizon, Floating Temple (Second Intersection) (area code).
            FS_LZX("85c.bin"), // Horizon, Twin Bridges (area code).
            FS_LZX("85d.bin"), // Horizon, Final Deposit (area code).
            FS_LZX("85e.bin"), // Horizon, Last Route (area code).
            FS_LZX("85f.bin"), // Horizon, Fourth Trial (area code).
            FS_LZX("860.bin"), // Horizon, Secret Room 1 (area code).
            FS_LZX("861.bin"), // Horizon, Secret Room 2 (area code).
            FS_LZX("862.bin"), // Horizon, Third Trial (area code).
            FS_LZX("863.bin"), // Horizon, Last Trial (area code).
            FS_LZX("864.bin"), // Horizon, Gravity Generator Room (area code).
            FS_LZX("865.bin"), // Starlight, Parking Lot (area code).
            FS_LZX("866.bin"), // Starlight, Closed Road (area code).
            FS_LZX("867.bin"), // Starlight, Fountain Square (area code).
            FS_LZX("868.bin"), // Starlight, Small Inlet (area code).
            FS_LZX("869.bin"), // Starlight, Alleyway (area code).
            FS_LZX("86a.bin"), // Starlight, Casino Entrance (area code).
            FS_LZX("86b.bin"), // Starlight, Casino Lobby (area code).
            FS_LZX("86c.bin"), // Starlight, Betting Room (area code).
            FS_LZX("86d.bin"), // Starlight, Slots Room (area code).
            FS_LZX("86e.bin"), // Starlight, Waiting Room (area code).
            FS_LZX("86f.bin"), // Starlight, Stage Area (area code).
            FS_LZX("870.bin"), // Starlight, Lookout Point (area code).
            FS_LZX("871.bin"), // Starlight, Wheel of Fortune (area code).
            FS_LZX("872.bin"), // Starlight, Gravity Generator Room (area code).
            FS_LZX("873.bin"), // Epikyur, Entrance (area code).
            FS_LZX("874.bin"), // Epikyur, Center Fountain (area code).
            FS_LZX("875.bin"), // Epikyur, Tattered Bridge (area code).
            FS_LZX("876.bin"), // Epikyur, Misaligned Bridge (area code).
            FS_LZX("877.bin"), // Epikyur, Haunted House (Yard) (area code).
            FS_LZX("878.bin"), // Epikyur, Haunted House (Lobby) (area code).
            FS_LZX("879.bin"), // Epikyur, Haunted House (Spike Traps) (area code).
            FS_LZX("87a.bin"), // Epikyur, Haunted House (Mirror Room) (area code).
            FS_LZX("87b.bin"), // Epikyur, Haunted House (Spike Pit) (area code).
            FS_LZX("87c.bin"), // Epikyur, Haunted House (Storeroom) (area code).
            FS_LZX("87d.bin"), // Epikyur, History Museum (Prehistoric Puzzle) (area code).
            FS_LZX("87e.bin"), // Epikyur, History Museum (Military Puzzle) (area code).
            FS_LZX("87f.bin"), // Epikyur, History Museum (Showcase Room) (area code).
            FS_LZX("880.bin"), // Epikyur, Castle of Time (First Room) (area code).
            FS_LZX("881.bin"), // Epikyur, Castle of Time (Second Room) (area code).
            FS_LZX("882.bin"), // Epikyur, Coaster Body 1 (area code).
            FS_LZX("883.bin"), // Epikyur, Haunted House (Coaster Start) (area code).
            FS_LZX("884.bin"), // Epikyur, Coaster Body 2 (area code).
            FS_LZX("885.bin"), // Epikyur, Coaster Finish (area code).
            FS_LZX("886.bin"), // Epikyur, Gravity Generator Room (area code).
            FS_LZX("887.bin"), // Thantos, Starting Point (area code).
            FS_LZX("888.bin"), // Thantos, Streets (area code).
            FS_LZX("889.bin"), // Thantos, Up the Ladder (area code).
            FS_LZX("88a.bin"), // Thantos, Wrecked Lot (area code).
            FS_LZX("88b.bin"), // Thantos, Battery Ambush (area code).
            FS_LZX("88c.bin"), // Thantos, Battle for the Battery (area code).
            FS_LZX("88d.bin"), // Thantos, Compactor (Secret Room 2) (area code).
            FS_LZX("88e.bin"), // Thantos, Subway Entrance (area code).
            FS_LZX("88f.bin"), // Thantos, Aboard the Subway (area code).
            FS_LZX("890.bin"), // Thantos, Subway Destination (area code).
            FS_LZX("891.bin"), // Thantos, Supposed Dead End (area code).
            FS_LZX("892.bin"), // Thantos, The Crevice (area code).
            FS_LZX("893.bin"), // Thantos, Voltage Storage Unit (area code).
            FS_LZX("894.bin"), // Thantos, Secret Room 3 (area code).
            FS_LZX("895.bin"), // Thantos, Hangout (area code).
            FS_LZX("896.bin"), // Thantos, Secret Room 1 (area code).
            FS_LZX("897.bin"), // Thantos, Back Alley (area code).
            FS_LZX("898.bin"), // Thantos, Hidden Territory (area code).
            FS_LZX("899.bin"), // Thantos, Gravity Generator Room (area code).
            FS_LZX("89a.bin"), // Warship Noah, Runway (area code).
            FS_LZX("89b.bin"), // Warship Noah, Sliding Floors (West) (area code).
            FS_LZX("89c.bin"), // Warship Noah, Sliding Floors (East) (area code).
            FS_LZX("89d.bin"), // Warship Noah, Security Barrier Control Room (area code).
            FS_LZX("89e.bin"), // Warship Noah, Card Key Room (area code).
            FS_LZX("89f.bin"), // Warship Noah, Storage Area (area code).
            FS_LZX("8a0.bin"), // Warship Noah, Bridge Lift (area code).
            FS_LZX("8a1.bin"), // Warship Noah, Western Defensive Unit (area code).
            FS_LZX("8a2.bin"), // Warship Noah, Left Engine Room (area code).
            FS_LZX("8a3.bin"), // Warship Noah, Eastern Defensive Unit (area code).
            FS_LZX("8a4.bin"), // Warship Noah, Right Engine Room (area code).
            FS_LZX("8a5.bin"), // Warship Noah, Engine Defense Mechanism Control Room (area code).
            FS_LZX("8a6.bin"), // Warship Noah, Generator Room (area code).
            FS_LZX("8a7.bin"), // Warship Noah, Main Reactor (area code).
            FS_LZX("8a8.bin"), // Warship Noah, Power Shaft (area code).
            FS_LZX("8a9.bin"), // Alcatraz, Secret Room 1 (area code).
            FS_LZX("8aa.bin"), // Starlight, Hidden Room (area code).
            FS_LZX("8ab.bin"), // Neverland, Secret Room 1 (area code).
            FS_LZX("8ac.bin"), // Epikyur, Haunted House (Hidden Room) (area code).
            FS_LZX("8ad.bin"), // Warship Noah, Secret Room (area code). (Normally unused.)
            FS_LZX("8ae.bin"), // Aquanet, Secret Room 1 (area code).
            FS_LZX("8af.bin"), // Alcatraz, Cell Room (area code).
            FS_LZX("8b0.bin"), // Tutorial Area (area code).
            FS_LZX("8b1.bin"), // Thantos, Top of the Tower (area code).
            FS_LZX("8b2.bin"), // Warship Noah, Sthertoth? (area code).
            FS_LZX("8b3.bin"), // Alcatraz, Secret Room 2 (area code).
            FS_LZX("8b4.bin"), // Aquanet, Secret Room 2 (area code).
            FS_LZX("8b5.bin"), // Neverland, Secret Room 2 (area code).
            FS_LZX("8b6.bin"), // Alcatraz, BHB Army Ship Storeroom (area code).
            FS_LZX("8b7.bin"), // Alcatraz, Unused Secret Room (area code)?
            FS_LZX("8b8.bin"), // Warship Noah, Below Headquarters (area code).
            FS_LZX("8b9.bin"), // Warship Noah, Central Command Room (area code).
            FS_LZX("8ba.bin"), // Warship Noah, The Top (area code).
            FS_LZX("8bb.bin"), // Warship Noah, The Heart (area code).
            FS_LZX("8bc.bin"), // Warship Noah, The God of Chaos (area code).
            FS_LZX("8bd.bin"), // Warship Noah, The Angel of Light & Shadow (area code).
            FS_LZX("8be.bin"), // Model shading type 1.
            FS_LZX("8bf.bin"), // Model shading type 2.
            FS_LZX("8c0.bin"), // Model shading type 3.
            FS_LZX("8c1.bin"), // Model shading type 4.
            FS_LZX("8c2.bin"), // Model shading type 5.
            FS_LZX("8c3.bin"), // Model shading type 6.
            FS_LZX("8c4.bin"), // Model shading type 7.
            FS_LZX("8c5.bin"), // Model shading type 8.
            FS_LZX("8c6.bin"), // Model shading type 9. (Unused.)
            FS_LZX("8c7.bin"), // Model shading type 10.
            FS_LZX("8c8.bin"), // Model shading type 11.
            FS_LZX("8c9.bin"), // Model shading type 12.
            FS_LZX("8ca.bin"), // Model shading type 13.
            FS_LZX("8cb.bin"), // Model shading type 14.
            FS_LZX("8cc.bin"), // Model shading type 15.
            FS_LZX("8cd.bin"), // Model shading type 16.
            FS_LZX("8ce.bin"), // Model shading type 17.
            FS_LZX("8cf.bin"), // Model shading type 18.
            FS_LZX("8d0.bin"), // Model shading type 19.
            FS_LZX("8d1.bin"), // Model shading type 20.
            FS_LZX("8d2.bin"), // Model shading type 21.
            FS_LZX("8d3.bin"), // Model shading type 22.
            FS_LZX("8d4.bin"), // Model shading type 23.
            FS_LZX("8d5.bin"), // Model shading type 24.
            FS_LZX("8d6.bin"), // Model shading type 25.
            FS_LZX("8d7.bin"), // Model shading type 26.
            FS_LZX("8d8.bin"), // Model shading type 27.
            FS_LZX("8d9.bin"), // Model shading type 28.
            FS_LZX("8da.bin"), // Model shading type 29.
            FS_LZX("8db.bin"), // Model shading type 30.
            FS_LZX("8dc.bin"), // Model shading type 31.
            FS_LZX("8dd.bin"), // Model shading type 32.
            FS_LZX("8de.bin"), // Model shading type 33.
            FS_LZX("8df.bin"), // Model shading type 34.
            FS_LZX("8e0.bin"), // Model shading type 35.
            FS_LZX("8e1.bin"), // Model shading type 36.
            FS_LZX("8e2.bin"), // Model shading type 37.
            FS_LZX("8e3.bin"), // Model shading type 38.
            FS_LZX("8e4.bin"), // Model shading type 39.
            FS_LZX("8e5.bin"), // Model shading type 40.
            FS_LZX("8e6.bin"), // Model shading type 41.
            FS_LZX("8e7.bin"), // Model shading type 42.
            FS_LZX("8e8.bin"), // Model shading type 43.
            FS_LZX("8e9.bin"), // Model shading type 44.
            FS_LZX("8ea.bin"), // Model shading type 45. (Unused.)
            FS_LZX("8eb.bin"), // Model shading type 46. (Unused.)
            FS_LZX("8ec.bin"), // Model shading type 47. (Unused.)
            FS_LZX("8ed.bin"), // Model shading type 48.
            FS_LZX("8ee.bin"), // Model shading type 49. (Unused.)
            FS_LZX("8ef.bin"), // Model shading type 50. (Unused.)
            FS_LZX("8f0.bin"), // Model shading type 51. (Unused.)
            FS_LZX("8f1.bin"), // Model shading type 52. (Unused.)
            FS_LZX("8f2.bin"), // Model shading type 53.
            FS_LZX("8f3.bin"), // Model shading type 54.
            FS_LZX("8f4.bin"), // Model shading type 55.
            FS_LZX("8f5.bin"), // Model shading type 56
            FS_LZX("8f6.bin"), // Model shading type 57.
            FS_LZX("8f7.bin"), // Model shading type 58. (Unused.)
            FS_LZX("8f8.bin"), // Model shading type 59. (Unused.)
            FS_LZX("8f9.bin"), // Model shading type 60. (Unused.)
            FS_LZX("8fa.bin"), // Model shading type 61. (Unused.)
            FS_YAY("8fb.bin"), // Alcatraz 3D map.
            FS_YAY("8fc.bin"), // Aquanet 3D map.
            FS_YAY("8fd.bin"), // Horizon 3D map.
            FS_YAY("8fe.bin"), // Starlight 3D map.
            FS_YAY("8ff.bin"), // Neverland 3D map.
            FS_YAY("900.bin"), // Epikyur 3D map.
            FS_YAY("901.bin"), // Thantos 3D map.
            FS_YAY("902.bin"), // Warship Noah 3D map.
            FS_LZX("903.bin"), // Orange character.*
            FS_LZX("904.bin"), // White character.*
            FS_LZX("905.bin"), // Filled heart symbol.*
            FS_LZX("906.bin"), // Empty heart symbol.*
            FS_LZX("907.bin"), // Remote Control symbol.*
            FS_LZX("908.bin"), // Fire level symbol.*
            FS_LZX("909.bin"), // Bomb level symbol.*
            FS_LZX("90a.bin"), // Fire Stone symbol.*
            FS_LZX("90b.bin"), // Water Stone symbol.*
            FS_LZX("90c.bin"), // Wind Stone symbol.*
            FS_LZX("90d.bin"), // Earth Stone symbol.*
            FS_LZX("90e.bin"), // Lightning Stone symbol.*
            FS_LZX("90f.bin"), // Light Stone symbol.*
            FS_LZX("910.bin"), // Shadow Stone symbol.*
            FS_LZX("911.bin"), // Gold symbol.*
            FS_LZX("912.bin"), // White Bomber icon.*
            FS_LZX("913.bin"), // Black Bomber icon.*
            FS_LZX("914.bin"), // Red Bomber icon.*
            FS_LZX("915.bin"), // Blue Bomber icon.*
            FS_LZX("916.bin"), // Red King icon.*
            FS_LZX("917.bin"), // Green King icon.*
            FS_LZX("918.bin"), // List of Hiragana Japanese characters.* (Normally unused.)
            FS_LZX("919.bin"), // List of Katakana Japanese characters.* (Normally unused.)
            FS_LZX("91a.bin"), // List of English characters.*
            FS_LZX("91b.bin"), // List of symbols.*
            FS_LZX("91c.bin"), // "READY" text.* 
            FS_LZX("91d.bin"), // "HURRY UP" text.*
            FS_LZX("91e.bin"), // "TIME UP" text.*
            FS_LZX("91f.bin"), // "DRAW" and "GAME" texts.*
            FS_LZX("920.bin"), // "WIN" text.*
            FS_LZX("921.bin"), // "LOSE" text.*
            FS_LZX("922.bin"), // Number and letter (for the player who won the round).*
            FS_LZX("923.bin"), // "PAUSE" text.*
            FS_LZX("924.bin"), // "TEAM" text.*
            FS_LZX("925.bin"), // Green King & flag.*
            FS_LZX("926.bin"), // Red King & flag.*
            FS_LZX("927.bin"), // "GAMEOVER" text.*
            FS_LZX("928.bin"), // "CONTINUE" text.*
            FS_LZX("929.bin"), // Game note background.*
            FS_LZX("92a.bin"), // "Tutorial" text.*
            FS_LZX("92b.bin"), // "Pommy Control" text.*
            FS_LZX("92c.bin"), // "CPU" text.*
            FS_LZX("92d.bin"), // "2P" text.*
            FS_LZX("92e.bin"), // "Story Mode" text.*
            FS_LZX("92f.bin"), // "Battle Mode" text.*
            FS_LZX("930.bin"), // "Custom Bomberman" text.*
            FS_LZX("931.bin"), // "Options" text.*
            FS_LZX("932.bin"), // Sky background.*
            FS_LZX("933.bin"), // Bomberman file images.*
            FS_LZX("934.bin"), // Brown arrow.*
            FS_LZX("935.bin"), // Empty green bar? (No graphic.)*
            FS_LZX("936.bin"), // Green bar.*
            FS_LZX("937.bin"), // Silver arrow.*
            FS_LZX("938.bin"), // "PUSH START TO RETURN" text.*
            FS_LZX("939.bin"), // "Bomberman 64 The Second Attack!" title image.*
            FS_LZX("93a.bin"), // Merchant Ship Frontier background.*
            FS_LZX("93b.bin"), // Shop display window frame.*
            FS_LZX("93c.bin"), // Small orange arrow.*
            FS_LZX("93d.bin"), // Shop tabs' text.*
            FS_LZX("93e.bin"), // Merchant Ship Frontier worker image with Cowboy's clothing.*
            FS_LZX("93f.bin"), // Merchant Ship Frontier worker image without Cowboy's clothing.*
            FS_LZX("940.bin"), // "SHOP" text.*
            FS_LZX("941.bin"), // White selection cursor image.*
            FS_LZX("942.bin"), // Battle Mode background tile.*
            FS_LZX("943.bin"), // "Battle" text.*
            FS_LZX("944.bin"), // "Type" text.*
            FS_LZX("945.bin"), // "Select" text.*
            FS_LZX("946.bin"), // "Character" text.*
            FS_LZX("947.bin"), // "Options" text.*
            FS_LZX("948.bin"), // "Stage" text.*
            FS_LZX("949.bin"), // "L Button Z Button CHALLENGE" and "R Button OPTIONS" images.*
            FS_LZX("94a.bin"), // "NOTHING" text.*
            FS_LZX("94b.bin"), // Player-number text.*
            FS_LZX("94c.bin"), // Red selection cursor.*
            FS_LZX("94d.bin"), // Trophy (gold).*
            FS_LZX("94e.bin"), // Trophy (silver).*
            FS_LZX("94f.bin"), // Trophy (bronze).*
            FS_LZX("950.bin"), // Survival box image.*
            FS_LZX("951.bin"), // King & Knights box image.*
            FS_LZX("952.bin"), // Score Attack box image.*
            FS_LZX("953.bin"), // Key Trial box image.*
            FS_LZX("954.bin"), // Battle Royal box image.*
            FS_LZX("955.bin"), // Question mark box image.*
            FS_LZX("956.bin"), // Monkey icon.*
            FS_LZX("957.bin"), // Platypus icon.*
            FS_LZX("958.bin"), // Fox icon.*
            FS_LZX("959.bin"), // Party Girl icon.*
            FS_LZX("95a.bin"), // Human Girl icon.*
            FS_LZX("95b.bin"), // Panda icon.*
            FS_LZX("95c.bin"), // Wolf icon.*
            FS_LZX("95d.bin"), // Bunny icon.*
            FS_LZX("95e.bin"), // Bull icon.*
            FS_LZX("95f.bin"), // Swordsman icon.*
            FS_LZX("960.bin"), // Maid icon.*
            FS_LZX("961.bin"), // Viking icon.*
            FS_LZX("962.bin"), // Reaper icon.*
            FS_LZX("963.bin"), // Witch icon.*
            FS_LZX("964.bin"), // Knight icon.*
            FS_LZX("965.bin"), // Alcatraz planet image.*
            FS_LZX("966.bin"), // Aquanet planet image.*
            FS_LZX("967.bin"), // Horizon planet image.*
            FS_LZX("968.bin"), // Starlight planet image.*
            FS_LZX("969.bin"), // Neverland planet image.*
            FS_LZX("96a.bin"), // Epikyur planet image.*
            FS_LZX("96b.bin"), // Thantos planet image.*
            FS_LZX("96c.bin"), // Warship Noah image.*
            FS_LZX("96d.bin"), // Black hole image.*
            FS_LZX("96e.bin"), // Merchant Ship Frontier image.*
            FS_LZX("96f.bin"), // Green dot.*
            FS_LZX("970.bin"), // "World Select" text.*
            FS_LZX("971.bin"), // World Select legend text.*
            FS_LZX("972.bin"), // "Members" text.*
            FS_LZX("973.bin"), // "VICTORY" text.*
            FS_LZX("974.bin"), // Kings & flags.*
            FS_LZX("975.bin"), // "VS" text.*
            FS_LZX("976.bin"), // "© 2000 HUDSON SOFT" text.*
            FS_LZX("977.bin"), // "Custom" text.*
            FS_LZX("978.bin"), // "Data" text.*
            FS_LZX("979.bin"), // Custom Bomber background tile.*
            FS_LZX("97a.bin"), // Custom Part icons.*
            FS_LZX("97b.bin"), // Custom Data icons.*
            FS_LZX("97c.bin"), // Blank gray square...* (Unused.)
            FS_LZX("97d.bin"), // Language tabs' image.* (Normally unused.)
            FS_LZX("97e.bin"), // "Confirm" text icon.*
            FS_LZX("97f.bin"), // "Name" image.*
            FS_LZX("980.bin"), // Planet heads-up display image.*
            FS_LZX("981.bin"), // Outer light's 2D animation.
            FS_LZX("982.bin"), // Central light's 2D animation.
            FS_LZX("983.bin"), // Inner light's 2D animation.
            FS_YAY("984.bin"), // Bronze trophy. (Unused.)
            FS_YAY("985.bin"), // Silver trophy. (Unused.)
            FS_YAY("986.bin"), // Golden trophy. (Unused.)
            FS_YAY("987.bin"), // Disco light.
            FS_YAY("988.bin"), // Colorful lights (needs to be animated).
            FS_YAY("989.bin"), // Small disco ball.
            FS_YAY("98a.bin"), // Winner's podium.
            FS_YAY("98b.bin"), // Golden crown.
            FS_LZX("98c.bin"), // HUDSON publisher display.*
            FS_LZX("98d.bin"), // Full Helmet icon.*
            FS_LZX("98e.bin"), // Warrior's Armor icon.*
            FS_LZX("98f.bin"), // Gauntlet icon.*
            FS_LZX("990.bin"), // Armored Boots icon.*
            FS_LZX("991.bin"), // Plate icon.*
            FS_LZX("992.bin"), // Frog Suit icon.*
            FS_LZX("993.bin"), // Webbed Gloves icon.*
            FS_LZX("994.bin"), // Frog Feet icon.*
            FS_LZX("995.bin"), // Helmet icon.*
            FS_LZX("996.bin"), // Biker Suit icon.*
            FS_LZX("997.bin"), // Leather Gloves icon.*
            FS_LZX("998.bin"), // Leather Boots icon.*
            FS_LZX("999.bin"), // Pointed Hat icon.*
            FS_LZX("99a.bin"), // Clown Suit icon.*
            FS_LZX("99b.bin"), // White Gloves icon.*
            FS_LZX("99c.bin"), // Clown Shoes icon.*
            FS_LZX("99d.bin"), // Robot Head icon.*
            FS_LZX("99e.bin"), // Robot Suit icon.*
            FS_LZX("99f.bin"), // Robot Arm icon.*
            FS_LZX("9a0.bin"), // Robot Boots icon.*
            FS_LZX("9a1.bin"), // Cat Ears icon.*
            FS_LZX("9a2.bin"), // Cat Suit icon.*
            FS_LZX("9a3.bin"), // Cat Gloves icon.*
            FS_LZX("9a4.bin"), // Cat Slippers icon.*
            FS_LZX("9a5.bin"), // Mohawk icon.*
            FS_LZX("9a6.bin"), // Leather Jacket icon.*
            FS_LZX("9a7.bin"), // Brass Knuckles icon.*
            FS_LZX("9a8.bin"), // Boots icon.*
            FS_LZX("9a9.bin"), // Cowboy Hat icon.*
            FS_LZX("9aa.bin"), // Cowboy Vest icon.*
            FS_LZX("9ab.bin"), // Cowboy Gloves icon.*
            FS_LZX("9ac.bin"), // Cowboy Boots icon.*
            FS_LZX("9ad.bin"), // Topknot icon.*
            FS_LZX("9ae.bin"), // Kimono icon.*
            FS_LZX("9af.bin"), // Sword icon.*
            FS_LZX("9b0.bin"), // Sandals icon.*
            FS_LZX("9b1.bin"), // Beret icon.*
            FS_LZX("9b2.bin"), // Artist's Smock icon.*
            FS_LZX("9b3.bin"), // Paint Set icon.*
            FS_LZX("9b4.bin"), // Slippers icon.*
            FS_LZX("9b5.bin"), // Beard icon.*
            FS_LZX("9b6.bin"), // Tank Body icon.*
            FS_LZX("9b7.bin"), // Fan icon.*
            FS_LZX("9b8.bin"), // Bigfoot Shoes icon.*
            FS_LZX("9b9.bin"), // Headgear icon.*
            FS_LZX("9ba.bin"), // Elephant Suit icon.*
            FS_LZX("9bb.bin"), // Gloves icon.*
            FS_LZX("9bc.bin"), // Kung Fu Shoes icon.*
            FS_LZX("9bd.bin"), // Gold Helmet icon.*
            FS_LZX("9be.bin"), // Gold Suit icon.*
            FS_LZX("9bf.bin"), // Gold Gloves icon.*
            FS_LZX("9c0.bin"), // Gold Boots icon.*
            FS_LZX("9c1.bin"), // Ribbon icon.*
            FS_LZX("9c2.bin"), // Pink Dress icon.*
            FS_LZX("9c3.bin"), // Slash Claws icon.*
            FS_LZX("9c4.bin"), // High Heels icon.*
            FS_LZX("9c5.bin"), // Bald Head icon.*
            FS_LZX("9c6.bin"), // Apron icon.*
            FS_LZX("9c7.bin"), // Hand Puppets icon.*
            FS_LZX("9c8.bin"), // Pommy Slippers icon.*
            FS_LZX("9c9.bin"), // Rabbit Ears icon.*
            FS_LZX("9ca.bin"), // Duck Suit icon.*
            FS_LZX("9cb.bin"), // Drill icon.*
            FS_LZX("9cc.bin"), // Sneakers icon.*
            FS_YAY("9cd.bin"), // Sthertoth object.
            FS_YAY("9ce.bin"), // Sthertoth standing.
            FS_YAY("9cf.bin"), // Sthertoth walking.
            FS_YAY("9d0.bin"), // Sthertoth kneeling.
            FS_YAY("9d1.bin"), // Sthertoth dashing & slashing.
            FS_YAY("9d2.bin"), // Sthertoth tossing underhand.
            FS_YAY("9d3.bin"), // Sthertoth taking a blow (or freezing).
            FS_YAY("9d4.bin"), // Sthertoth jumping with legs kicked back.
            FS_YAY("9d5.bin"), // Sthertoth jumping with legs raised.
            FS_YAY("9d6.bin"), // Sthertoth aerial tossing.
            FS_YAY("9d7.bin"), // Sthertoth flailing arms.
            FS_LZX("9d8.bin"), // Sthertoth's eyes flickering.
            FS_LZX("9d9.bin"), // Sthertoth's eyes glowing.
            FS_YAY("9da.bin"), // Sthertoth's tail? (Unused.)
            FS_YAY("9db.bin"), // Fallen blue crate.
            FS_YAY("9dc.bin"), // Fallen triangular, metallic block.
            FS_YAY("9dd.bin"), // Fallen giant, riveted metal block.
            FS_YAY("9de.bin"), // Alt glass shield (animated). (Unused?)
            FS_RAW("9df.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9e0.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9e1.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9e2.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9e3.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9e4.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9e5.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9e6.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9e7.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9e8.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9e9.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9ea.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9eb.bin"), // (Unknown. Messes up the code.)
            FS_RAW("9ec.bin"), // (Unknown. Messes up the code.)
            FS_YAY("9ed.bin"), // God of Chaos object.
            FS_YAY("9ee.bin"), // God of Chaos standing.
            FS_YAY("9ef.bin"), // God of Chaos walking.
            FS_YAY("9f0.bin"), // God of Chaos stepping forward and moving around.
            FS_YAY("9f1.bin"), // God of Chaos pounding right fist to the ground.
            FS_YAY("9f2.bin"), // God of Chaos looking up with arms spread wide.
            FS_YAY("9f3.bin"), // God of Chaos clasping claws together.
            FS_YAY("9f4.bin"), // God of Chaos taking a blow.
            FS_LZX("9f5.bin"), // God of Chaos' jewel turning red and then flashing.
            FS_LZX("9f6.bin"), // God of Chaos' jewel turning blue and then flashing.
            FS_YAY("9f7.bin"), // God of Chaos' tail? (Unused.)
            FS_LZX("9f8.bin"), // God of Chaos sticking fists into the ground one-by-one and out.
            FS_YAY("9f9.bin"), // White bubble briefly grown (animated).
            FS_YAY("9fa.bin"), // White bubble bulging slightly.
            FS_YAY("9fb.bin"), // White ring.
            FS_YAY("9fc.bin"), // Rushing blue beam (animated, but needs effect).
            FS_YAY("9fd.bin"), // White beam.
            FS_LZX("9fe.bin"), // High-contrast electric sphere's 2D animation.
            FS_LZX("9ff.bin"), // Rushing blue beam's flickering 2D animation.
            FS_YAY("a00.bin"), // High-contrast electric sphere growing (animated, but needs effect).
            FS_YAY("a01.bin"), // High-contrast electric sphere (needs to be animated).
            FS_RAW("a02.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a03.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a04.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a05.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a06.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a07.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a08.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a09.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a0a.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a0b.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a0c.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a0d.bin"), // (Unknown. Messes up the code.)
            FS_YAY("a0e.bin"), // The Angel object.
            FS_YAY("a0f.bin"), // The Angel idling.
            FS_YAY("a10.bin"), // The Angel guarding quickly.
            FS_YAY("a11.bin"), // The Angel swinging staff.
            FS_YAY("a12.bin"), // The Angel raising staff up into the air.
            FS_YAY("a13.bin"), // The Angel raising staff and sticking it into the ground.
            FS_YAY("a14.bin"), // The Angel slamming staff to the ground.
            FS_YAY("a15.bin"), // The Angel spinning staff with one hand then sticking it into the ground with both.
            FS_LZX("a16.bin"), // The Angel's jewel turning red.
            FS_LZX("a17.bin"), // The Angel's jewel turning brown.
            FS_LZX("a18.bin"), // The Angel's jewel turning green.
            FS_LZX("a19.bin"), // The Angel's jewel turning purple(?).
            FS_LZX("a1a.bin"), // The Angel's jewel turning white.
            FS_LZX("a1b.bin"), // The Angel's jewel turning blue.
            FS_LZX("a1c.bin"), // The Angel's jewel turning pink(?).
            FS_YAY("a1d.bin"), // The Angel guarding with staff.
            FS_YAY("a1e.bin"), // The Angel lunging staff forward.
            FS_YAY("a1f.bin"), // The Angel pulling staff back.
            FS_YAY("a20.bin"), // The Angel preparing to guard.
            FS_YAY("a21.bin"), // The Angel exposing weak point.
            FS_YAY("a22.bin"), // The Angel taking a blow.
            FS_RAW("a23.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a24.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a25.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a26.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a27.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a28.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a29.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a2a.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a2b.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a2c.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a2d.bin"), // (Unknown. Messes up the code.)
            FS_YAY("a2e.bin"), // Glowing fireball.
            FS_YAY("a2f.bin"), // Fiery blow (much like the one from a detonated Earth Bomb).
            FS_YAY("a30.bin"), // Air circle. (Unused.)
            FS_YAY("a31.bin"), // Air oval. (Unused.)
            FS_YAY("a32.bin"), // Dust cloud (needs to be animated).
            FS_LZX("a33.bin"), // Dust cloud's animation.
            FS_YAY("a34.bin"), // Electricity branch (animated).
            FS_LZX("a35.bin"), // Lightning texture (normally unused?).
            FS_YAY("a36.bin"), // Power burst (animated).
            FS_LZX("a37.bin"), // Fireball's 2D animation.
            FS_YAY("a38.bin"), // Flare disintegration (needs to be animated).
            FS_LZX("a39.bin"), // Flare disintegration's 2D animation.
            FS_YAY("a3a.bin"), // Shadowy hole.
            FS_YAY("a3b.bin"), // Large-scale glass shining (animated).
            FS_LZX("a3c.bin"), // Frame texture. (Unused.)
            FS_RAW("a3d.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a3e.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a3f.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a40.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a41.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a42.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a43.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a44.bin"), // (Unknown. Messes up the code.)
            FS_RAW("a45.bin"), // (Unknown. Messes up the code.)
            FS_YAY("a46.bin"), // [A tiny block?]
            FS_LZX("a47.bin"), // Sewage filter destroyed (cutscene).
            FS_LZX("a48.bin"), // Pipelines destroyed (cutscene).
            FS_LZX("a49.bin"), // Generator Room door opened (cutscene).
            FS_LZX("a4a.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a4b.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a4c.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a4d.bin"), // First set of barriers shattered (cutscene).
            FS_LZX("a4e.bin"), // Second set of barriers shattered (cutscene).
            FS_LZX("a4f.bin"), // Water gate opened (cutscene).
            FS_LZX("a50.bin"), // Fountain pool emptied (cutscene).
            FS_LZX("a51.bin"), // Water elevator opened (cutscene).
            FS_LZX("a52.bin"), // Water fountain destroyed (cutscene).
            FS_LZX("a53.bin"), // First set of barriers shattered alt (unused cutscene).
            FS_LZX("a54.bin"), // First door opened on Aquanet (cutscene).
            FS_LZX("a55.bin"), // Fountain mechanism lowered (cutscene).
            FS_LZX("a56.bin"), // Test cutscene (unused cutscene)?
            FS_LZX("a57.bin"), // Blue jewel placed (cutscene).
            FS_LZX("a58.bin"), // Blue jewels reacting (cutscene).
            FS_LZX("a59.bin"), // Blue jewels reacting alt (cutscene).
            FS_LZX("a5a.bin"), // Red jewel reacting (cutscene).
            FS_LZX("a5b.bin"), // Blue jewel collected from guards (cutscene).
            FS_LZX("a5c.bin"), // Blue jewel collected from narrow path (cutscene).
            FS_LZX("a5d.bin"), // Western door opened (cutscene).
            FS_LZX("a5e.bin"), // Eastern door opened (cutscene).
            FS_LZX("a5f.bin"), // Developmental message (unused cutscene)?
            FS_LZX("a60.bin"), // Temporary message (regarding green jewel mechanism) (unused cutscene).
            FS_LZX("a61.bin"), // Green jewels reacting (cutscene).
            FS_LZX("a62.bin"), // Red jewel collected (cutscene).
            FS_LZX("a63.bin"), // Green jewel collected from puzzle (cutscene).
            FS_LZX("a64.bin"), // Green jewel revealed (cutscene).
            FS_LZX("a65.bin"), // Green jewel collected from switches (cutscene).
            FS_LZX("a66.bin"), // Green jewel collected from last trial (cutscene).
            FS_LZX("a67.bin"), // Placing the back green jewel (cutscene).
            FS_LZX("a68.bin"), // Placing the left green jewel (cutscene).
            FS_LZX("a69.bin"), // Placing the right green jewel (cutscene).
            FS_LZX("a6a.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a6b.bin"), // Queen of Hearts card collected (cutscene).
            FS_LZX("a6c.bin"), // Ace of Spades card collected (cutscene).
            FS_LZX("a6d.bin"), // King of Clubs card collected (cutscene).
            FS_LZX("a6e.bin"), // Knight of Diamonds card collected (cutscene).
            FS_LZX("a6f.bin"), // Queen of Hearts card placed (cutscene).
            FS_LZX("a70.bin"), // Ace of Spades card placed (cutscene).
            FS_LZX("a71.bin"), // King of Clubs card placed (cutscene).
            FS_LZX("a72.bin"), // Knight of Diamonds card placed (cutscene).
            FS_LZX("a73.bin"), // Starlight fountain elevator activated (cutscene).
            FS_LZX("a74.bin"), // Second Starlight elevator activated (cutscene).
            FS_LZX("a75.bin"), // Large bunny statue destroyed (cutscene).
            FS_LZX("a76.bin"), // Both green jewels placed (cutscene).
            FS_LZX("a77.bin"), // Left green jewel placed (unused cutscene)?
            FS_LZX("a78.bin"), // Right green jewel placed (unused cutscene)?
            FS_LZX("a79.bin"), // Opening the first door on Neverland (cutscene).
            FS_LZX("a7a.bin"), // Opening the cage (cutscene).
            FS_LZX("a7b.bin"), // Setting up the bridge (cutscene).
            FS_LZX("a7c.bin"), // Opening the final door on Neverland (cutscene).
            FS_LZX("a7d.bin"), // Opening the door for the special switch (cutscene).
            FS_LZX("a7e.bin"), // Opening the door to Molok's room (cutscene).
            FS_LZX("a7f.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a80.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a81.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a82.bin"), // Castle bridge activated (cutscene).
            FS_LZX("a83.bin"), // Haunted House Pass collected (cutscene).
            FS_LZX("a84.bin"), // Army tank activated (cutscene).
            FS_LZX("a85.bin"), // Museum Pass collected (cutscene).
            FS_LZX("a86.bin"), // Releasing the coaster battery (cutscene).
            FS_LZX("a87.bin"), // Starting up the rollercoaster (cutscene).
            FS_LZX("a88.bin"), // Epikyur first entry (cutscene).
            FS_LZX("a89.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a8a.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a8b.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a8c.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a8d.bin"), // Lowering the stone pillar (cutscene).
            FS_LZX("a8e.bin"), // Train battery 1 (cutscene).
            FS_LZX("a8f.bin"), // Train battery 2 (cutscene).
            FS_LZX("a90.bin"), // Placing one battery (cutscene).
            FS_LZX("a91.bin"), // Charging up the subway (cutscene).
            FS_LZX("a92.bin"), // Charging up the subway alt (cutscene).
            FS_LZX("a93.bin"), // Powering up the elevator (cutscene).
            FS_LZX("a94.bin"), // Taking out the gravity barrier (cutscene).
            FS_LZX("a95.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a96.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a97.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a98.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("a99.bin"), // Security guards sent out (cutscene).
            FS_LZX("a9a.bin"), // Leaving elevator, restarting game (unused cutscene)?
            FS_LZX("a9b.bin"), // Leaving elevator, restarting game alt (unused cutscene)?
            FS_LZX("a9c.bin"), // Security Control Mechanism thing destroyed (cutscene).
            FS_LZX("a9d.bin"), // Card Key 3 inserted (cutscene).
            FS_LZX("a9e.bin"), // Card Key 1 inserted (cutscene).
            FS_LZX("a9f.bin"), // Card Key 2 inserted (cutscene).
            FS_LZX("aa0.bin"), // Card Key 1 collected (cutscene).
            FS_LZX("aa1.bin"), // First engine destroyed last (cutscene).
            FS_LZX("aa2.bin"), // Second engine destroyed last (cutscene).
            FS_LZX("aa3.bin"), // Slider deactivated (cutscene).
            FS_LZX("aa4.bin"), // Card Key 2 collected (cutscene).
            FS_LZX("aa5.bin"), // Control panel activation (cutscene).
            FS_LZX("aa6.bin"), // Card Key 3 collected (cutscene).
            FS_LZX("aa7.bin"), // Distant ladder activation (cutscene).
            FS_LZX("aa8.bin"), // Main reactor output terminated (cutscene).
            FS_LZX("aa9.bin"), // Power shaft cutting power supply (cutscene).
            FS_LZX("aaa.bin"), // Elevator warning (cutscene).
            FS_LZX("aab.bin"), // Elevator going down (cutscene)?
            FS_LZX("aac.bin"), // Elevator going up (cutscene)?
            FS_LZX("aad.bin"), // Elevator use cancelled (unused cutscene)?
            FS_LZX("aae.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("aaf.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("ab0.bin"), // Water drained at Aquanet (unused cutscene)?
            FS_LZX("ab1.bin"), // Meeting the Angel (cutscene).
            FS_LZX("ab2.bin"), // Meeting Pommy (cutscene).
            FS_LZX("ab3.bin"), // Meeting Baelfael (cutscene).
            FS_LZX("ab4.bin"), // Baelfael defeated (cutscene).
            FS_LZX("ab5.bin"), // Meeting Lilith on Alcatraz (cutscene).
            FS_LZX("ab6.bin"), // Alcatraz Gravity Generator room entry (cutscene).
            FS_LZX("ab7.bin"), // Gravity Generator destroyed on Alcatraz (cutscene).
            FS_LZX("ab8.bin"), // Central Command Room meeting after Alcatraz (cutscene).
            FS_LZX("ab9.bin"), // Meeting Behemos (cutscene).
            FS_LZX("aba.bin"), // Behemos defeated (cutscene).
            FS_LZX("abb.bin"), // Meeting Lilith on Aquanet (cutscene).
            FS_LZX("abc.bin"), // Aquanet Gravity Generator room entry (cutscene).
            FS_LZX("abd.bin"), // Gravity Generator destroyed on Aquanet (cutscene).
            FS_LZX("abe.bin"), // Central Command Room meeting after Aquanet (cutscene).
            FS_LZX("abf.bin"), // Central Command Room meeting after Aquanet and Horizon (cutscene).
            FS_LZX("ac0.bin"), // Meeting Ashtarth (cutscene).
            FS_LZX("ac1.bin"), // Ashtarth defeated (cutscene).
            FS_LZX("ac2.bin"), // Meeting Lilith on Horizon (cutscene).
            FS_LZX("ac3.bin"), // Horizon Gravity Generator room entry (cutscene).
            FS_LZX("ac4.bin"), // Gravity Generator destroyed on Horizon (cutscene).
            FS_LZX("ac5.bin"), // Central Command Room meeting after Horizon (cutscene).
            FS_LZX("ac6.bin"), // Central Command Room meeting after Horizon and Aquanet (cutscene).
            FS_LZX("ac7.bin"), // Meeting Zhael (cutscene).
            FS_LZX("ac8.bin"), // Zhael defeated (cutscene).
            FS_LZX("ac9.bin"), // Starlight Gravity Generator room entry (cutscene).
            FS_LZX("aca.bin"), // Gravity Generator destroyed on Starlight (cutscene).
            FS_LZX("acb.bin"), // Central Command Room meeting after Starlight (cutscene).
            FS_LZX("acc.bin"), // Meeting Molok (cutscene).
            FS_LZX("acd.bin"), // Molok defeated (cutscene).
            FS_LZX("ace.bin"), // Meeting Lilith on Neverland (cutscene).
            FS_LZX("acf.bin"), // Neverland Gravity Generator room entry (cutscene).
            FS_LZX("ad0.bin"), // Gravity Generator destroyed on Neverland (cutscene).
            FS_LZX("ad1.bin"), // Central Command Room meeting after Neverland (cutscene).
            FS_LZX("ad2.bin"), // Central Command Room meeting after Neverland and Starlight (cutscene).
            FS_LZX("ad3.bin"), // Meeting Zoniha (cutscene).
            FS_LZX("ad4.bin"), // Zoniha defeated (cutscene).
            FS_LZX("ad5.bin"), // Epikyur Gravity Generator room entry (cutscene).
            FS_LZX("ad6.bin"), // Gravity Generator destroyed on Epikyur (cutscene).
            FS_LZX("ad7.bin"), // Central Command Room meeting after Epikyur (cutscene).
            FS_LZX("ad8.bin"), // Meeting Bulzeeb (cutscene).
            FS_LZX("ad9.bin"), // Bulzeeb defeated (cutscene).
            FS_LZX("ada.bin"), // Thantos Gravity Generator room entry (cutscene).
            FS_LZX("adb.bin"), // Gravity Generator destroyed on Thantos (cutscene).
            FS_LZX("adc.bin"), // Central Command Room meeting after Thantos (cutscene).
            FS_LZX("add.bin"), // Mihaele takes over (cutscene).
            FS_LZX("ade.bin"), // Meeting up with Lilith (cutscene).
            FS_LZX("adf.bin"), // Mihaele defeated (cutscene).
            FS_LZX("ae0.bin"), // Bomberman defeated (cutscene).
            FS_LZX("ae1.bin"), // Rukifellth's challenge (cutscene).
            FS_LZX("ae2.bin"), // Meeting Rukifellth (cutscene).
            FS_LZX("ae3.bin"), // Rukifellth defeated (cutscene).
            FS_LZX("ae4.bin"), // Sthertoth defeated (cutscene).
            FS_LZX("ae5.bin"), // Sthertoth almost defeated (cutscene).
            FS_LZX("ae6.bin"), // The Angel defeated (cutscene).
            FS_LZX("ae7.bin"), // God of Chaos post-battle (cutscene).
            FS_LZX("ae8.bin"), // Reunions and farewells (cutscene).
            FS_LZX("ae9.bin"), // Sthertoth's reign (cutscene).
            FS_LZX("aea.bin"), // Arrival at Aquanet (cutscene).
            FS_LZX("aeb.bin"), // Arrival at Horizon (cutscene).
            FS_LZX("aec.bin"), // Arrival at Starlight (cutscene).
            FS_LZX("aed.bin"), // Arrival at Neverland (cutscene).
            FS_LZX("aee.bin"), // Arrival at Epikyur (cutscene).
            FS_LZX("aef.bin"), // Arrival at Thantos (cutscene).
            FS_LZX("af0.bin"), // Arrival at Warship Noah (cutscene).
            FS_LZX("af1.bin"), // Pommy evolves at Alcatraz (cutscene).
            FS_LZX("af2.bin"), // Pommy evolves at Aquanet (cutscene).
            FS_LZX("af3.bin"), // Pommy evolves at Horizon (cutscene).
            FS_LZX("af4.bin"), // Pommy evolves at Starlight (cutscene).
            FS_LZX("af5.bin"), // Pommy evolves at Neverland (cutscene).
            FS_LZX("af6.bin"), // Pommy evolves at Epikyur (cutscene).
            FS_LZX("af7.bin"), // Pommy evolves at Thantos (cutscene).
            FS_LZX("af8.bin"), // Pommy evolves at Warship Noah (cutscene).
            FS_LZX("af9.bin"), // Arrival at the BHB Army Ship storeroom (cutscene).
            FS_LZX("afa.bin"), // Normal ending (cutscene).
            FS_LZX("afb.bin"), // Good ending, part 1 (cutscene).
            FS_LZX("afc.bin"), // Good ending, part 2 (cutscene).
            FS_LZX("afd.bin"), // Good ending, intro (cutscene).
            FS_LZX("afe.bin"), // Good ending, part 3 (cutscene).
            FS_LZX("aff.bin"), // Normal stage CPU nodes?
            FS_LZX("b00.bin"), // Park stage CPU nodes?
            FS_LZX("b01.bin"), // Tropical Island stage CPU nodes?
            FS_LZX("b02.bin"), // Desert Shrine stage CPU nodes?
            FS_LZX("b03.bin"), // Unused stage CPU nodes?
            FS_LZX("b04.bin"), // River stage CPU nodes?
            FS_LZX("b05.bin"), // Royal Palace stage CPU nodes?
            FS_LZX("b06.bin"), // Floating Halls stage CPU nodes?
            FS_LZX("b07.bin"), // Hanging Gardens stage CPU nodes?
            FS_LZX("b08.bin"), // Ranch stage CPU nodes?
            FS_LZX("b09.bin"), // Underground River stage CPU nodes?
            FS_LZX("b0a.bin"), // Cloud Castle stage CPU nodes?
            FS_LZX("b0b.bin"), // Castle Garden stage CPU nodes?
            FS_LZX("b0c.bin"), // Crystal Palace stage CPU nodes?
            FS_LZX("b0d.bin"), // Tutorial one (cutscene).
            FS_LZX("b0e.bin"), // Tutorial two (cutscene).
            FS_LZX("b0f.bin"), // Tutorial one (Japanese cutscene?).
            FS_LZX("b10.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b11.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b12.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b13.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b14.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b15.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b16.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b17.bin"), // Baelfael's secret file (cutscene).
            FS_LZX("b18.bin"), // Behemos' secret file (cutscene).
            FS_LZX("b19.bin"), // Ashtarth's secret file (cutscene).
            FS_LZX("b1a.bin"), // Zhael's secret file (cutscene).
            FS_LZX("b1b.bin"), // Molok's secret file (cutscene).
            FS_LZX("b1c.bin"), // Zoniha's secret file (cutscene).
            FS_LZX("b1d.bin"), // Epikyur: getting around (cutscene).
            FS_LZX("b1e.bin"), // Bulzeeb's secret file (cutscene).
            FS_LZX("b1f.bin"), // Thantos: using Wind Bomb (cutscene).
            FS_LZX("b20.bin"), // Thantos: using Earth Bomb (cutscene).
            FS_LZX("b21.bin"), // Mihaele's secret file (cutscene).
            FS_LZX("b22.bin"), // Rukifellth's secret file (cutscene).
            FS_LZX("b23.bin"), // Aquanet: Guardian Armor (cutscene).
            FS_LZX("b24.bin"), // Horizon: Guardian Armor (cutscene).
            FS_LZX("b25.bin"), // Starlight: Guardian Armor (cutscene).
            FS_LZX("b26.bin"), // Neverland: Guardian Armor (cutscene).
            FS_LZX("b27.bin"), // Thantos: starting point (cutscene).
            FS_LZX("b28.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b29.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b2a.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b2b.bin"), // Baelfael's secret file (Japanese cutscene).
            FS_LZX("b2c.bin"), // Behemos' secret file (Japanese cutscene).
            FS_LZX("b2d.bin"), // Ashtarth's secret file (Japanese cutscene).
            FS_LZX("b2e.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b2f.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b30.bin"), // Unknown (Japanese cutscene).
            FS_LZX("b31.bin"), // Guardian Boots acquired (cutscene).
            FS_LZX("b32.bin"), // Guardian Sleeves acquired (cutscene).
            FS_LZX("b33.bin"), // Guardian Vest acquired (cutscene).
            FS_LZX("b34.bin"), // Guardian Helmet acquired (cutscene).
            FS_LZX("b35.bin"), // Bomberman (Neutral)*
            FS_LZX("b36.bin"), // Bomberman (Delighted)*
            FS_LZX("b37.bin"), // Bomberman (Upset)*
            FS_LZX("b38.bin"), // Bomberman (Serious)*
            FS_LZX("b39.bin"), // Normal Pommy (Neutral)*
            FS_LZX("b3a.bin"), // Normal Pommy (Delighted)*
            FS_LZX("b3b.bin"), // Normal Pommy (Upset)*
            FS_LZX("b3c.bin"), // Normal Pommy (Serious)*
            FS_LZX("b3d.bin"), // Knuckle Pommy (Neutral)*
            FS_LZX("b3e.bin"), // Knuckle Pommy (Delighted)*
            FS_LZX("b3f.bin"), // Knuckle Pommy (Upset)*
            FS_LZX("b40.bin"), // Knuckle Pommy (Serious)*
            FS_LZX("b41.bin"), // Animal Pommy (Neutral)*
            FS_LZX("b42.bin"), // Animal Pommy (Delighted)*
            FS_LZX("b43.bin"), // Animal Pommy (Upset)*
            FS_LZX("b44.bin"), // Animal Pommy (Serious)*
            FS_LZX("b45.bin"), // Hammer Pommy (Neutral)*
            FS_LZX("b46.bin"), // Hammer Pommy (Delighted)*
            FS_LZX("b47.bin"), // Hammer Pommy (Upset)*
            FS_LZX("b48.bin"), // Hammer Pommy (Serious)*
            FS_LZX("b49.bin"), // Claw Pommy (Neutral)*
            FS_LZX("b4a.bin"), // Claw Pommy (Delighted)*
            FS_LZX("b4b.bin"), // Claw Pommy (Upset)*
            FS_LZX("b4c.bin"), // Claw Pommy (Serious)*
            FS_LZX("b4d.bin"), // Penguin Pommy (Neutral)*
            FS_LZX("b4e.bin"), // Penguin Pommy (Delighted)*
            FS_LZX("b4f.bin"), // Penguin Pommy (Upset)*
            FS_LZX("b50.bin"), // Penguin Pommy (Serious)*
            FS_LZX("b51.bin"), // Beast Pommy (Neutral)*
            FS_LZX("b52.bin"), // Beast Pommy (Delighted)*
            FS_LZX("b53.bin"), // Beast Pommy (Upset)*
            FS_LZX("b54.bin"), // Beast Pommy (Serious)*
            FS_LZX("b55.bin"), // Magic Pommy (Neutral)*
            FS_LZX("b56.bin"), // Magic Pommy (Delighted)*
            FS_LZX("b57.bin"), // Magic Pommy (Upset)*
            FS_LZX("b58.bin"), // Magic Pommy (Serious)*
            FS_LZX("b59.bin"), // Knight Pommy (Neutral)*
            FS_LZX("b5a.bin"), // Knight Pommy (Delighted)*
            FS_LZX("b5b.bin"), // Knight Pommy (Upset)*
            FS_LZX("b5c.bin"), // Knight Pommy (Serious)*
            FS_LZX("b5d.bin"), // Devil Pommy (Neutral)*
            FS_LZX("b5e.bin"), // Devil Pommy (Delighted)*
            FS_LZX("b5f.bin"), // Devil Pommy (Upset)*
            FS_LZX("b60.bin"), // Devil Pommy (Serious)*
            FS_LZX("b61.bin"), // Cat Pommy (Neutral)*
            FS_LZX("b62.bin"), // Cat Pommy (Delighted)*
            FS_LZX("b63.bin"), // Cat Pommy (Upset)*
            FS_LZX("b64.bin"), // Cat Pommy (Serious)*
            FS_LZX("b65.bin"), // Bird Pommy (Neutral)*
            FS_LZX("b66.bin"), // Bird Pommy (Delighted)*
            FS_LZX("b67.bin"), // Bird Pommy (Upset)*
            FS_LZX("b68.bin"), // Bird Pommy (Serious)*
            FS_LZX("b69.bin"), // Chicken Pommy (Neutral)*
            FS_LZX("b6a.bin"), // Chicken Pommy (Delighted)*
            FS_LZX("b6b.bin"), // Chicken Pommy (Upset)*
            FS_LZX("b6c.bin"), // Chicken Pommy (Serious)*
            FS_LZX("b6d.bin"), // Dragon Pommy (Neutral)*
            FS_LZX("b6e.bin"), // Dragon Pommy (Delighted)*
            FS_LZX("b6f.bin"), // Dragon Pommy (Upset)*
            FS_LZX("b70.bin"), // Dragon Pommy (Serious)*
            FS_LZX("b71.bin"), // Dinosaur Pommy (Neutral)*
            FS_LZX("b72.bin"), // Dinosaur Pommy (Delighted)*
            FS_LZX("b73.bin"), // Dinosaur Pommy (Upset)*
            FS_LZX("b74.bin"), // Dinosaur Pommy (Serious)*
            FS_LZX("b75.bin"), // Pixie Pommy (Neutral)*
            FS_LZX("b76.bin"), // Pixie Pommy (Delighted)*
            FS_LZX("b77.bin"), // Pixie Pommy (Upset)*
            FS_LZX("b78.bin"), // Pixie Pommy (Serious)*
            FS_LZX("b79.bin"), // Shadow Pommy (Neutral)*
            FS_LZX("b7a.bin"), // Shadow Pommy (Delighted)*
            FS_LZX("b7b.bin"), // Shadow Pommy (Upset)*
            FS_LZX("b7c.bin"), // Shadow Pommy (Serious)*
            FS_LZX("b7d.bin"), // Baelfael (Neutral)*
            FS_LZX("b7e.bin"), // Baelfael (Delighted)* (Unused.)
            FS_LZX("b7f.bin"), // Baelfael (Clenching)*
            FS_LZX("b80.bin"), // Baelfael (Serious)*
            FS_LZX("b81.bin"), // Behemos (Neutral)*
            FS_LZX("b82.bin"), // Behemos (Delighted)*
            FS_LZX("b83.bin"), // Behemos (Clenching)*
            FS_LZX("b84.bin"), // Behemos (Serious)*
            FS_LZX("b85.bin"), // Ashtarth (Neutral)*
            FS_LZX("b86.bin"), // Ashtarth (Delighted)*
            FS_LZX("b87.bin"), // Ashtarth (Clenching)*
            FS_LZX("b88.bin"), // Ashtarth (Serious)*
            FS_LZX("b89.bin"), // Zhael (Neutral)*
            FS_LZX("b8a.bin"), // Zhael (Delighted)*
            FS_LZX("b8b.bin"), // Zhael (Clenching)*
            FS_LZX("b8c.bin"), // Zhael (Serious)*
            FS_LZX("b8d.bin"), // Molok (Neutral)*
            FS_LZX("b8e.bin"), // Molok (Delighted)*
            FS_LZX("b8f.bin"), // Molok (Clenching)*
            FS_LZX("b90.bin"), // Molok (Serious)*
            FS_LZX("b91.bin"), // Bulzeeb (Neutral)*
            FS_LZX("b92.bin"), // Bulzeeb (Delighted)*
            FS_LZX("b93.bin"), // Bulzeeb (Clenching)*
            FS_LZX("b94.bin"), // Bulzeeb (Serious)*
            FS_LZX("b95.bin"), // Zoniha (Neutral)*
            FS_LZX("b96.bin"), // Zoniha (Delighted)*
            FS_LZX("b97.bin"), // Zoniha (Clenching)*
            FS_LZX("b98.bin"), // Zoniha (Serious)*
            FS_LZX("b99.bin"), // Rukifellth (Neutral)*
            FS_LZX("b9a.bin"), // Rukifellth (Excited)*
            FS_LZX("b9b.bin"), // Rukifellth (Suffering)*
            FS_LZX("b9c.bin"), // Rukifellth (Head Down)*
            FS_LZX("b9d.bin"), // Lilith (Neutral)*
            FS_LZX("b9e.bin"), // Lilith (Delighted)*
            FS_LZX("b9f.bin"), // Lilith (Clenching)*
            FS_LZX("ba0.bin"), // Lilith (Possessed)*
            FS_LZX("ba1.bin"), // Sthertoth (Neutral)*
            FS_LZX("ba2.bin"), // Sthertoth (Shouting)*
            FS_LZX("ba3.bin"), // Sthertoth (Annoyed)*
            FS_LZX("ba4.bin"), // Sthertoth (Annoyed2)* (Unused.)
            FS_LZX("ba5.bin"), // Sthertoth, God of Chaos (Excited)*
            FS_LZX("ba6.bin"), // Sthertoth, God of Chaos (Shouting)*
            FS_LZX("ba7.bin"), // Sthertoth, God of Chaos (Angry)*
            FS_LZX("ba8.bin"), // Sthertoth, God of Chaos (Triumphant)*
            FS_LZX("ba9.bin"), // The Angel (No Expression)*
            FS_LZX("baa.bin"), // The Angel (No Expression2)* (Unused.)
            FS_LZX("bab.bin"), // The Angel (No Expression3)* (Unused.)
            FS_LZX("bac.bin"), // Normal Pommy (Smug)*
            FS_LZX("bad.bin"), // Enemy attacks settings.
            FS_LZX("bae.bin"), // Enemy properties.
            FS_LZX("baf.bin"), // "Hudson 2000" text.*
            FS_LZX("bb0.bin"), // "Bomberman64 Team Presents" text.*
            FS_LZX("bb1.bin"), // "Bomberman64 The Second Attack!" text.*
            FS_LZX("bb2.bin"), // "The" text.*
            FS_LZX("bb3.bin"), // "Second" text.*
            FS_LZX("bb4.bin"), // "Attack" text.*
            FS_LZX("bb5.bin"), // "Hudson 1999" text.* (Unused.)
            FS_LZX("bb6.bin"), // "Hudson 1999" text.* (Unused.)
            FS_LZX("bb7.bin"), // Bomb title image.*
            FS_LZX("bb8.bin"), // "BOMBERMAN" title image.*
            FS_LZX("bb9.bin"), // "64" title image.*
            FS_LZX("bba.bin"), // Bomberman's introductory image.*
            FS_LZX("bbb.bin"), // Pommy's introductory image.*
            FS_LZX("bbc.bin"), // Baelfael's introductory image.*
            FS_LZX("bbd.bin"), // Behemos' introductory image.*
            FS_LZX("bbe.bin"), // Ashtarth's introductory image.*
            FS_LZX("bbf.bin"), // Zhael's introductory image.*
            FS_LZX("bc0.bin"), // Molok's introductory image.*
            FS_LZX("bc1.bin"), // Zoniha's introductory image.*
            FS_LZX("bc2.bin"), // Bulzeeb's introductory image.*
            FS_LZX("bc3.bin"), // Lilith's introductory image.*
            FS_LZX("bc4.bin"), // Rukifellth's introductory image.*
            FS_LZX("bc5.bin"), // Black trapezoids (used for effect).*
            FS_LZX("bc6.bin"), // Black triangle (used for effect).*
            FS_LZX("bc7.bin"), // "Hudson 1999" text.* (Unused.)
            FS_LZX("bc8.bin"), // "Hudson 1999" text.* (Unused.)
            FS_LZX("bc9.bin"), // Baelfael icon.*
            FS_LZX("bca.bin"), // Behemos icon.*
            FS_LZX("bcb.bin"), // Ashtarth icon.*
            FS_LZX("bcc.bin"), // Zhael icon.*
            FS_LZX("bcd.bin"), // Molok icon.*
            FS_LZX("bce.bin"), // Zoniha icon.*
            FS_LZX("bcf.bin"), // Bulzeeb icon.*
            FS_LZX("bd0.bin"), // Lilith icon.*
            FS_LZX("bd1.bin"), // Rukifellth icon.*
            FS_LZX("bd2.bin"), // Aquanet Hint icon.*
            FS_LZX("bd3.bin"), // Horizon Hint icon.*
            FS_LZX("bd4.bin"), // Starlight Hint icon.*
            FS_LZX("bd5.bin"), // Neverland Hint icon.*
            FS_LZX("bd6.bin"), // Epikyur Hint icon.*
            FS_LZX("bd7.bin"), // Thantos Hint icon.*
            FS_LZX("bd8.bin"), // Warship Noah Hint icon.* (Unused.)
            FS_LZX("bd9.bin"), // Ending 2 icon.*
            FS_LZX("bda.bin"), // Ending 1 icon.*
            FS_LZX("bdb.bin"), // Full Power icon.*
            FS_LZX("bdc.bin"), // Battle Map A icon.*
            FS_LZX("bdd.bin"), // Battle Map B icon.*
            FS_LZX("bde.bin"), // Battle Map C icon.*
            FS_LZX("bdf.bin"), // Battle Map D icon.*
            FS_LZX("be0.bin"), // Potion of Youth icon.*
            FS_LZX("be1.bin"), // Red "X" image.*
            FS_LZX("be2.bin"), // Life-Up icon.*
            FS_LZX("be3.bin"), // "COMPLETE" image.*
            FS_LZX("be4.bin"), // Rumble Pak data?
            FS_LZX("be5.bin"), // Shop item costs and text.
            FS_LZX("be6.bin"), // Demo Loop Preview text file.
            FS_LZX("be7.bin"), // Joystick display.*
            FS_LZX("be8.bin"), // A button display.*
            FS_LZX("be9.bin"), // B button display.*
            FS_LZX("bea.bin"), // Z button display.*
            FS_LZX("beb.bin"), // R buttons display.*
            FS_LZX("bec.bin"), // (Top) C button display.*
            FS_LZX("bed.bin"), // (Other) C buttons display.*
            FS_LZX("bee.bin"), // Plus sign display.*
            FS_LZX("bef.bin"), // Joystick rotation display.*
            FS_LZX("bf0.bin"), // Flying by (cutscene).
            FS_LZX("bf1.bin"), // Zooming in (cutscene).
            FS_LZX("bf2.bin"), // Black hole warning (cutscene).
            FS_LZX("bf3.bin"), // Blacking out (cutscene).
            FS_RAW("bf4.bin"), // (Unknown. Messes up the code.)
            FS_LZX("bf5.bin"), // Game credits (normal ending) text file.
            FS_LZX("bf6.bin"), // Game demo, part 1 (cutscene).
            FS_LZX("bf7.bin"), // Game demo, part 2 (cutscene).
            FS_LZX("bf8.bin"), // Game demo, part 3 (cutscene).
            FS_LZX("bf9.bin"), // Game demo, part 4 (cutscene).
            FS_LZX("bfa.bin"), // Game demo, part 5 (cutscene).
            FS_LZX("bfb.bin"), // Game credits (good ending) text file.
            FS_LZX("bfc.bin"), // Good ending, part 4 (cutscene).
            FS_LZX("bfd.bin"), // Good ending, part 5 (cutscene).
            FS_LZX("bfe.bin"), // Good ending, part 6 (cutscene).
            FS_LZX("bff.bin"), // Good ending, part 7 (cutscene).
            FS_LZX("c00.bin"), // Space background.*
            FS_LZX("c01.bin"), // Good ending, part 8 (cutscene).
            FS_LZX("c02.bin"), // White slash image one.*
            FS_LZX("c03.bin"), // White slash image two.*
            FS_LZX("c04.bin"), // White slash image three.*
            FS_LZX("c05.bin"), // Bomberman's voyage (cutscene).
            FS_LZX("c06.bin"), // Sewage pipe conversation (cutscene).
            FS_LZX("c07.bin"), // Fire blast-twisting introduction (cutscene).
            FS_LZX("c08.bin"), // Bomb Throw introduction (cutscene).
            FS_LZX("c09.bin"), // Swimming pool conversation (cutscene).
            FS_LZX("c0a.bin"), // Underwater city conversation (cutscene).
            FS_LZX("c0b.bin"), // Deep water conversation (cutscene).
            FS_LZX("c0c.bin"), // The pretty fountain (cutscene).
            FS_LZX("c0d.bin"), // Push-block introduction (cutscene).
            FS_LZX("c0e.bin"), // The pretty fountain (Japanese cutscene).
            FS_LZX("c0f.bin"), // Jewel case hint (cutscene).
            FS_LZX("c10.bin"), // Green jewel doesn't fit (cutscene).
            FS_LZX("c11.bin"), // Writing on the wall (cutscene).
            FS_LZX("c12.bin"), // Writing on the wall (Japanese cutscene).
            FS_LZX("c13.bin"), // Writing on the wall (Japanese cutscene).
            FS_LZX("c14.bin"), // Playing card hint (cutscene).
            FS_LZX("c15.bin"), // Slots loss (cutscene).
            FS_LZX("c16.bin"), // Slots loss (Japanese cutscene).
            FS_LZX("c17.bin"), // Slots loss (Japanese cutscene).
            FS_LZX("c18.bin"), // Castle entry hint (Japanese cutscene).
            FS_LZX("c19.bin"), // Castle entry hint (Japanese cutscene).
            FS_LZX("c1a.bin"), // Castle entry hint (unused cutscene).
            FS_LZX("c1b.bin"), // Haunted House entry hint (unused cutscene).
            FS_LZX("c1c.bin"), // Museum entry hint (unused cutscene).
            FS_LZX("c1d.bin"), // The one who holds the light (cutscene).
            FS_LZX("c1e.bin"), // The door locked by magic (cutscene).
            FS_LZX("c1f.bin"), // The glowing Museum Pass (cutscene).
            FS_LZX("c20.bin"), // The glass protected by magic (cutscene).
            FS_LZX("c21.bin"), // The glowing Haunted House Pass (cutscene).
            FS_LZX("c22.bin"), // Rightside pillar's writing (cutscene).
            FS_LZX("c23.bin"), // Leftside pillar's writing (cutscene).
            FS_LZX("c24.bin"), // Dead battery (cutscene).
            FS_LZX("c25.bin"), // Amusement Park guide (cutscene).
            FS_LZX("c26.bin"), // Unknown (Japanese cutscene).
            FS_LZX("c27.bin"), // Unknown (Japanese cutscene).
            FS_LZX("c28.bin"), // Unknown (Japanese cutscene).
            FS_LZX("c29.bin"), // Card Key in wrong slot (cutscene).
            FS_LZX("c2a.bin"), // At the Engine Room (cutscene).
            FS_LZX("c2b.bin"), // Western engine down (cutscene).
            FS_LZX("c2c.bin"), // Eastern engine down (cutscene).
            FS_LZX("c2d.bin"), // Finding the power button (cutscene).
            FS_LZX("c2e.bin"), // Main Reactor introduction (cutscene).
            FS_LZX("c2f.bin"), // Unknown (Japanese cutscene).
            FS_LZX("c30.bin"), // Model shading type 62.
            FS_LZX("c31.bin"), // Model shading type 63.
            FS_LZX("c32.bin"), // Model shading type 64.
            FS_LZX("c33.bin"), // Model shading type 65.
            FS_LZX("c34.bin"), // Model shading type 66.
            FS_LZX("c35.bin"), // Model shading type 67.
            FS_LZX("c36.bin"), // Model shading type 68.
            FS_LZX("c37.bin"), // Model shading type 69.
            FS_LZX("c38.bin"), // Model shading type 70.
            FS_LZX("c39.bin"), // Model shading type 71.
            FS_LZX("c3a.bin"), // Model shading type 72.
            FS_LZX("c3b.bin"), // Model shading type 73. (Unused.)
            FS_LZX("c3c.bin"), // Model shading type 74. (Unused.)
    }
};
