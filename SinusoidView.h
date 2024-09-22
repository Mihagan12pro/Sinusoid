
// SinusoidView.h: интерфейс класса CSinusoidView
//

#pragma once
class CSinusoidDoc;

class CSinusoidView : public CView
{
protected: // создать только из сериализации
	CSinusoidView() noexcept;
	DECLARE_DYNCREATE(CSinusoidView)


// Атрибуты
public:
	
	CSinusoidDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CSinusoidView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	double f(double x);

	double EquationSolver();

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в SinusoidView.cpp
inline CSinusoidDoc* CSinusoidView::GetDocument() const
   { return reinterpret_cast<CSinusoidDoc*>(m_pDocument); }
#endif

