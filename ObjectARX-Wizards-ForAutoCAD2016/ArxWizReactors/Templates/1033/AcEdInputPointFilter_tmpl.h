// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- [!output HEADER_FILE] : Declaration of the [!output CLASS_NAME]
//-----------------------------------------------------------------------------
#pragma once

#ifdef [!output UPPER_CASE_SAFE_PROJECT_NAME]_MODULE
#define DLLIMPEXP __declspec(dllexport)
#else
//----- Note: we don't use __declspec(dllimport) here, because of the
//----- "local vtable" problem with msvc. If you use __declspec(dllimport),
//----- then, when a client dll does a new on the class, the object's
//----- vtable pointer points to a vtable allocated in that client
//----- dll. If the client dll then passes the object to another dll,
//----- and the client dll is then unloaded, the vtable becomes invalid
//----- and any virtual calls on the object will access invalid memory.
//-----
//----- By not using __declspec(dllimport), we guarantee that the
//----- vtable is allocated in the server dll during the ctor and the
//----- client dll does not overwrite the vtable pointer after calling
//----- the ctor. And, since we expect the server dll to remain in
//----- memory indefinitely, there is no problem with vtables unexpectedly
//----- going away.
#define DLLIMPEXP
#endif

//-----------------------------------------------------------------------------
#include "[!output INCLUDE_HEADER]"

//-----------------------------------------------------------------------------
//----- Note: Uncomment the DLLIMPEXP symbol below if you wish exporting
//----- your class to other ARX/DBX modules
class /*DLLIMPEXP*/ [!output CLASS_NAME_ROOT] : public [!output BASE_CLASS] {

public:
	ACRX_DECLARE_MEMBERS([!output CLASS_NAME_ROOT]) ;

protected:
	//----- Pointer to the document this reactor instance belongs to.
	AcApDocument *mpDocument ;

public:
	[!output CLASS_NAME_ROOT] (AcApDocument *pDoc =NULL) ;
	virtual ~[!output CLASS_NAME_ROOT] () ;

	virtual void Attach (AcApDocument *pDoc) ;
	virtual void Detach () ;
	virtual AcApDocument *Subject () const ;
	virtual bool IsAttached () const ;

	virtual Acad::ErrorStatus processInputPoint (
		bool &changedPoint,
		AcGePoint3d &newPoint,
		bool &displayOsnapGlyph,
		bool &changedTooltipStr,
		ACHAR *&newTooltipString,
		bool &retry,
		AcGiViewportDraw *drawContext,
		AcApDocument *document,
		bool pointComputed,
		int history,
		const AcGePoint3d &lastPoint,
		const AcGePoint3d &rawPoint,
		const AcGePoint3d &grippedPoint,
		const AcGePoint3d &cartesianSnappedPoint,
		const AcGePoint3d &osnappedPoint,
		AcDb::OsnapMask osnapMask,
		const AcArray<AcDbCustomOsnapMode *> &customOsnapModes,
		AcDb::OsnapMask osnapOverrides,
		const AcArray<AcDbCustomOsnapMode *> &customOsnapOverrides,
		const AcArray<AcDbObjectId> &pickedEntities,
		const AcArray<AcDbObjectIdArray, AcArrayObjectCopyReallocator<AcDbObjectIdArray> > &nestedPickedEntities,
		const AcArray<Adesk::GsMarker> &gsSelectionMark,
		const AcArray<AcDbObjectId> &keyPointEntities,
		const AcArray<AcDbObjectIdArray, AcArrayObjectCopyReallocator<AcDbObjectIdArray> > &nestedKeyPointEntities,
		const AcArray<Adesk::GsMarker> &keyPointGsSelectionMark,
		const AcArray<AcGeCurve3d *> &alignmentPaths,
		const AcGePoint3d &computedPoint,
		const ACHAR *tooltipString
	) ;

} ;

#ifdef [!output UPPER_CASE_SAFE_PROJECT_NAME]_MODULE
ACDB_REGISTER_OBJECT_ENTRY_AUTO([!output CLASS_NAME_ROOT])
#endif
