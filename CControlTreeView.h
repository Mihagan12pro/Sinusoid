#pragma once
#include"afxcview.h"

// Просмотр CControlTreeView

class CControlTreeView
	: public CTreeView
{
	DECLARE_DYNCREATE(CControlTreeView)

protected:
	CControlTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CControlTreeView();

public:
	void FillTree();
	HTREEITEM  m_hCoord, m_hSinus, m_hHatch;
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


