// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/MagicCircle.h"

AMagicCircle::AMagicCircle()
{
	PrimaryActorTick.bCanEverTick = true;

	MagicCircleDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("MagicCircleDecal"));
	MagicCircleDecal->SetupAttachment(GetRootComponent()); 
}

void AMagicCircle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMagicCircle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

