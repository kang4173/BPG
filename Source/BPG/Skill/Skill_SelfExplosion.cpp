// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_SelfExplosion.h"

USkill_SelfExplosion::USkill_SelfExplosion()
{
    PrimaryComponentTick.bCanEverTick = true;

}

void USkill_SelfExplosion::BeginPlay()
{
    Super::BeginPlay();

}

void USkill_SelfExplosion::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USkill_SelfExplosion::Tbagging()
{
}

void USkill_SelfExplosion::ActiveSkill()
{
}
