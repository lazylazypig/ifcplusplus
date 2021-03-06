// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// MainFrm.h : interface of the CMainFrame class
//

#pragma once
#include "BuildingElementsPane.h"
#include "OutputWnd.h"
#include "PropertiesWnd.h"
#include "STEPWnd.h"
#include <Inventor/errors/SoDebugError.h>
class IfcQueryDoc;
class IfcQueryMFCView;

class CMainFrame : public CFrameWndEx
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
	IfcQueryDoc* getCurrentDocument();
	IfcQueryMFCView* getCurrentView();

	void zoomToModel();
	void OnLoadWallExample( UINT ID );
	void OnClearWindowState( UINT ID );
	void OnZoomToBoundings( UINT ID );
	void OnWriteFileIFC( UINT ID );
	void OnWriteFileWebGL( UINT ID );
	void OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags );
	void OnUpdate();
	BOOL PreTranslateMessage( MSG* pMsg );
	static void slotMessageWrapper( void* obj_ptr, shared_ptr<StatusCallback::Message> m );
	void OnStatusMessage( const shared_ptr<StatusCallback::Message>& m );
	shared_ptr<StatusCallback> m_message_target;
	
protected:  // control bar embedded members
	CMFCRibbonBar					m_wndRibbonBar;
	CMFCRibbonApplicationButton		m_MainButton;
	CMFCToolBarImages				m_PanelImages;
	CMFCRibbonStatusBar				m_wndStatusBar;
	BuildingElementsPane			m_wndBuildingElements;
	OutputWidget					m_wndOutput;
	CPropertiesWnd					m_wndProperties;
	STEPWnd							m_wndSTEP;
	CMFCRibbonButton*				m_btnLoadWall;
	CMFCRibbonButton*				m_btn_clear_window_state;
	CMFCRibbonButton*				m_btnZoomToBoundings;
	CMFCRibbonButton*				m_btnExportIFC;
	CMFCRibbonButton*				m_btnExportWebGL;
	CProgressCtrl					m_ctrl_progress;
	bool m_internal_call_to_select = false;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg void OnFilePrint();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnUpdateFilePrintPreview(CCmdUI* pCmdUI);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	afx_msg void OnViewChange( UINT nCmdID );
	afx_msg void OnSize( UINT nType, int cx, int cy );

	afx_msg void DocToFrame();
	DECLARE_MESSAGE_MAP()

	BOOL CreateDockingWindows();
	void SetDockingWindowIcons(BOOL bHiColorIcons);
};
