
// C_MFC_SampleDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "C_MFC_Sample.h"
#include "C_MFC_SampleDlg.h"
#include "afxdialogex.h"
#include "RadProc.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CC_MFC_SampleDlg 對話方塊




CC_MFC_SampleDlg::CC_MFC_SampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CC_MFC_SampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CC_MFC_SampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CC_MFC_SampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CC_MFC_SampleDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CC_MFC_SampleDlg 訊息處理常式

BOOL CC_MFC_SampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CC_MFC_SampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CC_MFC_SampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CC_MFC_SampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString GetModuleDir()
{
	HMODULE module = GetModuleHandle(0);
	char pFileName[MAX_PATH];
	GetModuleFileName(module, pFileName, MAX_PATH);
	CString csFullPath(pFileName);
	int nPos = csFullPath.ReverseFind(_T('\\'));
	if (nPos < 0)
		return CString("");
	else
		return csFullPath.Left(nPos);
}

int funcFileProc(double *pfDestAddr, CString strFullFileName, int nHeight, int nWidth, int i_exposure_time, int rgbg_panel)
{
	FILE    *fp;
	char *pcFileName;
	int nFileLen;
	unsigned char *pucFileBuf;
	char ucBuf[36] = { 0 };
	int nIndex = 0;

	pcFileName = strFullFileName.GetBuffer();
	fp = fopen(pcFileName, "rb");
	if (fp == NULL)
	{
		MessageBox(NULL, "File open failed.", "Error", MB_OK);
		return 1;
	}

	fseek(fp, 0, SEEK_END); // seek to end of file
	nFileLen = ftell(fp); // get current file pointer
	fseek(fp, 0, SEEK_SET); // seek back to beginning of file

	pucFileBuf = new unsigned char[nFileLen];

	fread(pucFileBuf, sizeof(unsigned char), nFileLen, fp);

	int cnt = 0;
	int front = 0, front2 = 0, num = 0;
	unsigned char tmp[16] = { 0 };
	unsigned char tmp2[16] = { 0 }; // for scientific notation
	bool b_new_line_end = false;
	bool b_scientific_notation = false;
	bool b_dot = false;
	bool b_negative = false;
	bool b_negative_for_scientific_notation = false;
	bool b_positive_for_scientific_notation = false;

	CString str_err_msg;

	while (true) {
		switch (pucFileBuf[cnt]) {
		case 0x0D:
			cnt++;
			break;
		case ',':
			if (0 == front) {
				str_err_msg = "there's something wrong in csv value, plz check : no value";
				MessageBox(NULL, str_err_msg, "Error", MB_OK);
				return 3;
			}
			if (rgbg_panel && num % 2 == 1) { //move next. special case for rgbg panel...
				front = 0;
				front2 = 0;
				cnt++;
				num++;
				break;
			}
			b_new_line_end = false;
			tmp[front] = '\0';
			tmp2[front2] = '\0';
			if (false == b_scientific_notation) {
				if (rgbg_panel) {
					pfDestAddr[num / 2] = atof((char*)tmp);
				}
				else {
					pfDestAddr[num] = atof((char*)tmp);
				}
			}
			else {
				//double ss = atof((char*)tmp) * pow(0.1, -1 * atoi((char*)tmp2));
				if (b_negative_for_scientific_notation == true &&
					b_positive_for_scientific_notation == false) {
					if (rgbg_panel) {
						pfDestAddr[num / 2] = atof((char*)tmp) * pow(0.1, atoi((char*)tmp2));
					}
					else {
						pfDestAddr[num] = atof((char*)tmp) * pow(0.1, atoi((char*)tmp2));
					}
				}
				else if (b_negative_for_scientific_notation == false &&
					b_positive_for_scientific_notation == true) {
					//double ss = atof((char*)tmp) * pow(10.0, atoi((char*)tmp2));
					if (rgbg_panel) {
						pfDestAddr[num / 2] = atof((char*)tmp) * pow(10.0, atoi((char*)tmp2));
					}
					else {
						pfDestAddr[num] = atof((char*)tmp) * pow(10.0, atoi((char*)tmp2));
					}


				}
				else {
					str_err_msg = "there's something wrong in csv value, plz check : " +
						CString(tmp);
					MessageBox(NULL, str_err_msg, "Error", MB_OK);
					return 2;
				}
			}

			if (i_exposure_time != -1) {//Mean BOE...
				if (rgbg_panel) {
					pfDestAddr[num / 2] = (pfDestAddr[num / 2] / i_exposure_time) * 260;
				}
				else {
					pfDestAddr[num] = (pfDestAddr[num] / i_exposure_time) * 260;
				}
			}

			front = 0;
			front2 = 0;
			num++;
			cnt++;
			b_scientific_notation = false;
			b_dot = false;
			b_negative = false;
			b_negative_for_scientific_notation = false;
			b_positive_for_scientific_notation = false;
			break;
		case 0x0a:
			if (0 == front) {
				str_err_msg = "there's something wrong in csv value, plz check : no value";
				MessageBox(NULL, str_err_msg, "Error", MB_OK);
				return 3;
			}

			if (rgbg_panel && num % 2 == 1) { //move next. special case for rgbg panel...
				front = 0;
				front2 = 0;
				num++;
				cnt++;
				break;
			}
			b_new_line_end = true;
			tmp[front] = '\0';
			tmp2[front2] = '\0';
			if (false == b_scientific_notation) {
				pfDestAddr[num] = atof((char*)tmp);
			}
			else {
				//double ss = atof((char*)tmp) * pow(0.1, -1 * atoi((char*)tmp2));
				if (b_negative_for_scientific_notation == true &&
					b_positive_for_scientific_notation == false) {
					if (rgbg_panel) {
						pfDestAddr[num / 2] = atof((char*)tmp) * pow(0.1, atoi((char*)tmp2));
					}
					else {
						pfDestAddr[num] = atof((char*)tmp) * pow(0.1, atoi((char*)tmp2));
					}

				}
				else if (b_negative_for_scientific_notation == false &&
					b_positive_for_scientific_notation == true) {

					if (rgbg_panel) {
						pfDestAddr[num / 2] = atof((char*)tmp) * pow(10.0, atoi((char*)tmp2));
					}
					else {
						pfDestAddr[num] = atof((char*)tmp) * pow(10.0, atoi((char*)tmp2));
					}

				}
				else {
					str_err_msg = "there's something wrong in csv value, plz check : " +
						CString(tmp);
					MessageBox(NULL, str_err_msg, "Error", MB_OK);
					return 2;
				}
			}

			if (i_exposure_time != -1) {//Mean BOE...
				if (rgbg_panel) {
					pfDestAddr[num / 2] = (pfDestAddr[num / 2] / i_exposure_time) * 260;
				}
				else {
					pfDestAddr[num] = (pfDestAddr[num] / i_exposure_time) * 260;
				}

			}

			front = 0;
			front2 = 0;
			num++;
			cnt++;
			b_scientific_notation = false;
			b_dot = false;
			b_negative = false;
			b_negative_for_scientific_notation = false;
			b_positive_for_scientific_notation = false;
			break;
		case 'e':
			b_scientific_notation = true;
			cnt++;
			break;
		case '.':
			if (false == b_dot) {
				b_dot = true;

				if (false == b_scientific_notation) {
					tmp[front++] = pucFileBuf[cnt++];
				}
				else {
					tmp2[front2++] = pucFileBuf[cnt++];
				}
			}
			else {
				str_err_msg = "there's something wrong in csv value, plz check : " +
					CString(tmp) + ".";
				MessageBox(NULL, str_err_msg, "Error", MB_OK);
				return 2;
			}
			break;
		case '-':
			if (false == b_negative) {
				b_negative = true;

				if (false == b_scientific_notation) {
					if (0 == front) {
						tmp[front++] = pucFileBuf[cnt++];
					}
					else {
						str_err_msg = "there's something wrong in csv value, plz check : " +
							CString(tmp) + "-";
						MessageBox(NULL, str_err_msg, "Error", MB_OK);
						return 2;
					}
				}
				else {
					if (0 == front2) {
						b_negative_for_scientific_notation = true;
					}
					else {
						str_err_msg = "there's something wrong in csv value, plz check : " +
							CString((char*)tmp) + "e" + CString((char*)tmp2) + "-";
						MessageBox(NULL, str_err_msg, "Error", MB_OK);
						return 2;
					}
				}
			}
			else {
				if (false == b_scientific_notation) {
					str_err_msg = "there's something wrong in csv value, plz check : " +
						CString((char*)tmp) + "-";
					MessageBox(NULL, str_err_msg, "Error", MB_OK);
					return 2;
				}
				else {
					if (0 == front2) {
						b_negative_for_scientific_notation = true;
						cnt++;
					}
					else {
						str_err_msg = "there's something wrong in csv value, plz check : " +
							CString((char*)tmp) + CString((char*)tmp2) + "-";
						MessageBox(NULL, str_err_msg, "Error", MB_OK);
						return 2;
					}
				}
			}
			break;
		case '+':
			if (false == b_scientific_notation) {
				str_err_msg = "there's something wrong in csv value, plz check : " +
					CString((char*)tmp) + "-";
				MessageBox(NULL, str_err_msg, "Error", MB_OK);
				return 2;
			}
			else {
				if (0 == front2) {
					b_positive_for_scientific_notation = true;
					cnt++;
				}
				else {
					str_err_msg = "there's something wrong in csv value, plz check : " +
						CString((char*)tmp) + CString((char*)tmp2) + "-";
					MessageBox(NULL, str_err_msg, "Error", MB_OK);
					return 2;
				}
			}
			break;
		case '0':	case '1':	case '2':	case '3':	case '4':
		case '5':	case '6':	case '7':	case '8':	case '9':
			if (false == b_scientific_notation) {
				tmp[front++] = pucFileBuf[cnt++];
			}
			else {
				tmp2[front2++] = pucFileBuf[cnt++];
			}
			break;
		default:
			cnt++;
			break;
		}

		if (cnt >= nFileLen) {
			if (false == b_new_line_end) {//Last value no \r\n should check
				if (rgbg_panel) { //move next. special case for rgbg panel...
					break;
				}
				if (0 == front) {
					str_err_msg = "there's something wrong in csv value, plz check : no value";
					MessageBox(NULL, str_err_msg, "Error", MB_OK);
					return 3;
				}
				tmp[front] = '\0';
				tmp2[front2] = '\0';
				if (false == b_scientific_notation) {
					pfDestAddr[num] = atof((char*)tmp);
				}
				else {
					//double ss = atof((char*)tmp) * pow(0.1, -1 * atoi((char*)tmp2));
					if (b_negative_for_scientific_notation == true &&
						b_positive_for_scientific_notation == false) {

						if (rgbg_panel) {
							pfDestAddr[num / 2] = atof((char*)tmp) * pow(0.1, atoi((char*)tmp2));
						}
						else {
							pfDestAddr[num] = atof((char*)tmp) * pow(0.1, atoi((char*)tmp2));
						}

					}
					else if (b_negative_for_scientific_notation == false &&
						b_positive_for_scientific_notation == true) {
						if (rgbg_panel) {
							pfDestAddr[num / 2] = atof((char*)tmp) * pow(10.0, atoi((char*)tmp2));
						}
						else {
							pfDestAddr[num] = atof((char*)tmp) * pow(10.0, atoi((char*)tmp2));
						}

					}
					else {
						str_err_msg = "there's something wrong in csv value, plz check : " +
							CString((char*)tmp);
						MessageBox(NULL, str_err_msg, "Error", MB_OK);
						return 2;
					}
				}

				if (i_exposure_time != -1) {//Mean BOE...
					if (rgbg_panel) {
						pfDestAddr[num / 2] = (pfDestAddr[num / 2] / i_exposure_time) * 260;
					}
					else {
						pfDestAddr[num] = (pfDestAddr[num] / i_exposure_time) * 260;
					}

				}

				front = 0;
				front2 = 0;
				num++;
				cnt++;
				b_scientific_notation = false;
				b_dot = false;
				b_negative = false;
				b_negative_for_scientific_notation = false;
				b_positive_for_scientific_notation = false;
			}
			break;
		}

		if (rgbg_panel) {
			if (num / 2 > nHeight * nWidth) {
				MessageBox(NULL, "The bmp width and height is not fit to csv file(column and row).", "Error", MB_OK);
				return 2;
			}
		}
		else {
			if (num > nHeight * nWidth) {
				MessageBox(NULL, "The bmp width and height is not fit to csv file(column and row).", "Error", MB_OK);
				return 2;
			}
		}


	}

	fclose(fp);

	delete pucFileBuf;
	return 0;
}

ColorDataSrc color_data_src;
DataBuf data_buf;
CompDataResult comp_data_result;

void CC_MFC_SampleDlg::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CString str_exe_directory_path = GetModuleDir() + "\\";
	CString str_cfg_file_full_path = str_exe_directory_path + "DMR_CFG_GVO_720_2160.rad";
	CString str_dll_file_full_path = str_exe_directory_path + "Rad.dll";
	CString str_capras_032_R_file_full_path = str_exe_directory_path + "Red32.csv";
	CString str_capras_032_G_file_full_path = str_exe_directory_path + "Green32.csv";
	CString str_capras_032_B_file_full_path = str_exe_directory_path + "Blue32.csv";
	CString str_capras_064_R_file_full_path = str_exe_directory_path + "Red64.csv";
	CString str_capras_064_G_file_full_path = str_exe_directory_path + "Green64.csv";
	CString str_capras_064_B_file_full_path = str_exe_directory_path + "Blue64.csv";
	CString str_capras_096_R_file_full_path = str_exe_directory_path + "Red96.csv";
	CString str_capras_096_G_file_full_path = str_exe_directory_path + "Green96.csv";
	CString str_capras_096_B_file_full_path = str_exe_directory_path + "Blue96.csv";
	CString str_capras_160_R_file_full_path = str_exe_directory_path + "Red160.csv";
	CString str_capras_160_G_file_full_path = str_exe_directory_path + "Green160.csv";
	CString str_capras_160_B_file_full_path = str_exe_directory_path + "Blue160.csv";
	CString str_capras_192_R_file_full_path = str_exe_directory_path + "Red192.csv";
	CString str_capras_192_G_file_full_path = str_exe_directory_path + "Green192.csv";
	CString str_capras_192_B_file_full_path = str_exe_directory_path + "Blue192.csv";
	CString str_capras_224_R_file_full_path = str_exe_directory_path + "Red224.csv";
	CString str_capras_224_G_file_full_path = str_exe_directory_path + "Green224.csv";
	CString str_capras_224_B_file_full_path = str_exe_directory_path + "Blue224.csv";
	CString str_flash_file_full_path = str_exe_directory_path + "DemuraFlash.hex";

	typedef int(*importFunction)(ColorDataSrc*, DataBuf*, CompDataResult*);

	// Load DLL file
	HINSTANCE hinstLib = LoadLibrary(str_dll_file_full_path);
	if (hinstLib == NULL)
	{
		MessageBox("Unable to find DLL function.", "Error");
		return;
	}

	// Get function pointer
	importFunction RadFunc = (importFunction)GetProcAddress(hinstLib, "RadFunc");
	if (RadFunc == NULL)
	{
		FreeLibrary(hinstLib);
		MessageBox("Unable to find DLL function.", "Error");
		return;
	}

	FILE *pFile;
	pFile = fopen(str_cfg_file_full_path.GetBuffer(), "rb");
	fread(color_data_src.pucDllCtrl, 1, DEMURA_CFG_SIZE, pFile);

	funcFileProc(color_data_src.pd032_R, str_capras_032_R_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd032_G, str_capras_032_G_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd032_B, str_capras_032_B_file_full_path, 2160, 720, -1, 0);

	funcFileProc(color_data_src.pd064_R, str_capras_064_R_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd064_G, str_capras_064_G_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd064_B, str_capras_064_B_file_full_path, 2160, 720, -1, 0);

	funcFileProc(color_data_src.pd096_R, str_capras_096_R_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd096_G, str_capras_096_G_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd096_B, str_capras_096_B_file_full_path, 2160, 720, -1, 0);

	funcFileProc(color_data_src.pd160_R, str_capras_160_R_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd160_G, str_capras_160_G_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd160_B, str_capras_160_B_file_full_path, 2160, 720, -1, 0);

	funcFileProc(color_data_src.pd192_R, str_capras_192_R_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd192_G, str_capras_192_G_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd192_B, str_capras_192_B_file_full_path, 2160, 720, -1, 0);

	funcFileProc(color_data_src.pd224_R, str_capras_224_R_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd224_G, str_capras_224_G_file_full_path, 2160, 720, -1, 0);
	funcFileProc(color_data_src.pd224_B, str_capras_224_B_file_full_path, 2160, 720, -1, 0);

	/* major operation requirement from DLL */
	if (0 == RadFunc(&color_data_src, &data_buf, &comp_data_result))
	{
		FILE *fp_32;
		errno_t err;
		int k;
		int data_size;
		int DMRpatter_start = 256;
		int compensate_crc = 2;
		int flash_full_chksum = 2;
		data_size = 720 * 2160 * 3 * 3 / 8;
		err = fopen_s(&fp_32, str_flash_file_full_path, "wb");
		for (k = 0; k < (data_size + DMRpatter_start + compensate_crc + flash_full_chksum); k++)
		{
			fwrite((char*)(comp_data_result.pucFlhCompData + k), 1, sizeof(char), fp_32);
		}
		fclose(fp_32);

		MessageBox("Demura Finish!.", "Info");
	}
	else
	{

		MessageBox("Demura Fail!.", "Error");
	}

}
