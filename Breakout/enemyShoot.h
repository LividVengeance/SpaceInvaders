//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//

#pragma once

#if !defined(__ENEMYBALL_H__)
#define __ENEMYBALL_H__

// Library Includes

// Local Includes
#include "entity.h"

// Types

// Constants

// Prototypes
class CSprite;

class CEnemyShoot : public CEntity
{
	// Member Functions
public:
	CEnemyShoot();
	virtual ~CEnemyShoot();

	virtual bool Initialise(float _fPosX, float _fPosY, float _fVelocityX, float _fVelocityY);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	float GetVelocityX() const;
	float GetVelocityY() const;
	void SetVelocityX(float _fX);
	void SetVelocityY(float _fY);

	void SetVisable(bool _bVisable);
	bool GetVisable();

	float GetRadius() const;

protected:

private:
	CEnemyShoot(const CEnemyShoot& _kr);
	CEnemyShoot& operator= (const CEnemyShoot& _kr);

	// Member Variables
public:

protected:
	float m_fVelocityX;
	float m_fVelocityY;

	bool bCanBeHit;

private:

};


#endif    // __ENEMYBALL_H__
