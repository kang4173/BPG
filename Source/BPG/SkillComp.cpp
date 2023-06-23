// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillComp.h"

// Sets default values for this component's properties
USkillComp::USkillComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkillComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USkillComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USkillComp::Tbagging_Implementation()
{
}

