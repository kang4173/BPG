// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_InvisibleMan.h"

void USkill_InvisibleMan::BeginPlay()
{
}

void USkill_InvisibleMan::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
}

void USkill_InvisibleMan::Tbagging()
{
}

void USkill_InvisibleMan::ActiveSkill()
{
	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Green, FString::Printf(TEXT("ActiveSikll")));
}
