#pragma once
#include "afxdialogex.h"
class CSinusoidView;

// CNonModal dialog

class CNonModal : public CDialogEx
{
	DECLARE_DYNAMIC(CNonModal)

public:
	CSinusoidView* pMainView;
	CNonModal(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CNonModal();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChangeColorDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAcceptcolorbtn();
	CMFCColorButton m_ColorCrl;
};
