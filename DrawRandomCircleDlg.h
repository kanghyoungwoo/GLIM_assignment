
// DrawRandomCircleDlg.h: 헤더 파일
//

#pragma once

#include<iostream>
// CDrawRandomCircleDlg 대화 상자
class CDrawRandomCircleDlg : public CDialogEx
{
private:
	CImage m_image;

	void DrawRandomCircle();
	BOOL validimgPos(int x, int y);

	bool isInCircle(int x, int y, int nCenterX, int nCenterY, int nRadius);

// 생성입니다.
public:
	CDrawRandomCircleDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAWRANDOMCIRCLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
	afx_msg void OnBnClickedButtonDraw();
	afx_msg void OnBnClickedButtonAction();
	afx_msg void OnBnClickedButtonOpen();
	void UpdateDisplay();
	void moveCircle();
	void drawCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
	void LoadImageAndMarkCenter(CString& imagepath);
};
