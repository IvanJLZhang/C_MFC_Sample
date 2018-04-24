using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using C_WINFORM_Sample.Model;
using static C_WINFORM_Sample.Model.ColorDataSrc;
namespace C_WINFORM_Sample
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;
        }
        public const int MAX_WIDTH = 1440;
        public const int MAX_HEIGHT = 2880;
        public const int DEMURA_CFG_SIZE = 256;
        public const Int32 MAX_FLASH_SIZE_QHD = 32 * 1024 * 1024 / 8;	// 32 Mb
        delegate int RadFunc(IntPtr color_src, IntPtr data_buf, IntPtr data_result);
        ColorDataSrc colorDataSrc;
        DataBuf dataBuf;
        CompDataResult compDataResult;
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void funcFileProc(double[] dest, string filePath, int nHeight, int nWidth, int i, int y)
        {
            if (!File.Exists(filePath))
                return;
            int index = 0;
            using (var fileStream = File.OpenRead(filePath))
            {
                var reader = new StreamReader(fileStream);
                while (!reader.EndOfStream)
                {
                    var line = reader.ReadLine();
                    var values = line.Split(',');
                    foreach (var item in values)
                    {
                        if (!string.IsNullOrEmpty(item))
                        {
                            Double.TryParse(item, out double result);
                            dest[index++] = result;
                        }
                    }
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.button1.Enabled = false;
            DllInvoke dllInvoke = new DllInvoke("Rad.dll");

            colorDataSrc = new ColorDataSrc()
            {
                pd000_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pd000_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pd000_B = new double[MAX_WIDTH * MAX_HEIGHT],

                pd016_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pd016_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pd016_B = new double[MAX_WIDTH * MAX_HEIGHT],

                pd032_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pd032_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pd032_B = new double[MAX_WIDTH * MAX_HEIGHT],

                pd064_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pd064_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pd064_B = new double[MAX_WIDTH * MAX_HEIGHT],

                pd096_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pd096_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pd096_B = new double[MAX_WIDTH * MAX_HEIGHT],

                pd128_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pd128_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pd128_B = new double[MAX_WIDTH * MAX_HEIGHT],

                pd160_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pd160_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pd160_B = new double[MAX_WIDTH * MAX_HEIGHT],

                pd192_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pd192_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pd192_B = new double[MAX_WIDTH * MAX_HEIGHT],

                pd224_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pd224_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pd224_B = new double[MAX_WIDTH * MAX_HEIGHT],

                pucBmpSrc = new byte[MAX_WIDTH * MAX_HEIGHT * 3],
                pucDllCtrl = new byte[DEMURA_CFG_SIZE],
            };

            dataBuf = new DataBuf()
            {
                pdBuf0_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf1_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf2_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf3_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf4_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf5_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf6_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf7_R = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf8_R = new double[MAX_WIDTH * MAX_HEIGHT],

                pdBuf0_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf1_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf2_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf3_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf4_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf5_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf6_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf7_G = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf8_G = new double[MAX_WIDTH * MAX_HEIGHT],

                pdBuf0_B = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf1_B = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf2_B = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf3_B = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf4_B = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf5_B = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf6_B = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf7_B = new double[MAX_WIDTH * MAX_HEIGHT],
                pdBuf8_B = new double[MAX_WIDTH * MAX_HEIGHT],

                pdBuf9 = new double[MAX_WIDTH * MAX_HEIGHT],
            };

            compDataResult = new CompDataResult()
            {
                pucCompData = new byte[MAX_WIDTH * MAX_HEIGHT * 3],
                pucFlhCompData = new byte[MAX_FLASH_SIZE_QHD],
            };

            #region path
            string str_exe_directory_path = Environment.CurrentDirectory + "\\";
            string str_cfg_file_full_path = str_exe_directory_path + "DMR_CFG_GVO_720_2160.rad";
            string str_capras_032_R_file_full_path = str_exe_directory_path + "Red32.csv";
            string str_capras_032_G_file_full_path = str_exe_directory_path + "Green32.csv";
            string str_capras_032_B_file_full_path = str_exe_directory_path + "Blue32.csv";
            string str_capras_064_R_file_full_path = str_exe_directory_path + "Red64.csv";
            string str_capras_064_G_file_full_path = str_exe_directory_path + "Green64.csv";
            string str_capras_064_B_file_full_path = str_exe_directory_path + "Blue64.csv";
            string str_capras_096_R_file_full_path = str_exe_directory_path + "Red96.csv";
            string str_capras_096_G_file_full_path = str_exe_directory_path + "Green96.csv";
            string str_capras_096_B_file_full_path = str_exe_directory_path + "Blue96.csv";
            string str_capras_160_R_file_full_path = str_exe_directory_path + "Red160.csv";
            string str_capras_160_G_file_full_path = str_exe_directory_path + "Green160.csv";
            string str_capras_160_B_file_full_path = str_exe_directory_path + "Blue160.csv";
            string str_capras_192_R_file_full_path = str_exe_directory_path + "Red192.csv";
            string str_capras_192_G_file_full_path = str_exe_directory_path + "Green192.csv";
            string str_capras_192_B_file_full_path = str_exe_directory_path + "Blue192.csv";
            string str_capras_224_R_file_full_path = str_exe_directory_path + "Red224.csv";
            string str_capras_224_G_file_full_path = str_exe_directory_path + "Green224.csv";
            string str_capras_224_B_file_full_path = str_exe_directory_path + "Blue224.csv";
            string str_flash_file_full_path = str_exe_directory_path + "DemuraFlash.txt";

            using (var file = new FileStream(str_cfg_file_full_path, FileMode.Open, FileAccess.Read))
            {
                file.Read(colorDataSrc.pucDllCtrl, 0, DEMURA_CFG_SIZE);
            }
            funcFileProc(colorDataSrc.pd032_R, str_capras_032_R_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd032_G, str_capras_032_G_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd032_B, str_capras_032_B_file_full_path, 2160, 720, -1, 0);

            funcFileProc(colorDataSrc.pd064_R, str_capras_064_R_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd064_G, str_capras_064_G_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd064_B, str_capras_064_B_file_full_path, 2160, 720, -1, 0);

            funcFileProc(colorDataSrc.pd096_R, str_capras_096_R_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd096_G, str_capras_096_G_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd096_B, str_capras_096_B_file_full_path, 2160, 720, -1, 0);

            funcFileProc(colorDataSrc.pd160_R, str_capras_160_R_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd160_G, str_capras_160_G_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd160_B, str_capras_160_B_file_full_path, 2160, 720, -1, 0);

            funcFileProc(colorDataSrc.pd192_R, str_capras_192_R_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd192_G, str_capras_192_G_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd192_B, str_capras_192_B_file_full_path, 2160, 720, -1, 0);

            funcFileProc(colorDataSrc.pd224_R, str_capras_224_R_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd224_G, str_capras_224_G_file_full_path, 2160, 720, -1, 0);
            funcFileProc(colorDataSrc.pd224_B, str_capras_224_B_file_full_path, 2160, 720, -1, 0);
            #endregion

            IntPtr dataSrcPtr = Marshal.AllocHGlobal(Marshal.SizeOf(colorDataSrc));
            Marshal.StructureToPtr(colorDataSrc, dataSrcPtr, false);

            IntPtr dataBufPtr = Marshal.AllocHGlobal(Marshal.SizeOf(dataBuf));
            Marshal.StructureToPtr(dataBuf, dataBufPtr, false);


            IntPtr dataResultPtr = Marshal.AllocHGlobal(Marshal.SizeOf(compDataResult));
            Marshal.StructureToPtr(compDataResult, dataResultPtr, false);


            RadFunc radFunc = (RadFunc)dllInvoke.Invoke("RadFunc", typeof(RadFunc));

            var ret = radFunc(dataSrcPtr, dataBufPtr, dataResultPtr);
            if (ret == 0)
            {
                compDataResult = (CompDataResult)Marshal.PtrToStructure(dataResultPtr, typeof(CompDataResult));
                using (var fileStream = File.Open(str_flash_file_full_path, FileMode.OpenOrCreate, FileAccess.Write))
                {
                    int DMRpatter_start = 256;
                    int compensate_crc = 2;
                    int flash_full_chksum = 2;
                    int write_size = 720 * 2160 * 3 * 3 / 8 + DMRpatter_start + compensate_crc + flash_full_chksum;
                    fileStream.Write(compDataResult.pucFlhCompData, 0, write_size);
                }
            }
            this.button1.Enabled = true;

        }
    }


}
