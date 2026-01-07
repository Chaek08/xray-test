
#pragma once

#include "CameraDefs.h"

class ENGINE_API		CEffectorCam
{
protected:
	ECamEffectorType	eType;
	BOOL				bAffected;
	
	friend class		CCameraManager;
	float				fLifeTime;
public:
						CEffectorCam	(ECamEffectorType type, float tm, BOOL affected)	{eType = type; fLifeTime=tm; bAffected=affected;};
						CEffectorCam	()									{eType=(ECamEffectorType)0; fLifeTime=0.0f;};
	virtual				~CEffectorCam	()									{};
			void		SetType			(ECamEffectorType type)				{eType=type;}
	IC ECamEffectorType	GetType			()									{return eType;}
	IC BOOL				Affected		() {return bAffected;}
	virtual	BOOL		Valid			()									{return fLifeTime>0.0f;}
	IC virtual BOOL		Overlapped		()									{return FALSE;}

	virtual	BOOL		Process			(Fvector &p, Fvector &d, Fvector &n, float& fFov, float& fFar, float& fAspect){fLifeTime-=Device.fTimeDelta; return Valid();};

	virtual	void		ProcessIfInvalid(Fvector &p, Fvector &d, Fvector &n, float& fFov, float& fFar, float& fAspect){};
	virtual BOOL		AllowProcessingIfInvalid()							{return FALSE;}
};
