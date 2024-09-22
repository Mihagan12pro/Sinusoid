
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
		double halfX = rc.Width()/2;
		double halfY = rc.Height() / 2;
		double height = rc.Height();
		
		int step = 10;
		for (int x = 0; x < rc.Width()/2; x++)
		{
			pDC->MoveTo(x, halfY);
			if (x % step == 0 )
			{
				double b = x - halfX; // Смещение прямой

				double a = -1000.0; // Начало интервала
				double b_val = 1000.0; // Конец интервала

				double root = bisection(a, b_val, 1, b, halfY, halfX);
				double y = halfY * sin(PI / halfX * root);

				double Y = height - halfY - y;
				double X = halfX + root;
				pDC->LineTo(X, Y);
			}
		}
		//for (int x = rc.Width()/2; x < rc.Width();x++)
		//{
		//	pDC->MoveTo(0, rc.Height() / 2);
		//	double infinum,  supremum;


		//	double halfWidth = rc.Width()/2;
		//	double halfHeight = rc.Height() / 2;
		//	double height = rc.Height();

		//	if (x % 20 == 0)
		//	{
		//		double b = x - halfWidth; // Смещение прямой

		//		 infinum = -1000.0; // Начало интервала
		//		supremum = 1000.0; // Конец интервала

		//		double root = EquationSolver(infinum, supremum, 1, b, halfHeight, halfWidth);
		//		double y = halfHeight * sin(PI / halfWidth * root);

		//		double Y = height - halfHeight - y;
		//		double X = halfWidth + root;
		//		pDC->LineTo(X, Y);
		//		
		//	}
		//}


	}


	
}
//
//double CSinusoidView::EquationSolver(double a, double b, double m, double b_const, double amplitude, double period)
//{
//
//
//	double c;
//	while ((b - a) >= 1e-6)
//	{
//		c = (a + b) / 2; // Средняя точка
//		if (f(c, m, b_const, amplitude, period) == 0.0)
//		{
//			break; // c является корнем
//		}
//		else if (f(c, m, b_const, amplitude, period) * f(a, m, b_const, amplitude, period) < 0)
//		{
//			b = c; // Корень находится в левой части
//		}
//		else
//		{
//			a = c; // Корень находится в правой части
//		}
//	}
//	return (a + b) / -2; // Возвращаем среднюю точку как приближенную к корню
//}
//double CSinusoidView::f(double x, double m, double b, double amplitude, double period)
//{
//	double frequency = PI / period * x; // Частота
//	return amplitude * sin(frequency) - (1 * x + b); // Разность между синусом и уравнением прямой
//}


double CSinusoidView::f(double x, double m, double b, double amplitude, double period) {
	double frequency = PI / period * x; // Частота
	return amplitude * sin(frequency) - (1 * x + b); // Разность между синусом и уравнением прямой
}


// Метод бисекции
double CSinusoidView::bisection(double a, double b, double m, double b_const, double amplitude, double period) {


	double c;
	while ((b - a) >= 1e-6)
	{
		c = (a + b) / 2; // Средняя точка
		if (f(c, m, b_const, amplitude, period) == 0.0)
		{
			break; // c является корнем
		}
		else if (f(c, m, b_const, amplitude, period) * f(a, m, b_const, amplitude, period) < 0)
		{
			b = c; // Корень находится в левой части
		}
		else
		{
			a = c; // Корень находится в правой части
		}
	}
	return (a + b) / -2; // Возвращаем среднюю точку как приближенную к корню
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
