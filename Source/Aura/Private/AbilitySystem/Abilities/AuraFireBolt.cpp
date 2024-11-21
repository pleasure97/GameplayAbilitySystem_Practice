// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/AuraFireBolt.h"
#include "Kismet/KismetSystemLibrary.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level); 
	const float ManaCost = FMath::Abs(GetManaCost(Level)); 
	const float Cooldown = GetCooldown(Level); 

	if (Level == 1)
	{
		return FString::Printf(TEXT(
			// Title 
			"<Title>FIRE BOLT</>\n\n"

			// Level
			"<Small>Level : </><Level>%d</>\n"
			// ManaCost 
			"<Small>Mana Cost : </><ManaCost>%.1f</>\n"
			// Cooldown 
			"<Small>Cooldown : </><Cooldown>%.1f</>\n\n"

			// Description 
			"<Default>Launches a bolt of fire, "
			"exploding on impact and dealing: </>"

			//Damage
			"<Damage>%d</><Default> fire damage with"
			" a chance to burn</>"),

			// Values
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
	}
	else
	{
		return FString::Printf(TEXT(
			// Title 
			"<Title>FIRE BOLT</>\n\n"

			// Level
			"<Small>Level : </><Level>%d</>\n"
			// ManaCost 
			"<Small>Mana Cost : </><ManaCost>%.1f</>\n"
			// Cooldown 
			"<Small>Cooldown : </><Cooldown>%.1f</>\n\n"

			// Number of FireBolts 
			"<Default>Launches %d bolts of fire, "
			"exploding on impact and dealing: </>"

			//Damage
			"<Damage>%d</><Default> fire damage with"
			" a chance to burn</>"),

			// Values
			Level,
			ManaCost,
			FMath::Min(Level, NumProjectiles), 
			Cooldown,
			ScaledDamage);
	}
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level); 
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);

	return FString::Printf(TEXT(
		// Title 
		"<Title>NEXT LEVEL: </>\n\n"

		// Level
		"<Small>Level : </><Level>%d</>\n"
		// ManaCost 
		"<Small>Mana Cost : </><ManaCost>%.1f</>\n"
		// Cooldown 
		"<Small>Cooldown : </><Cooldown>%.1f</>\n\n"

		// Number of FireBolts 
		"<Default>Launches %d bolts of fire, "
		"exploding on impact and dealing: </>"

		//Damage
		"<Damage>%d</><Default> fire damage with"
		" a chance to burn</>"),

		// Values
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, NumProjectiles),
		ScaledDamage);
}

void UAuraFireBolt::SpawnProjectiles(const FVector& ProjectileLocation, const FGameplayTag& SocketTag, bool bOverridePitch, float PitchOverride, AActor* HomingTarget)
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority(); 
	if (!bIsServer) return;

	const FVector SocketLocation = ICombatInterface::Execute_GetCombatSocketLocation(GetAvatarActorFromActorInfo(), SocketTag);
	FRotator Rotation = (ProjectileLocation - SocketLocation).Rotation(); 
	if (bOverridePitch) { Rotation.Pitch = PitchOverride; }

	const FVector Forward = Rotation.Vector(); 
	const FVector LeftOfSpread = Forward.RotateAngleAxis(-ProjectileSpread / 2.f, FVector::UpVector); 

	const int32 NumProjectiles = FMath::Min(MaxNumProjectiles, GetAbilityLevel()); 
	if (NumProjectiles > 1)
	{
		for (int32 i = 0; i < NumProjectiles; i++)
		{

		}
	}
	else
	{

	}

	UKismetSystemLibrary::DrawDebugArrow(
		GetAvatarActorFromActorInfo(), 
		SocketLocation, 
		SocketLocation + Rotation.Vector() * 100.f, 
		5,
		FLinearColor::Green,
		120,
		5); 
}
