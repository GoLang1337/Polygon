#pragma once

class AItem_Weapon_General
{
public:
	char pad_0000[692]; //0x0000
	int32_t WeaponDamage; //0x02B4
	char pad_02B8[8]; //0x02B8
	int32_t MaxMagazineAmmo; //0x02C0
	int32_t MaxStockAmmo; //0x02C4
	float TimeBetweenShots; //0x02C8
	char pad_02CC[4]; //0x02CC
	float WeaponRecoil; //0x02D0
	float WeaponRecoilAlphaPerShot; //0x02D4
	float AccuracyHip; //0x02D8
	float AccuracySight; //0x02DC
	float SpreadShot; //0x02E0
	char pad_02E4[32]; //0x02E4
	bool bIsPremium; //0x0304
	bool bIsAvailable; //0x0305
	char pad_0306[130]; //0x0306
	int32_t CurrentMagazineAmmo; //0x0388
	uint16_t CurrentStockAmmo; //0x038C
	char pad_038E[2]; //0x038E
	float CurrentSpread; //0x0390
}; //Size: 0x0394

class UHealthStatsComponent
{
public:
	char pad_0000[192]; //0x0000
	int32_t Health; //0x00C0
	float Stamina; //0x00C4
	char pad_00C8[959]; //0x00C8
}; //Size: 0x0487



/*
Info:

- Health is stored in the server-side
- Stamina is stored in the client-side (so can be modified)
- Current spread is manipulated by AccuracyHip and AccuracySight
- Don't set TimeBetweenShots less to 0.f or any negative value else will not work

*/