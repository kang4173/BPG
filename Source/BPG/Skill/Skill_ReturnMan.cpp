// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_ReturnMan.h"

USkill_ReturnMan::USkill_ReturnMan()
{
    PrimaryComponentTick.bCanEverTick = true;

}

void USkill_ReturnMan::BeginPlay()
{
    Super::BeginPlay();

}

void USkill_ReturnMan::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USkill_ReturnMan::Tbagging()
{
}

void USkill_ReturnMan::ActiveSkill()
{
}
