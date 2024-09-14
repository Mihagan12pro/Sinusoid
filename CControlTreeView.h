#pragma once
#include"afxcview.h"
class CSinusoidDoc;
// Просмотр CControlTreeView

class CControlTreeView
	: public CTreeView
{
	DECLARE_DYNCREATE(CControlTreeView)

protected:
	CControlTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CControlTreeView();

public:
	CSinusoidDoc* m_pDoc;
	

	void FillTree();
	HTREEITEM  m_hCoord, m_hSinus, m_hHatch, m_hMain;
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


