﻿
// DrawView.cpp: CDrawView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Draw.h"
#endif

#include "DrawDoc.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CDrawView 构造/析构

CDrawView::CDrawView() noexcept
{
	// TODO: 在此处添加构造代码

}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawView 绘图

void CDrawView::OnDraw(CDC* /*pDC*/)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDrawView 诊断

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView 消息处理程序


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	this->m_ptOrigin = point;

	CView::OnLButtonDown(nFlags, point);
}


void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值


	////1.SDK
	//{
	//	HDC hdc;
	//	hdc = ::GetDC(m_hWnd);
	//	::MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);
	//	::LineTo(hdc, point.x, point.y);
	//	::ReleaseDC(m_hWnd, hdc);
	//}

	////2.CDC类
	//{
	//	CDC* pDC = GetDC();
	//	pDC->MoveTo(m_ptOrigin);
	//	pDC->LineTo(point);
	//	ReleaseDC(pDC);
	//}

	////3.CClientDC
	//{
	//	//CClientDC dc(this);
	//	CClientDC dc(GetParent());

	//	dc.MoveTo(m_ptOrigin);
	//	dc.LineTo(point);
	//}

	//4.CWindowDC
	{
		//CWindowDC dc(this);
		//CWindowDC dc(GetParent());
		CWindowDC dc(GetDesktopWindow());


		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
	}

	CView::OnLButtonUp(nFlags, point);
}
