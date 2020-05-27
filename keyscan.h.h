#define READ_COL    PINC&0xF0 
#define READ_COL_c1    PINC&0x10 
#define READ_COL_c3    PINC&0x40 
#define WRITE_ROW   PORTC 
#define Null    0 

void Init_Port_keyscan(void)                //포트 설정 
{ 
    DDRC = 0x0f;                    //키패드 입력을 위한 포트설정 
    PORTC = 0x0f; 
}
unsigned char KeyScan(void)         //7장 키패드 디바운싱 처리와 같은 키스캔 함수   
{                                                   
    unsigned char Get_Key_Data = 0; 
    unsigned int KeyScan_Line_Sel = 0xF7; 
    unsigned char KeyScan_Sel = 0, key_num = 0; 
    for(KeyScan_Sel=0;KeyScan_Sel<4;KeyScan_Sel++) 
    {                                                                                         
        WRITE_ROW = KeyScan_Line_Sel;   
        delay_us(10);                     
        Get_Key_Data = READ_COL;             

        if(Get_Key_Data != 0x00)   
        {                                                           
            switch(Get_Key_Data)           
            {                                                                               
                case 0x10:     
                    key_num = KeyScan_Sel*4 + 1; 
                    break;           
                case 0x20:       
                    key_num = KeyScan_Sel*4 + 2; 
                    break;                     
                case 0x40:   
                    key_num = KeyScan_Sel*4 + 3;     
                    break;       
                case 0x80: 
                    key_num = KeyScan_Sel*4 + 4;   
                    break;         
                default :       
                    key_num = Null;   
            }               
            return key_num; 
        }     
        KeyScan_Line_Sel = (KeyScan_Line_Sel >> 1); 
        delay_us(1);           
    } 
    return key_num; 
}

unsigned char KeyScan_c1(void)         //7장 키패드 디바운싱 처리와 같은 키스캔 함수   
{                                                   
    unsigned char Get_Key_Data = 0; 
    unsigned int KeyScan_Line_Sel = 0xF7; 
    unsigned char KeyScan_Sel = 0, key_num = 0; 
    for(KeyScan_Sel=0;KeyScan_Sel<4;KeyScan_Sel++) 
    {                                                                                         
        WRITE_ROW = KeyScan_Line_Sel;   
        delay_us(10);                     
        Get_Key_Data = READ_COL_c1;             

        if(Get_Key_Data != 0x00)   
        {                                                           
            switch(Get_Key_Data)           
            {                                                                               
                case 0x10:     
                    key_num = KeyScan_Sel*4 + 1; 
                    break;                    
                default :       
                    key_num = Null;   
            }               
            return key_num; 
        }     
        KeyScan_Line_Sel = (KeyScan_Line_Sel >> 1); 
        delay_us(1);           
    } 
    return key_num; 
}

unsigned char KeyScan_c3(void)         //7장 키패드 디바운싱 처리와 같은 키스캔 함수   
{                                                   
    unsigned char Get_Key_Data = 0; 
    unsigned int KeyScan_Line_Sel = 0xF7; 
    unsigned char KeyScan_Sel = 0, key_num = 0;
    
    for(KeyScan_Sel=0;KeyScan_Sel<4;KeyScan_Sel++) 
    {                                                                                         
        WRITE_ROW = KeyScan_Line_Sel;   
        delay_us(10);                     
        Get_Key_Data = READ_COL_c3;             

        if(Get_Key_Data != 0x00)   
        {                                                           
            switch(Get_Key_Data)           
            {                     
                case 0x40:   
                    key_num = KeyScan_Sel*4 + 3;     
                    break;               
                default :       
                    key_num = Null;   
            }               
            return key_num; 
        }     
        KeyScan_Line_Sel = (KeyScan_Line_Sel >> 1); 
        delay_us(1);           
    } 
    return key_num; 
}