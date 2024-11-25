// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ArcaneShards.h"

FString UArcaneShards::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);

	if (Level == 1)
	{
		return FString::Printf(TEXT(
			// Title 
			"<Title>ARCANE SHARDS</>\n\n"

			// Level
			"<Small>Level : </><Level>%d</>\n"
			// ManaCost 
			"<Small>Mana Cost : </><ManaCost>%.1f</>\n"
			// Cooldown 
			"<Small>Cooldown : </><Cooldown>%.1f</>\n\n"

			// Description 
			"<Default>Summon a shard of arcane energy, "
			"causing radial arcane damage of  </>"

			//Damage
			"<Damage>%d</><Default> at the shard origin.</>"),

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
			"<Title>ARCANE SHARDS</>\n\n"

			// Level
			"<Small>Level : </><Level>%d</>\n"
			// ManaCost 
			"<Small>Mana Cost : </><ManaCost>%.1f</>\n"
			// Cooldown 
			"<Small>Cooldown : </><Cooldown>%.1f</>\n\n"

			// Additional Number of Shock Targets 
			"<Default>Summon %d shards of arcane energy, causing radial arcane damage of </>"

			//Damage
			"<Damage>%d</><Default> damage. </>"),

			// Values
			Level,
			ManaCost,
			FMath::Min(Level, MaxNumShards),
			Cooldown,
			ScaledDamage);
	}
}

FString UArcaneShards::GetNextLevelDescription(int32 Level)
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

		// Description 
		"<Default>Summon shards of arcane energy, "
		"causing radial arcane damage of  </>"

		//Damage
		"<Damage>%d</><Default> at the shard origin.</>"),

		// Values
		Level,
		ManaCost,
		Cooldown,
		ScaledDamage);
}
