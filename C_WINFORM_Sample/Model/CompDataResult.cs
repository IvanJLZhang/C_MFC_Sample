#region 文件说明
/*------------------------------------------------------------------------------
// Copyright © 2018 Granda. All Rights Reserved.
// 苏州广林达电子科技有限公司 版权所有
//------------------------------------------------------------------------------
// File Name: CompDataResult
// Author: Ivan JL Zhang    Date: 2018/4/24 10:36:21    Version: 1.0.0
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
    // compensated data result
    public struct CompDataResult
    {
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_WIDTH * MAX_HEIGHT * 3)]
        public byte[] pucCompData;      // compensated data in gray level with BMP file header 54 bytes
        [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_FLASH_SIZE_QHD)]
        public byte[] pucFlhCompData;           // compensated data for flash
        public byte ucJudgmentResult;           // judgment result
    };
}
