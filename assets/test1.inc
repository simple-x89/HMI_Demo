#DATA
    word    test1_sprites
//1) reel1
            0x5500,0x0055,    // line  1        11111111    
            0x0040,0x0100,    // line  2       1        1   
            0x0010,0x0400,    // line  3      1          1  
            0x4104,0x1001,    // line  4     1  1  11     1 
            0x0001,0x4000,    // line  5    1              1
            0x0401,0x4010,    // line  6    1    1    1    1
            0x0101,0x4040,    // line  7    1   1      1   1
            0x4101,0x4041,    // line  8    1   1  11  1   1
            0x4101,0x4041,    // line  9    1   1  11  1   1
            0x0101,0x4040,    // line 10    1   1      1   1
            0x0401,0x4010,    // line 11    1    1    1    1
            0x0001,0x4100,    // line 12    1           1  1
            0x4004,0x1001,    // line 13     1     11     1 
            0x0010,0x0400,    // line 14      1          1  
            0x0040,0x0100,    // line 15       1        1   
            0x5500,0x0055     // line 16        11111111    
#END

#CONST
    S_reel1
#END

#DATA
    word    test1_colors
            BLACK,
            RED,
            GREEN,
            BLUE
#END

#DATA
    byte    test1_palette
            0,1,2,3             // BLACK, RED, GREEN, BLUE (New Palette)
#END

#CONST
    P_New_Palette
#END
