#pragma once

// CCySocketDataT1 명령 대상

class CCySocketDataT1 : public CObject
{
public:
	CCySocketDataT1();
	virtual ~CCySocketDataT1();

public:
	public:

		virtual void Serialize(CArchive& ar);
	CString m_score;

};


