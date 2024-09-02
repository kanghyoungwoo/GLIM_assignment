
// DrawRandomCircleDlg.cpp: 구현 파일
//
#include <iostream>
#include "pch.h"
#include "framework.h"
#include "DrawRandomCircle.h"
#include "DrawRandomCircleDlg.h"
#include "afxdialogex.h"
#include <windows.h>
#include "shellapi.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#pragma comment(linker, "/entry:winmaincrtstartup /subsystem:console")
#endif

#define MAX_PATH 256
#define TIME 20
#define XLENGTH 10
using namespace std;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDrawRandomCircleDlg 대화 상자



CDrawRandomCircleDlg::CDrawRandomCircleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DRAWRANDOMCIRCLE_DIALOG, pParent)
	, m_x1(0)
	, m_y1(0)
	, m_x2(0)
	, m_y2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawRandomCircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X1, m_x1);
	DDX_Text(pDX, IDC_EDIT_Y1, m_y1);
	DDX_Text(pDX, IDC_EDIT_X2, m_x2);
	DDX_Text(pDX, IDC_EDIT_Y2, m_y2);
}

BEGIN_MESSAGE_MAP(CDrawRandomCircleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DRAW, &CDrawRandomCircleDlg::OnBnClickedButtonDraw)
	ON_BN_CLICKED(IDC_BUTTON_ACTION, &CDrawRandomCircleDlg::OnBnClickedButtonAction)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CDrawRandomCircleDlg::OnBnClickedButtonOpen)
	//ON_STN_CLICKED(IDC_STATIC_END, &CDrawRandomCircleDlg::OnStnClickedStaticEnd)
END_MESSAGE_MAP()


// CDrawRandomCircleDlg 메시지 처리기

BOOL CDrawRandomCircleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDrawRandomCircleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDrawRandomCircleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDrawRandomCircleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDrawRandomCircleDlg::OnBnClickedButtonDraw()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nWidth = 1200;
	int nHeight = 530;
	int nBpp = 8;
	int nGray = 80;

	m_image.Create(nWidth, -nHeight, nBpp);

	if (nBpp == 8)
	{
		static RGBQUAD rgb[256];
		for (int i = 0;i < 256;i++)
		{
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
			m_image.SetColorTable(0, 256, rgb);
		}
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	// 이렇게 초기화 대신 memset이 더 간단하다
	//for (int j = y1 - nRadius;j < 2 * nRadius;j++)
	//{
	//	for (int i = x1 - nRadius;i < 2 * nRadius;i++)
	//	{
	//		fm[j * nPitch + i] = nGray;
	//	}
	//}
	//memset(fm, 0, nWidth * nHeight);
	memset(fm, 0, nWidth * nHeight);



	// Update Display함수로 대체
	//CClientDC dc(this); // 이 다이얼로그에 만들겠다
	//m_image.Draw(dc, 0, 0); //0 * 0이 시작위치
	UpdateDisplay();
	DrawRandomCircle();

}

void CDrawRandomCircleDlg::DrawRandomCircle()
{
	int x1 = GetDlgItemInt(IDC_EDIT_X1);
	int y1 = GetDlgItemInt(IDC_EDIT_Y1);


	int nRadius = rand() % 10 + 20;

	int x = x1 - nRadius;
	int y = y1 - nRadius;

	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	int nGray = 100;

	memset(fm, 0, nWidth * nHeight);


	if ((x1 - nRadius) >= 0 && (x1 + nRadius) < nWidth && (y1 - nRadius) >= 0 && (y1 + nRadius) < abs(nHeight))
	{
		for (int j = y; j < y + nRadius * 2; j++)
		{
			for (int i = x;i < x + nRadius * 2;i++)
			{
				if (isInCircle(i, j, x1, y1, nRadius))
				{
					fm[j * nPitch + i] = nGray;
				}
			}
		}
	}
	else
	{
		AfxMessageBox(_T("원 범위가 이미지 영역을 벗어났습니다. 좌표를 다시 설정해주세요."));
	}

	UpdateDisplay();
	//Sleep(10000);

}

bool CDrawRandomCircleDlg::isInCircle(int x, int y, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = x - nCenterX; // 왼쪽
	double dY = y - nCenterY; // 상단
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius*nRadius)
	{
		bRet = true;
	}

	return bRet;
}
void CDrawRandomCircleDlg::moveCircle()
{
	int x1 = GetDlgItemInt(IDC_EDIT_X1);
	int y1 = GetDlgItemInt(IDC_EDIT_Y1);
	int x2 = GetDlgItemInt(IDC_EDIT_X2);
	int y2 = GetDlgItemInt(IDC_EDIT_Y2);

	int nRadius = rand() % 10 + 20;

	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	int nGray = 100;

	memset(fm, 0, nWidth * nHeight);

	//drawCircle(fm, ++nSttX, ++nSttY, nRadius, nGray); // 좌상단 값을 입력 받아 네모를 그림
	CString g_strFileImage;
	TCHAR path[MAX_PATH] = { 0, };
	GetModuleFileName(NULL, path, MAX_PATH);

	PathRemoveFileSpec(path); // 실행파일 경로에서 디렉토리 경로만 얻기
	PathAppend(path, _T("image")); // 이미지 폴더 추가

	
	//이미지 폴더 없으면 생성
	if (!PathFileExists(path))
	{
		if (!CreateDirectory(path, NULL))
		{
			AfxMessageBox(_T("Failed to create directory."));
			return;
		}
	}

	for (int i = 0; i <= TIME; i++)
	{


		g_strFileImage.Format(_T("%s\\circle_%d.bmp"), path, i);
		HRESULT hr = m_image.Save(g_strFileImage, Gdiplus::ImageFormatBMP);
		if (FAILED(hr))
		{
			// Handle saving error
			CString strError;
			strError.Format(_T("이미지 저장 실패! %s"), (LPCTSTR)g_strFileImage);
			AfxMessageBox(strError);
			return;
		}
		int dx = (x2 - x1) / TIME; // TIME개의 단계
		int dy = (y2 - y1) / TIME;

		int cx = x1 + dx * i;
		int cy = y1 + dy * i;

		memset(fm, 0, nWidth * nHeight);
		drawCircle(fm, cx - nRadius, cy - nRadius, nRadius, nGray);
		//Sleep(20);

	}

	UpdateDisplay();


}

void CDrawRandomCircleDlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

BOOL CDrawRandomCircleDlg::validimgPos(int x, int y)
{
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	CRect rect(0, 0, nWidth, nHeight);

	return rect.PtInRect(CPoint(x, y));
}

void CDrawRandomCircleDlg::drawCircle(unsigned char *fm, int x,int y, int nRadius, int nGray) // 좌상단 값을 입력받아 우하단 으로가면서 그리는 동그라미
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2; j++) //좌상단(x,y) -> 우하단(x + nRadius * 2, y + nRadius * 2) 으로 가는 네모
	{
		for (int i = x;i < x + nRadius * 2;i++)
		{
			if (isInCircle(i, j, nCenterX, nCenterY, nRadius))
			{
				fm[j * nPitch + i] = nGray;
			}
		}
	}
}

void CDrawRandomCircleDlg::OnBnClickedButtonAction()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	moveCircle();
	
}


void CDrawRandomCircleDlg::OnBnClickedButtonOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_image != NULL)
	{
		m_image.Destroy();
	}

	CFileDialog dlg(TRUE, _T("bmp"), NULL, OFN_FILEMUSTEXIST, _T("Image Files (*.bmp;*.jpg)|*.bmp;*.jpg|All Files (*.*)|*.*||"));


	TCHAR path[MAX_PATH] = { 0, };
	GetModuleFileName(NULL, path, MAX_PATH);


	if (dlg.DoModal() == IDOK)
	{
		CString imagePath = dlg.GetPathName();
		LoadImageAndMarkCenter(imagePath);
	}

}

void CDrawRandomCircleDlg::LoadImageAndMarkCenter(CString& imagepath)
{
	m_image.Load(imagepath);
	UpdateDisplay();

	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	int sumX = 0;
	int sumY = 0;
	int nGray = 100;
	int count = 0;

	for (int j = 0;j < nHeight;j++)
	{
		for (int i = 0;i < nWidth;i++)
		{
			if (fm[j * nPitch + i] == nGray)
			{
				sumX += i;
				sumY += i;
				count++;
			}
		}
	}

	if (count > 0)
	{
		int centerX = sumX / count;
		int centerY = sumY / count;

		CClientDC dc(this);

		CPen pen(PS_SOLID, 1, RGB(0, 255, 0));
		CPen* pOldPen = dc.SelectObject(&pen);

		dc.MoveTo(centerX - XLENGTH, centerY - XLENGTH);
		dc.LineTo(centerX + XLENGTH, centerY + XLENGTH);

		dc.MoveTo(centerX - XLENGTH, centerY + XLENGTH);
		dc.LineTo(centerX + XLENGTH, centerY - XLENGTH);

		CString coordText;
		coordText.Format(_T("(%d, %d)"), centerX, centerY);
		dc.TextOutW(centerX + 15, centerY, coordText);

		dc.SelectObject(pOldPen);

	}

}
