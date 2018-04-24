#region 文件说明
/*------------------------------------------------------------------------------
// Copyright © 2018 Granda. All Rights Reserved.
// 苏州广林达电子科技有限公司 版权所有
//------------------------------------------------------------------------------
// File Name: DataBuf
// Author: Ivan JL Zhang    Date: 2018/4/24 10:31:14    Version: 1.0.0
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
using static C_WINFORM_Sample.Model.ColorDataSrc;
using static C_WINFORM_Sample.Form1;

namespace C_WINFORM_Sample.Model
{
    public struct DataBuf
    {
        /* for temp. processing */
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf0_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf1_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf2_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf3_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf4_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf5_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf6_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf7_R;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf8_R;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf0_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf1_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf2_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf3_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf4_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf5_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf6_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf7_G;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf8_G;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf0_B;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf1_B;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf2_B;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf3_B;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf4_B;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf5_B;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf6_B;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf7_B;
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf8_B;

        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT)]
        public double[] pdBuf9; // temp buffer for processing in prediction and combination.
    }
}
