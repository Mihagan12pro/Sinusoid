
// SinusoidDoc.h: интерфейс класса CSinusoidDoc 
//



#pragma once



class CSinusoidView;
class CMainFrm;
class CControlTreeView;
class CNonModal;

class CSinusoidDoc : public CDocument
{
protected: // создать только из сериализации
	CSinusoidDoc() noexcept;
	DECLARE_DYNCREATE(CSinusoidDoc)

// Атрибуты
public:
	//static SinusoidFunction *sinusoida ;
	CControlTreeView* m_pTreeView;
	CSinusoidView *m_pView;
	CNonModal *m_NonModal;
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
	bool m_bCoord, m_bSinus, m_bHatch, m_bHatch45,m_bBrush;
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
public:
	afx_msg void OnCoordsEventHandler();
	afx_msg void OnSinusEventHandler();
	afx_msg void OnUpdateCoordsUI(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSinusUI(CCmdUI* pCmdUI);
	afx_msg void OnHatchEventHandler();
	afx_msg void OnHatch45EventHandler();
	afx_msg void OnBrushEventHandler();
	afx_msg void OnUpdateBrushUI(CCmdUI* pCmdUI);
	afx_msg void OnUpdateHatchUI(CCmdUI* pCmdUI);
	afx_msg void OnUpdateHatch45UI(CCmdUI* pCmdUI);
	afx_msg void OnObjectsDlg();
	afx_msg void OnNonModal();
};
