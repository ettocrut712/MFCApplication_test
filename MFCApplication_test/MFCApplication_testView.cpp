
// MFCApplication_testView.cpp : implementation of the CMFCApplicationtestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication_test.h"
#endif

#include "MFCApplication_testDoc.h"
#include "MFCApplication_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationtestView

IMPLEMENT_DYNCREATE(CMFCApplicationtestView, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationtestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplicationtestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplicationtestView construction/destruction

CMFCApplicationtestView::CMFCApplicationtestView()
{
	// TODO: add construction code here

}

CMFCApplicationtestView::~CMFCApplicationtestView()
{
}

BOOL CMFCApplicationtestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationtestView drawing

void CMFCApplicationtestView::OnDraw(CDC* /*pDC*/)
{
	CMFCApplicationtestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCApplicationtestView printing


void CMFCApplicationtestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplicationtestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplicationtestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplicationtestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCApplicationtestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplicationtestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplicationtestView diagnostics

#ifdef _DEBUG
void CMFCApplicationtestView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationtestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationtestDoc* CMFCApplicationtestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationtestDoc)));
	return (CMFCApplicationtestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationtestView message handlers
