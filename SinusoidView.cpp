
// SinusoidView.cpp: реализация класса CSinusoidView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Sinusoid.h"
#endif

#include "SinusoidDoc.h"
#include "SinusoidView.h"

#include<vector>







#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSinusoidView

IMPLEMENT_DYNCREATE(CSinusoidView, CView)

BEGIN_MESSAGE_MAP(CSinusoidView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Создание или уничтожение CSinusoidView

CSinusoidView::CSinusoidView() noexcept
{
	// TODO: добавьте код создания

}

CSinusoidView::~CSinusoidView()
{
}

BOOL CSinusoidView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CSinusoidView

void CSinusoidView::OnDraw(CDC* pDC)
{
	//CPaintDC dc(this);

	

	CSinusoidDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rc;
	GetClientRect(&rc);
	CPen* pOld;

	double mx = 2 * 3.14 / rc.Width();
	double my = 2.f / rc.Height();

	if (pDoc->m_bCoord)
	{
		pDC->MoveTo(0, rc.Height() / 2);
		pDC->LineTo(rc.Width(), rc.Height() / 2);

		pDC->MoveTo(0, rc.Height() / 2);
	}

	if (pDoc->m_bSinus)
	{
		CPen pen(PS_SOLID, 1, RGB(255, 0, 0));

		 pOld = pDC->SelectObject(&pen);

		//pDC->MoveTo(0, rc.Height() / 2);
		

		for (int x = 0; x < rc.Width();x++)
		{
			double X_rad = x * mx;
			int y = rc.Height() / 2 + sin(X_rad) / my;

			pDC->LineTo(x, y);
		}
		pDC->SelectObject(pOld);

		
	}
	if (pDoc->m_bHatch)
	{
		for (int x = 0; x < rc.Width();x++)
		{
			double X_rad = x * mx;
			int y = rc.Height() / 2 + sin(X_rad) / my;
			
			if (x % 20 == 0)
			{
				pDC->MoveTo(x, y);
				pDC->LineTo(x,rc.Height()/2);
			}
			//pDC->LineTo(x, y);
		}

	}
	if (pDoc->m_bHatch45)
	{
		

		bool first = true;
		int oldX;

		pDC->MoveTo(rc.Width()/2, rc.Height() / 2);
		for (int x = 0; x < rc.Width();x++)
		{
			double X_rad = x * mx;
			int y = rc.Height() / 2 + sin(X_rad) / my;

			
				if (x % 40 == 0)
				{
					/*pDC->MoveTo(x, y);
					pDC->LineTo(x, rc.Height() / 2);*/
					if (!first)
					{
						pDC->MoveTo(oldX, rc.Height() / 2);
						pDC->LineTo(x, y);
						
						
						oldX = x;
					}
					else
					{
						first = false;
						oldX = x;
					}
				}
			
		
			//pDC->LineTo(x, y);
		}
		
	}
	


	
}


// Печать CSinusoidView

BOOL CSinusoidView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSinusoidView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSinusoidView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CSinusoidView

#ifdef _DEBUG
void CSinusoidView::AssertValid() const
{
	CView::AssertValid();
}

void CSinusoidView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSinusoidDoc* CSinusoidView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSinusoidDoc)));
	return (CSinusoidDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CSinusoidView
