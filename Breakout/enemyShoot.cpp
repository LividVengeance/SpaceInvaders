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
#include "resource.h"
#include "utils.h"

// This Includes
#include "enemyShoot.h"

// Static Variables

// Static Function Prototypes

// Implementation

CEnemyShoot::CEnemyShoot()
	: m_fVelocityX(0.0f)
	, m_fVelocityY(0.0f)
{

}

CEnemyShoot::~CEnemyShoot()
{

}

bool
CEnemyShoot::Initialise(float _fPosX, float _fPosY, float _fVelocityX, float _fVelocityY)
{
	VALIDATE(CEntity::Initialise(IDB_BALLSPRITE, IDB_BALLMASK));

	m_fX = _fPosX;
	m_fY = _fPosY;

	m_fVelocityX = _fVelocityX;
	m_fVelocityY = _fVelocityY;
	bCanBeHit = false;

	return (true);
}

void
CEnemyShoot::Draw()
{
	if (bCanBeHit)
	{
		CEntity::Draw();
	}

}

void
CEnemyShoot::Process(float _fDeltaTick)
{
	//m_fX += m_fVelocityX * _fDeltaTick;
	m_fY += 400 * _fDeltaTick;

	CEntity::Process(_fDeltaTick);
}

float
CEnemyShoot::GetVelocityX() const
{
	return (m_fVelocityX);
}

float
CEnemyShoot::GetVelocityY() const
{
	return (m_fVelocityY);
}

void
CEnemyShoot::SetVelocityX(float _fX)
{
	m_fVelocityX = _fX;
}

void
CEnemyShoot::SetVelocityY(float _fY)
{
	m_fVelocityY = _fY;
}

float
CEnemyShoot::GetRadius() const
{
	return (GetWidth() / 2.0f);
}

void CEnemyShoot::SetVisable(bool _bVisable)
{
	bCanBeHit = _bVisable;
}

bool CEnemyShoot::GetVisable()
{
	return(bCanBeHit);
}
