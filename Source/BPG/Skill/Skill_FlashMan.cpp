// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_FlashMan.h"

USkill_FlashMan::USkill_FlashMan()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void USkill_FlashMan::BeginPlay()
{
	Super::BeginPlay();


}

void USkill_FlashMan::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void USkill_FlashMan::Tbagging()
{
	
}

void USkill_FlashMan::ActiveSkill()
{
		
}

void USkill_FlashMan::CharacterCall(ACharacter* OwnChar)
{
	Char = Cast<ABaseChar>(OwnChar);

	if (Char)
	{
		SetCharSpeed();
	}

}
