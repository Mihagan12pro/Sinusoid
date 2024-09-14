// CControlTreeView.cpp: файл реализации
//

#include "pch.h"
#include "Sinusoid.h"
#include "CControlTreeView.h"


// CControlTreeView

IMPLEMENT_DYNCREATE(CControlTreeView, CTreeView)

CControlTreeView::CControlTreeView()
{

}

CControlTreeView::~CControlTreeView()
{
}

BEGIN_MESSAGE_MAP(CControlTreeView, CTreeView)
END_MESSAGE_MAP()


// Диагностика CControlTreeView

#ifdef _DEBUG
void CControlTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CControlTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CControlTreeView
