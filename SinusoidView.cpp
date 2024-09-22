
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

#include<vector>
using namespace std;




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


double CSinusoidView::F(double x,double b)
{
	CRect rcLocal;
	GetClientRect(&rcLocal);
	double period = rcLocal.Width() / 2;
	double amplitude = rcLocal.Height() / 2;
	double frequency = 3.14 / period * x; // Частота
	
	return amplitude * sin(frequency) - (1 * x + b); // Разность между синусом и уравнением прямой
}



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
			int y = rc.Height() / 2 + sin(-X_rad) / my;

			pDC->LineTo(x, y);
		}
		pDC->SelectObject(pOld);

		
	}
	
	if (pDoc->m_bHatch)
	{
		for (int x = 0; x < rc.Width();x++)
		{
			double X_rad = x * mx;
			int y = rc.Height() / 2 + sin(-X_rad) / my;
			/*CPen pen(PS_SOLID, 1, RGB(0, 255, 0));

			pOld = pDC->SelectObject(&pen);*/
			if (x % 20 == 0)
			{
				pDC->MoveTo(x, y);
				pDC->LineTo(x, rc.Height() / 2);

			}
			//pDC->LineTo(x, y);
			//pDC->SelectObject(pOld);
		}

	}
	if (pDoc->m_bHatch45)
	{
		pDC->MoveTo(rc.Width()/2, rc.Height() / 2);

		for (int x = rc.Width()/2; x < rc.Width();x++)
		{
			double infinum,  supremum;
			if (x % 20 == 0)
			{
				double width = (double)rc.Width() / 2;
				double b = x - rc.Width()/2; // Смещение прямой
				//f(x) = kx + b, где k - тангенс угла наклона, b - смещение прямой
				infinum  = -width;//начало интервала
				supremum =  width;//конец интервала

				
				while (fabs(supremum - infinum) > eps)
				{
					infinum = supremum - (supremum - infinum) * F(supremum,b) / (F(
						supremum,b) - F(infinum,b));
					supremum = infinum - (infinum - supremum) * F(infinum,b) / (F(
						infinum,b) - F(supremum,b));
				}

			


			}
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
