
// SinusoidDoc.h: интерфейс класса CSinusoidDoc 
//

#include"defines.h"

#pragma once
#define Point CPoint2D
#define SinisoidFunction CSinusoidFunction

class CPoint2D
{
private:
	int amplitude;//Высота "волны", она же амплитуда
	int width;//Ширина "волны" синусоиды. Тем меньше, тем шире
	int vecrticalCenter;
	int screenWidth;
	int x;
	const double PI = 3.14;
	
public:
	CPoint2D(int _x, int _amp, int _width, int _vecrtCent,int _scrWdth)
	{
		x = _x;
		amplitude = _amp;
		width = _width;
		vecrticalCenter = _vecrtCent;
		screenWidth = _scrWdth;
	}

	int X()
	{
		return x;
	}

	int Y()
	{
		return vecrticalCenter + static_cast<int>(amplitude * sin(width * 2 * PI * x / screenWidth));
	}
};

class CSinusoidFunction
{

};







class CSinusoidDoc : public CDocument
{
protected: // создать только из сериализации
	CSinusoidDoc() noexcept;
	DECLARE_DYNCREATE(CSinusoidDoc)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CSinusoidDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
