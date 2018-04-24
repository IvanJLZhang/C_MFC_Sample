#ifndef __PROC_REQ_H__
#define __PROC_REQ_H__

#define MAX_WIDTH           1440
#define MAX_HEIGHT          2880

// we allocate the maximum flash size for all cases.
#define MAX_FLASH_SIZE_QHD  32 * 1024 * 1024 / 8	// 32 Mb

// the size of demura configuration file, here we define 256 bytes
#define DEMURA_CFG_SIZE     256     // demura config size
/* definition of return type */
enum
{
    RTN_TYPE_BMP = 0,
    RTN_TYPE_FLASH,
};

struct ColorDataSrc
{
    double pd000_R[MAX_WIDTH * MAX_HEIGHT];     // input source data for demura processing
    double pd000_G[MAX_WIDTH * MAX_HEIGHT];
    double pd000_B[MAX_WIDTH * MAX_HEIGHT];

    double pd016_R[MAX_WIDTH * MAX_HEIGHT];
    double pd016_G[MAX_WIDTH * MAX_HEIGHT];
    double pd016_B[MAX_WIDTH * MAX_HEIGHT];

    double pd032_R[MAX_WIDTH * MAX_HEIGHT];
    double pd032_G[MAX_WIDTH * MAX_HEIGHT];
    double pd032_B[MAX_WIDTH * MAX_HEIGHT];

    double pd064_R[MAX_WIDTH * MAX_HEIGHT];
    double pd064_G[MAX_WIDTH * MAX_HEIGHT];
    double pd064_B[MAX_WIDTH * MAX_HEIGHT];

    double pd096_R[MAX_WIDTH * MAX_HEIGHT];
    double pd096_G[MAX_WIDTH * MAX_HEIGHT];
    double pd096_B[MAX_WIDTH * MAX_HEIGHT];

    double pd128_R[MAX_WIDTH * MAX_HEIGHT];
    double pd128_G[MAX_WIDTH * MAX_HEIGHT];
    double pd128_B[MAX_WIDTH * MAX_HEIGHT];

    double pd160_R[MAX_WIDTH * MAX_HEIGHT];
    double pd160_G[MAX_WIDTH * MAX_HEIGHT];
    double pd160_B[MAX_WIDTH * MAX_HEIGHT];

    double pd192_R[MAX_WIDTH * MAX_HEIGHT];
    double pd192_G[MAX_WIDTH * MAX_HEIGHT];
    double pd192_B[MAX_WIDTH * MAX_HEIGHT];

    double pd224_R[MAX_WIDTH * MAX_HEIGHT];
    double pd224_G[MAX_WIDTH * MAX_HEIGHT];
    double pd224_B[MAX_WIDTH * MAX_HEIGHT];

    unsigned char   pucBmpSrc[MAX_WIDTH * MAX_HEIGHT * 3];  // BMP data Source
    unsigned char   pucDllCtrl[DEMURA_CFG_SIZE];            // demura dll control configuration data
	unsigned char   ucQueryType;                            // demura control query type, 0: demura process, 1: judgment
};

/* for temp. processing */

struct DataBuf
{
    double pdBuf0_R[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf1_R[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf2_R[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf3_R[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf4_R[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf5_R[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf6_R[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf7_R[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf8_R[MAX_WIDTH * MAX_HEIGHT];

	double pdBuf0_G[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf1_G[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf2_G[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf3_G[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf4_G[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf5_G[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf6_G[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf7_G[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf8_G[MAX_WIDTH * MAX_HEIGHT];

	double pdBuf0_B[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf1_B[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf2_B[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf3_B[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf4_B[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf5_B[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf6_B[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf7_B[MAX_WIDTH * MAX_HEIGHT];
	double pdBuf8_B[MAX_WIDTH * MAX_HEIGHT];
    
    double pdBuf9[MAX_WIDTH *  MAX_HEIGHT]; // temp buffer for processing in prediction and combination.

};


// compensated data result
struct CompDataResult
{
    unsigned char pucCompData[MAX_WIDTH * MAX_HEIGHT * 3];      // compensated data in gray level with BMP file header 54 bytes
	unsigned char pucFlhCompData[MAX_FLASH_SIZE_QHD];           // compensated data for flash
    unsigned char ucJudgmentResult;                             // judgment result
};

#endif
