#region 文件说明
/*------------------------------------------------------------------------------
// Copyright © 2018 Granda. All Rights Reserved.
// 苏州广林达电子科技有限公司 版权所有
//------------------------------------------------------------------------------
// File Name: ColorDataSrc
// Author: Ivan JL Zhang    Date: 2018/4/24 10:01:54    Version: 1.0.0
// Description: 
//   
// 
// Revision History: 
// <Author>  		<Date>     	 	<Revision>  		<Modification>
// 	
//----------------------------------------------------------------------------*/
#endregion
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using static C_WINFORM_Sample.Form1;
namespace C_WINFORM_Sample.Model
{
    public struct ColorDataSrc
    {

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd000_R;// input source data for demura processing
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd000_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd000_B;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd016_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd016_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd016_B;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd032_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd032_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd032_B;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd064_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd064_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd064_B;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd096_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd096_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd096_B;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd128_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd128_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd128_B;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd160_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd160_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd160_B;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd192_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd192_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd192_B;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd224_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd224_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pd224_B;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT * 3)]
        public byte[] pucBmpSrc;  // BMP data Source
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = DEMURA_CFG_SIZE)]
        public byte[] pucDllCtrl;            // demura dll control configuration data
        public byte ucQueryType;
    }
}
