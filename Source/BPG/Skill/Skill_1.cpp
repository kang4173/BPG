// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_1.h"

USkill_1::USkill_1()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void USkill_1::BeginPlay()
{
	Super::BeginPlay();


}

void USkill_1::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
