#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//R0 regiser initial parameter for Data signal
char *SV_L1_Data_r0[] = {
        "0061727026503255544",
        "1660130752435362260",
        "0676457016477551225",
        "1763467705267605701",
        "1614265052776007236",
        "1446113457553463523",
        "1467417471470124574",
        "0022513456555401603",
        "0004420115402210365",
        "0072276243316574510",
        "1632356715721616750",
        "1670164755420300763",
        "1752127524253360255",
        "0262220014044243135",
        "1476157654546440020",
        "1567545246612304745",
        "0341667641424721673",
        "0627234635353763045",
        "0422600144741165152",
        "1661124176724621030",
        "1225124173720602330",
        "1271773065617322065",
        "0611751161355750124",
        "0121046615341766266",
        "0337423707274604122",
        "0246610305446052270",
        "0427326063324033344",
        "1127467544162733403",
        "0772425336125565156",
        "1652465113031101044",
        "1737622607214524550",
        "1621315362240732407",
        "0171733204500613155",
        "1462031354327077565",
        "1141265411761074755",
        "0665106277260231251",
        "0573123144343776027",
        "0222101406610314705",
        "0140673225434336401",
        "0624233245727625631",
        "0224022145647544263",
        "0222501602610354705",
        "1370337660412244327",
        "0563567347256715524",
        "1407636661116077143",
        "1137431557133151004",
        "1113003456475500265",
        "1746553632646152413",
        "1465416631251321074",
        "0130516430377202712",
        "0762173527246302776",
        "1606732407336425136",
        "1131112010066741562",
        "1107467740060732403",
        "0755500241327076744",
        "1443037764170374631",
        "0243224434357700345",
        "0445504023027564357",
        "1211152271373271472",
        "0256644102553071753",
        "0733312314424771412",
        "1636376400221406415",
        "0574114621235461516",
        "1710717574016037362"
    };
//R1 regiser initial parameter for Data signal
char *SV_L1_Data_r1[] = {
        "0377627103341647600",
        "0047555332635133703",
        "0570574070736102152",
        "0511013576745450615",
        "1216243446624447775",
        "0176452272675511054",
        "0151055342317137706",
        "1127720116046071664",
        "0514407436155575524",
        "0253070462740453542",
        "0573371306324706336",
        "1315135317732077306",
        "1170303027726635012",
        "1637171270537414673",
        "0342370520251732111",
        "0142423551056551362",
        "0641261355426453710",
        "0237176034757345266",
        "1205663360515365064",
        "0725000004121104102",
        "0337367500320303262",
        "1303374445022536530",
        "1033071464007363115",
        "0753124124237073577",
        "0133522075443754772",
        "1244212514312345145",
        "1066056211234322164",
        "0073115240113351010",
        "1102260031574577224",
        "1166703527236520553",
        "0056062273631723177",
        "0141517013160576212",
        "1644007677312431616",
        "0201757033615262622",
        "0357610362675720200",
        "1637504174727237065",
        "1510345507743707753",
        "0540160763721100120",
        "0406415410457500342",
        "0707515543554212732",
        "0140216674314371011",
        "0445414471314273300",
        "0120121661750263177",
        "0477301251340044262",
        "1157040657040363676",
        "1222265021477405004",
        "0314661556545362364",
        "0177320240371640542",
        "0735517310345570340",
        "1367565551220511432",
        "1274167141162675644",
        "1543641015130470077",
        "0640733734534576460",
        "0216312531021205434",
        "0050232164401566177",
        "0702636370401726111",
        "1733537351460015703",
        "1523265651140460620",
        "0607703231502460135",
        "1757246242710445777",
        "0464412467237572274",
        "1050617751566552643",
        "1041606123021052264",
        "1335441345250455042"
    };   
//C regiser initial parameter for Data signal
char *SV_L1_Data_C[] = {
        "10100",
        "10100",
        "00110",
        "10100",
        "10100",
        "00110",
        "10100",
        "00110",
        "00110",
        "00110",
        "10100",
        "00110",
        "10100",
        "00110",
        "00110",
        "10100",
        "00110",
        "00110",
        "00110",
        "00110",
        "10100",
        "10100",
        "10100",
        "00110",
        "10100",
        "00110",
        "00110",
        "00110",
        "00110",
        "10100",
        "10100",
        "00110",
        "10100",
        "00110",
        "00110",
        "00110",
        "10100",
        "10100",
        "01100",
        "00110",
        "00011",
        "01100",
        "10100",
        "00110",
        "10100",
        "10100",
        "00110",
        "00110",
        "00110",
        "10100",
        "10100",
        "10100",
        "00110",
        "10100",
        "00110",
        "10100",
        "00110",
        "00110",
        "10100",
        "10010",
        "10001",
        "11000",
        "00110",
        "10100"
    };
    
//R0 regiser initial parameter for Pilot signal    
char *SV_L1_Pilot_r0[] = {
        "0227743641272102303",
        "0603070242564637717",
        "0746325144437416120",
        "0023763714573206044",
        "0155575663373106723",
        "0022277536552741033",
        "0137757627072411730",
        "0413034001670700216",
        "0501123675324707024",
        "0013727517464264567",
        "0663351450332761127",
        "1450710073416110356",
        "1716542347100366110",
        "0743601273016301212",
        "1454332372150500137",
        "1473215015316613621",
        "1255535602164437613",
        "1164537254033266174",
        "1500537251137244274",
        "0766727150471256024",
        "0457637114652202460",
        "0436500136253056124",
        "1666265767713037215",
        "1465272157164065443",
        "0607440357166466472",
        "1670202421463640077",
        "1312661744614412524",
        "1413034001672741216",
        "1113765722434040551",
        "0621573414133237134",
        "0526104310250410535",
        "0426454733176070600",
        "1440644676733136472",
        "0557275325702027456",
        "0657637150553356442",
        "1403560400557766512",
        "1531165662277124403",
        "1403072012721162611",
        "0541210077534050730",
        "1660256422576622574",
        "0646767375467672136",
        "1563301635027210017",
        "1403462012723163611",
        "0767233376550711053",
        "1260555130762307205",
        "0531075060147161624",
        "0112673710551347402",
        "1314750013607403146",
        "0471706447643213002",
        "0770352206645261362",
        "0255127616022236737",
        "1035616240477274125",
        "0251115713566666576",
        "0752241454312660541",
        "0461250256520434602",
        "1116341217327713444",
        "0765232132271554573",
        "0774370107303671123",
        "1407140711055577677",
        "1753355476331367516",
        "0101630163132222775",
        "0730471404057577456",
        "1336743247162047542",
        "0020666576373544533"
    };
    
//R1 regiser initial parameter for Pilot signal    
char *SV_L1_Pilot_r1[] = {
        "1667217344450257245",
    "0300642746017221737",
    "0474006332201753645",
    "0613606702460402137",
    "1465531713404064713",
    "1063646422557130427",
    "1066060465055002004",
    "0225574416605070652",
    "1733560674073230405",
    "1116277147142260461",
    "0663351450332761127",
    "1110300535412261305",
    "1046105227571557243",
    "1020346561064461527",
    "1270052747201123510",
    "1041553307136735706",
    "1002352163603013730",
    "1362622514254366256",
    "0556645716623157361",
    "0020341533300021636",
    "1470231623730254774",
    "1437100574634755567",
    "0215346037247347710",
    "1074246275146357122",
    "1655552356143710472",
    "1067241424131022656",
    "1611144345044137740",
    "1235122601654653275",
    "0663754302501454556",
    "0330540311241344370",
    "1763277034331577303",
    "1325110610226320770",
    "0632344657312671631",
    "1432530060077160315",
    "1272177170234542346",
    "0043174152003062273",
    "0633575650312403065",
    "0305021033755066410",
    "0137373436464572225",
    "0014331642301151614",
    "0444423305436737401",
    "0232343171540161113",
    "0101411166154322757",
    "0501120665453153342",
    "1042475051720150775",
    "1533531265037673325",
    "0506620200211067675",
    "1324133406103765602",
    "0203136107415235456",
    "1521524233172031026",
    "0164213410044443204",
    "1221110757557452411",
    "0252317630101475044",
    "0014540074363706135",
    "0371711523526255275",
    "0012400567546521471",
    "0312622351062337705",
    "0023647344743400250",
    "0257310611765747211",
    "1540176212407214706",
    "1412637164262406706",
    "0363125736302421243",
    "0414175374460515677",
    "0004500310276201661"
    }; 
    
//c regiser initial parameter for Pilot signal    
char *SV_L1_Pilot_C[] = {
        "01000",
    "00000",
    "01000",
    "00000",
    "01000",
    "01000",
    "00000",
    "01000",
    "00000",
    "00000",
    "00000",
    "01000",
    "01000",
    "00000",
    "00000",
    "00000",
    "01000",
    "01000",
    "01000",
    "01000",
    "00000",
    "01000",
    "01000",
    "00000",
    "01000",
    "00000",
    "01000",
    "00000",
    "00000",
    "00000",
    "00000",
    "01000",
    "01000",
    "00000",
    "01000",
    "01000",
    "00110",
    "00000",
    "01010",
    "00110",
    "00101",
    "10001",
    "00110",
    "00000",
    "10001",
    "00000",
    "00110",
    "00101",
    "00110",
    "10010",
    "10001",
    "00011",
    "01000",
    "00000",
    "00000",
    "00101",
    "10001",
    "00000",
    "01000",
    "00000",
    "00000",
    "10001",
    "00000",
    "01000"
    };
//R0 regiser initial parameter for Pilot overlay signal    
char *SV_L1_Pilot_Overlay_r0[] = {
        "0110111011",
    "0111101000",
    "1100000001",
    "0110110110",
    "0100011000",
    "0011111100",
    "0011111100",
    "1111000101",
    "0011001100",
    "1000011010",
    "0001001001",
    "0110101011",
    "0101110000",
    "0010110011",
    "1110000111",
    "1000000000",
    "1111101101",
    "1111101011",
    "0010001011",
    "0011101000",
    "0011011010",
    "0011111100",
    "0111001100",
    "1000101110",
    "0101000010",
    "0000101010",
    "0000100001",
    "1000010000",
    "1011100100",
    "0110111111",
    "1001110000",
    "1101110101",
    "0101111100",
    "1011001000",
    "1000001100",
    "0001100101",
    "0000000010",
    "0010100011",
    "1111010010",
    "0000100101",
    "0100111011",
    "0110111001",
    "0010011101",
    "1000011010",
    "0010000010",
    "1001001111",
    "1111001111",
    "0010110010",
    "0111111110",
    "0100100011",
    "0100001110",
    "0111101101",
    "1000010010",
    "1001001110",
    "0001011110",
    "1110001001",
    "1110110001",
    "1101111110",
    "0111111000",
    "1010001111",
    "1100110100",
    "0011010010",
    "1101010100",
    "1001110110"
    }; 
//R1 regiser initial parameter for Pilot Overlay signal
char *SV_L1_Pilot_Overlay_r1[] = {
	"0100110000",
    "0110000010",
    "1110010001",
    "0101110011",
    "1011000110",
    "1010101111",
    "1110001000",
    "0001010000",
    "1011111100",
    "0100010101",
    "1100000100",
    "0111011110",
    "1001110011",
    "1001101010",
    "0001100101",
    "0101101000",
    "0111111011",
    "1001110001",
    "1101011001",
    "0111011110",
    "0011100101",
    "1101000001",
    "0110110001",
    "0011000001",
    "1111100001",
    "0010011011",
    "0110011110",
    "0000111000",
    "0000000101",
    "0000100100",
    "0110101101",
    "1011010001",
    "0001110111",
    "0110100111",
    "0111010101",
    "1110110101",
    "1011110110",
    "1011011010",
    "1100101010",
    "1101101111",
    "1110011111",
    "1000100000",
    "0110000101",
    "0101111101",
    "0011110111",
    "1010001010",
    "1101000011",
    "1101101101",
    "1011101001",
    "0100001100",
    "1001100010",
    "1100110011",
    "0011110101",
    "0100110100",
    "1110011000",
    "1000111100",
    "0100010000",
    "0010011101",
    "1100011010",
    "0010011000",
    "0001001000",
    "0110001110",
    "0110101101",
    "1100011011"
    };
    // Function to convert an octal digit to binary
char* octal_digit_to_binary(char octal_digit) {
    switch (octal_digit) {
        case '0': return "000";
        case '1': return "001";
        case '2': return "010";
        case '3': return "011";
        case '4': return "100";
        case '5': return "101";
        case '6': return "110";
        case '7': return "111";
        default: return NULL; // Handle invalid input if necessary
    }
}

// Function to convert an octal bit string to binary
char* convert_octal_to_binary(char* octal_bits) {
    // Calculate the length of the input octal string
    int octal_length = strlen(octal_bits)-1;
    //printf("octal len is %d\n",octal_length);

    // Calculate the length of the binary string (including the null terminator)
    int binary_length = octal_length * 3 + 2;

    // Allocate memory for the bina	ry string dynamically
    char* binary_bits = (char*)malloc(binary_length);
    char* new_binary=(char*)malloc(binary_length);
    
    // Convert the remaining bits to binary and concatenate them
    for (int i = 1; i < octal_length+1; ++i) {																																			
        char* binary_digit = octal_digit_to_binary(octal_bits[i]);
        strcat(binary_bits, binary_digit);
    }

    new_binary[0]=octal_bits[0];
    new_binary[55]='\0';
    strcat(new_binary,binary_bits);
   
// Update the octal_bits with the binary result
   
    return new_binary;
}
//PRN code generation for NavIC constellation
//function to shift the bits according to taps given to registers
void shift(int *register_array, int feedback, int length) {
    for (int i = 0; i < length-1; i++) {
        register_array[i] = register_array[i+1];
    }
    register_array[length-1] = feedback;
}
int* genNavicCaCode_Data(int sv ) {
    if (sv < 0 || sv > 63) {
        printf("Error: PRN ID out of bounds!\n");
        return NULL;
    } 
    
        int r0[55],r1[55],C[5];
	for(int i=0;i<55;i++)
	{
		r0[i]=SV_L1_Data_r0[sv][i]-'0';
		r1[i]=SV_L1_Data_r1[sv][i]-'0';
		if(i<5)
		{
			C[i]=SV_L1_Data_C[sv][i]-'0';
		}
        }

   int codeLength = 10230;
         int* cad = malloc( codeLength* sizeof(int));
        for (int j = 0; j < codeLength; j++) {
            int a = ((r0[50] ^ r0[45]) ^ r0[40]) ^ ((r0[20] ^ r0[10]) ^ (r0[5] ^ r0[0]));
     
            int sigma2A = ((r0[50] ^ r0[45]) ^ r0[40]) & ((r0[20] ^ r0[10]) ^ (r0[5] ^ r0[0]));
            int sigma2B = ((r0[50] ^ r0[45]) & r0[40]) ^ ((r0[20] ^ r0[10]) & (r0[5] ^ r0[0]));
            int sigma2C = (r0[50] & r0[45]) ^ ((r0[20] & r0[10]) ^ (r0[5] & r0[0]));
            int sigma2 = (sigma2A ^ sigma2B) ^ sigma2C;
            int temp = ((r0[40] ^ r0[35]) ^ (r0[30] ^ r0[25])) ^ (r0[15] ^ r0[0]);
            int R1A = sigma2 ^ temp;
            int R1B = ((r1[50] ^ r1[45]) ^ (r1[40] ^ r1[20])) ^ ((r1[10] ^ r1[5]) ^ (r1[0]));
            int b = R1A ^ R1B;
            int z = r1[0] ^ C[0];
            shift(C, C[0], 5);
            shift(r1, b, 55);
            shift(r0, a, 55);
            cad[j] = z;
        }

        return cad ;
        
    }
int *genNavicCaCode_Pilot(int sv) {
    if (sv < 0 || sv > 63) {
        printf("Error: PRN ID out of bounds!\n");
        return NULL;
    }
       int r0_p[55],r1_p[55],C_p[5];
	 for(int i=0;i<55;i++)
	{
		r0_p[i]=SV_L1_Pilot_r0[sv][i]-'0';
		r1_p[i]=SV_L1_Pilot_r1[sv][i]-'0';
		if(i<5)
		{
			C_p[i]=SV_L1_Pilot_C[sv][i]-'0';
		}
        }

        int codeLength = 10230;
    	  int* cap = malloc(codeLength * sizeof(int));

    // Initialize r0_p, r1_p, and C_p based on SV_L1_Pilot_r0, SV_L1_Pilot_r1, and SV_L1_Pilot_C arrays

    for (int k = 0; k < codeLength; k++) {
        int r_p = (r0_p[50] ^ r0_p[45]) ^ (r0_p[40]) ^ ((r0_p[20] ^ r0_p[10]) ^ (r0_p[5] ^ r0_p[0]));
        int sigma2A = (r0_p[50] ^ r0_p[45] ^ r0_p[40]) & (r0_p[20] ^ r0_p[10] ^ r0_p[5] ^ r0_p[0]);
        int sigma2B = ((r0_p[50] ^ r0_p[45]) & (r0_p[40])) ^ ((r0_p[20] ^ r0_p[10]) & (r0_p[5] ^ r0_p[0]));
        int sigma2C = (r0_p[50] & r0_p[45]) ^ (r0_p[20] & r0_p[10]) ^ (r0_p[5] & r0_p[0]);
        int sigma2 = sigma2A ^ sigma2B ^ sigma2C;
        int temp = r0_p[40] ^ r0_p[35] ^ r0_p[30] ^ r0_p[25] ^ r0_p[15] ^ r0_p[0];
        int R1A = sigma2 ^ temp;
        int R1B = ((r1_p[50] ^ r1_p[45]) ^ (r1_p[40] ^ r1_p[20])) ^ ((r1_p[10] ^ r1_p[5]) ^ (r1_p[0]));
        int r3_p = R1A ^ R1B;
        int z1 = (r1_p[0] + C_p[0]) % 2;

        shift(r0_p, r_p, 55);
        shift(r1_p, r3_p, 55);
        shift(C_p, C_p[0], 5);

        cap[k] = z1;
    }

    return cap;
}
int* genNavicCaCode_Pilot_Overlay(int sv) {
    // Check if sv is within the valid range
    if (sv < 0 || sv > 63) {
        printf("Error: PRN ID out of bounds!\n");
        return NULL;
    }

    // Initialize registers
    int r0_pl[10], r1_pl[10];
    for (int i = 0; i < 10; i++) {
        r0_pl[i] = SV_L1_Pilot_Overlay_r0[sv][i] - '0';
        r1_pl[i] = SV_L1_Pilot_Overlay_r1[sv][i] - '0';
    }

    int* ca = (int*)malloc(1800 * sizeof(int)); // Allocate memory for the PRN sequence

    // Generate Pilot Overlay PRN sequence
    for (int l = 0; l < 1800; l++) {
        int r_pl = (r0_pl[5] ^ r0_pl[2]) ^ (r0_pl[1] ^ r0_pl[0]);
        // Compute σ2A
        int sigma2A = (r0_pl[5] ^ r0_pl[2]) & (r0_pl[1] ^ r0_pl[0]);
        // Compute σ2B
        int sigma2B = (r0_pl[5] & r0_pl[2]) ^ (r0_pl[1] & r0_pl[0]);
        // Compute σ2
        int sigma2 = sigma2A ^ sigma2B;
        // Compute r1A
        int temp = r0_pl[6] ^ r0_pl[3] ^ r0_pl[2] ^ r0_pl[0];
        int R1A = sigma2 ^ temp;
        // Compute r1B
        int R1B = r1_pl[5] ^ r1_pl[2] ^ r1_pl[1] ^ r1_pl[0];
        int r3_pl = R1A ^ R1B;
        int z2 = r1_pl[0];

        shift(r0_pl, r_pl, 10);
        shift(r1_pl, r3_pl, 10);

        // Modulo 2 add and store in the PRN sequence array
        ca[l] = z2;
    }

    return ca;
}
//function to upsample the Data PRN sequence generated to required sampling rate
int* genNavicCaTable_Data(float samplingFreq, int codeLength, float codeFreqBasis, int* satId, int satIdLength) {
    float samplingPeriod = 1.0 / samplingFreq;  
    int sampleCount = (int)(samplingFreq / (codeFreqBasis / codeLength));
    float* indexArr = (float*)malloc(sampleCount * sizeof(float));
    int* result = (int*)malloc(sampleCount * satIdLength * sizeof(int));

    if (indexArr == NULL || result == NULL) {
        // Handle memory allocation failure
        free(indexArr);
        free(result);
        return NULL;
    }

    // Precompute indexArr values outside the loop
    for (int i = 0; i < sampleCount; i++) {
        indexArr[i] = i * samplingPeriod * codeFreqBasis;
    }

    FILE* file_data = fopen("code_table_data.txt", "w");
    if (file_data == NULL) {
        printf("Failed to open the file for writing.\n");
        free(indexArr);
        free(result);
        return NULL;
    }

    for (int i = 0; i < satIdLength; i++) {
        int* satPrn = genNavicCaCode_Data(satId[i]);
        if (satPrn == NULL) {
            // Handle error in genNavicCaCode_Data function
            fclose(file_data);
            free(indexArr);
            free(result);
            return NULL;
        }

        for (int j = 0; j < sampleCount; j++) {
            result[i * sampleCount + j] = satPrn[(int)indexArr[j]];
            fprintf(file_data, "%d\n", result[i * sampleCount + j]);
        }

        free(satPrn); // Free the memory allocated in genNavicCaCode_Data function
    }

    fclose(file_data);
    free(indexArr);
    return result;
}

int* genNavicCaTable_Pilot(float samplingFreq, int codeLength, float codeFreqBasis, int* satId, int satIdLength) {
    float samplingPeriod = 1.0 / samplingFreq;  
    int sampleCount = (int)(samplingFreq / (codeFreqBasis / codeLength));
    float* indexArr = (float*)malloc(sampleCount * sizeof(float));
    int* result = (int*)malloc(sampleCount * satIdLength * sizeof(int));

    if (indexArr == NULL || result == NULL) {
        // Handle memory allocation failure
        free(indexArr);
        free(result);
        return NULL;
    }

    // Precompute indexArr values outside the loop
    for (int i = 0; i < sampleCount; i++) {
        indexArr[i] = i * samplingPeriod * codeFreqBasis;
    }

    FILE* file_data = fopen("code_table_pilot.txt", "w");
    if (file_data == NULL) {
        printf("Failed to open the file for writing.\n");
        free(indexArr);
        free(result);
        return NULL;
    }

    for (int i = 0; i < satIdLength; i++) {
        int* satPrn = genNavicCaCode_Pilot(satId[i]);
        if (satPrn == NULL) {
            // Handle error in genNavicCaCode_Pilot function
            fclose(file_data);
            free(indexArr);
            free(result);
            return NULL;
        }

        for (int j = 0; j < sampleCount; j++) {
            result[i * sampleCount + j] = satPrn[(int)indexArr[j]];
            fprintf(file_data, "%d\n", result[i * sampleCount + j]);
        }

        free(satPrn); // Free the memory allocated in genNavicCaCode_Pilot function
    }

    fclose(file_data);
    free(indexArr);
    return result;
}
int* genNavicCaTable_Pilot_Overlay(float samplingFreq, int codeLength, float codeFreqBasis, int* satId, int satIdLength) {
    float samplingPeriod = 1.0 / samplingFreq; 
    int sampleCount = (int)(samplingFreq / (codeFreqBasis / codeLength));

    float* indexArr = (float*)malloc(sampleCount * sizeof(float));
    int* result = (int*)malloc(sampleCount * satIdLength * sizeof(int));

    if (indexArr == NULL || result == NULL) {
        // Handle memory allocation failure
        free(indexArr);
        free(result);
        return NULL;
    }

    // Precompute indexArr values outside the loop
    for (int i = 0; i < sampleCount; i++) {
        indexArr[i] = i * samplingPeriod * codeFreqBasis;
    }

    FILE* file_data = fopen("code_table_pilot_overlay.txt", "w");
    if (file_data == NULL) {
        printf("Failed to open the file for writing.\n");
        free(indexArr);
        free(result);
        return NULL;
    }

    for (int i = 0; i < satIdLength; i++) {
        int* satPrnOverlay = genNavicCaCode_Pilot_Overlay(satId[i]);
        if (satPrnOverlay == NULL) {
            // Handle error in genNavicCaCode_Pilot_Overlay function
            fclose(file_data);
            free(indexArr);
            free(result);
            return NULL;
        }

        for (int j = 0; j < sampleCount; j++) {
            result[i * sampleCount + j] = satPrnOverlay[(int)indexArr[j]];
            fprintf(file_data, "%d\n", result[i * sampleCount + j]);
        }

        free(satPrnOverlay); // Free the memory allocated in genNavicCaCode_Pilot_Overlay function
    }

    fclose(file_data);
    free(indexArr);
    return result;
}

int main() {
// Convert octal bit strings to binary for SV_L1_Data_r0
for (int i = 0; i < 64; i++) {
	char* r0_data=convert_octal_to_binary(SV_L1_Data_r0[i]);
	char* r1_data=convert_octal_to_binary(SV_L1_Data_r1[i]);
	char* r0_pilot=convert_octal_to_binary(SV_L1_Pilot_r0[i]);
	char* r1_pilot=convert_octal_to_binary(SV_L1_Pilot_r1[i]);
	
	SV_L1_Data_r0[i] = malloc(strlen(r0_data) + 1); // +1 for the null terminator
	SV_L1_Data_r1[i] = malloc(strlen(r1_data) + 1);
	SV_L1_Pilot_r0[i] = malloc(strlen(r0_pilot) + 1);
	SV_L1_Pilot_r1[i] = malloc(strlen(r1_pilot) + 1);
	
	if (SV_L1_Data_r0[i] != NULL && SV_L1_Data_r1[i] != NULL && SV_L1_Pilot_r0[i] != NULL && SV_L1_Pilot_r1[i] != NULL) {
            strcpy(SV_L1_Data_r0[i], r0_data);
            strcpy(SV_L1_Data_r1[i], r1_data);
            strcpy(SV_L1_Pilot_r0[i], r0_pilot);
            strcpy(SV_L1_Pilot_r1[i], r1_pilot);
            }
           
	else {
   	 printf("Memory allocation failed\n");
	}

	 }
	 
//printing prn data of sattelite ids
/*
  	for(int i=0;i<64;i++)
  	{
	printf("\nSATELLITE: %d\n",i+1);
  	int* data_prn=genNavicCaCode_Data(i);
  	printf("Data prn (first 24)          :");
  	for(int j=0;j<24;j++){
  		printf("%d",data_prn[j]);
  	}
  	
  	printf(" Data prn (Last 24)           :");
  	for(int j=10206;j<10230;j++){
  		printf("%d",data_prn[j]);
  	}
  	int* pilot_prn=genNavicCaCode_Pilot(i);
  	printf("\nPilot prn (first 24)         :");
  	for(int j=0;j<24;j++){
  		printf("%d",pilot_prn[j]);
  	}
  	printf(" Pilot prn (last 24)          :");
  	for(int j=10206;j<10230;j++){
  		printf("%d",pilot_prn[j]);
  	}
  	
  	int* pilot_overlay_prn=genNavicCaCode_Pilot_Overlay(i);
  	printf("\npilot overlay prn (first 24) :");
  	for(int j=0;j<24;j++){
  		printf("%d",pilot_overlay_prn[j]);
  	}
  	
  	printf(" pilot overlay prn (last 24)  :");
  	for(int j=1776;j<1800;j++){
  		printf("%d",pilot_overlay_prn[j]);
  	}
  }
  */
    int satId[] = {1, 46, 62, 50};
    int satIdlength = sizeof(satId) / sizeof(satId[0]);
    genNavicCaTable_Data(4e6, 10230, 1.023e6, satId, satIdlength);
    genNavicCaTable_Pilot(4e6, 10230, 1.023e6, satId, satIdlength);
    genNavicCaTable_Pilot_Overlay(4e6, 1800, 1.023e6, satId, satIdlength);
    return 0;    
} 












  
