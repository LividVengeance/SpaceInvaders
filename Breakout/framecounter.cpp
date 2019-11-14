//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School.
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//

// Library Includes

// Local Includes

// This Include
#include "framecounter.h"

// Static Variables

// Static Function Prototypes


CFPSCounter::CFPSCounter()
	:m_fTimeElapsed(0.0f)
	, m_iFrameCount(0)
	, m_fFrameRate(0)
{

}

CFPSCounter::~CFPSCounter()
{

}


bool
CFPSCounter::Initialise()
{
	return (true);
}


void 
CFPSCounter::CountFramesPerSecond(float _fDeltaTime)
{
	++m_iFrameCount;

	m_fTimeElapsed += _fDeltaTime;

	if (m_fTimeElapsed >= 1.0f)
	{
		m_fFrameRate = static_cast< float >(m_iFrameCount);
		m_iFrameCount = 0;
		m_fTimeElapsed = 0.0f;
	}
	UpdateFPSText();
}

void CFPSCounter::UpdateFPSText()
{
	m_strFPS = L"FPS: ";
	wchar_t wstrTemp[10];
	_itow_s(static_cast< int >(m_fFrameRate), wstrTemp, 10);
	m_strFPS += wstrTemp;
}


void CFPSCounter::DrawFPSText(HDC _hdc, int _iWidth, int _iHeight)
{
	const int kiX = _iWidth - 70;
	const int kiY = _iHeight - 14;
	TextOut(_hdc, kiX, kiY, m_strFPS.c_str(), static_cast< int >(m_strFPS.size()));
	SetTextColor(_hdc, RGB(255, 255, 255));
}

